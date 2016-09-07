//
//  touppercase.c
//  
//
//  Created by Derek Rodriguez on 9/7/16.
//
//

#include <stdio.h>
#include <ctype.h>


int main(void) {
    
    char ch, message[20];
    
    int i = 0, count = 0;
    
    printf("Enter a message\n");
    
    while ((ch = getchar()) != '\n') {
        
        message[i++] = ch;
        count++;
        
    }

    
    
    /* Exercise 2
     for (i = 0; i < count; i++) {
        
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + 'A');
        }
        
    }*/
    
    
    /* Exercise 3 */
    for (i = 0; i < count; i++) {
        if (isalpha(message[i]) && islower(message[i])) {
            message[i] = ((message[i] - 'a') + 'A');
        }
        
    }
    
    printf ("%s\n", message);
    
    
    
    return 0;
    
}