//
//  amount2.c
//  
//
//  Created by Derek Rodriguez on 8/24/16.
//
//

#include <stdio.h>


int main() {
    
    int quarters, dimes, nickels, pennies;
    printf("Please input the amount of quarters, dimes, nickels, pennies: \n");
    
    scanf("%d %d %d %d", &quarters, &dimes, &nickels, &pennies);
    
    printf("total amount: %d \n", quarters * 25 + dimes * 10 + nickels * 5 + pennies * 1);
    
    return 0;
    
}