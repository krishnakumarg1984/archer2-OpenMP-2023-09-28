# Makefile for mandelbrot area code

#
# Fortran compiler and options for Cray/clang 
#
FC=     ftn -O3 -h omp

# Fortran compiler and options for GNU 
#
#FC=     ftn -O3 -fopenmp
#
# Object files
#
OBJ=	area.o

#
# Compile
#
.SUFFIXES:	.f90 .o
area:	$(OBJ)
	$(FC) -o $@ $(OBJ) 

.f90.o:
	$(FC) -c $< 

#
# Clean out object files and the executable.
#
clean:
	rm *.o area
