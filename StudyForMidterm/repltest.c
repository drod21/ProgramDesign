//
//  repltest.c
//  
//
//  Created by Derek Rodriguez on 10/16/16.
//
//

#include <stdio.h>

void repl(char *str);

int main() {
    
    char str[] = "Hello xom, good xorning.";
    
    printf("Before replacing x's: %s \n", str);
    
    repl(str);
    
    printf("After replacing: \n %s \n", str);
    
    
    return 0;
    
}

void repl(char *str) {
    
    for (; *str != '\0'; str++) {
        
        if (*str == 'x') {
            
            *str = 'm';
            
        }
        
    }
    
    
}
