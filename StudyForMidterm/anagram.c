//
//  anagram.c
//
//
//  Created by Derek Rodriguez on 9/4/16.
//
//

#include <stdio.h>
#include <ctype.h>
// With bool
#include <stdbool.h>

#define N 26

void read_word(int counts[N]);
bool equal_array(int counts1[N], int counts2[N]);

int main(void) {

    int first_word[N] = {0}, second_word[N] = {0};
    
    printf("Enter the first word: \n");
    
    read_word(first_word);
    
    printf("Enter the second word: \n");
    
    read_word(second_word);
    
    if (equal_array(first_word, second_word)) {
        printf("Words are anagrams.\n");
    } else {
        printf("Words are not anagrams.\n");
    }
    
    
    
    /* Old way without functions
    while ((ch=getchar()) != '\n') {
        
            letter_counts[ch - 'a']++;
        
    }
    
    for(i = 0; i < N; i++) {
        
        printf("%d", letter_counts[i]);
        
    }
    printf("\n");
    
    printf("Enter a second word: ");
    
    while ((ch = getchar()) != '\n') {
        
        letter_counts[ch - 'a']--;
        
    }
    for (i = 0; i < N; i++) {
        
      printf("%d", letter_counts[i]);
        
    }
    
    printf("\n");
    
    for (i = 0; i < N; i++) {
        
        if (letter_counts[i] == 0) {
            
            count++;
            
        }
        
    }
    
    if (count == N) {
        
        printf("Words are anagrams\n");
        
    } else {
        
        printf("Words are not anagrams\n");
        
    } */
    
    
    return 0;
}


void read_word(int counts[N]) {
    
    char ch;
    
    while ((ch = getchar()) != '\n') {
        
        counts[ch - 'a']++;
        
    }
    
}

bool equal_array(int counts1[N], int counts2[N]) {
    
    int i, count = 0;
    
    
    
    for (i = 0; i < N; i++) {
        
            if (counts1[i] == counts2[i]) {
            
                count++;
            
            }
        
   
    }
    
    if (count == N) {
        return true;
    } else {
    return false;
    }
}