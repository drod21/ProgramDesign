//
//  readlinenew.c
//  
//
//  Created by Derek Rodriguez on 2/24/16.
//
//
int read_line(char *str, int n);

#include <stdio.h>
#include <string.h>
#define STR_LEN 10
int main() {
    int first;
    int second;
    char text1[STR_LEN+1];
    char text2[STR_LEN+1];
    
    printf("text1:\n");
    first = read_line(text1, STR_LEN);
    printf("text2:\n");
    second = read_line(text2, STR_LEN);
    printf("\n%s\n%s\n", text1, text2);
    
    if (strcmp(text1, text2) == 0) {
        printf("both strings are same");
    } else if (strlen(text1) > strlen(text2)) {
            printf("text 1: %s is larger.\n", text1);
    } else {
        printf("text 2: %s is larger.\n", text2);
    }

}
int read_line(char *str, int n)
{
    int ch, i = 0;
    while((ch = getchar()) == ' ') ;
    *str++=ch;
    i++;
    while ((ch = getchar()) != '\n')
    {  if (i < n)
    {
        *str++= ch;
        i++;
    }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}