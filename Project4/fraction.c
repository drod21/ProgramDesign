/*fraction_math.c for Project 5
 * Program Design
 *
 * Derek Rodriguez
 * U37516832
 * 9/19/16
 *
 */

#include <stdio.h>
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
int find_gcd(int m, int n);

int main(void) {
  int num1, denom1, num2, denom2, result_num, result_denom;
  char operator;

  printf("Enter two fractions separated by a +, -, * or / sign: \n");
  scanf("%d/%d %c%d/%d", &num1, &denom1, &operator, &num2, &denom2);

    // Add calls to reduce fractions after each computation

  switch (operator) {
          
    case '+':
          result_num = num1 * denom2 + num2 * denom1;
          result_denom = denom1 * denom2;
          reduce(result_num, result_denom, &result_num, &result_denom);
          printf("The sum is %d/%d\n", result_num, result_denom);
          break;
          
    case '-':
          result_num = num1 * denom2 - num2 * denom1;
          result_denom = denom1 * denom2;
          reduce(result_num, result_denom, &result_num, &result_denom);
          printf("The difference is %d/%d\n", result_num, result_denom);
          break;
          
    case '*':
          result_num = num1 * num2;
          result_denom = denom1 * denom2;
          reduce(result_num, result_denom, &result_num, &result_denom);
          printf("The product is %d/%d\n", result_num, result_denom);
          break;
          
    case '/':
          result_num = num1 * denom2;
          result_denom = denom1 * num2;
          reduce(result_num, result_denom, &result_num, &result_denom);
          printf("The quotient is %d/%d\n", result_num, result_denom);
          break;
          
    default:
          printf("Unrecognized operator: %c\n", operator);
          
  }

  return 0;

}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    
    int gcd;
    
    // Call find_gcd, then divide numerator and denominator by GCD
    gcd = find_gcd(numerator, denominator);
    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
    
}

int find_gcd(int m, int n) {
    
    // Find GCD of the fraction
    if (n == 0)
        return m;
    return find_gcd(n, m % n);
    
}