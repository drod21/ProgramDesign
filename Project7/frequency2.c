//
//  frequency2.c
//  
//
//  Created by Derek Rodriguez on 10/19/16.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 1000
#define WORD_LEN 50

int read_line(char *str, int n);
int isPresent(char *word, char words[][WORD_LEN + 1], int count);

int main() {
    
    char input_words[STR_LEN + 1];
    char words[STR_LEN][WORD_LEN + 1];
    char *pch;
    
    int freq[100] = {0};
    int count = 0;
    int i = 0, chars_in_string, pos = 0;
    int flag = 0;
    
    printf("Please enter a sentence: \n");
    chars_in_string = read_line(input_words, STR_LEN + 1);
    // Strtok to tokenize string
    pch = strtok(input_words, " ,.!-");
    
    while (pch != NULL) {
        for (i = 0; i < chars_in_string; i++) {
       
            if (strcmp(words[i], pch) == 0) {
            
                flag = 1;
                break;
    
            } else {
            
                flag = 0;
        
            }
        }
        
        if (flag == 1) {
            freq[i]++;
            
        } else if (flag == 0) {
            
            strcpy(words[count], pch);
            freq[count] = 1;
            count++;
            
        }
        
        pch = strtok(NULL, " ,.!");
        
    }
    printf("%d\n", count);
    
    printf("The frequency is: \n");
    
    for (i = 0; i < count; i++) {
        printf("%s\t%d\n", words[i], freq[i]);
    }
    
    return 0;
    
}

int isPresent(char word[], char words[][WORD_LEN + 1], int count) {
    
    int i;
    
    for (i = 0; i < count; i++) {
    // If word is present, return position
        if (strcmp(word, words[i]) == 0) {
            
            return i;
            
        }
        
    }
    
    return -1;
    
}

/*read_line skips the white space(s) before beginning to store input characters*/
int read_line(char *str, int n) {
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n') {
       
        if (i < n) {
            *str++= ch;
            i++;
        }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}

