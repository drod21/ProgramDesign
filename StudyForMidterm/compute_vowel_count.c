//
//  compute_vowel_count.c
//  
//
//  Created by Derek Rodriguez on 9/19/16.
//
//

#include <stdio.h>


int compute_vowel_count(const char *sentence);

int main() {
    
    char ch, sentence[26];
    
    int i = 0, count = 0, result;
    
    printf("Enter a sentence: \n");
    
    while ((ch = getchar()) !='\n') {
        
        sentence[i++] = ch;
        count++;
        
    }
    
    result = compute_vowel_count(sentence);
    printf("Your sentence contains %d vowels. \n", result);
    return 0;
    
}

int compute_vowel_count(const char *sentence) {
    
    int count = 0;
    char *p;
    for (p = sentence; *p; p++) {
        
        if (*p == 'a' || *p == 'i' || *p == 'e' || *p == 'o' || *p == 'u') {
            
            count++;
            
        }
        
    }
    
    return count;
    
}