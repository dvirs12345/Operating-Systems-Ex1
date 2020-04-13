//Author - Dvir Sadon
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    pid_t pid = fork(); // Duplicate
    if(pid == 0) // Checks if child
    {
        pid_t pid = fork();
        if(pid == 0) // Checks if child (of child)
        {
            printf("\nHello! I am in GRAND-CHILD\n");
        }
        else
        {
            printf("\nHello! I am in CHILD\n");
        }
    }
    else
    {
        printf("\nHello I am in PARENT\n");
    }

    sleep(10); 
    return 0;
} 

