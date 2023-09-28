#
# Fortran compiler and options for Cray
#
FC=     ftn -h omp  -O0 

#
# Object files
#
OBJ=	adi.o
#
# Compile
#
.SUFFIXES:	.f90 .o
adi:	$(OBJ)
	$(FC) -o $@ $(OBJ) 

.f90.o:
	$(FC) -c $< 

#
# Clean out object files and the executable.
#
clean:
	rm *.o adi 
