//
//  fibonnaci.c
//  
//
//  Created by Derek Rodriguez on 9/14/16.
//
//

#include <stdio.h>

int fibonnaci(int num);

int main() {
    
    
    for (int i = 1; i < 10; i++) {
        printf("%d, ", fibonnaci(i));
    }
    
    
    
    return 0;
    
}


int fibonnaci(int num) {
    
    if (num == 1 || num == 2) {
        
        return 1;
        
    } else {
        
        return fibonnaci(num - 1) + fibonnaci(num - 2);
        
    }
    
}