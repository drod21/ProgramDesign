//
//  rowsums.c
//  
//
//  Created by Derek Rodriguez on 2/1/16.
//
//

#define N 3
#define M 2

#include <stdio.h>

int main(void) {
    int m[M][N] = {{9, 7, 4}, {20, 15, 3}};
    int row_total[M] = {0}, column_total[N] = {0};
    
    printf("Row total: ");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            row_total[i] += m[i][j];
        }
        printf(" %d ", row_total[i]);
    }
    printf("\n");
    
    printf("Column sum: ");
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            column_total[j] += m[i][j];
        }
        printf(" %d ", column_total[j]);
    }
    printf("\n");
    return 0;
}