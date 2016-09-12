//
//  pointertest.c
//  
//
//  Created by Derek Rodriguez on 9/5/16.
//
//

#include <stdio.h>


int main() {
    
    int *p, i;
    
    
    p = &i;
    i = 1;
    printf("*p = %d\n", *p);
    printf("i = %d\n", i);
    *p = 9;
    printf("*p = %d\n", *p);
    printf("i = %d\n", i);
    return 0;
}