function val = PETSC_MAT_LOCAL
% Obtain PETSC constant MAT_LOCAL

coder.inline('always');

val = petscGetEnum('MAT_LOCAL');
end
