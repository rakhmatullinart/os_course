//
//  main.c
//  week4
//
//  Created by admin on 12/09/2018.
//  Copyright © 2018 admin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int pid, n = 5;
    switch (pid = fork()) {
        case 0:
            printf("Hello from child [%d - %d]\n", getpid(), n);
            
        case -1:
            return EXIT_FAILURE;
            
        default:
            printf("Hello from parent [%d - %d]\n", getpid(), n);
            
    }
    return 0;
}
