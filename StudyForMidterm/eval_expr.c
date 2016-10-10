//
//  eval_expr.c
//  
//
//  Created by Derek Rodriguez on 10/10/16.
//
//

#include <stdio.h>


int main() {
    
    float num1, num2, num3;
    float result;
    
    char op1, op2;
    
    
    printf("Please enter an expression: \n");
    
    scanf("%f %c %f %c %f", &num1, &op1, &num2, &op2, &num3);
    
    
    if (op1 == '+') {
        
        num1 += num2;
            
    } else if (op1 == '-') {
            
        num1 -= num2;
            
    } else if (op1 == '*') {
            
        num1 *= num2;
            
    } else if (op1 == '/') {
            
        if (num2 == 0) {
                
            printf("Number not divisible by zero. \n");
                
        } else {
            
            num1 /= num2;
            
        }
            
    }
    
    result = num1;
    
    if (op2 == '+') {
        
        result += num3;
        
    } else if (op2 == '-') {
        
        result -= num3;
        
    } else if (op2 == '*') {
        
        result *= num3;
        
    } else if (op2 == '/') {
        
        if (num3 == 0) {
            
            printf("Number not divisible by zero. \n");
            
        } else {
            
            result /= num3;
            
        }
    }
    
    
    
    printf ("%.1f \n", result);


    return 0;
    
}
