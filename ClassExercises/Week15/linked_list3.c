#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
struct node *last_to_first(struct node *list);
void clearList(struct node *list);
void printList(struct node *list);
struct node {
	int value;          /* data stored in the node  */
	struct node *next;  /* pointer to the next node */
};

int main()
{

 	struct node *first = NULL;

	/* inserting nodes */
	first = add_to_list(first, 83);
	first = add_to_list(first, 64);
	first = add_to_list(first, 98);
	first = add_to_list(first, 31);
        first = add_to_list(first, 64);
	first = add_to_list(first, 3);
	first = add_to_list(first, 136);
    printList(first);
    first = last_to_first(first);

      	printList(first);	
	clearList(first);
	return 0;

}

struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node, *cur, *prev;
	
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("Error: malloc failed in add_to_list\n");
	    return list;
	  }

	  
	  new_node->value = n;
	  for(cur = list, prev = NULL;
		cur!= NULL && new_node->value > cur->value;
		prev = cur, cur = cur->next)
	  ;
	  if(cur!= NULL && new_node->value == cur->value)
	  {
		printf("number already exists. \n");
		free(new_node);
		return list;
	  }
	  new_node->next = cur;
	  if(prev== NULL) 
	  	return new_node;
	  else{
		prev->next = new_node;
		return list;
	}
}

struct node *search_list(struct node *list, int n)
{
	  struct node *p;
	
	  for (p = list; p != NULL; p = p->next)
	    if (p->value == n)
	      return p;
	  return NULL;
}

struct node *last_to_first(struct node *list) {
    struct node *prev, *cur;
    
    if (list == NULL)
        return list;
    for (prev = NULL, cur = list; cur->next != NULL; prev = cur, cur = cur->next);
    if (prev == NULL)
        return list;
    else {
        prev->next = NULL;
        cur->next = list;
        return cur;
    }
}

struct node *delete_from_list(struct node *list, int n)
{
  struct node *cur, *prev;
	  
  for (cur = list, prev = NULL;
       cur != NULL && cur->value != n;
       prev = cur, cur = cur->next)
    ;
  if (cur == NULL) 
    return list;             /* n was not found */
  if (prev == NULL)
    list = list->next;       /* n is in the first node */
  else
    prev->next = cur->next;  /* n is in some other node */
  free(cur);
  return list;
}

void clearList(struct node *list)
{
  struct node *p;
  while(list != NULL)
  {
	p = list;
        list = list->next;
        if( p!= NULL)
           free(p);
  }
}
void printList(struct node *list)
{
	struct node *p;
	for (p = list; p!=NULL; p = p->next)
		printf ("%d\n", p->value);
    printf("\n");
}
