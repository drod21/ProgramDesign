//
//  smallest.c
//  
//
//  Created by Derek Rodriguez on 10/15/16.
//
//

#include <stdio.h>

int *find_smallest(int a[], int n);

int main() {
    
    int a[7] = {3, 42, 52, 91, 2, 13, 49};
    
    int *min;
    
    min = find_smallest(a, 7);
    
    printf("The smallest value is: %d\n", *min);
    
    return 0;
    
}

int *find_smallest(int a[], int n) {
    
    int *p, *min;
    
    min = a + 1;
    
    for (p = a; p < a + n; p++) {
        
        if (*p < *min) {
            
            *min = *p;
            
        }
        
    }
    
    return min;
    
}
