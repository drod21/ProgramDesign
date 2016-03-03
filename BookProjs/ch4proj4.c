//
//  ch4proj4.c
//  
//
//  Created by Derek Rodriguez on 3/2/16.
//
//

#include <stdio.h>
#include <math.h>

int main(void) {

    int n;
    int octal = 0;
    int i, j;
    printf("Enter a number between 0 and 32767 : ");
    scanf("%d", &n);
    
    for (i = n, j = 0; i > 7; i = i/8, j = j + 1) {
        int temp = i % 8;
        
    /* octal equivalent to given remain */
        octal = octal + temp * pow(10,j);
    }
    octal = octal + i * pow(10, j);
    printf ("in octal: %5d", octal);
    return 0;
}