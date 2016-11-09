//
//  stack.c
//  
//
//  Created by Derek Rodriguez on 10/28/16.
//
//

#include "stack.h"

struct node *make_empty(struct node *top) {
   
    struct node *p;
    
    while (top != NULL) {
        
        p = top;
        top = top->next;
        free(p);
        
    }
    
    return NULL;
    
}

struct node *push(struct node *top, int i) {
    
    struct node *new_node;
    
    new_node = malloc(sizeof(struct node));
    
    if (new_node == NULL) {
        
        printf("Malloc failed");
        return top;
        
    }
    
    new_node->value = i;
    new_node->next = top;
    return new_node;
    
}

struct node *pop(struct node *top, int *i) {
    

    struct node *temp;
    
    if (top != NULL) {
        
        *i = top->value;
        temp = top->next;
        free(top);
        return temp;
        
    } else {
        
        printf("Stack is empty, cannot pop. \n");
        
    }
    
    return top;
    
    
}

struct node *roll(struct node *top) {
    
    struct node *temp = top->next;
    struct node *prev = temp->next;
    
    temp->next = prev->next;
    
    prev->next = top;
    
    top = prev;
    
    return top;
    
    
}

void print_stack(struct node *top) {
    struct node *p;
    if(top != NULL){
        for(p = top; p !=NULL; p=p->next)
            printf("%d\n", p->value);
        printf("\n");
    }
    else
        printf("stack is empty\n");
}
