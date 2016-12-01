#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
int count_n(struct node *list, int n);
struct node *find_largest(struct node *list);
void clearList(struct node *list);

struct node {
	int value;          /* data stored in the node  */
	struct node *next;  /* pointer to the next node */
};

int main()
{

 	struct node *first = NULL;
	int number, count = 0;	

	/* inserting nodes */
	first = add_to_list(first, 3);
	first = add_to_list(first, 64);
	first = add_to_list(first, 98);
	first = add_to_list(first, 3);
    first = add_to_list(first, 64);
	first = add_to_list(first, 3);
	first = add_to_list(first, 136);

	printf("Enter a number: ");
	scanf("%d", &number);
	
	count = count_n(first, number);
	printf("The number of nodes that contains %d is %d.\n", number, count);
    
    find_largest(first);
    printf("Largest: %d\n", first->value);
    
	clearList(first);
	return 0;

}

struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node;
	
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("malloc failed in add_to_list\n");
	    return list;
	  }
	  new_node->value = n;
	  new_node->next = list;
	  return new_node;
}

struct node *search_list(struct node *list, int n)
{
	  struct node *p;
	
	  for (p = list; p != NULL; p = p->next)
	    if (p->value == n)
	      return p;
	  return NULL;
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
int count_n(struct node *list, int n){
	
    struct node *p;
    int count = 0;
    
    for (p = list; p != NULL; p = p->next) {
        
        if (p->value == n)
            count++;
        
    }

    return count;
    
}

struct node *find_largest(struct node *list) {
    
    struct node *p = NULL;
    
    for (; list != NULL; list = list->next) {
        
        if (list->value > list->next->value) {
            
            p = list;
            
        } else if (list->next->value > list->value) {
            
            p = list->next;
            
        }
        
        return p;
        
    }
    
    return NULL;
    
}
