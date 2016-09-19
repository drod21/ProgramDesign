#include <stdio.h>

int find_largest(int a[], int n);
void selection_sort(int a[], int n);

int main() {

int a[10];
printf("Enter %d numbers to be sorted: \n", 10);

	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}



	printf("In sorted order: \n");

	selection_sort(a, 10);

	for (int i = 0; i < 10; i++) {
		printf(" %d,", a[i]);
	}
	printf("\n");
return 0;
}
int find_largest(int a[], int n) {
int i, largest = 0;

for (i = 1; i < n; i++) {
	if (a[i] > a[largest]) 
	largest = i;
}
return largest;
}

void selection_sort(int a[], int n) {
	int temp, largest = 0;
	
//stopping condition
	if (n == 1) return;
	
	largest = find_largest(a, n);

	if (largest < n - 1) {

	temp = a[n - 1];
	a[n - 1] = a[largest];
	a[largest] = temp;
	}
selection_sort(a, n - 1);
}
