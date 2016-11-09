/* Derek Rodriguez
 * U37516832
 * 11/2/16
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
    
    struct dog *new_node, *temp;
    
    new_node = malloc(sizeof(struct dog));
    
    if (new_node == NULL) {
        
        printf("Database full, cannot add more dogs. \n");
        return list;
        
    }
    
    printf("Please enter the patient number: \n");
    scanf("%d", &new_node->number);
    
    for (temp = list; temp != NULL; temp = temp->next) {
        
        if (temp != NULL && new_node->number == temp->number) {
            
            printf("Dog is already a patient. \n");
            
            free(new_node);
            return list;
            
        }
        
    }
    
    printf("Please enter the dog's name: \n");
    read_line(new_node->dog_name, NAME_LEN);
    printf("Please enter the breed: \n");
    read_line(new_node->breed, NAME_LEN);
    printf("Please enter the owner's last name: \n");
    read_line(new_node->owner_last_name, NAME_LEN);
    
    new_node->next = NULL;
    
    if (list == NULL) {
        // if list is null, new_node is top of list.
        list = new_node;
        list->next = NULL;
        return new_node;
        
    } else {
    
        // Loop through list until the next node is null
        // Store the new dog at the empty next node.
        
        for (temp = list; temp->next != NULL; temp = temp->next);
        
        temp->next = new_node;
        new_node->next = NULL;
        return list;
        
    }
    
    free(new_node);
}

void search(struct dog *list) {
    
    struct dog *p;
    char name[NAME_LEN + 1];
    int found = 0;
    printf("\n Please insert a name to find: \n");
    read_line(name, NAME_LEN);
    
    for (p = list; p != NULL; p = p->next) {
        
        if (strcmp(p->dog_name, name) == 0) {
            found = 1;
            printf("%d\t%s\t%s\t%s\n", p->number, p->dog_name, p->breed, p->owner_last_name);
        }
    }
    
    if (!found) {
        
        printf("Dog not found");
        
    }
    
}

void print(struct dog *list) {
    
    struct dog *d;
    
    printf("\nNumber  Name		  Breed		  Owner Last Name\n");
    
    for (d = list; d != NULL; d = d->next) {
        
        printf("%d\t%s\t%18s\t%10s\n", d->number, d->dog_name, d->breed, d->owner_last_name);
        
    }
    
}

void clear(struct dog *list) {
    
    struct dog *p;
    
    while (list != NULL) {
        
        p = list;
        list = list->next;
        
        if (p != NULL)
            free(p);
        
    }
    
}

int read_line(char str[], int n) {
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
