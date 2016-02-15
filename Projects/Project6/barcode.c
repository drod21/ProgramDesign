/*****************************************************************
 * This program finds the edges of light and dark regions of the
 * input binary bit pattern.
 * ***************************************************************/

#include <stdio.h>

void edge(int n, int a[], int b[]);
int main(void)
{
	int input[8]={0};
	int output[8];

	int i;
	printf("please enter the 8 bit bar code");
	for(i=0;i<8;i++)
		scanf("%1d", &input[i]);

	edge(8, input, output);

	for(i=0;i<8;i++)
		printf("%d", output[i]);

	return 0;
}

void edge(int n, int a[], int b[])
{


	int i;
	b[0]=0;
	for (i = 1;i<n; i++)
		if(a[i]==a[i-1])
			b[i]=0;
		else
			b[i]=1;
}
