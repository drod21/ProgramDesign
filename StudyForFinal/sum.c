//
//  sum.c
//  
//
//  Created by Derek Rodriguez on 11/28/16.
//
//

#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int g(int x);

int main() {
    
    int a = 1;
    int b = 10;
    int result;
    
  
    result = sum(g, a, b);
    
    printf("%d\n", result);

}

int sum(int (*f)(int), int start, int end) {
    
    int i, result = 0;
    
    for (i = start; i <= end; i++) {
        
        result += f(i);
        
    }
    
    return result;
}

int g(int x) {
    
    return x;
    
}
