//
//  reversewords.c
//  Reads a message, then prints reversal
//
//  Created by Derek Rodriguez on 9/12/16.
//
//

#include <stdio.h>
#define SIZE 50

int main() {
    
    char ch;
    char message[SIZE], *p;
   // int count = 0;
    
    printf("Please enter a sentence to be reversed: \n");
    
    /* Pointers as Array Names */
    p = message;
    
    while ((ch = getchar()) != '\n') {
        
        *(p++) = ch;
        
        
    }
    
    
    for (p--; p >= message; p--) {
        
        printf("%c", *p);
        
    }

    /* With pointers */
    /*
    while ((ch = getchar()) != '\n') {
        
        message[count++] = ch;
        
        
    }
    
    
    
    for (p = message + count - 1; p >= message; p--) {
        
        printf("%c", *p);
        
    }*/
    /*
    for (i = count - 1; i >= 0; i--) {
        
        printf("%c", message[i]);
        
    }
    */
    printf("\n");
    
    return 0;
}