//
//  sortwords.c
//  
//
//  Created by Derek Rodriguez on 12/1/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

// Compare function for qsort
int compare(const void *p, const void *q);

int read_line(char *str, int n);



/* Each word is no more than 20 characters long. Stop reading when user enters empty word (presses enter 
 * without entering a word. Store each word in a dynamically allocated string using an array of pointers to 
 * keep track of the strings. After all words read, sort the arrayl then use loop to print the words in 
 * sorted order.
 */
 

int main() {
    
    int i, j;
    int length = 0;
    int index = 0;
    char *words[LEN + 1];
    char str[LEN + 1];
    char temp[LEN + 1];
    
    for (;;) {
        
        if (index == LEN) {
            
            printf("No space left \n");
            break;
            
        }
        
        printf("Enter word: ");
        length = read_line(str, LEN);
        
        if (length == 0)
            break;
        
        words[index] = malloc(length);
        
        if (words[index] == NULL) {
            
            printf("No space left \n");
            break;
            
        }
        
        strcpy(words[index++], str);
        
        /* Use insertion sort */
        /*for (i = 0; i < index; i++) {
            for (j = i + 1; j < index; j++) {
            
            if (strcmp(words[i], words[j]) > 0) {
                
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            
            }
            
            }
        }*/
        
        /* Using qsort */
        qsort(words, index, sizeof(words[0]), compare);
    
    }

    
    
    printf("Sorted order: \n");
    
    for (i = 0; i < index; i++) {
        
        printf("%s\n", words[i]);
        free(words[i]);
        
    }
    
}

int compare(const void *p, const void *q) {
    
    return strcmp(*(char **)p, *(char **)q);
    
}

int read_line(char *str, int n) {
    
    int i = 0;
    int ch;
    
    while ((ch = getchar()) != '\n') {      // loop through characters entered
        
        if (i < n) {
            
            *str++= ch;         // store characters in string
            i++;                // increment i
            
        }
        
    }
    
    *str = '\0';                // store null character
    
    return i;
    
}
