//
//  ex1.c
//  os_c
//
//  Created by admin on 29/08/2018.
//  Copyright © 2018 admin. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("%lu, %lu, %lu\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%d, %f, %f", a, b, c);
    return 0;
}
