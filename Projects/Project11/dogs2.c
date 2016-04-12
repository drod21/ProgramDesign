#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NAME_LEN 30

struct dog{
	int number;
	char dog_name[NAME_LEN+1];
	char owner_last_name[NAME_LEN+1];
	char breed[NAME_LEN+1];
	struct dog *next;
};

/*function prototypes*/
struct dog *append(struct dog *list);
void search(struct dog *list);
void print(struct dog *list);
void clear(struct dog *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct dog *dog_list = NULL;  
  printf("Operation Code: a for appending to the list, s for finding a dog"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': dog_list = append(dog_list);
                break;
      case 's': search(dog_list);
                break;
      case 'p': print(dog_list);
                break;
      case 'q': clear(dog_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/************************************************************
 * append: Prompts the user for informaiton about a dog and *
 * then append the dog structure to the end of the list.    *
 * Prints an error message and returns prematurely  if the  *
 * dog already exists by its patient number or memory       *
 * could not be allocated for the dog structure.            *
 * *********************************************************/

struct dog *append(struct dog *list){
  struct dog *cur, *new_node;

  new_node = malloc(sizeof(struct dog));
  if (new_node == NULL) {
    printf("Database is full; can't add more dogs.\n");
    return list;
  }

  printf("Enter dog's patient number: ");
  scanf("%d", &new_node->number);

  for (cur = list;cur != NULL;cur = cur->next)
  if (cur != NULL && new_node->number == cur->number) {
    printf("Patient already exists.\n");
    free(new_node);
    return list;
  }

  printf("Enter dog's  name: ");
  read_line(new_node->dog_name, NAME_LEN);
  printf("Enter dog's breed: ");
  read_line(new_node->breed, NAME_LEN);
  printf("Enter owner's last name: ");
  read_line(new_node->owner_last_name, NAME_LEN);

  if(list == NULL)
  {
        list = new_node;
        return list;
  }
  else{
   for(cur = list; cur->next!= NULL; cur = cur->next);
     cur->next = new_node;
     new_node->next = NULL;
     return list;
 }

}

/***********************************************************
 * search: Prompts the user to enter a dog's name, then    *
 * looks up dog(s) by name in the list. Prints the all the *
 * informaiton of the dogs with the name if found.         *
 * Otherwise, prints a message.                            *
 * ********************************************************/

void search (struct dog *list)
{
  char search_name[NAME_LEN+1];
  struct dog *p;
  int found =0;
  printf("Enter dog's name: ");
  read_line(search_name, NAME_LEN);

  for(p=list;
       p != NULL;
       p = p->next)
  {
   if(strcmp(search_name, p->dog_name)==0){
    	found = 1;
    	printf("%d\t", p->number);
	printf("%s\t", p->dog_name);
    	printf("%s\t", p->breed);
    	printf("%s\n", p->owner_last_name);
    }
  } 
  if(!found)
    printf("dog not found.\n");

}

/************************************************************
 * print: Prints a listing of all dogs in the list, showing *
 * the dog's patient number, name, breed, and owner's last  *
 * name.                                                    *
 * *********************************************************/

void print(struct dog *list){

  struct dog *p;

  printf("Dog Number\tDog Name\t"
         "Dog Breed\tOwner Last Name\n");
  for (p = list; p != NULL; p = p->next)
    printf("%d\t\t%s\t\t%s\t\t%s\n", p->number, p->dog_name,p->breed,
           p->owner_last_name);

}
/***************************************************************
 * clear: Clears the entire linked list. It begins at the head * 
 * of the list and frees memory allocated for each node of the *
 * linked list.                                                *
 * ************************************************************/

void clear(struct dog *list)
{
  struct dog *p;

  while(list!=NULL)
  {
         p = list;
         list = list->next;
         if(p!=NULL)
            free(p);
  }

}

/***************************************************************
 * read_line: Skips leading white-space characers, then reads  *
 * the remainder of the input line and stores it in str.       *
 * Truncate the line if its length exceeds n. Returns the      *
 * number of characters stored.                                *
 * ************************************************************/

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
 }
