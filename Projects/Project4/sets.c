//
//  sets.c
//
//
//  Created by Derek Rodriguez on 2/1/16.
//
//

#include <stdio.h>
#define SIZE 10

void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main(void) {
    
    int set_A[SIZE], set_B[SIZE], union_array[SIZE], intersection_array[SIZE];
    int i = 0, f = 0, k = 0, j = 0, elem_A, elem_B;
    
    printf("Please enter the number of elements in the first set:\n");
    scanf("%d", &elem_A);
    printf("Please enter the numbers in the first set:\n");
    for (i = 0; i < elem_A; i++) {
        scanf("%d", &set_A[i]);
    }
    
    printf("Please enter the number of elements in the second set:\n");
    scanf("%d", &elem_B);
    
    printf("Please enter the numbers in the second set:\n");
    for (i = 0; i < elem_B; i++) {
        scanf("%d", &set_B[i]);
    }
    
   //union
    
    for (i = 0; i < elem_B; i++) {
        union_array[k] = set_A[i];
        k++;
    }
    
    for (i = 0; i < elem_A; i++) {
        f = 0;
        for (j = 0; j < elem_B; j++) {
            if (set_B[i] == union_array[j]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            if (i < elem_B) {
            union_array[k] = set_B[i];
            k++;
            }
        }
    }
    
    selection_sort(union_array, k);
    printf("The union of the two sets is: { ");
    for (i = 0; i < k; i++) {
        printf(" %d", union_array[i]);
    }
    printf(" }\n");
    
    // intersection
    
    for (j = 0; j < elem_A; j++) {
        for (i = 0; i < elem_B; i++) {
            if (set_A[i] < set_B[j])
                intersection_array[i] = set_A[i];
        }
        if (i != elem_B) {
            intersection_array[k] = set_B[i];
            printf("%d",intersection_array[i]);
            k++;
        }
    }
    
    selection_sort(intersection_array, k);
    printf("The intersection of the two sets is: { ");
    for (i = 0; i < k; i++) {
        printf(" %d", intersection_array[i]);
    }
    printf(" }\n");
    return 0;

}

void selection_sort(int a[], int n)
{
    int largest = 0, temp;
    
    if (n == 1)
        return;
    
    
    largest = find_largest(a, n);
    
    if (largest < n - 1) {
        temp = a[n-1];
        a[n-1] = a[largest];
        a[largest] = temp;
    }
    
    selection_sort(a, n - 1);
}

int find_largest(int a[], int n)
{
    int largest_index = 0;
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > a[largest_index])
            largest_index = i;
    return largest_index;
}
