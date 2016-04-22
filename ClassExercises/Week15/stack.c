#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node* push(struct node* top, int i) {
   struct node *new_node;
    
   new_node = malloc(sizeof(struct node));
    
   if(new_node == NULL) {
	printf("malloc failed");
        return top;
   }
   
   new_node->value = i;
   new_node->next = top;
   return new_node;

}

struct node *make_empty(struct node *top) {
    struct node *p;
    while (top != NULL) {
        p = top;
        top = top->next;
        free (p);
    }
    return NULL;
}

struct node *pop(struct node *top, int *i) {
    struct node *temp;
    
    if (top != NULL) {
        *i = top->value;
        temp = top->next;
        free(top);
        return temp;
    } else {
        printf("Stack is empty, can not pop.\n");
    }
  return top;
}

struct node *roll(struct node *top) {
    struct node *temp, *new_node;
    int i;
    
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("malloc failed\n");
        return top;
    }
    
    if (top != NULL) {
        new_node = top;
        i = new_node->value;
        temp = new_node->next;
        new_node = temp->next;
        new_node->next->value = i;
        return new_node;
    }
    
    
    /*if (top != NULL) {
    temp = top->next;
    top->next = temp->next;
    }*/
    
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
