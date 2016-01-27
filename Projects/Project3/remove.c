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
    
    int str = 0;
    char ch;
    printf("Please enter a message.\n");
    
    while ((ch = getchar()) != '\n') {
        putchar(toupper(ch));
        str++;
    }
    putchar('\n');


    return 0;

}
