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
    
    // User input for dollar amount
    printf("Please enter a U.S. dollar amount:\n");
    scanf("%d", &dollarAmount);
    
    // Checks that dollarAmount is in the correct range.
    if (dollarAmount < 0 || dollarAmount > 1000000000) {
        
        printf("Amount must be between 0 and 1000000000, inclusive.\n");
        
    } else {
    
    printf("$20 bills: %d\n", dollarAmount / TWENTY); // Number of 20 dollar bills
    dollarAmount = dollarAmount % TWENTY; // Number left over after 20
        
    printf("$10 bills: %d\n", dollarAmount / TEN); // Number of 10 dollar bills
    dollarAmount = dollarAmount % TEN; // Number left over after 10
        
    printf("$5 bills: %d\n", dollarAmount / FIVE); // Number of 5 dollar bills
    dollarAmount = dollarAmount % FIVE; // Number left over after 5
        
    printf("$1 bills: %d\n", dollarAmount); //Number of 1 dollar bills
        
    }
    
    return 0;
}
