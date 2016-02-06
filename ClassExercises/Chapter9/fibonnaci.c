//
//  fibonnaci.c
//  
//
//  Created by Derek Rodriguez on 2/3/16.
//
//

#include <stdio.h>

int find_largest (int a[], int n) {
    int i;
    int max_index = 0;
    
    for i=1; i < n; i++)
    if (a[i] > a[max_index])
        max_index = i;
    return max_index;
}

void selection_sort(int a[n], int n) {
    
}

int main(void) {
    int i;
    int a[N];
    
    printf("enter %d numbers:\n", N);
    for (i = 0;)
}