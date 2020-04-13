//Author - Dvir Sadon
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    pid_t pid = fork();
    if(pid == 0) // Checks if got a child
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            printf("\nHello! I am in GRAND-CHILD\n");
        }
        else
        {
            printf("\nHello! I am in CHILD");
        }
    }
    else
    {
        printf("\nHello I am in PARENT");
    }

    return 0;
} 

