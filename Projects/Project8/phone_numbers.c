/* Translates seven-letter words in a file *
 * to their corresponding phone numbers *
 * Derek Rodriguez *
 * U37516832 *
 */

 
void translate(char *word, char *phone_number);


#include <stdio.h>
#define n 30


int main() {
    FILE *in_File,*out_File;
    char word[8];
    char input_File[n];  /* Read in file name */
    char output_File[n];  /* Write out file name */
    char phone_number[8];

    
    printf("Please enter the file name:\n");
    scanf("%s", input_File);
    /* Add the .cvt extension to the user input file name */
    snprintf(output_File, n, "%s.cvt", input_File);
    printf("Output file name: %s\n", output_File);
    
    in_File = fopen(input_File, "r");
    out_File = fopen(output_File, "w");
    
    
    if (in_File == NULL) {
        printf("File doesn't exist\n");
    } else {
        while (!feof(in_File) && !ferror(in_File)) {
            if (fscanf(in_File, "%s",word) == 1) {
            //function calling for translate word to phone number
            translate(word, phone_number);
            fprintf(out_File,"%s\n", phone_number);
            }
        }
    }
    
    fclose(in_File);
    fclose(out_File);
    
    return 0;
}

void translate(char *word, char *phone_number) {
    int i = 0;
    char *q = NULL;
    
    /* For loop to iterate through each letter */
    for (i = 0; word[i] != '\0'; i++) {
        /* Switch statement to change each letter to the corresponding number */
        switch (word[i]) {
            case 'A':
            case 'B':
            case 'C':
                q = "2";
                break;
            case 'D':
            case 'E':
            case 'F':
                q = "3";
                break;
            case 'G':
            case 'H':
            case 'I':
                q = "4";
                break;
            case 'J':
            case 'K':
            case 'L':
                q = "5";
                break;
            case 'M':
            case 'N':
            case 'O':
                q = "6";
                break;
            case 'P':
            case 'R':
            case 'S':
                q = "7";
                break;
            case 'T':
            case 'U':
            case 'V':
                q = "8";
                break;
            case 'W':
            case 'X':
            case 'Y':
                q = "9";
                break;
            default:
                break;
        }
        /* Set phone_number equal to q, and increase phone_number */
        *phone_number++= *q;
    }
    
    *phone_number = '\0';
}

