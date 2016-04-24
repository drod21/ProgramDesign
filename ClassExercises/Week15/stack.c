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
    struct node *temp, *prev;
   // int i, j, k;
    int count;
    prev = top;
    
    /*top = pop(top, &i);
    top = pop(top, &j);
    top = pop(top, &k);
    top = push(top, j);
    top = push(top, i);
    top = push(top, k);*/
    prev = malloc(sizeof(struct node));
    if (prev == NULL) {
        printf("malloc failed\n");
        return top;
    }
    
    
    //for (temp = top, prev = NULL; temp != NULL; prev = temp, temp = temp->next);
    
    if (top != NULL) {
        temp = top->next;
        prev = temp->next; //temp->value = 8, temp->next->value = 32
        prev->next = top; //prev->value = 32, prev->next->value = 25
        top = temp->next; //prev->value = 32, prev->next = 94, temp->value = 8
        //top->next = prev->next; //top->value = 32, top->next = 94, top->next->next = 8
        //top->next->value = i;
        //new_node->next = top->next;
       // new_node = temp;
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
