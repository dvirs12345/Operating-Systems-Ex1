//Author- Dvir Sadon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

#define SLEEP_TIME 4000000

int main()
{
    pid_t pid = fork(); // Duplicate
    if(pid == 0) // If In Child
    {
        // Working on the current directory
        chdir("/");

        // move to a new session
        setsid();

        // Close open channels for input or output
        close(stdout);
        close(stdin);
        close(stderr);

        // Log updates
        openlog("Daemon1", LOG_PID, LOG_DAEMON);
        usleep(SLEEP_TIME);
        syslog(LOG_NOTICE, "Working on it...");
        usleep(SLEEP_TIME);
        syslog(LOG_NOTICE, "DONE!");
    }
    else
        printf("Daemon PID = %d\n", pid);

    return 0;
}