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
#include "dogs.h"

struct dog *append(struct dog *list) {
    struct dog *top_list, *temp;
    
    top_list = malloc(sizeof(struct dog));
    if (top_list == NULL) {
        printf("Database is full; can't add more dogs.\n");
        return list;
    }
    
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
    
    
    /* Checks the list for empty at beginning, if empty, stores top of the list to 
     * list. Else, stores the list to end of list, and loops through, 
     * setting the previous node equal to the last(next) node */
    if (list == NULL) {
        list = top_list;
        list->next = NULL;
        return top_list;
    } else {
        for (temp = list; temp->next != NULL; temp = temp->next);
        temp->next = top_list;
        top_list->next = NULL;
        return list;
    }
    
    free(temp);
    free(top_list);
}

void search (struct dog *list) {
    /* Search for user input dog name */
    struct dog *p;
    char name[NAME_LEN + 1];
    int found = 0;
    printf("Please insert a name to find: \n");
    read_line(name, NAME_LEN);
    
    for (p = list; p != NULL; p = p->next) {
        /* If dog is found, continue searching for another */
        if (strcmp(p->dog_name, name) == 0) {
            found = 1;
            printf("%d\t%s\t%s\t%s\n", p->number, p->dog_name, p->breed, p->owner_last_name);
        }
    }
    if (!found) {
        printf("Dog not found.\n");
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
