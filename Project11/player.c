/* The program roster.c maintains a roster for a sports team. Each player has a
 * last name, first name, and a number.
 * 
 * Derek Rodriguez
 * U37516832
 * 11/19/2016
 *
 */

#include "player.h"
#include "readline.h"

struct player *append_to_list(struct player *roster) {

    struct player *cur, *new_node;
   
    new_node = malloc(sizeof(struct player));
    
    if (new_node == NULL) {
        
        printf("Database is full. Cannot add more players. \n");
        return roster;
    }
    
    
    printf("\nEnter player number: \n");
    scanf("%d", &new_node->number);
    
    for (cur = roster; cur != NULL && (strcmp(cur->last_name, new_node->last_name) > 0); cur = cur->next) {
        
        if (cur != NULL && new_node->number == cur->number) {
            
            printf("\nPlayer already exists.");
            return roster;
            
        }
   
    }
    /* Read in last name, first name */
    printf("Please enter the player's last name: \n");
    read_line(new_node->last_name, NAME_LEN);
    printf("Please enter the player's first name: \n");
    read_line(new_node->first_name, NAME_LEN);
    
    char str1[NAME_LEN + 1];
    char str2[NAME_LEN + 1];
    
    strcpy(str1, new_node->last_name);
    strcat(str1, new_node->first_name);
    strcpy(str2, roster->last_name);
    strcat(str2, roster->first_name);
    
    int result = strcmp(str1, str2);
    
    /*for (struct node *p = roster; p->next != NULL; p = p->next) {
    strcpy(str2, p->last_name);
    strcat(str2, p->first_name);*/
        
    
    
    
    
    /* new_node is the top of the list. */
    if (roster == NULL) {
        
        roster = new_node;
        roster->next = NULL;
        return new_node;
        
    } else if (strcmp(roster->last_name, new_node->last_name) > 0) {
        
        new_node->next = roster;
        roster = new_node;
   
    } else {
         // Loop to end of roster, use cur to point to the end of roster
        for (cur = roster; cur->next != NULL && (((strcmp(cur->next->last_name, new_node->last_name) <= 0)) && (strcmp(cur->next->first_name, new_node->first_name) < 0)); cur = cur->next)
             ;
        
         // Store new_node to the end of the list
            if (cur->next == NULL) {
                
                cur->next = new_node;
                new_node->next = NULL;
                
            } else {
                // Place new_node between cur node and next node in list
                new_node->next = cur->next;
                cur->next = new_node;
                
        }
        
    }
    
    return roster;
    
}

struct player *delete_from_list(struct player *roster) {
    
    struct player *prev, *cur;
    int number;
    
    printf("\nPlease enter a player's number to remove: \n");
    scanf("%d", &number);
    
    for (cur = roster, prev = NULL;
         cur != NULL && cur->number != number;
         prev = cur, cur = cur->next);
    
    if (cur == NULL) {

        printf("Player does not exist. \n");
        return roster; /* Player not found */
    
    }
    
    if (prev == NULL) {
        
        roster = roster->next;  /* Player was found in the first node */
        printf("Player %s, %s deleted. \n", cur->last_name, cur->first_name);
        
    } else {
        
        prev->next = cur->next; /* Player found in some other node */
        printf("Player %s, %s deleted. \n", cur->last_name, cur->first_name);
        
    }
    
    free(cur);
    
    return roster;
    
}

void find_player(struct player *roster) {
	
    struct player *p;
    int number;
    int found = 0;
    
    printf("\nEnter the player's number to find: \n");
    scanf("%d", &number);
    
    /* Loop through the roster searching for the player, if found,
     * set found flag to 1, and print out the player name. 
     */
    
    for (p = roster; p != NULL; p = p->next) {
        
        if (p->number == number) {
            
            found = 1;
            
            printf("Player name: %s, %s\n", p->last_name, p->first_name);
            
        }
        
    }

    if (!found) {
        
        printf("Player not found. \n");
        
    }
    
}
void printList(struct player *roster) {

    struct player *p;
    /* Loop through the roster, print the roster. */
    printf("\nPlayer Number\t Last Name\t First Name \n");
    for (p = roster; p != NULL; p = p->next) {
        
        printf("%d\t\t %-10s\t %-10s\n", p->number, p->last_name, p->first_name);
        
    }
    
}
void clearList(struct player *roster) {
    
	/* Loop through roster, set struct p to point to roster,
     * increment roster.
     * If p is NOT NULL, free p.
     */
    
    struct player *p;
    
    while (roster != NULL) {
        
        p = roster;
        roster = roster->next;
        
        if (p != NULL) {
            
            free(p);
            
        }
        
    }

}


