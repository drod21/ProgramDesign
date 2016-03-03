//
//  ch5proj7.c
//  
//
//  Created by Derek Rodriguez on 3/2/16.
//
//

#include <stdio.h>

int main(void) {
    int a, b, c, d, smallest = 0, largest = 0;
    int i;
    printf("enter four integers:");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
    if (a < b) {
        smallest = a;
        largest = b;
        printf("%d %d\n", smallest, largest);
    } else {
        smallest = b;
        largest = a;
        printf("%d %d\n", smallest, largest);
    }
    
    if (c < smallest) {
        smallest = c;
    } else {
        largest = c;
        printf("%d %d\n", smallest, largest);
        
    }
    
    if (d < smallest) {
        smallest = d;
    } else {
        d = largest;
        
    }
    
    printf("Smallest: %d\n", smallest);
    printf("Largest: %d\n", largest);
    return 0;
}