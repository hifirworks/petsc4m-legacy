function errCode = petscMatSetOption(mat, op, flg)
%Sets a parameter option for a matrix. Some options may be specific to 
%certain storage formats. Some options determine how values will be 
%inserted (or added). Sorted, row-oriented input will generally 
%assemble the fastest. The default is row-oriented.
%
%   errCode = petscMatSetOption(mat, op, flg)
%
%   assembled(int)
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscMatAssemblyEnd, petscMatSetValues, petscMatAssemblyBegin
%
% PETSc C interface:
%   PetscErrorCode MatSetOption(Mat mat,MatOption op,PetscBool flg)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetOption.html

%#codegen -args {PetscMat, int32(0), int32(0)}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    errCode = coder.ceval('MatSetOption', t_mat, op, flg);

    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'MatSetOptions returned error code %d\n', errCode)
    end
end

end
