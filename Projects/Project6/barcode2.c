/*****************************************************************
 * This program finds the edges of light and dark regions of the
 * input binary bit pattern.
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
    *a2 = 0;
    
    for (p = a1 + 1; p < a1 + n; p++) {
        a2++;
        if (*p == *(p - 1)) {
            *a2 = 0;
        } else {
            *a2 = 1;
        }
    }
}
