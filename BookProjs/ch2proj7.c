//
//  ch2proj7.c
//  Write a program that reads dollar amount, then shows how to pay that amount in smallest number
//  of $20, $10, $5, $1 bills
//
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
    
    printf("$20 bills: %d\n", dollarAmount / TWENTY);
    dollarAmount = dollarAmount % TWENTY;
    printf("$10 bills: %d\n", dollarAmount / TEN);
    dollarAmount = dollarAmount % TEN;
    printf("$5 bills: %d\n", dollarAmount / FIVE);
    dollarAmount = dollarAmount % FIVE;
    printf("$1 bills: %d\n", dollarAmount);
    
    return 0;
}
