//
//  reversesentence.c
//  
//
//  Created by Derek Rodriguez on 9/17/16.
//
//

#include <stdio.h>


int main() {
    
    char sentence[26];
    char *p, *start, *finish, *temp;
    char ch, term;
    
    
    p = sentence;
    printf("Enter a sentence: \n");
    while ((ch = getchar())!= '\n') {
        
        *(p++) = ch;
        if (ch == '!' || ch == '.' || ch == '?') {
            term = ch;
            break;
        }
        
    }
    *p = '\0';
    p = p - 2;
    start = p;
    
    //Find and display reverse order of words
    for (finish = p; finish >= sentence; finish--) {
        
        // Loop till beginning of sentence in reverse order
        while (start >= sentence && *start != ' ') {
            start--;
        }
        
        //Condition to check if beginning of sentence is reached
        if (start <= sentence) {
            printf("%c", ' ');
            start = sentence;
        }
        //Print each word
        for (temp = start; temp <= p; temp++ ) {
            printf("%c", *temp);
        }
        //Store next word values
        finish = --start;
        p = finish;
        
    }
    //Print terminating character
    printf("%c\n", term);
    return 0;
    
}