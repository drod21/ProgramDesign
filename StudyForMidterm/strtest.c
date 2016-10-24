//
//  strtest.c
//  
//
//  Created by Derek Rodriguez on 10/16/16.
//
//

#include <stdio.h>

int f(char *s, char *t);


int main() {
    
    char str[] = "abcd";
    char str2[] = "bcd";
    int result;
    
    result = f(str, str2);
    
    printf("%d \n", result);
    
    return 0;
    
}

int f(char *s, char *t) {
    
    char *p1, *p2;
    
    for (p1 = s; *p1 != '\0'; p1++) {
        
        for (p2 = t; *p2 != '\0'; p2++) {
            
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
