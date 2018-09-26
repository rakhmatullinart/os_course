#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    
    int fd[2];  // Used to store two ends of pipe
    
    char input_str[100], second_sting[100];
    
    
    if (pipe(fd)==0){
    
        scanf("%s", input_str);
        write(fd[1], input_str, strlen(input_str)+1);
        
        read(fd[0], second_sting, 100);
        printf("%s", second_sting);
        
        exit(EXIT_SUCCESS);
    }
    else{
        exit(EXIT_FAILURE);
    }
    
}

