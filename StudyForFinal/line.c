//
//  line.c
//  
//
//  Created by Derek Rodriguez on 11/12/16.
//
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

struct word {
    
    char word[MAX_WORD_LEN + 1];
    struct word *next;
    
};

struct word *first_word = NULL;
struct word *cur_word = NULL;


void clear_line(void) {
    
    struct word *temp;
    
    while (first_word != NULL) {
        
        temp = first_word;
        first_word = first_word->next;
        free(temp);
        
    }
    
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
    
}

void add_word(const char *word) {
    
    if (num_words > 0)
        line_len++; /* count spaces after words */
    
    if (first_word == NULL) {
        first_word = malloc(sizeof(struct word));
    
        if (first_word != NULL) {
            
            strcpy(first_word->word, word);
            first_word->next = NULL;
            cur_word = first_word;
            
        } else {
            
            printf("Unable to allocate memory.\n");
            return;
            
        }
    
    } else {
        
        struct word *temp = malloc(sizeof(struct word));
        if (temp != NULL) {
            strcpy(temp->word, word);
            temp->next = NULL;
            cur_word->next = temp;
            cur_word = temp;
            
        } else {
            
            printf("Unable to allocate memory. \n");
            return;
            
        }
    }
    
    line_len += strlen(word);
    num_words++;
    
}

int space_remaining(void) {
    
    return MAX_LINE_LEN - line_len;
    
}

void write_line(void) {
    
    int extra_spaces, spaces_to_insert, i, j;
    
    extra_spaces = MAX_LINE_LEN - line_len;
    
    struct word *line_out = first_word;
    
    for (; line_out != NULL; line_out = line_out->next) {
        
        printf("%s", line_out->word);
        
        if (line_out->next != NULL) {
            
            putchar(' ');
            spaces_to_insert = extra_spaces / (num_words - 1);
            
            for (i = 0; i <spaces_to_insert; i++)
                putchar(' ');
            
            extra_spaces -= spaces_to_insert;
            num_words--;
            
        }
    }
    /* original
    for (i = 0; i < line_len; i++) {
        
        if (word->line[i] != ' ')
            putchar(word->line[i]);
        else {
            
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (j = 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
            
        }
        
    }
     */
    
    printf("\n");
    
}

void flush_line(void) {
    /* original
    if (line_len > 0)
        puts(line);
    */
    
    if (line_len > 0) {
        
        struct word *p = first_word;
        
        for (; p != NULL; p = p->next) {
            
            printf("%s ", p->word);
            
        }
        
        printf("\n");
        
    }
}
