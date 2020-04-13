//Author - Dvir Sadon
#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
char child_stack[STACK_SIZE+1];

void print(const char *text)
{
    for(int i=0;i<30;i++)
    {
        printf("hello from %s", text);
        usleep(300000);
    }
        
}

int func(void *params)
{
    print("Child\n");
}

int func2(void *params)
{
    print("Grand-Child\n");
}

int main()
{
    int r1 = clone(func, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    int r2 = clone(func2, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    printf("clone id = %d\n", r1);
    printf("clone id = %d\n", r2);
    printf("parent id %d\n", getpid());

    return 0;
}

