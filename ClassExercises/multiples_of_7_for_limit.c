#include <stdio.h>

int main()
{

	int number = 0, counter = 0, multiples = 0;
	printf("Enter the number of multiples of 7:");

	scanf("%d", &number);


	for(counter = 0; counter < number; counter ++)
	{
		multiples = 7*(counter +1);	
		if(multiples >= 100) break;
	 	printf("%d\n", multiples);
	}
	
	return 0;
}  
	
