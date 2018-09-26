#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int sig)
{
    printf("Caught killing signal by user for proccess %d", getpid());
    exit(0);
}

int  main(void)
{
    signal(SIGINT, sigint_handler);
    
    while (1){
        pause();
    }
    return 0;
}



