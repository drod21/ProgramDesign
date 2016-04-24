//
//  stacktest.c
//  
//
//  Created by Derek Rodriguez on 4/21/16.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 100

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
    char brackets[STACK_SIZE];
    int i = 0;
    char leave;
    bool not_parantheses = false, match = true;
    
    printf("Please enter a set of nested paranthese or brackets\n");
    gets(brackets);
    make_empty();
    
    for (i = 0; i < STACK_SIZE; i++) {
        if (brackets[i] == '{' || brackets[i] == '[' || brackets[i] == '(') {
            push(brackets[i]);
        } else if (brackets[i] == '}' || brackets[i] == ']' || brackets[i] == ')') {
            leave = pop();
            if ((brackets[i] == '}' && leave == '{') || (brackets[i] == ']' && leave == '[') || (brackets[i] == ')' && leave == '(')) {
                match = true;
                continue;
            } else {
                match = false;
                push(leave);
                break;
            }
        } else {
            not_parantheses = true;
        }
    }
    if (!not_parantheses)
        printf("Invalid input\n");
    else if (is_empty())
        printf("Nested properly\n");
    else if (!match)
        printf("Not matching\n");
    else
        printf("Not nested properly\n");
    return 0;
}

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void make_empty(void) {
    top = 0;
}
bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(char i) {
    if (is_full()) {
        stack_overflow();
    } else {
        contents[top++] = i;
    }
}
char pop(void) {
    if (is_empty()) {
        stack_overflow();
    } else {
        return contents[--top];
    }
}
void stack_overflow(void) {
    printf("Stack overflow\n");
    exit(1);
}

void stack_underflow(void) {
    printf("Stack underflow\n");
    exit(2);
}

