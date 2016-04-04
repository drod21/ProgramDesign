#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int read_line(char str[], int n);

int main()
{
    char input_buffer[1001];
    int length = 0;
    char *sentence = NULL;

    printf ("Please type a sentence:\n");
    read_line(input_buffer, 1000);
    
    
    length = strlen(input_buffer);
    printf ("Allocating %d bytes to hold the sentence\n\n", length+1);

    sentence = malloc(length+1);
    if(sentence == NULL){
		printf("malloc failed");
		return 0;
	}
		
    strcpy (sentence, input_buffer);
   
    printf ("%s\n", sentence);
	 
	return 0;
}
int read_line(char str[], int n)
{
  int ch, i = 0;
  
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}

