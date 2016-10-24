//
//  selection_recursive.c
//  
//
//  Created by Derek Rodriguez on 10/15/16.
//
//

#include <stdio.h>

void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main() {
    
    int a[] = {3, 1, 2, 21, 12, 63, 42, 31, 29, 19};
    
    int i;
    
    printf("Original array: \n");
    for (i = 0; i < 10; i++) {
        
        printf("%d ", a[i]);
    
    }
    
    printf("\n");
    
    selection_sort(a, 10);
    
    printf("In sorted order: \n");
    
    for (i = 0; i < 10; i++) {
        
        printf("%d ", a[i]);
        
    }
    
    printf("\n");
    
}

int find_largest(int a[], int n) {
    
    int max = 0;
    int i;
    
    for (i = 0; i < n; i++) {
        
        if (a[i] > a[max]) {
            
            max = i;
            
        }
        
    }
    
    return max;
    
}

void selection_sort(int a[], int n) {
    
    int largest, temp;
    
    if (n == 1) {
        
        return;
        
    }
    
    largest = find_largest(a, n);
    
    if (largest < n - 1) {
        
        temp = a[n - 1];
        
        a[n - 1] = a[largest];
        
        a[largest] = temp;
        
    }
    
    selection_sort(a, n -1);
    
}
