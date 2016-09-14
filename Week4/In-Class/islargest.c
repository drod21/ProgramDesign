//
//  islargest.c
//  
//
//  Created by Derek Rodriguez on 9/14/16.
//
//

#include <stdio.h>

int islargest(int a[], int n);

int main() {
    
    int a[10] = {23, 42, 44, 2, 32, 22, 94, 92, 84, 48};
    int largest;
    
    largest = islargest(a, 10);
    
    printf("The index of 94 is %d.\n", largest);
    
    return 0;

}


int islargest(int a[], int n) {
    
    int i, largest = a[0], index = 0;
    
    for (i = 0; i < n; i++) {
        
        if (a[i] > largest ) {
            
            largest = a[i];
            
        }
        
        if (a[i] == largest) {
            index = i;
        }
        
    }
    
    return index;
    
}