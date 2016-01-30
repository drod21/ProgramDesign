/* Derek Rodriguez **
** U37516832 **
** 01/25/2016 **
*************
** Takes a message entered by user **
** Removes punctuation (nonletters) except white spaces **
** Makes letters Uppercase, prints message **
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    /* Define variables */
    int str = 0;
    char ch;
    
    printf("Please enter a message.\n");
    
    /* While loop && if statement. */
    while ((ch = getchar()) != '\n') { /* Reads input and escapes when enter key is pressed */
        if ( ispunct(ch)){ /* Use ispunct function that checks for punctuation */
            ch = '\t'; /* Define ch for punctuation marks */
        } else {
        putchar(toupper(ch)); /* Puts the characters to uppercase and prints them */
        str++;
    }
        
    }
    putchar('\n'); /* New line to avoid cluttered terminal */

    return 0;

}
