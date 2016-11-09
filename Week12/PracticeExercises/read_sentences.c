#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int read_line(char str[], int n);

int main()
{
    char input_buffer[1001];
    int length = 0;
    char *sentence[50] = NULL;
    int i, num_words = 0;

    
    for (;;) {
        
        printf ("Please type a sentence:\n");
        read_line(input_buffer, 1000);
    
    
        length = strlen(input_buffer);
        if (length == 0)
            break;

        
        printf ("Allocating %d bytes to hold the sentence\n\n", length+1);

        sentence[num_words] = malloc(length+1);
        
        if(sentence == NULL){
            printf("malloc failed");
            return 0;
        }
		
        strcpy(sentence[num_words], input_buffer);
        num_words++;
        
   
        for (i = 0; i < num_words; i++) {

            printf ("%s\n", sentence);
	 
        }
        
        
        printf("Deallocating memory. \n");
        for (i = 0; i < num_words; i++) {
            
            free(sentence[i]);
            
        }
        
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

