#Author - Dvir Sadon
CC=gcc
AR=ar
FLAGS= -Wall -g

all: main2_1 main2_2 main2_3 runall

runall: main2_4
	# File on the right
	./$^ 

# Makes main
main: main2_1.c main2_2.c main2_3.c
	$(CC) $(FLAGS) main2_1.c main2_2.c main2_3.c -o main

# Makes main2_1
main2_1: main2_1.c 
	$(CC) $(FLAGS) main2_1.c -o main2_1

# Makes main2_2
main2_2: main2_2.c 
	$(CC) $(FLAGS) main2_2.c -o main2_2

# Makes main2_3
main2_3: main2_3.c
	$(CC) $(FLAGS) main2_3.c -o main2_3

# Makes main2_4
main2_4: main2_4.c
	$(CC) $(FLAGS) main2_4.c -o main2_4

# Cleans and the makes
.PHONY: clean all 

# Cleans all unnecessary files
clean:
	rm -f *.o *.a *.so main2_1 main2_2 main2_3 main2_4