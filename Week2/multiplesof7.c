//
//  multiplesof7.c
//  
//
//  Created by Derek Rodriguez on 9/1/16.
//
//

#include <stdio.h>


int main() {
    
    int i, num_7, mult_7;
    
    printf("Enter a number of times to find multiples of 7: ");
    scanf("%d", &num_7);
    
    for (i = 1; i <= num_7; i++) {
        mult_7 = 7 * i;
        if (mult_7 > 100)
            break;
        if (mult_7 % 2 == 1)
            continue;
        printf("%d\n", mult_7);
        
    }
    
    
    
    return 0;
    
}