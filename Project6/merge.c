/* Takes two sets of characters entered by the user 
 * and merges them character by character
 *
 * Derek Rodriguez
 * U37516832
 * 10/3/16
 *
 */

#include <stdio.h>
#define SIZE 1000

void merge (char *s3, const char *s1, const char *s2);
int read_line(char *str, int n);


int main() {
    
    char first_set[N + 1], second_set[N + 1];
    char third_set[N + 1];
    int i;
    
    printf("Enter the first set of characters: \n");
    
    read_line(first_set, N);
    
    printf("Enter the second set of characters: \n");
    
    read_line(second_set, N);
    
    
    
    
    
    return 0;
    
}

void merge (char *s3, const char *s1, const char *s2) {
    
    
    
    
    
}

int read_line(char *str, int n) {
    
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

