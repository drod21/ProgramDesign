/*****************************************************************
 * This program finds the edges of light and dark regions of the
 * input binary bit pattern.
 * Derek Rodriguez *
 * U37516832 *
 * 2/18/16 *
 * ***************************************************************/

#include <stdio.h>

void edge(int n, int *a1, int *a2);
int main(void)
{
	int input[8]={0};
    int output[8];

    int i;
	printf("please enter the 8 bit bar code:\n");
    for(i = 0; i < 8; i++) {
		scanf("%1d", &input[i]);
    }

   edge(8, input, output);
    

	for(i = 0; i < 8; i++)
		printf("%d", output[i]);

	return 0;
}

void edge(int n, int *a1, int *a2)
{
    int *p;
    *a2 = 0; /* Begin *a2 at zero */
    
    /* Start *p at second element in the array that a1 is pointing to */
    for (p = a1 + 1; p < a1 + n; p++) {
        a2++; /* Increment a2 through the loop */
        if (*p == *(p - 1)) { /* Compares *p at its position to the previous position */
            *a2 = 0;
        } else {
            *a2 = 1;
        }
    }
}
