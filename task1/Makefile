CC=gcc
AR=ar
OBJECTS_MAIN = main1_1.o
OBJECTS_LIB = hello_Ariel.o
FLAGS= -Wall -g

# Creates all the nessecery files 
all: exportme hello_Ariel hello_Arielexe maintask3

exportme:
	export LD_LIBRARY_PATH=.

# 
hello_Ariel: hello_Ariel.o hello_Ariel.so 

hello_Ariel.so: $(OBJECTS_LIB)
	$(CC) -shared -o hello_Ariel.so $(OBJECTS_LIB)

# 
main1_1.o:hello_Ariel.h main1_1.c
	$(CC) $(FLAGS) -c -FPIC main1_1.c

# 
hello_Ariel.o:hello_Ariel.c
	$(CC) $(FLAGS) -c -FPIC hello_Ariel.c

# 
hello_Arielexe: main1_2.c hello_Ariel.so
	$(CC) $(FLAGS) main1_2.c hello_Ariel.so

maintask3: main1_3.c 
	$(CC) $(FLAGS) main1_3.c -ldl -o main3_lib 

.PHONY: all clean hello_Ariel

# Removes all redundent files
clean:
	rm -f *.o *.a *.so hello_Ariel *.out main3_lib 
