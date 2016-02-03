//
//  sets.c
//  
//
//  Created by Derek Rodriguez on 2/1/16.
//
//

#include <stdio.h>
#define M 10
#define N 10

int main(void) {
    
    int a[M], b[N], f = 0, i, k = 0, j, m, n;
    
    printf("Please enter the number of elements in the first set:\n");
    scanf("%d",&m);
    int arr1[m];
    printf("Please enter the numbers in the first set:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    printf("Please enter the number of elements in the second set:\n");
    scanf("%d",&n);
    int arr2[n];
    printf("Please enter the numbers in the second set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    for (i = 0; i < m; i++) {
        arr1[f] = a[i];
        f++;
    }
    
    for (i = 0; i < m; i++) {
        k = 0;
        for (j = 0; j < n; j++) {
            if (b[i] == arr1[j]) {
                k = 1;
                break;
            }
        }
        if (k == 0) {
            arr1[f] = b[i];
            f++;
        }
    }
    
    printf("The union of set A and B is:{");
    
    for (i = 0; i < f; i++) {
        printf(" %d,", arr1[i]);
    }
    printf("}\n");
    
    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
        if (b[i] == a[j])
            break;
    }
    if (i != n) {
        arr2[k] = b[i];
        k++;
    }
    }
    
    printf("The intersection of set A and B is: {");
    for (i = 0; i < k; i++)
        printf(" %d", arr2[i]);
    printf("}\n");
    
    return 0;
}