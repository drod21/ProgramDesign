/* Derek Rodriguez
 * 2/5/2016
 * U37516832
 *
 * Stores two user inputs into arrays (length the user defined) and compares the two sets
 * for union and intersection
 */

#include <stdio.h>
#define SIZE 10

void selection_sort(int a[], int n);
int find_largest(int a[], int n);
int get_intersection(int a[], int b[], int intersection_array[], int elem_A, int elem_B);
int get_union(int a[], int b[], int union_array[], int elem_A, int elem_B);
void print_value(int a[], int n);

int main() {
    int set_A[SIZE], set_B[SIZE], union_array[SIZE], intersection_array[SIZE];
    int i = 0, elem_A, elem_B, num_elements;
    
    printf("Please enter the number of elements in the first set:\n");
    scanf("%d", &elem_A);
    
    printf("Please enter the numbers in the first set:\n"); /* Check user input, set that equal to array size for set_A, then sort set A small -> large */
    for (i = 0; i < elem_A; i++) {
        scanf("%d", &set_A[i]);
    }
    selection_sort(set_A, elem_A);
    
    printf("Please enter the number of elements in the second set:\n");
    scanf("%d", &elem_B);
    
    printf("Please enter the numbers in the second set:\n"); /* Check user input, set that equal to array size for set_B, then sort set B small -> large */
    for (i = 0; i < elem_B; i++) {
        scanf("%d", &set_B[i]);
    }
    selection_sort(set_B, elem_B);
    
    /* Print union */
    num_elements = get_union(set_A, set_B, union_array, elem_A, elem_B);
    printf("The union of the two sets is: {");
    print_value(union_array, num_elements);
    
    /* Print intersection */
    num_elements = get_intersection(set_A, set_B, intersection_array, elem_A, elem_B);
    if (num_elements != 0) {
    printf("The intersection of the two sets is: {");
    print_value(intersection_array, num_elements);
    } else {
        printf("There is no intersection for these two sets");
    }
    return 0;
    
}

/* Function to print the array sets */
void print_value(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" %d ", a[i]);
    }
    
    printf("}\n");
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

int get_union(int a[], int b[], int union_array[], int elem_A, int elem_B) {
    int i = 0, j = 0, k = 0;
    /* While loop comparison */
    while ((i < elem_A) && (j < elem_B)) { /* Checks for elem a & b */
        if (a[i] < b[j]) {
            union_array[k] = a[i]; /* adds i to union array if set a < set b */
            i++;
            k++;
        } else if (a[i] > b[j]) {
            union_array[k] = b[j]; /* if set a > set b, set b placed in union array */
            j++;
            k++;
        } else {
            union_array[k] = a[i]; /* if values are the same, set a into array */
            i++;
            j++;
            k++;
        }
    }
    if (i == elem_A) {
        while (j < elem_B) {
            union_array[k] = b[j];
            j++;
            k++;
        }
    } else {
        while (i < elem_A) {
            union_array[k] = a[i];
            i++;
            k++;
        }
    }
    return(k);
}

int get_intersection(int a[], int b[], int intersection_array[], int elem_A, int elem_B) {
    int i = 0, j = 0, k = 0;
    
    /* Detect intersection */
    while ((i < elem_A) && (j < elem_B)) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            intersection_array[k] = a[i];
            i++;
            j++;
            k++;
        }
    }
    return(k);
}