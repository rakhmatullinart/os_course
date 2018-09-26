#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sigstop_handler(int sig)
{
    printf("Caught sigstop signal");
    exit(0);
}

void sigusr1_handler(int sig)
{
    printf("Caught sigusr1 signal");
    exit(0);
}

void sigkill_handler(int sig)
{
    printf("Caught sigkill signal");
    exit(0);
}

void sigint_handler(int sig)
{
    printf("Caught killing signal by user for proccess %d", getpid());
    exit(0);
}



int  main(void)
{
    printf("My pid is: %d\n", getpid());
    
    
    signal(SIGSTOP, sigstop_handler);
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGKILL, sigkill_handler);
    
    while (1){
        pause();
    }
    return 0;
}



