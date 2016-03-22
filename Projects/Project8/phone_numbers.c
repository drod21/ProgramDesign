//
//  phone_numbers.c
//  
//
//  Created by Derek Rodriguez on 3/21/16.
//
//
#define MAX_LEN 7
void translate(char *word, char *phone_number);


#include <stdio.h>


int main() {
    char *fileName = "phone_list.txt"; /* File Name */
    char *out_File = "phone_list.txt.cvt"; /*Output File Name */
    FILE *numbers = fopen(fileName, "r");
    FILE *output = fopen(out_File, "r+w");
    
    
    
    return 0;
}

void translate(char *word, char *phone_number) {
    
}