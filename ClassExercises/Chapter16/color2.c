#include "readline.h"
#include <stdio.h>
#include <string.h>
#define NAME_LEN 25
#define MAX_COLORS 100

struct color{
   char name[NAME_LEN+1];
   int red;
   int green;
   int blue;
};

struct color brighter(struct color c);
struct color make_color(int red, int green, int blue);
void print(struct color colors[], int nc);
void insert(struct color colors[], int *nc);
void search(struct color colors[], int nc);

int main()
{

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

/*insert a color to the array */
void insert(struct color colors[], int *nc)
{
  char name[NAME_LEN+1];

  if (*nc == MAX_COLORS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter color name: ");
  read_line(name, NAME_LEN);
  int i;

  for (i = 0; i < *nc; i++)
    if (strcmp(name, colors[i].name) == 0)
    {
	printf("Part already exists.\n");
    	return;
    }
  

  strcpy( colors[*nc].name, name);
  printf("Enter red: ");
  scanf("%d", &colors[*nc].red);
  printf("Enter green: ");
  scanf("%d", &colors[*nc].green);
  printf("Enter blue: ");
  scanf("%d", &colors[*nc].blue);
 
  (*nc)++;

}
/*display the colors stored in the array*/
void print(struct color colors[], int nc)
{

  int i;

  printf("Color\tRed\t"
         "Green\tBlue\n");
  for (i = 0; i < nc; i++)
  printf("%s\t%d\t%d\t%d\n", colors[i].name, colors[i].red,
           colors[i].green, colors[i].blue);
}
/*search a color by name and display the RGC if found */
void search(struct color colors[], int nc)
{
  int i;
  char name[NAME_LEN+1];

  printf("Enter color: ");
  read_line(name, NAME_LEN);
  for (i = 0; i < nc; i++)
    if (strcmp(name, colors[i].name) == 0)
      break;
  

  if (i <nc) {
    printf("Red\tGreen\tBlue:\n");
    printf("%d\t%d\t%d\n", colors[i].red, colors[i].green, colors[i].blue);
  } else
    printf("Color not found.\n");
}
