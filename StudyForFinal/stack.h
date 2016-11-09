//
//  stack.h
//  
//
//  Created by Derek Rodriguez on 10/28/16.
//
//

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

struct node *push(struct node *top, int i);
struct node *make_empty(struct node *top);
struct node *pop(struct node *top, int *i);
struct node *roll(struct node *top);
void print_stack(struct node *top);

#endif
/* stack_h */
