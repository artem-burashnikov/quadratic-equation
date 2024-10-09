.PHONY: all check clean

all: test_quadratic_equation

test_quadratic_equation: test_quadratic_equation.o quadratic_equation.o
	gcc -g -Wall test_quadratic_equation.o quadratic_equation.o -o test_quadratic_equation -lm

test_quadratic_equation.o: tests/test_quadratic_equation.c src/quadratic_equation.h
	gcc -I src -c tests/test_quadratic_equation.c

quadratic_equation.o: src/quadratic_equation.c src/quadratic_equation.h
	gcc -I src -c src/quadratic_equation.c -lm

check: test_quadratic_equation
	./test_quadratic_equation

clean:
	rm test_quadratic_equation test_quadratic_equation.o quadratic_equation.o
