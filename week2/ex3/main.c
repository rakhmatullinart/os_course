//
//  main.c
//  os_c
//
//  Created by admin on 29/08/2018.
//  Copyright © 2018 admin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(){
    int n;
    char s[10];
    
    scanf("%s", s);
    
    
    sscanf(s, "%d", &n);
    int i, j;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n - i; j++){
            printf(" ");
        }
        for (j = 1; j <= i * 2 - 1; j++)
            printf("*");
        printf("\n\n");
    }
    
    
    
    return 0;
}

