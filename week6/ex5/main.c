#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void syg_handler(int sig){
    printf("Got sygterm signal from parent");
    exit(0);
}


int main()
{
    pid_t pid = fork();
    if (pid < 0){
        printf("Can't create child process\n");
        return 1;
    }
    else if (pid > 0)
    {
        sleep(10);
        kill(pid, SIGTERM);
//        printf("Process parent, pid=%d\n %d",getpid(), pid);
//        exit(0);

        
    }
    else
    {
//        printf("Process child, pid=%d\n",getpid());
        signal(SIGTERM, syg_handler);
        while (1) {
            printf("I'm alive\n");
            sleep(1);
        }
        
    }
    
    return 0;
}



