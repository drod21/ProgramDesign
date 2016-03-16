/* reads in a line of text and computes the frequency of the words in the text. *
 * Derek Rodriguez *
 * U37516832 *
 * 3/12/2016 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int read_line(char *str, int n);
int search(int *a, int n, int key);
#define STR_LEN 1000
#define WORDS 50

int main(void) {
    int read_num, i = 0, j = 0, k = 0, n = 0, count;
    char input_words[STR_LEN + 1];
    char words[WORDS][STR_LEN];
    char temp[STR_LEN];
    
    printf("Please enter a sentence: \n");
    read_num = read_line(input_words, STR_LEN);
 
    return 0;
}

int search (int *a, int n, int key) {
    int *p;
    
    for (p = a; p < a + n; p++) {
        if (*p == key)
            return 1;
    }
    return 0;
}

/*read_line skips the white space(s) before beginning to store input characters*/
int read_line(char *str, int n) {
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n') {
        if (ispunct(ch)) {
            ch = '\t';
        } else if (i < n) {
            *str++= ch;
            i++;
        }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}
