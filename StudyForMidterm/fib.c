//
//  fib.c
//  
//
//  Created by Derek Rodriguez on 10/14/16.
//
//

#include <stdio.h>


int fib(int n);

int main() {
    
    for (int i = 1; i < 10; i++) {
        
        printf("%d \n", fib(i));
    
    }
    
    return 0;
    
}

int fib(int n) {
    
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
    
}
