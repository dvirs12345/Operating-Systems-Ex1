//Author - Dvir Sadon
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
char child_stack[STACK_SIZE+1];

int func(void *params)
{
    printf("In Child\n");
}

int func2(void *params)
{
    printf("In Son Of Child = Grand-Child\n")
}
int main()
{
    int r1 = clone(func, child_stack+STACK_SIZE, CLONE_PARENT,0);
    int r2 = clone(func2, child_stack+STACK_SIZE, CLONE_PARENT,0);
    printf("Clone result 1 = %d\n", r1);
    printf("Parent");

    return 0;
}

