//
//  sets.c
//  
//
//  Created by Derek Rodriguez on 2/1/16.
//
//

#include <stdio.h>
#define SIZE 10

void get_val_A(int arr[], int m);
void get_val_B(int arr[], int n);
void print_value(int arr[], int n);
void function_sort(int arr[]);
int find_inters(int set_A[], int set_B[], int inters_arr[]);
int find_union(int set_A[], int set_B[], int union_arr[]);

int main() {
    
    int set_A[SIZE], set_B[SIZE], inters_arr[SIZE], union_arr[SIZE * 2];
    int num_elements, elem_A, elem_B;
    
    printf("Please enter the number of elements in the first set:\n");
   /* printf("Enter the number of elements in set A:\n");
    scanf("%d", &elem_A);
    for (i = 0; i < elem_A; i++) {
        j = i + 1;
        printf("Enter number in set A:\n");
        scanf("%d", &set_A[i]);
    }*/
    get_val_A(set_A, elem_A);
    
    printf("Please enter the number of elements in the second set:\n");
    /*printf("Enter the number of elements in set B:\n");
    scanf("%d", &elem_B);
    for (i = 0; i < elem_B; i++) {
        j = i + 1;
        printf("Enter number in set B:\n");
        scanf("%d", &set_B[i]);
    }*/
    get_val_B(set_B, elem_B);
    
    function_sort(set_A);
    printf("Sorted elements of set A: ");
    print_value(set_A, elem_A);
    
    function_sort(set_B);
    printf("Sorted elements of set B: ");
    print_value(set_B, elem_B);
    
    num_elements = find_inters(set_A, set_B, inters_arr);
    printf("The intersection of the two sets is: ");
    print_value(inters_arr, num_elements);
    
    num_elements = find_union(set_A, set_B, union_arr);
    printf("The union of the two sets is: ");
    print_value(union_arr, num_elements);
    
}

void get_val_A(int arr[], int m) {
    int i, j;
    printf("Enter the number of elements in set A:\n");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        j = i + 1;
        printf("Enter number in set A:\n");
        scanf("%d", &arr[i]);
    }
}

void get_val_B(int arr[], int n) {
    int i, j;
    printf("Enter the number of elements in set B:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        j = i + 1;
        printf("Enter number in set B:\n");
        scanf("%d", &arr[i]);
    }
}

void print_value(int arr[], int n) {
    int i;
    printf("{");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

void function_sort(int arr[]) {
    int i, j, temp, swapping;
    
    for (i = 1; i < SIZE; i++) {
        swapping = 0;
        for (j = 0; j < SIZE - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapping = 1;
            }
        }
        if (swapping == 0) {
            break;
        }
    }
}

int find_inters(int set_A[], int set_B[], int inters_arr[]) {
    int i = 0, j = 0, k = 0;
    while ((i < SIZE) && (j < SIZE)) {
        if (set_A[i] < set_B[j]) {
            i++;
        } else if (set_A[i] > set_B[j]) {
            j++;
        } else {
            inters_arr[k] = set_A[i];
            i++;
            j++;
            k++;
        }
    }
    return(k);
}


int find_union(int set_A[], int set_B[], int union_arr[]) {
    int i = 0, j = 0, k = 0;
    while ((i < SIZE) && (j < SIZE)) {
        if (set_A[i] < set_B[j]) {
            union_arr[k] = set_A[i];
            i++;
            k++;
        } else if (set_A[i] > set_B[j]) {
            union_arr[k] = set_B[j];
            j++;
            k++;
        } else {
            union_arr[k] = set_A[i];
            i++;
            j++;
            k++;
        }
    }
    if (i == SIZE) {
        while (j < SIZE) {
            union_arr[k] = set_B[j];
            j++;
            k++;
        }
    }
    else {
        while (i < SIZE) {
            union_arr[k] = set_A[i];
            i++;
            k++;
        }
    }
    return(k);
}

