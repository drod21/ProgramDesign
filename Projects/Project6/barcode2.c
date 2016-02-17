/*****************************************************************
 * This program finds the edges of light and dark regions of the
 * input binary bit pattern.
 * ***************************************************************/

#include <stdio.h>

void* edge(int n, int *a1, int *a2);
int main(void)
{
	int input[8]={0};
    int output[8];
    int *p;

    int i;
	printf("please enter the 8 bit bar code");
    for(i = 0; i < 8; i++) {
		scanf("%1d", input);
    }

    p = edge(8, input, output);

	for(i = 0; i < 8; i++)
		printf("%d", *p);

	return 0;
}

void* edge(int n, int *a1, int *a2)
{
    
    
   /* int i;
    b[0]=0;
    for (i = 1;i<n; i++)
        if(a[i]==a[i-1])
            b[i]=0;
        else
            b[i]=1;*/
    int a[0];
   // a1 = &a[0];
    int *p;
    
    for (p = &a[1]; p < &a[n]; p++){
        if(*p == *a1){
            a2 = p;
        }else{
			a2 = a1;
        }
    }
    return a2;
}
