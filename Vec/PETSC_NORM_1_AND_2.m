function val = PETSC_NORM_1_AND_2
% Obtain PETSC constant NORM_1_AND_2

coder.inline('always');

val = petscGetEnum('NORM_1_AND_2');
end
