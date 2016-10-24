//
//  line_length.c
//  
//
//  Created by Derek Rodriguez on 10/18/16.
//
//

#include <stdio.h>

int line_length(const char *filename, int n);

int main() {
    
    
    
    
    return 0;
    
}

int line_length(const char *filename, int n) {
    
    FILE *fp;
    int count = 0, line = 1;
    int ch;
    
    if ((fp == fopen(filename, "r")) != NULL) {
        
        while (count <= n && (ch = fgetc(fp)) != EOF) {
            
            if (ch == '\n') {
                
                count++;
                
            } else if (num == n) {
            
                line++;
                
            }
            
        }
        
        fclose(fp);
        
    }
    
    return length;
    
}
