//
//  ch8proj15-caesar.c
//  
//
//  Created by Derek Rodriguez on 8/31/16.
//
//

#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int main() {
    
    char message[SIZE], ch;
    int i = 0, count = 0, n;
    
    printf("Please enter a message to be encrypted: \n");
    
    while ((ch = getchar()) != '\n') {
        message[i++] = ch;
        count++;
    }
    
    printf("Enter shift amount: \n");
    scanf("%d", &n);
    
    
    printf("Encrypted message: \n");
    for (i = 0; i < count; i++) {
        
            if (message[i] >= 'A' && message[i] <= 'Z') {
                
                message[i] = ((message[i] - 'A') + n) % 26 + 'A';
                
            } else if (message[i] >= 'a' && message[i] <= 'z') {
                
                message[i] = ((message[i] - 'a') + n) % 26 + 'a';
                
            }
        
        printf("%c", message[i]);
        
    }
    
    printf("\n");
    
    printf("Decrypted: \n");
    
        
        for (i = 0; i < count; i++) {
            
            if (message[i] >= 'A' && message[i] <= 'Z') {
                
                message[i] = ((message[i] - 'A') + 26 - n) % 26 + 'A';
                
            } else if (message[i] >= 'a' && message[i] <= 'z') {
                
                message[i] = ((message[i] - 'a') + 26 - n) % 26 + 'a';
                
            }
            
            printf("%c", message[i]);
            
    }
    
    printf("\n");

}