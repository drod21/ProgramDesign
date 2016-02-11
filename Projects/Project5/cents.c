/*cents.c, project 5. 
 ** Calculates the number of quarters, nickels, dimes, pennies **
 ** needed for the user input cent amount **
 ** Derek Rodriguez **
 ** U37516832 **
 */

#include <stdio.h>
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

void coins(int cents, int *quarters, int *dimes, int *nickels, int *pennies);

int main()
{
	//initialize variables
	int cents, pennies, quarters, dimes, nickels;
	cents = pennies = quarters = dimes = nickels = 0;
    coins(cents, &quarters, &dimes, &nickels, &pennies);

    printf("Quarters: %d\n", quarters);
    printf("Dimes: %d\n", dimes);
    printf("Nickels: %d\n", nickels);
    printf("Pennies: %d\n", pennies);
    
	return 0;
}

void coins(int cents, int *quarters, int *dimes, int *nickels, int *pennies) {
    /* Read user input */
    printf("Enter the number of cents:\n");
    scanf("%d", &cents);
    
    if (cents < 0 || cents > 10000) {
        printf("Invalid amount %d,\nAmount must be between 0 and 10000, inclusive\n", cents);
    } else {
        /* Do the computations and store them as pointers */
        /* Divides total cents into 25 and stores the variable */
        *quarters = cents / QUARTER;
        /* Takes the remainder of cents and quarters, divides by 10 */
        *dimes = cents % QUARTER / DIME;
        /* Takes the remainder of cents, quarters, dimes, divides by 5 */
        *nickels = cents % QUARTER % DIME / NICKEL;
        /* Takes the remainder of cents, quarts, dimes, and nickels */
        *pennies = cents % QUARTER % DIME % NICKEL;
    }
}

	
