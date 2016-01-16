//
//  amount.c
//  
//
//  Created by Derek Rodriguez on 1/13/16.
//
//

#include <stdio.h>


int main(void) {
    int p = 2, n = 3, d = 10, q = 6;
    int amount = q * 25 + d * 10 + n * 5 + p * 1;
    
    printf("Total amount is %d cents. \n", amount);
    return 0;
}