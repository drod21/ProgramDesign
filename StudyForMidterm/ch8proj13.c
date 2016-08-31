//
//  ch7proj11.c
//  Prints last name and first letter of first name
//
//  Created by Derek Rodriguez
//
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char ch, last[20];
    int count = 0, count2 = 0;
    
    printf("Enter first and last name: \n");
    /* Do while loop */
    do {
        ch = getchar(); /* Takes in user input */
        
        /* If first count is zero, first character is stored in last and counter increased */
        if (count == 0) {
            last[count] = ch;
            count++;
        }
        /* if ch is a space, count2 = 1(true) */
        if (ch == ' ')
            count2 = 1;
        /* if count1 is 1, character != '  ' and !=null, prints last name */
        if (count2 == 1 && ch!= ' ' && ch!='\n') {
            printf("%c", ch);
        }
    }
    while (ch != '\n');
    printf(", %s.\n",last);
    return 0;
}