//
//  ch3proj4.c
//  
//  Prompts user to enter a telephone number of (xxx) xxx-xxxx
//  And print in form xxx.xxx.xxxx
//  Created by Derek Rodriguez on 3/1/16.
//
//

#include <stdio.h>

int main(void) {
    char area_code[5], initial_number[9], final_number[13];
    int i;

printf("Please enter telephone number in (xxx) xxx-xxxx\n");
scanf("%s%s", area_code, initial_number);

    /* Loops from area_code[1] -> area_code[3] */
    /* for final_number[0->3] store area_code[1->3] to skip the parantheses */
    for (i = 1; i < 4; i++) {
        final_number[i - 1] = area_code[i];
    }
    final_number[3] = '.';
    
    /*Stores next 3 digits into final_number[4->6]*/
        for (i = 0; i < 3; i++) {
            final_number[i + 4] = initial_number[i];
    }
    final_number[7] = '.';
    
    /*Stores the next 4 digits from initial_number(i+4=[6->9]) to final_number[8->11]*/
    for (i = 0; i < 4; i++) {
        final_number[i + 8] = initial_number[i + 4];
    }
    final_number[12] = '\0';
    
    printf("You entered %s \n", final_number);
    
    return 0;
}