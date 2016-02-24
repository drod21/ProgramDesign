//
//  read_line.c
//  
//
//  Created by Derek Rodriguez on 2/22/16.
//
//

#include <stdio.h>
#include <string.h>
int read_line(char *str, int n);

#define STR_LEN 10
int main()
{
    int num_chars;
    char sen[STR_LEN+1];
    printf("enter a sentence: ");
    
    num_chars = read_line(sen, STR_LEN);
    printf("you entered: %s, it has %d characters", sen, num_chars);
    return 0;
}

int read_line(char *str, int n)
{
    int ch, i = 0;
    int begin = 0;
    int end = strlen(str) - 1;
    
    while ((ch = getchar()) == ' ')
        *str++ = ch;
    i++;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
        *str++= ch;
        i++;
    }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}
