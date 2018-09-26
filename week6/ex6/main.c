#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig){
    printf("Proccess was killed");
    exit(0);
}


int  main(void)
{
    pid_t children_pid[2];
    int fd[2];
    pipe(fd);
//    children_pid[0] = fork();
    
    // child proccess
    if ((children_pid[0] = fork()) == 0){
        close(fd[1]);
        read(fd[1], &children_pid[1], sizeof(children_pid[1]));
        kill(children_pid[1], SIGKILL);
        printf("Killed second child proccess");
    }
    
    else{
//        children_pid[1] = fork();
        // second child proccess
        if ((children_pid[1] = fork()) == 0){
            signal(SIGKILL, handler);
            while (1) {
                sleep(1);
            }
        }
        // parent proccess
        else{
            close(fd[0]);
            write(fd[0], &children_pid[1], sizeof(children_pid[1]));
            wait(NULL);
        }
    }
    
    return 0;
}



