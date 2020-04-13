//Author- Dvir Sadon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

#define SLEEP_TIME 4000000

int main()
{
    pid_t pid = fork();
    if(pid == 0) // If In Child
    {
        chdir("/");
        setsid();

        close(stdout);
        close(stdin);
        close(stderr);

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