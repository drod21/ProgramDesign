//
//  pointertest.c
//  
//
//  Created by Derek Rodriguez on 9/19/16.
//
//

#include <stdio.h>


int main() {
    
    int *p;
    int i = 4;
    
    p = &i;
    printf("i = %d, p = %d \n", i, *p);
    
    printf("values of &i and p = %p, %p \n", &i, p);
    
    *p = 32;
    
    printf("i = %d, p = %d \n", i, *p);
    
    return 0;
    
}