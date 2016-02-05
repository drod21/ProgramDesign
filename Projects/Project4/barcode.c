/*   
 ** Derek Rodriguez
 ** 2/5/2016
 ** U37516832
 ** This program detects edges of light and dark regions of a barcode.
 ** Processes input bit pattern, assigns 1 to output bit when:
 ** 1 = two consecutive bits are different, 0 = the same
 ** 0 for the first output bit (no previous bit)
 **
  */

#include <stdio.h>

#define SIZE 8
void edge(int n, int a1[], int a2[]); /* Edge Function */

int main(void) {
    int arr1[SIZE], arr2[SIZE];  /* Declare variables */
    int i;
    char c;
    
    printf("Enter the 8-bit barcode: \n");
    for (i = 0; i < SIZE; i++) {
        scanf("%c", &c);
        if (c == '1') {     // If condition during scanf to automatically
            arr1[i] = 1;    // store 0's and 1's to the array
        } else {
            arr1[i] = 0;
    }
    }
    
    edge(SIZE, arr1, arr2); /* Function call for edge detection */
    for (i = 0; i < SIZE; i++) {
        printf("%d", arr2[i]);
    }
    printf("\n");
    
    return 0;
}

void edge(int n, int a1[], int a2[]) {
    a2[0] = 0;
    int previous = a1[0];
    int i;
    
    /* For loop to check the previous bit and store into array */
    for(i = 1; i < n; i++) {
        if(previous == a1[i]){
            a2[i] = 0;
        } else {
            a2[i] = 1;
        }
        previous = a1[i];
        
    }
}
