//
//  main.c
//  lab_session
//
//  Created by admin on 05/09/2018.
//  Copyright © 2018 admin. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void BubbleSort(int arr[], int arr_len){
    int i, j;
    for (i = 0; i < arr_len - 1; i++){
        for (j = 0; j < arr_len - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main(){
    int a[5] = {5, 3, 8, 1, 9};
    BubbleSort(a, 5);
    int i;
    for (i = 0; i < 5; i++)
        printf("%d", a[i]);
    return 0;
}
