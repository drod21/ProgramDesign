//
//  gcd_recursive.c
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
    
    if (n == 0) {
        return m;
    } else {
        return gcd(n, m % n);
    }
    
}