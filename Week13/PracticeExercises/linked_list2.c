#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
int count_n(struct node *list, int n);
void clearList(struct node *list);
struct node *find_largest(struct node *list);
void printList(struct node *list);

struct node {
	int value;          /* data stored in the node  */
	struct node *next;  /* pointer to the next node */
};

int main()
{

 	struct node *first = NULL;
	int number, count = 0;	
	struct node *largest;

        /* inserting nodes */
    first = add_to_list(first, 83);
    first = add_to_list(first, 64);
    first = add_to_list(first, 98);
    first = add_to_list(first, 31);
    first = add_to_list(first, 64);
    first = add_to_list(first, 3);
    first = add_to_list(first, 136);

	/*printf("enter a number: ");
	scanf("%d", &number);
	
	count = count_n(first, number);
	printf("there are %d %d\n", count, number);

	if((largest =find_largest(first))!=NULL)
	  printf("The largest value is : %d\n", largest->value);*/
    printList(first);
	clearList(first);	 
	return 0;

}

struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node, *prev, *cur;
	
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("malloc failed in add_to_list\n");
	    return list;
	  }
    
    new_node->value = n;
    
    for (cur = list, prev = NULL; cur != NULL && new_node->value > cur->value; prev = cur, cur = cur->next);
    
    if (cur != NULL && new_node->value == cur->value) {
        
        printf("Number already exits. \n");
        free(new_node);
        return list;
        
    }
    new_node->next = cur;
    
    if (prev == NULL) {
        return new_node;
    } else {
        
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

int count_n(struct node *list, int n){

	  struct node *p;
	  int count = 0;
	
          for (p = list; p != NULL; p = p->next)
            if (p->value == n)
              count++;

          return count;

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

struct node *find_largest(struct node *list)
{
  struct node *p = list;
  struct node *largest = list;
  if(p != NULL)
  {
	for(p = list->next; p!=NULL; p = p->next)
 	{	
	  if(p->value>largest->value)
	    largest = p;
  	}
  	return largest;
  } 
  else
	return NULL;
}

void printList(struct node *list)
{
    struct node *p;
    for (p = list; p!=NULL; p = p->next)
        printf ("%d\n", p->value);
}

