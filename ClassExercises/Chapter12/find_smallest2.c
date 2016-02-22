#include <stdio.h>

int* find_smallest(int arr[], int n);

int main()
{
	int a[7] = {3, 42, 52, 91, 2, 13, 49};
	int* min;
	min = find_smallest(a, 7);
	printf("the smallest value is: %d", *min);
	return 0;

}

int* find_smallest(int arr[], int n)
{
//	int i;
	int *min; 
	min = &arr[0];
	int *p;

//	for(i = 1; i < n; i++)
	for(p = &arr[1]; p < &arr[n]; p++)
	{
//		if(arr[i]< min)

//			min = arr[i]; 
		if(*p < *min)

			min = p;
	}
	return min;

}
