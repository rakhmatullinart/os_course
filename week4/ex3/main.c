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

void ask_input(){
    printf("Enter command: ");
}

void read_input(char *s){
    scanf("%s", s);
}

int main(void) {
    char input_string[50];
    while (1) {
        ask_input();
        read_input(input_string);
	printf("%s", input_string);
        system(input_string);
    }
    return 0;
}
