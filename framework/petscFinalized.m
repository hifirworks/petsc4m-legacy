function [finalized, errCode] = petscFinalized
%Determine whether PetscFinalize() has been called yet.
%   [finalized, errCode] = petscFinalized
%
%   finalized(int)
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscInitialize, petscFinalize, petscInitialized
%
% PETSc C interface:
%   PetscErrorCode  PetscFinalized(PetscBool  *isFinalized)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscFinalized.html

%#codegen -args {}

finalized = int32(0);
errCode = int32(-1);

if ~coder.target('MATLAB')
    b = coder.opaque('PetscBool');
    errCode = coder.ceval('PetscFinalized', coder.wref(b));
    
    if errCode && (nargout==1 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'PetscFinalized returned error code %d\n', errCode)
    end

    finalized = coder.ceval(' ', b);
end
end
