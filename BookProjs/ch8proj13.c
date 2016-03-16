//
//  ch8proj13.c
//  
//
//  Created by Derek Rodriguez on 3/4/16.
//
//

#include <stdio.h>
#include <string.h>

#define STR_LEN 30

int main(void) {
    char first[STR_LEN], last[STR_LEN];
    char save[100][20];
    int count = 0, count2, count3;
    
    printf("Enter first and last name: \n");
    while (scanf("%s %s", &first, &last) != EOF) {
        count3 = strlen(last);
        for (count2 = 0; count2 < count3; count2++) {
            save[count][count2] = last[count2];
        }
        printf("Name: %s, %c. \n", last, first[0]);
        count++;
        return 0;
    }
    return 0;
}