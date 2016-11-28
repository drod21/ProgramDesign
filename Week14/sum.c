#include <stdio.h>

int sum (int (*f) (int), int start, int end);
int fact(int n);
int square(int n);
int cube(int n);

int main()
{
	int start, end;
	printf("Enter start value: ");	
	scanf("%d", &start);
	printf("Enter end value: ");
	scanf("%d", &end);
	
	//display the sum of factorials, the sum of squares, 
	//and the sum of cubes from start to end


    int factorial = sum(fact, start, end);
    int sq = sum(square, start, end);
    int cubed = sum(cube, start, end);
    
    printf("Sum: %d\n", factorial);
    printf("Sum of squares: %d \n", sq);
    printf("Sum of cubes: %d \n", cubed);


	return 0;
}

int sum (int (*f) (int), int start, int end)
{
    
    int i, sum = 0;

    for (i = start; i <= end; i++) {
        
        sum += f(i);
        
    }
    
    return sum;

}

int fact(int n)
{
    
    if (n == 1) {
        
        return 1;
        
    } else {
        
        return (n * fact(n - 1));
        
    }

}

int square(int n)
{
    
    return n * n;
    
}

int cube(int n)
{
    
    return n * n * n;
    
}
