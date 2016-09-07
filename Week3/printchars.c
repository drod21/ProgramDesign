//
//  printchars.c
//  
//
//  Created by Derek Rodriguez on 9/7/16.
//
//

#include <stdio.h>


int main() {
    
    char ch;
    
   
    
    for (ch = 32; ch < 127; ch++) {
        
        printf(" %c %d\n", ch, ch);
        
    }
    
    return 0;
}