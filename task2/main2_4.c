//Author - Dvir Sadon
#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
char child_stack[STACK_SIZE+1];

int main2_1()
{
    char * args[2] = {"./main2_1",NULL};
    execvp(args[0], args);
    return 0;
}

int main2_2()
{
    char * args[2] = {"./main2_2",NULL};
    execvp(args[0], args);
    return 0;
}

int main2_3()
{
    char * args[2] = {"./main2_3",NULL};
    execvp(args[0], args);
    return 0;
}

int main()
{
    int r1 = clone(main2_1, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    int r2 = clone(main2_2, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    int r3 = clone(main2_3, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    printf("ID 1 = %d\n", r1);
    printf("ID 2 = %d\n", r2);
    printf("ID 3 = %d\n", r3);
    printf("Parent id %d\n", getpid());
    sleep(10);
}