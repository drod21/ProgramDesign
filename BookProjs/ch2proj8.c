/* Write a program that calculates remaining balance on a loan after 
first, second, third monthly payments */

#include <stdio.h>

int main(void) {
    float loan, annual_interest, monthly_interest, monthly_payment, first_pay, second_pay, third_pay;
    float total_loan, x;
    printf("Enter amount of loan:\n");
    scanf("%f", &loan);
    printf("Enter interest rate:\n");
    scanf("%f", &annual_interest);
    printf("Enter monthly payment:\n");
    scanf("%f", &monthly_payment);
    
    monthly_interest = loan * ((annual_interest / 100) / 12);
    total_loan = loan + monthly_interest;
    
    first_pay = total_loan - monthly_payment;
    
    monthly_interest = first_pay * ((annual_interest / 100) / 12);
    total_loan = first_pay + monthly_interest;
    second_pay = total_loan - monthly_payment;
    monthly_interest = second_pay * ((annual_interest / 100) / 12);
    total_loan = second_pay + monthly_interest;
    third_pay = total_loan - monthly_payment;
    
    
    printf("Remaining after first payment: %.2f\n", first_pay);
    printf("Remaining after first payment: %.2f\n", second_pay);
    printf("Remaining after first payment: %.2f\n", third_pay);


    return 0;
}
