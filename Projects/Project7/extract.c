/* This program takes user input web address and verifies it is valid *
 * by finding www. and .edu, not allowing .com, .org, etc.. *
 * then extracts the web address and stores into an output array and prints *
 * Derek Rodriguez *
 * U37516832 *
 * 2/25/16 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void extract(char *s1, char *s2);
int read_line(char *str, int n);
void removeChar(char *str, char garbage);
#define STR_LEN 1000
int main() {
    int read_in;
    char in_address[STR_LEN + 1]; /* Input and output arrays */
    char out_address[STR_LEN + 1];
    
    /* Prompts user to input web address, then uses read_line function to
     * store into in address, then calls on extract function */
    printf("Please enter a web address: ");
    read_in = read_line(in_address, STR_LEN);
    extract(in_address, out_address);
    
    /* Print the final web address */
    printf("%s\n", out_address);
    
    
    
    return 0;
}

void extract(char *s1, char *s2) {
    /* Pointers for loop, and to extract the address of www and edu from s1 */
    char *p;
    char *www = strstr(s1, "www.");
    char *edu = strstr(s1, ".edu");
    /* Checks if www and edu exit */
    if (www != NULL && edu != NULL) {
        p = s2;
        /* While loop to store the slots for www through edu */
        while (www < (edu + 4)) {
            *p = *www;
            www++;
            p++;
        }
    } else {
        /* Error message if www and edu are not present */
    printf("Web address starting with www. and ending with .edu not found\n");
    }
}

/*read_line skips the white space(s) before beginning to store input characters*/
int read_line(char *str, int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
        *str++= ch;
        i++;
    }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}

