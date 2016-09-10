//
//  addition.c
//  
//
//  Created by Derek Rodriguez on 9/10/16.
//
//

#include <stdio.h>

int add(int n, int m);

int main() {
    
    int num1, num2, result;
    
    printf("Please enter two numbers to add: \n");
    
    scanf("%d %d", &num1, &num2);
    
    result = add(num1, num2);
    
    printf("The addition is: %d.\n", result);
    
    return 0;
    
}

int add(int n, int m) {
    
    /* Add n and m using recursion */
    
    //If m is 0, n is the result
    if (m == 0) {
        
        return n;
    
      //  If m > 0, increment n and decrement m
    } else if (m > 0) {
        
        add(++n, --m);
        
        //If m < 0, decrement n and increment m
    } else if (m < 0) {
        
        add(--n, ++m);
    }
    
    return add(n, m);
}