//
//  strtoktest.c
//  
//
//  Created by Derek Rodriguez on 10/19/16.
//
//

#include <stdio.h>
#include <string.h>

int read_line(char *s, int n);

int main() {
    
    char number[20];
    char *pch;
    
    int count = 0;
    
    read_line(number, 20);
    pch = number;
    
    pch = strtok(number, "(),.!-");
    printf("Area code: %s\n", pch);
    
    while (pch != NULL) {
        pch = strtok(NULL, "(),.!-");
        count++;
        if (count == 1) {
            
            printf("First 3 digits: %s\n", pch);
        } else if (count == 2) {
            printf("Last 4 digits: %s\n", pch);
        }
    }
    
    
    
    return 0;
    
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
