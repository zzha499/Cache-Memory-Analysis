# template Makefile
# refer to https://makefiletutorial.com/ for more info

# GCC optimisation level
OPT = -O1 				

# the default target: add here all the targets that should be built when make
# is called without parameter
# use with `make`
default: matrix1 matrix2 matrix3

# use different targets for the different assignment tasks, see top of assignment specification

matrix1: matrix1.o 
	gcc $(OPT) -o matrix1 matrix1.o

# example target: compiling assignment
matrix1.o: matrix1.c
	gcc $(OPT) -c matrix1.c

matrix2: matrix2.o 
	gcc $(OPT) -o matrix2 matrix2.o

matrix2.o: matrix2.c
	gcc $(OPT) -c matrix2.c

matrix3: matrix3.o 
	gcc $(OPT) -o matrix3 matrix3.o

matrix3.o: matrix3.c
	gcc $(OPT) -c matrix3.c

# cleanup target
# use with 'make clean'
clean:
	rm -f *.o
	rm -f matrix1
	rm -f matrix2
	rm -f matrix3

