function obj = PETSC_NULL_REAL
% Obtain PETSC constant NULL of type PetscReal *

coder.inline('always');

obj = petscGetObject('PETSC_NULL_REAL');
end
