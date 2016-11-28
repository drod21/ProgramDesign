//
//  phonenumbers.c
//  
//
//  Created by Derek Rodriguez on 11/26/16.
//
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    
    
    FILE *fp;
    char *file = "numbers.txt";
    int area_code, first_three, last_four, ch;
    fp = fopen(file, "r");
    char str[31];
    int i = 0, count = 0;
    
    if (fp == NULL) {
        
        printf("File DNE \n");
        return 0;
        
    } else {
        while (!feof(fp)) {
            while ((ch = getc(fp)) != '\n')
            if (isdigit(ch)) {
                str[i++] = ch;
                count++;
            }
            str[i] = '\0';
            i = 0;
            sscanf(str, "%3d%3d%4d", &area_code, &first_three, &last_four);
            printf("(%3d) %3d-%4d\n", area_code, first_three, last_four);
            
        }
    }
    
    fclose(fp);
    return 0;
}
