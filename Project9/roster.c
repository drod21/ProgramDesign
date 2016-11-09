/* The program roster.c maintains a roster for a sports team. Each player has a
 * last name, first name, and a number.
 * 
 * Derek Rodriguez
 * U37516832
 * 11/07/2016
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 30
struct player{
	int number;
	char first_name[NAME_LEN+1];
	char last_name[NAME_LEN+1];
	struct player *next;
};


struct player *append_to_list(struct player *roster);
void find_player(struct player *roster);
void printList(struct player *roster);
void clearList(struct player *roster);
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

  struct player *team_roster = NULL;  
  printf("Operation Code: a for appending to the roster, f for finding a player"
	  ", p for printing the roster; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': team_roster = append_to_list(team_roster);
                break;
      case 'f': find_player(team_roster);
                break;
      case 'p': printList(team_roster);
                break;
      case 'q': clearList(team_roster);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct player *append_to_list(struct player *roster) {

    struct player *cur, *new_node, *temp;
    int number;
    
    printf("\nEnter player number: \n");
    scanf("%d", &number);
    
    for (temp = roster; temp != NULL; temp = temp->next) {
        
        if (temp != NULL && temp->number == number) {
            
            printf("\nPlayer already exists.");
            return roster;
            
        }
    }
    
    new_node = malloc(sizeof(struct player));
    
    if (new_node == NULL) {
        
        printf("Database is full. Cannot add more players. \n");
        return roster;
        
    }
    /* Store number into new_node */
    new_node->number = number;
    /* Read in last name, first name */
    printf("Please enter the player's last name: \n");
    read_line(new_node->last_name, NAME_LEN);
    
    printf("Please enter the player's first name: \n");
    read_line(new_node->first_name, NAME_LEN);
    /* Set new_node->next to null, since it's the last node in the list */
    new_node->next = NULL;
    
    /* new_node is the top of the list. */
    if (roster == NULL) {
        
        roster = new_node;
        roster->next = NULL;
        return new_node;
        
    } else {
        /* Loop to end of roster, use cur to point to the end of roster */
        for (cur = roster; cur->next != NULL; cur = cur->next);
        /* Store new_node to the end of the list */
        cur->next = new_node;
        new_node->next = NULL;
        return roster;
        
    }
    
    free(new_node);
    
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
