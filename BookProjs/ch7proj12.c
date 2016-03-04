//
//  ch7proj12.c
//  
// Evaluates user input expressions
//  Created by Derek Rodriguez on 3/4/16.
//
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char ch, c;
    float n, num = 0;
    
    printf("Enter an expression:\n");
    scanf("%f%c%f", &num, &ch, &n);
    /* If conditions to check for +, -, *, /, and not / by 0
     * Does first half of operation (user input 1 + 2 + 3, only evaulates
     * 1 + 2)
     */
    if (ch == '+')
        num = num + n;
    if (ch == '-')
        num = num - n;
    if (ch == '*')
        num = num * n;
    if (ch == '/')
        num = num / n;
    if (n == 0) {
        printf("Division by zero occured.\n");
        return 0;
    }
    /*Do while loop for second half of operation
     * (User input 1 + 2 + 3, evaluates 3 + result of 1 + 2)
     */
    do {
        scanf("%c%f%c", &ch, &n, &c);
        if (ch == '+')
            num = num + n;
        if (ch == '-')
            num = num - n;
        if (ch == '*')
            num = num * n;
        if (ch == '/')
            num = num / n;
    }
    while (c != '\n');
    printf("Result: %.1f\n",num);
    return 0;
}
