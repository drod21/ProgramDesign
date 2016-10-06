//
//  test_char_compare.c
//  
//
//  Created by Derek Rodriguez on 10/5/16.
//
// Prints the difference between array a and array b

#include <stdio.h>

int f(char *s, char *t);

int main() {
    
    char a[] = {"abcd"};
    char b[] = {"bcd"};
    
    int result;
    
    result = f(a,b);
    
    printf("Result : %d \n", result);
    
    
    return 0;
    
}

int f(char *s, char *t) {
    
    char *p1, *p2;
    
    for (p1 = s; *p1; p1++) {
        
        for (p2 = t; *p2; p2++) {
            
            if (*p1 == *p2) {
                
                break;
                
            }
            
        }
        
        if (*p2 == '\0') {
            
            break;
            
        }
        
    }
    
    return p1 - s;
    
}
