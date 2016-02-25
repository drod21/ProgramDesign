//
//  extract.c
//  
//
//  Created by Derek Rodriguez on 2/22/16.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void extract(char *s1, char *s2);
int read_line(char *str, int n);
void removeChar(char *str, char garbage);
#define STR_LEN 1000
int main() {
    int read_in;
    char in_address[STR_LEN + 1];
    char out_address[STR_LEN + 1];
    
    
    printf("Please enter a web address: ");
    read_in = read_line(in_address, STR_LEN);
    //printf("%s\n", in_address);
    extract(in_address, out_address);
    
    
    
    return 0;
}

void extract(char *s1, char *s2) {
    char *p;
    char *www = strstr(s1, "www.");
    char *edu = strstr(s1, ".edu");
    
    if (www != NULL && edu != NULL) {
        p = s2;
        while (www < (edu + 4)) {
            *p = *www;
            www++;
            p++;
        }
    } else {
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

