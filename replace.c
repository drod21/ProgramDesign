/* This program prompts the user for a three digit integer between 100 and 999, then adds 6 to each digit and divides it by 10, displaying the remainder (modulus 10)
 Derek Rodriguez
 COP3514
 U3756832 */
#include <stdio.h>

#define SUM 6
#define TEN 10
#define HUNDRED 100
#define MAX_NUMBER 999

int main(void)
{
    /* Declare Variables */
    int n, i, j, k;
    
    /* User input for integer */
    printf("Enter a three digit number between 100 and 999.\n");
    scanf("%d", &n);
    
    /* If/Else statement to establish condition */
    if (n < HUNDRED || n > MAX_NUMBER) {
        printf("Invalid input, number must be between 100 and 999.\n");
    } else {
        /* User (number + 6) % 10 */
        i = (n + SUM / HUNDRED) % TEN;
        j = (n + SUM / TEN) % TEN;
        k = (n + SUM) % TEN;
        
        /* Print the final answer */
        printf("New integer: %d%d%d\n", i, j, k);
    }
    return 0;
}