//
//  rectangles.c
//  
//
//  Created by Derek Rodriguez on 11/26/16.
//
//

#include <stdio.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

int find_area(struct rectangle r);
struct point center(struct rectangle r);
struct rectangle move_rectangle(struct rectangle r, int x, int y);
int in_rectangle(struct rectangle r, struct point p);

int main() {
    
    
    
    
}

int find_area(struct rectangle r) {
    
    int area;
    
    area = (r.lower_right.y * r.upper_left.x) + (r.lower_right.x + r.upper_left.y);
    area = area / 2;
    
    return area;
    
}

struct point center(struct rectangle r) {
    
    struct point c;
    
    c.x = (r.upper_left.x + r.lower_right.x) / 2;
    c.y = (r.upper_left.y + r.lower_right.y) / 2;
    
    return c;
    
}
