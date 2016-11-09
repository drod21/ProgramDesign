//
//  create_array.c
//  
//
//  Created by Derek Rodriguez on 10/27/16.
//
//

#include <stdio.h>
#include <stdlib.h>


int *create_array(int n, int initial_value);

int main() {
    
    int n, init;
    
    n = 10;
    init = 5;
    
    int *result;
    
    printf("Creating array of size %d with values %d.. \n", n, init);
    
    result = create_array(n, init);
    
    printf("Resulting array: \n");
    
    for (int i = 0; i < n; i++) {
        
        printf("%d ", result[i]);
        
    }
    
    printf("\n");
    
    return 0;
    
}

int *create_array(int n, int initial_value) {
    
    int *a;
    int i;
    
    a = (int *) malloc(n * sizeof(int));
    
    if (a == NULL) {
        
        printf("Malloc failed. \n");
        return NULL;
        
    } else {
        
        for (i = 0; i < n; i++) {
            
            a[i] = initial_value;
            
        }
        
    }
    
    return a;
    
}
