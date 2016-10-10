//
//  caesar.c
//  
//
//  Created by Derek Rodriguez on 10/9/16.
//
//

#include <stdio.h>
#define N 1000

void caesar(char *s, int n);
int read_line(char *s, int n);


int main(void) {
    
    
    int shift;
    
    char msg[N + 1];
    
    
    printf("Please enter the message to be encrypted: \n");
    read_line(msg, N);
    
    
    printf("Please enter the number of shift to take place. \n");
    scanf("%d", &shift);
    
    caesar(msg, shift);
    
    
    
    
    printf("Encrypted message: \n");
    
    printf("%s \n", msg);
    
    
    return 0;
    
}


void caesar(char *s, int n) {
    
    char *p;
    
    for (p = s; *p != '\0'; p++) {
        
        if (*p >= 'A' && *p <= 'Z') {
            
            *p = ((*p - 'A') + n) % 26 + 'A';
            
        } else if (*p >= 'a' && *p <= 'z') {
            
            *p = ((*p - 'a') + n) % 26 + 'a';
        }
        
    }
    
    
}


int read_line(char *s, int n) {
    
    int i = 0;
    int ch;
    
    while ((ch = getchar()) != '\n') {
        
        if (i < n) {
            
            *s++ = ch;
            i++;
            
        }
        
    }
    *s = '\0';
    
    return i;
    
}
