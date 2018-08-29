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
    char str[50];
    char reverse[50];
    
    printf("Enter any string : ");
    scanf("%s", str);
    
    int len = strlen(str);
    int end = len -1;
    int begin;
    for (begin = 0; begin < len; begin++ ){
        reverse[begin] = str[end];
        end--;
    }
    reverse[begin] = '\0';
    printf("%s", reverse);
    
    
    
    return 0;
}

