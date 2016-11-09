//
//  complex.c
//  
//
//  Created by Derek Rodriguez on 11/2/16.
//
//

#include <stdio.h>


struct complex {
    
    double real, imaginary;
    
};

struct complex make_complex(double real, double imaginary);

struct complex add_complex(struct complex c1, struct complex c2);

int main() {
  
    struct complex c1, c2, c3;
    
    double r1, r2, i1, i2;
    
    r1 = 5;
    r2 = 3;
    i1 = 9;
    i2 = 10;

    c1 = make_complex(r1, i1);
    c2 = make_complex(r2, i2);
    
    printf("c1: %lf %lf \n", c1.real, c1.imaginary);
    printf("c2: %lf %lf \n", c2.real, c2.imaginary);
    
    printf("c1 + c2: \n");
    
    c3 = add_complex(c1, c2);
    
    printf("%lf %lf \n", c3.real, c3.imaginary);
    
    
    
}


struct complex make_complex(double real, double imaginary) {
    
    struct complex c;
    
    c.real = real;
    c.imaginary = imaginary;
    
    return c;
    
}


struct complex add_complex(struct complex c1, struct complex c2) {
    
    struct complex c;
    
    c.real = c1.real + c2.real;
    
    c.imaginary = c1.imaginary + c2.imaginary;
    
    return c;
    
}
