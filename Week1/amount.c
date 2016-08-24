//
//  amount.c
//  
//
//  Created by Derek Rodriguez on 8/24/16.
//
//

#include <stdio.h>

int main() {
    
    int quarters, dimes, nickels, pennies;
    quarters = 6, dimes = 10, nickels = 3, pennies = 2;
    
    printf("total amount: %d\n", quarters * 25 + dimes * 10 + nickels * 5 + pennies * 1);
    
    return 0;
    
}