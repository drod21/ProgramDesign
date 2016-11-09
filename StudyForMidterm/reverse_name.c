//
//  reverse_name.c
//  Reverse order of name, prints last name and first letter of first name
//  For entered first and last name
//  Created by Derek Rodriguez on 9/20/16.
//
//



#include <stdio.h>
#include <string.h>
#define N 1000

void reverse_name(char *name);

int main(void) {
    
    char name[N + 1], ch;
    int i = 0;
    
    printf("Please enter a name: \n");
    
    while ((ch = getchar()) != '\n') {
        
        name[i++] = ch;
        
    }
    
    name[i + 1] = '\0';
    
    reverse_name(name);
    
    printf("%s. \n", name);
    
    return 0;
    
}


void reverse_name(char *name) {
   
    char first, *p, *last;
    
    int length;
    
    /* Store the first initial */
    first = *name;
    
    for (p = name; *p != '\0'; p++) {
        
        if (*p == ' ') {
            
            break;
            
        }
        
    }
    last = p + 1;
    
    
    strcat(last, ", ");
    length = strlen(last);
    
    *(last + length) = first;
    *(last + length + 1) = '\0';
    
    /* Print the final product */
    //printf("%s. \n", last);
    
    while (*name != '\0') {
        *name++ = *last;
        last++;
        
    }
    
    /* Loop through name pointer till a space is reached,
     * Then point name to the first element after the space.
     
     
    for (; *name != '\0'; name++) {
        
        if (*name == ' ') {
            
            name = name + 1;
            break;
            
        }
    }
    
     Add the comma and space, find strlen of name, add first and null character
    strcat(name, ", ");
    length = strlen(name);
    
    *(name + length) = first;
    *(name + length + 1) = '\0';
    
    printf("%s.\n", last);
    
    
     
     *Old way of doing this, with arrays
     *
     
    char last[20], *p, first[20];
    int count = 0, count2 = 0;
   
    
    
    // Loop through name pointer to find first name
    for (p = name; *p != '\0'; p++) {
        
        first[count] = *p;
        count++; // number of letters to space
        
        if (*p == ' ') {
            
            break;
            
        }
        
        
    }
    strcpy(last, p + 1);
    
    
    for (p = p + 1; *p != '\0'; p++) {
        
        count2++;
        
        
        if (*p == '\0') {
            
            break;
            
        }
        
    }
    
    strcpy(name, last);
    
    
    strcat(name, ", ");
    *(name + count2 + 1) = first[0];
    *(name + count2 + 2) = '\0';
    
    
*/
    
    
    
    /*
    int count1 = 0, count2 = 0;
    char last;
    
    do {
        
         * If count1 is zero, first character is stored ino last and count
         * Is increased
         
        
        if (count1 == 0 && *name != ' ') {
            
            last = *name;
            count1++;
            
        }
        
        * If character is equal to space, then count2 = 1
        
        if (*name == ' ' && count1 != 0) {
            
            count2 = 1;
            
        }
        
        * If count2 is 1, character is not space, and character is not null
         * Print the last name
         *
        
        if (count2 == 1 && *name != ' ' && *name != '\0') {
            
            printf("%c", *name);
            
        }
        
        name++;
        
    } while (*name != '\n');
    
    printf(", %c.\n", last);
         */
    
}