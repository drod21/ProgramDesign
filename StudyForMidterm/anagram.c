//
//  anagram.c
//
//
//  Created by Derek Rodriguez on 9/4/16.
//
//

#include <stdio.h>
#include <ctype.h>
#define N 26

int main(void) {
    char ch;
    int letter_counts[N] = {0};
    int i;
    int count = 0;
    
    printf("Enter a word: ");
    
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
        
    }
    
    
    return 0;
}