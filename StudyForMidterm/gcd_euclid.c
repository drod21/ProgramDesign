//
//  gcd_euclid.c
//  
//
//  Created by Derek Rodriguez on 9/3/16.
//
//

#include <stdio.h>

int gcd(int m, int n);

int main(void) {
    
    int d1, d2, greatestcommondivisor;
    
    printf("Enter two integers: \n");
    
    scanf("%d %d", &d1, &d2);
    
    greatestcommondivisor = gcd(d1, d2);
    
    printf("Greatest common divisor: %d\n", greatestcommondivisor);
    
    return 0;
    
}

int gcd(int m, int n) {
    
    int remainder;
    while (n != 0) {
        
        remainder = m % n;
        
        m = n;
        
        n = remainder;
        
    }
    
    return m;
    
}