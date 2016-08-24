//
//  amount4.c
//  
//
//  Created by Derek Rodriguez on 8/24/16.
//
//

#include <stdio.h>
#define QUARTERS 25
#define DIMES 10
#define NICKELS 5
#define PENNIES 1

int main() {
    
    int quarters, dimes, nickels, pennies;
    printf("Please input the amount of quarters, dimes, nickels, pennies: \n");
    
    scanf("%d %d %d %d", &quarters, &dimes, &nickels, &pennies);
    
    double total = (double) quarters * QUARTERS + dimes * DIMES + nickels * NICKELS + pennies * PENNIES;
    
    printf("total amount: $%.2f\n", total / 100);
    
    return 0;
    
}