#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

     int i;
     int sum = 0;

     for(i=1; i<argc; i++)
     {

	printf("%s", argv[i]);
        sum += atoi(argv[i]);
	
      }
      printf("sum is %d", sum); 
      return 0;
}
