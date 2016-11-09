//
//  charswordslines.c
//  
//
//  Created by Derek Rodriguez on 10/24/16.
//
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Invalid # of arguments. \n");
        return 0;
    }
    
    FILE *fp;
    fp = fopen(argv[1], "r");
    
    int ch, count = 0, word = 0;
    
    if (fp == NULL) {
        
        printf("File DNE \n");
        return 0;
        
    } else {
        
        while ((ch = fgetc(fp)) != EOF) {
            
            //count++; // Number of characters
            
             //Number of words
            if (ch == ' ') {
               
                word = 0;
                
                
            } else if (!word) {
                
                word = 1;
                count++;
                
            }
            
            
            /* Number of lines*/
             //if (ch == '\n')
             //count++;
             
            
        }
        //printf("Number of characters: %d \n", count);
        printf("Number of words: %d \n", count);
        //printf("Number of lines: %d \n", count);
        fclose(fp);
    }
    return 0;
    
}
