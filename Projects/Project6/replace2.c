/* This program prompts the user for the amount of numbers in a digit, then the numbers of the digit itself, then adds 6 to each digit and divides it by 10, displaying the remainder (modulus 10), then swaps the first and last digits.
 ** Derek Rodriguez *** 
 ** U3756832 *** 
 ** COP3514 ***
 ** 2/18/16 ***
  */

#include <stdio.h>

#define SUM 6
#define TEN 10
#define HUNDRED 100
#define MAX_NUMBER 999
void replace(int *a, int *b, int n);
void swap(int *p, int *q);

int main(void)
{
    /* Declare Variables */
    int num[0], i, j, dig, number, repl[0];
    
    /* User input for size of number and the number itself */
    printf("Enter the number of digits of the number:\n");
    scanf("%1d", &dig);
    printf("Enter the number.\n");
    for (i = 0; i < dig; i++) {
        scanf("%1d", &num[i]);
    }
    
    
    replace(&i, repl, dig); /* Replace values with computed values */
    
    swap(&i, &j); /* exchange values of i and j */
        
        /* Print the final answer */
    
    for (i = 0; i < dig; i++) {
        printf("%d", repl[i]);
    }
    
    return 0;
}

void replace(int *a, int *b, int n)
{
    int *p;
    *b = 0;
    
    for (p = a; p < a + n; p++) {
    /* Sum of individual (digits + 6) modulus 10 */
            *b = (*p / HUNDRED + SUM) % TEN;
        }
    for (p = a + 1; p < a + n; p++) {
        *b = (*p / TEN + SUM) % TEN;
        }
    for (p = a; p < a + n - 1; p++) {
        *b = (*p + SUM) % TEN;
        }
    
}
void swap(int *p, int *q)
{
    /* Creates a temporary variable to store the pointers *p && *q, and swap them. */
    int temp = *p;
    *p = *q;
    *q = temp;
    
}