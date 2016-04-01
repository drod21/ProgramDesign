#define color_len 100

#include <stdio.h>

struct color{
    char name[25];
   int red;
   int green;
   int blue;
};

int find_color(char name[25], struct part inv[], int nc)
void insert(struct color colors[], int *nc);
void search (struct color colors[], int nc);
void print(struct color colors[], int nc);
struct color brighter(struct color c);
struct color make_color(int red, int green, int blue);

int main()
{
    char code;
    struct color cols[color_len];
    int num_colors = 0;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (gtchar() != '\n')
            ;
        switch (code) {
            case 'i': insert(cols, &num_colors);
                break;
            case 's': search(cols, num_colors);
                break;
            case 'p': print(cols, num_colors);
                break;
            case 'q': return 0;
            default: printf("Illegal code\n");
                
        }
        printf("\n");
    }
	return 0;
}

struct color make_color(int red, int green, int blue)
{
	struct color c;
	if(red < 0) red =0;
	if (red > 255) red = 255;
	if(green < 0) green =0;
	if (green > 255) green = 255;
	if(blue < 0) blue =0;
	if (blue > 255) blue = 255;
	c.red = red;
	c.green = green;
	c.blue = blue;
	return c;
}

struct color brighter(struct color c)
{
	struct color c2;
	if(c.red == 0) c.red = 3;
	if(c.green ==0) c.green = 3;
	if(c.blue ==0) c.blue = 3;

	c2.red = (c.red/0.7>255)?255:(int)(c.red/0.7);
	c2.green = (c.green/0.7>255)?255:(int)(c.green/0.7);
	c2.blue = (c.blue/0.7>255)?255:(int)(c.blue/0.7);

	return c2;

}

int find_color(char name[25], struct part inv[], int nc)
{
    int i;
    
    for (i = 0; i < nc; i++)
        if (col[i].name == name)
            return i;
    return -1;
    
void insert(struct color colors[], int *nc) {
    if (*nc == color_len) {
        printf("Full\n");
        return;
    }
    printf ("Enter the name of the color\n");
        scanf("%s", name);
    if (find_color(name, colors, *nc) >= 0) {
        printf("Color already exists");
        return;
    }
    colors[*nc].name = name;
    
}

void search(struct color colors[], int nc) {
    
}

void print(struct color colors[], int nc) {
                
            }