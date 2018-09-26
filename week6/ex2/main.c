#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    
    int fd1[2];  // Used to store two ends of pipe
    
    char input_str[100], second_sting[100];
    pid_t p;
    
    if (pipe(fd1)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
    
    scanf("%s", input_str);
    p = fork();
    
    if (p < 0)
    {
        fprintf(stderr, "fork Failed" );
        return 1;
    }
    
    // Parent process
    else if (p > 0)
    {
        close(fd1[0]);
        
        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);
        
    }
        
    
    // child process
    else
    {
        close(fd1[1]);
        read(fd1[0], second_sting, 100);
        close(fd1[0]);
        printf("%s", second_sting);
        
        exit(0);
    }
}

