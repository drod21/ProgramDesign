//
//  anagram2.c
//  
//  Ch 13 PP 14
//  Created by Derek Rodriguez on 9/26/16.
//
//

#include <stdio.h>
#include <string.h>
#define N 26

int are_anagrams(char *word1, char *word2);

int main()
{
    
    char word1[N] = {0}, word2[N] = {0};
    char ch;
    int i;
    int result;
    
    printf("enter a word: ");
    
    while((ch=getchar())!= '\n') {

        word1[ch - 'a']++;
        
    }
    
    for(i =0;i<N;i++) {
        
        printf("%d", word1[i]);
    
    }
    
    printf("\n");
    
    
    printf("enter the second word: ");
    
    while((ch=getchar())!= '\n') {
        word2[ch - 'a']++;
        
    }
    
    for(i = 0; i < N; i++) {
        
        printf("%d", word2[i]);
        
    }
    
    printf("\n");
    
    result = are_anagrams(word1, word2);
    
    printf("Result is: %d\n", result);
    
    if(result == 1) {
        
        printf("The words are anagrams.\n");
        
    } else {
        
        printf("The words are NOT anagrams.\n");
    
    }
    
    return 0;
}

int are_anagrams(char *word1, char *word2) {
    
    int count = 0;
    int len1, len2;
    
    char *p, *q;
    
    len1 = strlen(word1);
    len2 = strlen(word2);

    if (len1 != len2) {
        
        return 0;
        
    }
    
    for (p = word1, q = word2; *p != '\0' && *q !='\0'; p++, q++) {

    
        if (*word1 == *word2) {
            
            count++;
            
            
        }
    }
    
    
    if (count == 1)
        
        return 1;
    
    else
        
        return 0;
    
    
}





