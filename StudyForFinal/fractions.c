//
//  fractions.c
//  
//
//  Created by Derek Rodriguez on 11/2/16.
//
//

#include <stdio.h>

struct fractions {
    
    int numerator, denominator;
    
};

struct fraction reduce(struct fraction f);
struct fraction add(struct fraction f1, f2);
struct fraction subtract(struct fraction f1, f2);
struct fraction multiply(struct fraction f1, f2);
struct fraction divide(struct fraction f1, f2);

int main() {
    
    struct fraction f;
    
    
    return 0;
    
}

struct fraction reduce(struct fraction f) {
    
    struct fraction f1;
    
    int remainder, m, n;
    
    m = f.numerator;
    n = f.denominator;
    
    while (n != 0) {
        
        remainder = m % n;
        
        m = n;
        
        n = remainder;
        
    }
    
    f1.numerator = f.numerator / m;
    
    f1.denominator = f.denominator / m;
    
    return f1;
    
}

struct fraction add(struct fraction f1, f2) {
    
    struct fraction f;
    
    f.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    
    f.denominator = f1.denominator * f2.denominator;
    
    return reduce(f);
    
}

struct fraction subtract(struct fraction f1, f2) {
    
    struct fraction f;
    
    f.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
    f.denominator = f1.denominator * f2.denominator;
    
    return reduce(f);
    
}

struct fraction multiply(struct fraction f1, f2) {
    
    struct fraction f;
    
    f.numerator = f1.numerator * f2.numerator;
    f.denominator = f2.numerator * f2.denominator;
    
    return reduce(f);
    
    
}

struct fraction divide(struct fraction f1, f2) {
    
    struct fraction f;
    
    f.numerator = f1.numerator * f2.denominator;
    f.denominator = f1.denominator * f2.numerator;
    
    return reduce(f);
    
}
