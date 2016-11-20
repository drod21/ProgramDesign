/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

struct node {

    char word[MAX_WORD_LEN+1];
    struct node *next;
    
};

struct node *line = NULL;
struct node *cur = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void) {
    
    struct node *p;
    
    while (line != NULL) {
        
        p = line;
        line = line->next;
        free(line);
        
   }
    
    line_len = 0;
  
    num_words = 0;
    
}
/*old
void add_word(const char *word)
{
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}
*/

void add_word(const char *word) {
    
    struct node *new_node;
    
    new_node = malloc(sizeof(struct node));
    
    if (new_node == NULL) {
        
        return;
        
    }
    if (num_words > 0) {
        new_node->word[line_len + 1] = '\0';
        line_len++;
    }
    if (line == NULL) {
        
        line = malloc(sizeof(struct node));
        if (line != NULL) {
            
            strcat(line->word, word);
            line->next = NULL;
            cur = line;
            
        }
        
    } else {
        
        if (new_node != NULL) {
            
            strcat(new_node->word, word);
            new_node->next = NULL;
            cur->next = new_node;
            cur = new_node;
            
        }
        
    }
    
    line_len += strlen(word);
    num_words++;
    
}
int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i;
    
    extra_spaces = MAX_LINE_LEN - line_len;
    
    struct node *line_out = line;
    
    for (; line_out != NULL; line_out = line_out->next) {
        
            printf("%s", line_out->word);
        
        if (line_out->next != NULL) {
            
            putchar(' ');
            spaces_to_insert = extra_spaces / (num_words - 1);
            
            for (i = 0; i < spaces_to_insert; i++)
                putchar(' ');
            
            extra_spaces -= spaces_to_insert;
            num_words--;
            
        }
    }
  printf("\n");
}

void flush_line(void)
{
    struct node *p = line;
    
    
    if (line_len > 0) {
        
      for (; p != NULL; p = p->next) {
          
          printf("%s ", p->word);
          
      }
        printf("\n");
    }
}
