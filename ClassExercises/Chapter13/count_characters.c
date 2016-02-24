#include <stdio.h>
int count_characters(char *s);
int main()
{
        char a[10] = "Hello!";
        int num = count_characters(a);
        printf("number of characters: %d", num);
        return 0;


}

int count_characters(char *s)
{

  int count = 0;
 
  while(*s!='\0')
  {
	count++;
        s++;
  }
  return count;
}
