//
//  find_smallest.c
//  
//
//  Created by Derek Rodriguez on 9/5/16.
//
//

#include <stdio.h>

int *find_smallest(int a[], int n);

int main() {
    
    int a[7] = {3, 42, 52, 91, 2, 13, 49};
    int *min;
    
    min = find_smallest(a, 7);
    
    printf("Smallest value is: %d\n", *min);
    
    return 0;
    
}

int *find_smallest(int a[], int n) {
    
    int i;
    int *min = &a[0]; //set min pointer = to first element of array a
    for (i = 1; i < n; i++) {
        if (a[i] < *min) { //check to see if a at i-th position is < *min at 1st position
            min = &a[i]; //set address of min = address of a[i] if a[i] < *min
        }
        
    }
    return min; //return pointer to min
}