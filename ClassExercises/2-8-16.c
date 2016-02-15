//
//  2-8-16.c
//  
//
//  Created by Derek Rodriguez on 2/8/16.
//
//

#include <stdio.h>


int main(void) {
    int *p;
    int i = 4;
    p = &i;
    
    printf("values of p and i: %p %d\n", p, i);
    
    *p = 32;
    printf("values of p and i: %p %d\n", p, i);
    
    return 0;
}