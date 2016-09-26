/* selection_sort.c, project 5, Program Design
 * 
 * Derek Rodriguez
 * U37516832
 * 9/25/16
 *
 */

#include <stdio.h>
#define N 10

void selection_sort(int a[], int n);
int *find_largest(int *a, int n);
void swap(int *p, int *q);

int main(void) {
  int i;
  int a[N];

  printf("Enter %d numbers to be sorted: \n", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  selection_sort(a, N);

  printf("In sorted order:");
  for (i = 0; i < N; i++)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}

void selection_sort(int a[], int n) {

    int *p = a;

  if (n == 1)
    return;
    
    // Put the largest element in a in the last memory slot of p
    swap(p + n - 1, find_largest(a, n));
    
  selection_sort(a, n - 1);
    
}

int *find_largest(int *a, int n) {
    
    int *p;
    int *largest;
    
    largest = a;
    
    // Find the largest element in a through pointer arithmetic
    for (p = a + 1; p < a + n; p++) {
        
        if (*p > *largest) {
            
            largest = p;
            
        }
        
    }
    
        return largest;
    
}

void swap(int *p, int *q) {
    
    /* Swaps first and last value. */
    int temp = *p;
    *p = *q;
    *q = temp;
    
}
