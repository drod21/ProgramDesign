/* Derek Rodriguez
 * U37516832 
 * 4/24/16
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
    printf("\nPlease enter the patient number: \n");
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
    
    if (list == NULL) {
        list = top_list;
        return list;
    } else if (strcmp(list->owner_last_name, top_list->owner_last_name) > 0) {
        top_list->next = list;
        list = top_list;
    } else {
        /* Loop through to compare owners last name and then dog name if owners last name is similar to dog name */
        for (temp = list; temp->next != NULL && (((strcmp(temp->next->owner_last_name, top_list->owner_last_name)< 0) || (strcmp(temp->next->owner_last_name, top_list->owner_last_name) == 0)) && (strcmp(temp->next->dog_name, top_list->dog_name) < 0)); temp = temp->next)
            ;
        /* Store the values and return */
             if (temp->next == NULL) {
                 temp->next = top_list;
                 top_list->next = NULL;
             } else {
                 top_list->next = temp->next;
                 temp->next = top_list;
             }    }
    return list;
}

struct dog* delete_from_list(struct dog *dogs) {
    struct dog *top, *temp, *prev;
    
    top = malloc(sizeof(struct dog));
    if (top == NULL) {
        printf("Database is full.\n");
        return dogs;
    }
    
    printf("\nPlease enter the patient number to remove: \n");
    scanf("%d", &top->number);
    for (temp = dogs, prev = NULL; temp != NULL && temp->number != top->number; prev = temp, temp = temp->next);
    
    if (temp == NULL) {
        return dogs;
    }
    if (prev == NULL) {
        dogs = dogs->next;
         printf("Deleted: Dog name: %s, Owner Last Name: %s Breed: %s\n", temp->dog_name, temp->owner_last_name, temp->breed);
    } else {
        prev->next = temp->next;
         printf("Deleted: Dog name: %s, Owner Last Name: %s, Breed: %s\n", temp->dog_name, temp->owner_last_name, temp->breed);
    }
   
    free(temp);
    return dogs;
}

void search (struct dog *list) {
    /* Search for user input dog name */
    struct dog *p;
    char name[NAME_LEN + 1];
    int found = 0;
    printf("\nPlease insert a name to find: \n");
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
