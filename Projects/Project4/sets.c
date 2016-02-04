//
//  sets.c
//
//
//  Created by Derek Rodriguez on 2/1/16.
//
//

#include <stdio.h>
#define SIZE 10

int main(void) {
    
    int set_A[SIZE], set_B[SIZE], union_array[SIZE], intersection_array[SIZE];
    int i = 0, f = 0, k = 0, j = 0, elem_A, elem_B;
    
    printf("Please enter the number of elements in the first set:\n");
    scanf("%d", &elem_A);
    printf("Please enter the numbers in the first set:\n");
    for (i = 0; i < elem_A; i++) {
        scanf("%d", &set_A[i]);
    }
    printf("Please enter the number of elements in the second set:\n");
    scanf("%d", &elem_B);
    
    printf("Please enter the numbers in the second set:\n");
    for (i = 0; i < elem_B; i++) {
        scanf("%d", &set_B[i]);
    }
   //union
    
    for (i = 0; i < elem_A; i++) {
        if (i < elem_A) {
        union_array[k] = set_A[i];
        k++;
    }
    }
    
    for (i = 0; i < elem_A; i++) {
        for (j = 0; j < elem_B; j++) {
            if (set_B[i] == union_array[j]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            if (i < elem_B) {
            union_array[k] = set_B[i];
            k++;
            }
        }
    }
    printf("The union of the two sets is: { ");
    for (i = 0; i < k; i++) {
        printf(" %d", union_array[i]);
    }
    printf(" }\n");
    
    // intersection
    
    for (j = 0; j < elem_A; j++) {
        for (i = 1; i < elem_B; i++) {
            if (set_B[i] == set_A[j])
                break;
        }
        if (i != elem_B) {
            intersection_array[k] = set_B[i];
            printf("%d",intersection_array[k]);
            k++;
        }
    }
    
    printf("The intersection of the two sets is: { ");
    for (i = 0; i < k; i++) {
        printf(" %d", intersection_array[i]);
    }
    printf(" }\n");
    return 0;

}