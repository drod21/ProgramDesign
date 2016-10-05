//
//  sameorlonger.c
//  
//
//  Created by Derek Rodriguez on 10/5/16.
//
//

#include <stdio.h>
#include <string.h>
#define SIZE 1000

int read_line(char *str, int n);


int main() {
    
    char a[SIZE + 1], b[SIZE + 1];
    int len1, len2;
    
    printf("Enter the first sentence: \n");
    read_line(a, SIZE);
    printf("Enter the second sentence: \n");
    read_line(b, SIZE);
    
    len1 = strlen(a);
    len2 = strlen(b);
    
    if (len1 > len2) {
        
        printf("First sentence is longer. \n");
        
    } else if (len1 < len2) {
        
        printf("Second sentence is longer. \n");
        
    } else if (len1 == len2) {
        
        printf("Sentence length is the same. \n");
        
    }
    
    
}





int read_line(char *str, int n) {
    
    int ch; int i = 0;
    
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            *str++= ch;
            i++;
        }
    
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}
