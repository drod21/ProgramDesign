//
//  duplicate.c
//  
//
//  Created by Derek Rodriguez on 10/27/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *s);

int main() {
    
    char *str = "This will be duplicated";
    char *p;
    
    printf("Current string: %s \n", str);
    
    p = duplicate(str);
 
    printf("Copied string: %s \n", p);
    
    
    return 0;
    
}

char *duplicate(char *s) {
    
    char *p;
    
    p = (char *) malloc(sizeof(s) + 1);
    
    strcpy(p, s);
    
    return p;
    
    
}
