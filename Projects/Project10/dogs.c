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

struct dog *append(struct dog *list){
    struct dog *cur, *new_node;
    
    new_node = malloc(sizeof(struct dog));

    if (new_node == NULL) {
        printf("full");
        return list;
    }
    printf("Please enter the patient number: \n");
    scanf("%d", &new_node->number);
    for (cur = list; cur != NULL; cur = cur->next) {
    if (cur != NULL && new_node->number == cur->number) {
        printf("Your dog is already a patient here. \n");
        free(new_node);
        return list;
    }
    }
    
    printf("Please enter the dog's name: \n");
    read_line(new_node->dog_name, NAME_LEN);
    
    printf("Please enter the dog's breed: \n");
    read_line(new_node->breed, NAME_LEN);
    
    printf("Please enter the owner's last name: \n");
    read_line(new_node->owner_last_name, NAME_LEN);
    

    new_node->next = list;
 
    return new_node;
    
    
}

void search (struct dog *list)
{
    struct dog *p;
    char name[NAME_LEN + 1];
    printf("Please insert a name to find: ");
    read_line(name, NAME_LEN);
    
    for (p = list; p != NULL; p = p->next) {
        if (strcmp(p->dog_name, name) == 0) {
            print(p);
        } else {
            printf("Name not found\n");
        }
    }

}
void print(struct dog *list){

    struct dog *d;
    printf("\nNumber\tName\tDog Breed\t\tOwner Last Name\n");
    for (d = list; d != NULL; d = d->next) {
        printf("%d\t%s\t%s\t\t%s\n", d->number, d->dog_name, d->breed, d->owner_last_name);
    }

}
void clear(struct dog *list)
{
	//add your code here

}

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
