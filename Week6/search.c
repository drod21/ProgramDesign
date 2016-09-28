//
//  search.c
//  
//
//  Created by Derek Rodriguez on 9/28/16.
//
//

#include <stdio.h>

int search(int *a, int n, int key);


#define N 10
int main() {
    int arr[N] = {3, 12, 31, 42, 52,12, 49, 53,64,96};
    int value;
    
    printf("enter the value: ");
    scanf("%d", &value);
    
    int result = search(arr, N, value);
    
    if(result) {
        
        printf("found\n");
        
    } else {
        
        printf("not found\n");
        
    }
    
    return 0;
}

int search(int *a, int n, int key) {
    
    int *p, flag = 0;
    
    for (p = a; *p != '\0'; p++) {
        
        if (*p == key) {
            
            flag = 1;
            break;
            
        } else {
            
            flag = 0;
            
        }
        
    }
    
    return flag;
    
    
}
