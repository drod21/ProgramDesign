//
//  recursion.c
//  
//
//  Created by Derek Rodriguez on 10/16/16.
//
//

#include <stdio.h>
int compute(int low, int high);

int main() {
    
    int low, high;
    
    low = 1;
    high = 5;
    int result;
    result = compute(low, high);
    
    printf("%d", result);
    
    
    return 0;
    
}

int compute(int low, int high) {
    
    if (low == high) return 0;
    else return 1 + compute(low+1, high-1);
    
}
