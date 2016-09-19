/*dollar.c for project 5
  Program Design
 */

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main() {
	//initialize variables and read input
	int dollar = 0, twenty = 0, ten = 0, five = 0, one = 0;
    
    printf("Enter a dollar amount:\n");
    scanf("%d", &dollar);


    //check the range of the input amount
    if(dollar < 0 || dollar > 1000000000) {
        
        printf("Invalid amount %d,\nAmount must be between 0 and 1000000000, inclusive\n", dollar);
        
    } else {
        
        pay_amount(dollar, &twenty, &ten, &five, &one);
    
		printf("$20 bills: %d\n", twenty);
	        printf("$10 bills: %d\n", ten);
        	printf("$5 bills: %d\n", five);
	        printf("$1 bills: %d\n", one);
        
    }
	
	return 0;
}

	
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    
    // Compute the smallest amount to pay in $20, $10, $5, and $1 bills
        *twenties = dollars/20;
        *tens = (dollars - (*twenties * 20))/10;
        *fives = (dollars - (*twenties * 20) - (*tens * 10))/5;
        *ones = dollars - (*twenties * 20) - (*tens * 10) - (*fives * 5);
        
    
}