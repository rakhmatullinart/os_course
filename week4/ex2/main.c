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
    int i;
    for (i = 0; i < 3; i++){
        fork();
        sleep(5);
    }
    return 0;
}
