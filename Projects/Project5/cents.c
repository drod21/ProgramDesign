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
	//initialize variables and read input
	int cents, pennies, quarters, dimes, nickels;
	pennies = quarters = dimes = nickels =0;
        printf("Enter the number of cents:\n");
	scanf("%d", &cents);

	//check the range of the input amount
	if(cents< 0 || cents > 10000)
	   printf("Invalid amount %d,\nAmount must be between 0 and 10000, inclusive\n", cents);
        else {
		quarters = cents/QUARTER;
		dimes = cents%QUARTER/DIME;
		nickels = cents%QUARTER%DIME/NICKEL;
		pennies = cents%QUARTER%DIME%NICKEL;

		printf("Quarters: %d\n", quarters);
	        printf("Dimes: %d\n", dimes);
        	printf("Nickels: %d\n", nickels);
	        printf("Pennies: %d\n", pennies);
	}
	return 0;
}

void coins(int cents, int *quarters, int *dimes, int *nickels, int *pennies) {
    
}

	
