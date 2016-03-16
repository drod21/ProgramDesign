//
//  phonenum.c
//  
//
//  Created by Derek Rodriguez on 3/9/16.
//
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char num[15];
    printf("enter telephone number\n");
    scanf("%s", num);
    char *check;
    check = strtok(num, "()-");
    printf("Area code: %s\n", check);
    check = strtok(NULL, "()-");
    printf("First three digits: %s\n", check);
    check = strtok(NULL, "()-");
    printf("Last four digits: %s\n", check);
    
    return 0;
    
}
