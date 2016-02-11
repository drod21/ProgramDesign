/*cents.c, project 5
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
        *quarters = cents / QUARTER;
        *dimes = cents % QUARTER / DIME;
        *nickels = cents % QUARTER % DIME / NICKEL;
        *pennies = cents % QUARTER % DIME % NICKEL;
    }
}

	
