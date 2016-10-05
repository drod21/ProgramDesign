//
//  count_characters.c
//  
//
//  Created by Derek Rodriguez on 10/3/16.
//
//

#include <stdio.h>

int count_character(char *s);
#define N 20
int main() {
    
    char msg[N] = "Hi there";
    int count_chars = count_character(msg);
    
    printf("There are %d characters in string: %s. \n", count_chars, msg);
    
}

int count_character(char *s) {
    
    int count = 0;
    
    for (;  *s != '\0'; s++) {
        
        count++;
        
    }
    
    return count;
    
}
