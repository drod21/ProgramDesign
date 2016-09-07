/* 
 * Derek Rodriguez
 * U37516832
 * 9/6/2016
 *
 * Asks user to enter two fractions separated by an operator and calculate the
 * result. Allows addition, subtraction, multiplication, divison by entering
 * +, -, *, or / between the fractions.
 *
 */

#include <stdio.h>


int main() {
    
    int num1, num2, denom1, denom2, result_num, result_denom;
    char operator;
    
    printf("Enter two fraction separated by a +, -. *. or / sign: \n");
    scanf("%d / %d %c %d / %d", &num1, &denom1, &operator, &num2, &denom2);
    
    /* Switch-Case statement for *, +, -, / operations, and default case for
     * invalid operation.
     */
    switch (operator) {
        case '*':
            result_num = num1 * num2; // Multiply both numerators
            result_denom = denom1 * denom2; // Multiply both denominators
            printf("The result is: %d/%d\n", result_num, result_denom);
            break;
        
        case '+':
            // Cross multiply and add
            result_num = (num1 * denom2) + (denom1 * num2);
            // Multiply both denominators
            result_denom = denom1 * denom2;
            printf("The sum is: %d/%d\n", result_num, result_denom);
            break;
            
        case '-':
            // Cross multiply and subtract
            result_num = (num1 * denom2) - (denom1 * num2);
            // Multiply both denominators
            result_denom = denom1 * denom2;
            printf("The difference is: %d/%d\n", result_num, result_denom);
            break;
            
        case '/':
            // Cross multiply
            result_num = (num1 * denom2);
            result_denom = (num2 * denom1);
            printf("The quotient is: %d/%d\n", result_num, result_denom);
            break;
            
        default:
            // Case for unrecognized operator
            printf("Unrecognized operator: %c \n", operator);
            break;
    }
    
    return 0;
    
}