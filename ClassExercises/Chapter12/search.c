#include <stdio.h>

#define N 10

int search(int *a, int n, int key);

int main()
{
	int arr[N] = {3, 12, 31, 42, 52,12, 49, 53,64,96};
	int value;
	printf("enter the value: ");
	scanf("%d", &value);
	int result = search(arr, N, value);
	if(result)
		printf("found\n"); 
	else
		printf("not found\n"); 
	
	return 0;
}

int search(int *a, int n, int key)
{
	int *p;

	for(p = a; p < a+n; p++)
	{
		if(*p == key)
			return 	1;

	}
	
	 return 0;
}
