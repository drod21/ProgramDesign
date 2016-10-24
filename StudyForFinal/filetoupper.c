//
//  filetoupper.c
//  
//
//  Created by Derek Rodriguez on 10/24/16.
//
//

#include <stdio.h>
#define LEN 1000

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        
        printf("Cannot open file. \n");
        return 0;
        
    }
    
    FILE *fp;
    char ch, str[LEN + 1];
    int i = 0, count = 0;
    
    fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
        
        printf("File does not exit. \n");
        return 0;
        
    } else {
        
        while ((ch = getc(fp)) != EOF) {
            
            str[i++] = ch;
            count++;
            
        }
        
        for (i = 0; i < count; i++) {
            
            if (str[i] >= 'a' && str[i] <= 'z') {
                
                str[i] = ((str[i] - 'a') + 'A');
                
            }
            
        }
        
        fputs(str, stdout);
        fclose(fp);
        
    }
        
        return 0;
    
}
