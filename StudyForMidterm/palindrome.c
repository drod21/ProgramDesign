//
//  palindrome.c
//  
// Read a message and check if it's a palindrome
//  Created by Derek Rodriguez on 9/12/16.
//
//

#include <stdio.h>
#include <string.h>

#define SIZE 50
#define TRUE 1
#define FALSE 0

int main() {
    
    char ch, palindrome[SIZE];
    
    int i, count = 0, flag = FALSE, length;
    
    while ((ch = getchar()) != '\n') {
        
        palindrome[count++] = ch;
        
    }
    length = strlen(palindrome);
    
    for (i = 0; i < length, i++) {
        
        
        
    }
    
    
    
    return 0;
}