/* Takes two sets of characters entered by the user 
 * and merges them character by character
 *
 * Derek Rodriguez
 * U37516832
 * 10/3/16
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

void merge (char *s3, char *s1, char *s2);
int read_line(char *str, int n);


int main() {
    
    char first_set[SIZE + 1], second_set[SIZE + 1];
    char third_set[SIZE + 1];
    
    printf("Enter the first set of characters: \n");
    
    read_line(first_set, SIZE);
    
    printf("Enter the second set of characters: \n");
    
    read_line(second_set, SIZE);
    
    merge(third_set, first_set, second_set);
    
    printf("%s \n", third_set);
    
    return 0;
    
}

void merge (char *s3, char *s1, char *s2) {
    
   /* s3 points to a string containing a string that 
    * Combines s1 and s2 letter by letter. 
    * The first set might be longer or shorter than the second set. 
    * The characters in s1 or s2 left after merging should be 
    * Appended to the resulting string s3, which points to 
    * third_set array of characters in main.
    */
    
    /* Loop through s1 and s2 for s1 != '\0' OR s2 != '\0'.
     * If s1 is not null character, add it to s3.
     * If s2 is not null character, add it to s3.
     * This covers each condition for any left over characters in each.
     */
    char *p = s1;
    char *q = s2;
    
    while ((*p != '\0') || (*q != '\0')) {
        
        if (*p != '\0') {
            
            *s3++ = *p;
            p++;
        }
        
        if (*q != '\0') {
            
            *s3++ = *q;
            q++;
        }
        
    }
    
    // Terminate s3.
    *s3 = '\0';
    
    
}

int read_line(char *str, int n) {
    
    /* Reads in n characters and stores in *str, which points to the 
     * Array of characters in main 
     */
    
    int ch;
    int i = 0;
    
    while ((ch = getchar()) != '\n') {
        
        if (i < n) {
            
        *str++= ch;
        i++;
            
        }
    }
    
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
    
}

