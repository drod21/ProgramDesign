#include <stdio.h>
#include <stdlib.h>

int int_compare(const void* p, const void* q);

int main() {
	int n, i;
	int *a;

	printf("Enter the length of the array: ");
	scanf("%d", &n);
	
	a = malloc(n*sizeof(int));

	for(i = 0; i < n; i++)
	{
		printf("Enter a number: ");
		scanf("%d", &a[i]);
	}

	qsort(a, n, sizeof(int), int_compare);
	
	printf("In sorted order:\n");

        for(i = 0; i < n; i++)
                printf("%d\t", a[i]);

        printf("\n");
	
	return 0;
}

int int_compare(const void* p, const void* q) {
    
    const int *p1 = p;
    const int *q1 = q;
    
   /* if (*p1 < *q1)
        return -1;
    else if (*p1 == *q1)
        return 0;
    else
        return 1;*/

    return *p1 - *q1;
    
}
