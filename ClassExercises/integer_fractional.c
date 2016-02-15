#include <stdio.h>

void decompose(double x, int *int_part, double *frac_part);

int main(void)
{
    double number;
    int int_num;
    double frac_num;
    printf("enter a floating point number: \n");
    scanf("%lf", &number);
    
    decompose(number, &int_num, &frac_num);

    printf("the integer part is %d\n", int_num);
    printf("the fractional part is %lf\n", frac_num);

   return 0;
}


void decompose(double x, int *int_part, double *frac_part)
{
   *int_part = (int) x;
   *frac_part = x - *int_part;
}

