//
//  isletter.c
//  
//
//  Created by Derek Rodriguez on 9/14/16.
//
//

#include <stdio.h>
#include <ctype.h>

int isletter(char c);

int main() {
    
    char ch = '/';
    int result;
    
    result = isletter(ch);
    
    printf("%d\n", result);
    return 0;
}

int isletter(char c) {
    
    if (isalpha(c)) {
        
        return 1;
        
    } else {
        return 0;
    }
    
}