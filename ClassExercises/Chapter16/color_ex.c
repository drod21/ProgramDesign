//
//  color_ex.c
//  
//
//  Created by Derek Rodriguez on 3/28/16.
//
//

#include <stdio.h>
struct color {
    int red;
    int green;
    int blue;
} magenta = {255, 0, 255};

struct color make_color(int red, int green, int blue) {
    struct color c;

    if (red < 0) {
        c.red = 0;
    } else if (red > 255) {
        c.red = 255;
    } else {
        c.red = red;
    }
    if (green < 0) {
        c.green = 0;
    } else if (green > 255) {
        c.green = 255;
    } else {
        c.green = green;
    }
    if (blue < 0) {
        c.blue = 0;
    } else if (blue > 255) {
        c.blue = 255;
    } else {
        c.blue = blue;
    }
    
    return c;
}


int main() {
    printf("Color values for magenta: \n");
    printf("Red: %d\n", magenta.red);
    printf("Green: %d\n", magenta.green);
    printf("Blue: %d\n", magenta.blue);
    
    struct color color2;
    printf("Please enter color values: \n");
    scanf("%d%d%d", &color2.red, &color2.green, &color2.blue);
    
    printf("Red: %d\n", color2.red);
    printf("Green: %d\n", color2.green);
    printf("Blue: %d\n", color2.blue);
    
    printf("Next color:\n");
    struct color color3;
    color3 = make_color(256,-1,275);
    printf("%d, %d, %d\n", color3.red, color3.green, color3.blue);
    
    
    return 0;
}

