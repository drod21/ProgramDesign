//
//  rectangle.c
//  
//
//  Created by Derek Rodriguez on 10/27/16.
//
//

#include <stdio.h>
#include <stdlib.h>

struct point {
    int x, y;
};

struct rectangle {
    struct point upper_left, lower_right;
};
struct rectangle *p;

int main() {
    
    p = malloc(sizeof(struct rectangle));
    p->upper_left.x = 10;
    p->lower_right.x = 20;
    p->upper_left.y = 25;
    p->lower_right.y = 15;
    
    
    return 0;
    
}
