/*****************************************************************/
/* This program adds, subtracts, or multiplies complex numbers.  */
/* Project 5, Program Design					 */
/* Derek Rodriguez */
/* U37516832 */
/*****************************************************************/ 
#include <stdio.h>
void read_numbers(double *r1, double *i1, double *r2, double *i2);
void add(double r1, double i1, double r2, double i2, double *r3, double *i3);
void subtract(double r1, double i1, double r2, double i2, double *r3, double *i3);
void multiply(double r1, double i1, double r2, double i2, double *r3, double *i3);
void print_complex(double r3, double i3); 

int main(void)
{
	double r1, r2, r3, i1, i2, i3;
	int option;
	
	printf("Complex Number Arithmetic Program: \n\n");
	for(;;)
	{
		printf("1. Add two complex numbers\n");
		printf("2. Subtract two complex numbers\n");
		printf("3. Multiply two complex numbers\n");
		printf("4. Quit\n\n");

		printf("Choose an option (1 - 4): ");
		scanf("%d", &option);
		switch(option){
			case 1:
				read_numbers(&r1, &i1, &r2, &i2);
				add(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 2:
				read_numbers(&r1, &i1, &r2, &i2);
				subtract(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 3:
				read_numbers(&r1, &i1, &r2, &i2);
				multiply(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 4:
				return 0;
			default:
				printf("Invalid option. Choose an option (1-4):\n");

		}
	}

	return 0;
}

void read_numbers(double *r1, double *i1, double *r2, double *i2)
{
    /* Read in the user input numbers for the real and imaginary sets */
    printf("Enter the real component for the first number:\n");
    scanf("%lf", r1);
    printf("Enter the imaginary component for the first number:\n");
    scanf("%lf", i1);
    printf("Enter the real component for the second number:\n");
    scanf("%lf", r2);
    printf("Enter the imaginary component for the second number:\n");
    scanf("%lf", i2);


}
void add(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
    /* Add the two real numbers and add the two imaginary numbers */
    *r3 = r1 + r2;
    *i3 = i1 + i2;

}
void subtract(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
    /* Subtract the two real numbers and subtract the two imaginary numbers */
    *r3 = r1 - r2;
    *i3 = i1 - i2;

}
void multiply(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
    /* Multiply the two real subtracted from the two imaginary multiplied */
    *r3 = (r1 * r2) - (i1 * i2);
    /* The sum of i1 * r2 and i2 * r1 */
    *i3 = (i1 * r2) + (i2 * r1);

}
void print_complex(double r3, double i3)
{
	if(i3 >= 0)
		printf("The operation yields %.3f + %.3fi\n\n", r3, i3);
	else
		
		printf("The operation yields %.3f  %.3fi\n\n", r3, i3);
}


