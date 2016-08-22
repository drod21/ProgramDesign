//
//  Derek Rodriguez
//  U37516832
//  8/22/2016
// Program that asks the user to enter a U.S. dollar amount and then shows how to pay that amount using the
// smallest number of $20, $10, $5, and $1 bills.
//

#include <stdio.h>

#define ONE 1
#define FIVE 5
#define TEN 10
#define TWENTY 20


int main(void) {
    int dollarAmount;
    
    printf("Please enter a U.S. dollar amount:\n");
    scanf("%d", &dollarAmount);
    
    if (dollarAmount < 0 || dollarAmount > 1000000000) {
        
        printf("Amount must be between 0 and 1000000000, inclusive");
        
    } else {
    
    printf("$20 bills: %d\n", dollarAmount / TWENTY);
    dollarAmount = dollarAmount % TWENTY;
    printf("$10 bills: %d\n", dollarAmount / TEN);
    dollarAmount = dollarAmount % TEN;
    printf("$5 bills: %d\n", dollarAmount / FIVE);
    dollarAmount = dollarAmount % FIVE;
    printf("$1 bills: %d\n", dollarAmount);
        
    }
    
    return 0;
}
