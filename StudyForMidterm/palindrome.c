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
    
    char ch, palindrome[SIZE], *p, *q;
    
    p = palindrome;
    q = palindrome;
    
    printf("Please enter a phrase: \n");
    
    while ((ch = getchar()) != '\n') {
        
        if (ch >= 'A' && ch <= 'Z') {
            
            *(p++) = ch;
            
        } else if (ch >= 'a' && ch <= 'z') {
            
            *(p++) = ch - 32;
            
        }
    }
    
    
    while (q < p) {
        
        p--;
        if (*p != *q) {
            
            printf("Not a palindrome. \n");
            break;
            
        } else {
            
            printf("Palindrome.\n", palindrome);
            break;
            
        }
        
        q++;
        
    }
    
    
    /*
    while (j < count) {
        
        count--;
        
        if (palindrome[count] != palindrome[j]) {
            
            printf("%s is not a palindrome.\n", palindrome);
            
        }
        
        j++;
    
    }*/
    
    
    
    
    return 0;
}