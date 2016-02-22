#include <stdio.h>

int *find_smallest(int arr[], int n);

int main()
{
	int a[7] = {3, 42, 52, 91, 2, 13, 49};
	int *min;
	min = find_smallest(a, 7);
	printf("the smallest value is: %d", *min);
	return 0;

}

int *find_smallest(int arr[], int n)
{
	int i;
	int *p_min; 
	p_min = &arr[0];

	for(i = 1; i < n; i++)
	{
		if(arr[i]< *p_min)
			p_min = &arr[i]; 
	}
	return p_min;

}
