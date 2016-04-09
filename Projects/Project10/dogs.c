/* Derek Rodriguez
 * U37516832 
 * 4/9/16
 * maintains records for canine patients at an animal hospital. Each dog’s record
 * has a name, a breed, a patient number, and owner’s last name.
 */

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

struct dog *append(struct dog *list) {
    struct dog *top_list, *end_list, *temp;
    
    top_list = malloc(sizeof(struct dog));
    temp = malloc(sizeof(struct dog));
    
    /* Takes in patient number and checks list for existing number */
    printf("Please enter the patient number: \n");
    scanf("%d", &top_list->number);
    
    for (temp = list; temp != NULL; temp = temp->next) {
        if (temp != NULL && top_list->number == temp->number) {
            printf("Your dog is already a patient here. \n");
            free(top_list); /* Frees the memory for top_list if found */
            return list;
        }
    }
    /* Enter the rest of the data to the top of the structure */
    printf("Please enter the dog's name: \n");
    read_line(top_list->dog_name, NAME_LEN);
    printf("Please enter the dog's breed: \n");
    read_line(top_list->breed, NAME_LEN);
    printf("Please enter the owner's last name: \n");
    read_line(top_list->owner_last_name, NAME_LEN);
    top_list->next = NULL;
    
    end_list = malloc(sizeof(struct dog)); /* Allocate storage for end of list */
    
    /* Checks the list for empty at beginning, if empty, stores top of the list to 
     * list. Else, stores the list to end of list, and loops through, 
     * setting the previous node equal to the last(next) node */
    if (list == NULL) {
        list = top_list;
        list->next = NULL;
        return top_list;
    } else {
        end_list = list;
        while (end_list->next != NULL) {
            end_list = end_list->next;
        }
        end_list->next = top_list;
    }

    return list;
}

void search (struct dog *list)
{
    /* Search for user input dog name */
    struct dog *p;
    char name[NAME_LEN + 1];
    printf("Please insert a name to find: \n");
    read_line(name, NAME_LEN);
    
    for (p = list; p != NULL; p = p->next) {
        /* If dog is found, continue searching for another */
        if (strcmp(p->dog_name, name) == 0) {
            printf("%d\t%s\t%s\t%s\n", p->number, p->dog_name, p->breed, p->owner_last_name);
            p = p->next;
            continue;
        } else {
            /* Name not found, break out of the loop */
            printf("Name not found\n");
            break;
        }
    }
}
void print(struct dog *list){
    /* Loop through the structure and print each node */
    struct dog *d;
    printf("\nNumber  Name		  Breed		  Owner Last Name\n");
    for (d = list; d != NULL; d = d->next) {
        printf("%d\t%s\t%18s\t%10s\n", d->number, d->dog_name, d->breed, d->owner_last_name);
    }

}
void clear(struct dog *list) {
    /* Clears the memory upon exit */
    struct dog *p;
    while(list != NULL) {
        p = list;
        list = list->next;
        if( p!= NULL)
            free(p);
    }
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
