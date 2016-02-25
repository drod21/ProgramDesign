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
int main()
{
    int read_in;
    char in_address[STR_LEN + 1];
    char out_address[STR_LEN + 1];
    
    
    printf("Please enter a web address: ");
    read_in = read_line(in_address, STR_LEN);
    //printf("%s\n", in_address);
    extract(in_address, out_address);
    
    
    
    return 0;
}

void extract(char *s1, char *s2)
{
    char *p;
    char *key;
    char *flag;
    /* Copies s1 to s2  and prints */
    //strcpy(s2, s1);
    for (p = s1; p < s1 + STR_LEN; p++) {
        if (strstr(p, "www.")) {
            key = strstr(p, "www.");
        }
        if (strstr(p, ".edu")) {
            flag = strstr(p, ".edu");
        }
    }
    s2 = malloc((strlen(key) + strlen(flag) + 1));
    strcat(s2, key);
    strcat(s2, flag);
    printf("%s \n", s2);
    
    //printf("Web address starting with www. and ending with .edu not found\n");
}

/*read_line skips the white space(s) before beginning to store input characters*/
int read_line(char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n)
    {
        *str++= ch;
        i++;
    }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}

void removeChar(char *str, char garbage) {
    
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage)
            dst++;
    }
    *dst = '\0';
}
