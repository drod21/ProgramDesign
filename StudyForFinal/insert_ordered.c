//
//  insert_ordered.c
//  
//
//  Created by Derek Rodriguez on 11/28/16.
//
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *insert_into_ordered_list(struct node *list, struct node *new_node);

int main() {
    
    struct node *list = NULL;
    struct node *new;
    
    
    new = malloc(sizeof(struct node));
    
    if (new == NULL) {
        
        printf("error allocating memory. \n");
        return 0;
        
    }
    
    int i = 23;
    new->value = i;
    list = insert_into_ordered_list(list, new);


    for (; list != NULL; list = list->next) {
        
        printf("Value: %d \n", list->value);
        
    }
    
    
    return 0;
    
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node) {
    
    struct node *cur, *prev;
    
    for (prev = NULL, cur = list; cur != NULL && cur->value <= new_node->value; prev = cur, cur = cur->next);
    
    new_node->next = cur;
    
    if (prev == NULL) {
        return new_node;
    } else {
        
        prev->next = new_node;
    }
    return list;
}
