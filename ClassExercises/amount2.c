//
//  amount.c
//  
//
//  Created by Derek Rodriguez on 1/13/16.
//
//

#include <stdio.h>

#define PENNY 1
#define NICKELS 5
#define DIMES 10
#define QUARTERS 25

int main(void) {
    int p, n, d, q;
    
    printf("Input the number of pennies, nickels, dimes, and quarters.\n");
    printf("Number of pennies:\n");
    scanf("%d", &p);
    printf("Number of nickels:\n");
    scanf("%d", &n);
    printf("Number of dimes:\n");
    scanf("%d", &d);
    printf("Number of quarters:\n");
    scanf("%d", &q);
    int amount = q * 25 + d * 10 + n * 5 + p * 1;
    
    printf("Total amount is %d cents. \n", amount);
    return 0;
}