//
//  extract.c
//  
//
//  Created by Derek Rodriguez on 2/22/16.
//
//

#include <stdio.h>
#include <string.h>
void extract(char *s1, char *s2);
int read_line(char *str, int n);
int search(int *a, int n, int key);
#define STR_LEN 1000
int main()
{
    char in_address[STR_LEN + 1];
    char out_address[STR_LEN + 1];
    
    extract(in_address, out_address);
    
    
    
    return 0;
}

void extract(char *s1, char *s2)
{
    int read_in;
    printf("Please enter a web address: ");
    read_in = read_line(s1, STR_LEN);
    /* Copies s1 to s2  and prints */
    strcpy(s2, s1);
    printf("%s\n", s2);
    

}

/*read_line skips the white space(s) before beginning to store input characters*/
int read_line(char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {  if (i < n)
    {
        *str++= ch;
        i++;
    }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}

int search(int *a, int n, int key)
{
    int *p;
    
    for(p = a; p < a+n; p++)
    {
        if(*p == key)
            return 	1;
        
    }
    
    return 0;
}
