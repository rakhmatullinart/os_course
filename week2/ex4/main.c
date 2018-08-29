//
//  main.c
//  os_c
//
//  Created by admin on 29/08/2018.
//  Copyright © 2018 admin. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void swap(int *p1, int *p2){
    int t = *p1;
    *p1 = *p2;
    *p2 = t;
}


int main(){
    int a, b;
    printf("\nEnter The First Number: ");
    scanf("%d", &a);
    printf("\nEnter The Second Number: ");
    scanf("%d", &b);
    
    swap(&a, &b);
    printf("First number: %d\nSecond number: %d\n", a, b);
    
    
    
    return 0;
}

