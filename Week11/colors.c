//
//  colors.c
//  
//
//  Created by Derek Rodriguez on 10/31/16.
//
//

#include <stdio.h>
#include "readline.h"
#include <string.h>

#define NAME_LEN 25
#define MAX_COLORS 100

struct color {
    
    int red, green, blue;
    char name[NAME_LEN + 1];
    
} magenta = {255, 0, 255};

struct color make_color(int red, int green, int blue);
struct color brighter(struct color c);
void print(struct color colors[], int nc);
void insert(struct color colors[], int *nc);
void search(struct color colors[], int nc);


int main() {
    
    char code;
    struct color cols[MAX_COLORS];
    int num_colors = 0;
    
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert(cols, &num_colors);
                break;
            case 's': search(cols, num_colors);
                break;
            case 'p': print(cols, num_colors);
                break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
    
    return 0;
}
    
}


struct color make_color(int red, int green, int blue) {
    
    struct color c;
    
    if (red < 0) {
        
        red = 0;
        
    }
    
    if (green < 0) {
        
        green = 0;
    
    }
    if (blue < 0) {
        
        blue = 0;
        
    }
    
    if (red > 255) {
        
        red = 255;
        
    }
    
    if (green > 255) {
        
        green = 255;
        
    }
    
    if (blue > 255) {
        
        blue = 255;
        
    }
    
        c.red = red;
        c.blue = blue;
        c.green = green;
    
    
    return c;
    
}

struct color brighter(struct color c) {
    
    struct color c2;
    
    if (c.red == 0) {
        
        c.red = 3;
        
    }
    
    if (c.green == 0) {
        
        c.green = 3;
        
    }
    
    if (c.blue  == 0) {
        
        c.blue = 3;
        
    }
    
    
    c2.red = (c.red / 0.7 > 255) ? 255 : (int) (c.red / 0.7);
    c2.green = (c.green / 0.7 > 255) ? 255 : (int) (c.green / 0.7);
    c2.blue = (c.blue / 0.7 > 255) ? 255 : (int) (c.blue / 0.7);
    
    return c2;
    
}

void insert(struct color colors[], int *nc) {
    char name[NAME_LEN+1];
    
    if (*nc == MAX_COLORS) {
        printf("Database is full; can't add more colors.\n");
        return;
    }
    
    printf("Enter color name: ");
    read_line(name, NAME_LEN);
    int i;
    
    for (i = 0; i < *nc; i++)
        if (strcmp(name, colors[i].name) == 0) {
            printf("Color already exists.\n");
            return;
        }
    
    
    strcpy(colors[*nc].name, name);
    printf("Enter red: ");
    scanf("%d", &colors[*nc].red);
    printf("Enter green: ");
    scanf("%d", &colors[*nc].green);
    printf("Enter blue: ");
    scanf("%d", &colors[*nc].blue);
    
    (*nc)++;
    
}

/*search a color by name and display the RGC if found */
void search(struct color colors[], int nc) {
    int i;
    char name[NAME_LEN + 1];
    
    printf("enter a color: \n");
    read_line(name, NAME_LEN);
    
    for (i = 0; i < nc; i++) {
        if (strcmp(name, colors[i].name) == 0)
            break;
    }

    if (i < nc) {
        printf("Red\tGreen\tBlue:\n");
        printf("%d\t%d\t%d\n", colors[i].red, colors[i].green, colors[i].blue);
    } else {
        printf("Color not found.\n");
    }
    
}

void print(struct color colors[], int nc) {
    
    int i;
    
    printf("Color\tRed\t"
           "Green\tBlue\n");
    for (i = 0; i < nc; i++)
        printf("%s\t%d\t%d\t%d\n", colors[i].name, colors[i].red,
               colors[i].green, colors[i].blue);
    
}
