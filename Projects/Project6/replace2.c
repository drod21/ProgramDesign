/* This program prompts the user for the amount of numbers in a digit, then the numbers of the digit itself, then adds 6 to each digit and divides it by 10, displaying the remainder (modulus 10), then swaps the first and last digits.
 ** Derek Rodriguez *** 
 ** U3756832 *** 
 ** COP3514 ***
 ** 2/18/16 ***
  */

#include <stdio.h>

#define SUM 6
#define TEN 10
void replace(int *a, int *b, int n);
void swap(int *p, int *q);

int main(void)
{
    /* Declare Variables */
    int i = 0, dig;
    
    /* User input for size of number and the number itself */
    printf("Enter the number of digits of the number:\n");
    scanf("%d", &dig);
    int num[dig], repl[dig];
    printf("Enter the number.\n");
    for (i = 0; i < dig; i++) {
        scanf("%1d", &num[i]);
    }
    
    replace(num, repl, dig); /* Replace values with computed values */
    swap(repl,(repl+dig-1)); /* Swap digits through pointer arithmetic */
    
    
        /* Print the final answer */
    for (i = 0; i < dig; i++) {
        printf("%d", repl[i]);
    }
    
    return 0;
}

void replace(int *a, int *b, int n)
{
    int *p;
    /* for p = a, loop through a, complete the calculation (digit + 6 % 10)
     ** and store into *b, then increment *b **/
    for (p = a; p < a + n; p++) {
        *b = (*p + SUM) % TEN;
        b++;
        }
}
void swap(int *p, int *q)
{
    /* Swaps first and last value through pointer arithmetic. */
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
}