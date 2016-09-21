//
//  reverse_name.c
//  Reverse order of name, prints last name and first letter of first name
//  For entered first and last name
//  Created by Derek Rodriguez on 9/20/16.
//
//

void reverse_name(char *name);

#include <stdio.h>
#define N 80

int main(void) {
    
    char name[N + 1];
    int i = 0;
    
    printf("Please enter a name: \n");
    
    while ((name[i] = getchar()) != '\n') {
        
        i++;
        
    }
    
    name[i + 1] = '\0';
    
    reverse_name(name);
    
    return 0;
    
}


void reverse_name(char *name) {
    
    int count1 = 0, count2 = 0;
    char last;
    
    do {
        
        /* If count1 is zero, first character is stored ino last and count 
         * Is increased
         */
        
        if (count1 == 0 && *name != ' ') {
            
            last = *name;
            count1++;
            
        }
        
        /* If character is equal to space, then count2 = 1 */
        
        if (*name == ' ' && count1 != 0) {
            
            count2 = 1;
            
        }
        
        /* If count2 is 1, character is not space, and character is not null
         * Print the last name
         */
        
        if (count2 == 1 && *name != ' ' && *name != '\0') {
            
            printf("%c", *name);
            
        }
        
        name++;
        
    } while (*name != '\n');
    
    printf(", %c.\n", last);
    
}
