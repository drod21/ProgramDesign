#include <stdio.h>
#define N 3
#define M 2
int main()
{

	int a[M][N]={{9, 7, 4}, {20, 15, 3}};
	int row, column, row_total[N] = {0}, column_total[N] = {0};

	 for(row = 0; row < M; row++)
        {
                for(column = 0; column< N; column++)
                {
                        row_total[row] += a[row][column];
                }
                printf("row total for row %d is %d \n", row, row_total[row]);
        }

	for(column=0; column<N; column ++)
	{
		for(row = 0; row <M; row++)
		{	
			column_total[column] += a[row][column];
		}	
		 printf("column total for column %d is %d\n", column, column_total[column]);

	}
	return 0;

/*
	for(row = 0; row < M; row++)
	{
		for(column = 0; column< N; column++)
		{
			printf("enter number for row %d , column %d:\n ", row, column);
			scanf("%d", &a[row][column]);
		}
	  
	}
*/

}
	
