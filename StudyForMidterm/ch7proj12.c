//
//  ch7proj12.c
//  
//
//  Created by Derek Rodriguez on 8/28/16.
//
//

#include <stdio.h>
#include <string.h>

int main(void) {
    
    char ch, c = '\0';
    float n, num = 0;
    printf("Please enter an expression\n");       
    scanf("%f%c%f", &num, &ch, &n);
    
    if (ch == '+') {
        num = num + n;
    }
    if (ch == '-') {
        num = num - n;
    }
    if (ch == '*') {
        num = num * n;
    }
    if (ch == '/') {
        if (n == 0) {
            printf("Division by zero not allowed\n");
            return 0;
        } else {
        num = num / n;
        }
    }
    
    while (c != '\n') {
        scanf("%c%f%c", &ch, &n, &c);
        if (ch == '+') {
            num = num + n;
        }
        if (ch == '-') {
            num = num - n;
        }
        if (ch == '*') {
            num = num * n;
        }
        if (ch == '/') {
                num = num / n;
        }
        
    }
    printf("Result: %.1f\n", num);
    
    
    return 0;
}