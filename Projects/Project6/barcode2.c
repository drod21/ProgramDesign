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
    
    
   /* int i;
    b[0]=0;
    for (i = 1;i<n; i++)
        if(a[i]==a[i-1])
            b[i]=0;
        else
            b[i]=1;*/
    int *p;
    int *q = a2;
    *a2 = 0;
    for (p = a1; p < a1 + n; p++) {
        if(*p == *p - 1) {
            *a2 = *p;
        } else {
			*a2 = *p-1;
        }
    }
}
