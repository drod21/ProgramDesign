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
    
    int set_A[SIZE] = {}, set_B[SIZE] = {}, union_array[SIZE] = {}, intersection_array[SIZE] = {};
    int i = 0, a, b, elem_A, elem_B;
    
    printf("Please enter the number of elements in the first set:\n");
    scanf("%d", &elem_A);
    printf("Please enter the numbers in the first set:\n");
    for (i = 0; i < elem_A; i++) {
        scanf("%d", &a);
        
        set_A[a] = 1;
    }
    
    printf("Please enter the number of elements in the second set:\n");
    scanf("%d", &elem_B);
    
    printf("Please enter the numbers in the second set:\n");
    for (i = 0; i < elem_B; i++) {
        scanf("%d", &b);
        
        set_B[b] = 1;
    }
    
    //union
    for (i = 0; i < SIZE; i++) {
        if(set_A[i] == 1 || set_B[i] == 1) {
            union_array[i] = 1;
        }
    }
    
    printf("The union of the two sets is: { ");
    for (i = 0; i < SIZE; i++) {
        if(union_array[i] == 1) {
            printf(" %d", i);
        }
    }
    
    printf(" }\n");
    
    // intersection
    for (i = 0; i < SIZE; i++) {
        if(set_A[i] == 1 && set_B[i] == 1) {
            intersection_array[i] = 1;
        }
    }
    
    printf("The intersection of the two sets is: { ");
    for (i = 0; i < SIZE; i++) {
        if(intersection_array[i] == 1) {
            printf(" %d", i);
        }
    }
    printf(" }\n");
    
    return 0;
}