/* vector.c, project 5, Program Design
 * Multiplies and compares vectors
 *
 * Derek Rodriguez
 * U37516832
 * 9/25/16
 *
 */

#include <stdio.h>


void multi_vec(int *v1, int *v2, int *v3, int n);
int comp_vec(int *v1, int *v2, int n);

int main() {
    
    int len, i, compare;
    
    // Prompt user to input the length of the two vectors
    printf("Enter the length of two vectors: \n");
    
    scanf("%d", &len);
    
    // Initialize the vectors and have user enter the values of the vectors
    int v1[len], v2[len], v3[len];
    
    printf("Please enter the values for the first vector: \n");
    
    for (i = 0; i < len; i++) {
        
        scanf("%d", &v1[i]);
        
    }
    
    printf("Please enter the values for the second vector: \n");
    
    for (i = 0; i < len; i++) {
        
        scanf("%d", &v2[i]);
        
    }
    
    // Call multi_vec function to multiply, store result in v3 array
    printf("The multiplication of the vectors is: ");
    multi_vec(v1, v2, v3, len);
    for (i = 0; i < len; i++) {
        
        printf("%d ", v3[i]);
        
    }
    printf("\n");
    
    // Call comp_vec function to compare the elements of the two vectors
    compare = comp_vec(v1, v2, len);
    
    if (compare == 1) {
        printf("The vectors are the same. \n");
    } else if (compare == 0) {
        
        printf("The vectors are not the same. \n");
        
    }
    
    return 0;
    
}


void multi_vec(int *v1, int *v2, int *v3, int n) {
    
    int *p, *q;
    
    // Loop through v1 & v2, multiply the elements, store in v3 and increment v3
    for (p = v1, q = v2; p < v1 + n; p++, q++) {
        
        *v3 = *p * *q;
        v3++;
        
    }
    
    
    
}

int comp_vec(int *v1, int *v2, int n) {
    
    
    int *p, *q, flag = 0;
    
    // Loop through v1 & v2 to compare the elements
    for (p = v1, q = v2; p < v1 + n; p++, q++) {
    
        if (*p == *q) {
            
            flag = 1;
            
        } else {
            
            flag = 0;
            
        }
      
    }
    return flag;

}