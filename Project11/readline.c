/* Reads a line of text and stores in a string 
 *
 * Derek Rodriguez
 * U37516832
 * 11/19/2016
 *
 */

#include "readline.h"


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
