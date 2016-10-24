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
    int i, num_chars, pos;
    
    printf("Please enter a sentence: \n");
    num_chars = read_line(input_words, STR_LEN + 1);
    // Strtok to tokenize string
    pch = strtok(input_words, " ,.!-");
    
    while (pch != NULL) {
        // Checks is word is present already
        pos = isPresent(pch, words, count);
        
        if (pos == -1) {
            
            strcpy(words[count], pch);
            freq[count] = 1;
            count++;
            
        } else {
            // If word is present, increment word count
            freq[pos]++;
        
        }
        pch = strtok(NULL, " ,.!");
        
    }
    
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

