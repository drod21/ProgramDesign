/* Derek Rodriguez
 * 2/5/2016
 * U37516832
 *
 * Stores two user inputs into arrays (length also defined by user) and compares the two sets
 * for logical union and intersection
 */

#include <stdio.h>
#define SIZE 10

void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main(void) {
    int set_A[SIZE], set_B[SIZE], union_array[SIZE], intersection_array[SIZE];
    int i = 0, f = 0, k = 0, j = 0, elem_A, elem_B;
    
    printf("Please enter the number of elements in the first set:\n");
    scanf("%d", &elem_A);
    printf("Please enter the numbers in the first set:\n"); /* Check user input, set that equal to array size for set_A */
    for (i = 0; i < elem_A; i++) {
        scanf("%d", &set_A[i]);
    }
    
    printf("Please enter the number of elements in the second set:\n");
    scanf("%d", &elem_B);
    printf("Please enter the numbers in the second set:\n"); /* Check user input, set that equal to array size for set_B */
    for (i = 0; i < elem_B; i++) {
        scanf("%d", &set_B[i]);
    }
    
    /* Union detection code */
    for (i = 0; i < elem_A; i++) {
        if (i < elem_A) {
            union_array[k] = set_A[i]; /* Store set_A into union array if less than user input length */
            k++;
        }
    }
    
    /* Comparison check for set B, along with variable f storing true/false, passing integers to union array */
    for (i = 0; i < elem_B; i++) {
        f = 0;
        for (j = 0; j < elem_B; j++) {
            if (set_B[i] == union_array[j]) {
                f = 1;
                break;
            }
        }
        
        /* Store the remaining variables from set B and increment counter */
        if (f == 0) {
            if (i < elem_B) {
                union_array[k] = set_B[i];
                k++;
            }
        }
    }
    
    selection_sort(union_array, k); /* Sort the numbers in the union array */
    printf("The union of the two sets is: {"); /* Print pattern for union */
    for (i = 0; i < k; i++) {
        printf(" %d", union_array[i]);
    }
    printf(" }\n");
    
    /* Detect intersection */
    k = 0;
    for (j = 0; j < elem_A; j++) { /* For loop to compare element A */
        for (i = 0; i < elem_B; i++) { /* Nested for loop for element B */
            if (set_B[i] == set_A[j]) { /* If set B == set A, intersection */
                break;
            }
        }
        
        if (i != elem_B) {
            intersection_array[k] = set_B[i]; /* If i isn't in elem_b, add set_B[i] into intersection array, increase counter */
            k++;
        }
    }
    
    /* Only sort the intersection array if there are values present
     * Otherwise, return empty set
     */
    if (intersection_array[k] != 0) {
    selection_sort(intersection_array, k);
    }
    printf("The intersection of the two sets is: { ");
    for (i = 0; i < k; i++) {
        printf(" %d", intersection_array[i]);
    }
    printf(" }\n");
        
    return 0;
    
}

/* Sort the integers by smallest -> largest */

void selection_sort(int a[], int n) {
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
/* Find the largest integer in the index */
int find_largest(int a[], int n) {
    int largest_index = 0;
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > a[largest_index])
            largest_index = i;
    return largest_index;
}
