/* 
 * The program reads the content of the file and shifts the content by the shift
 * amount, then writes the shifted message to a file with the same name but an
 * added extension of .sft.
 *
 * Derek Rodriguez
 * 10/19/2016
 * U37516832
 */

#include <stdio.h>
#include <string.h>

#define LEN 10000
#define file_name 100

void shift(char *message, int shift_amount);

int main() {
    
    FILE *in_file, *out_file;
    char input_file[file_name];
    char output_file[file_name];
    char message[LEN];
    
    int n;
    
    printf("Please enter the file name: \n");
    scanf("%s", input_file);
    /* Write the in file name to out file name, and add .sft to end */
    snprintf(output_file, file_name, "%s.sft", input_file);
    
    printf("Please enter a shift amount: \n");
    scanf("%d", &n);
    
    /* Open input and output files */
    in_file = fopen(input_file, "r");
    out_file = fopen(output_file, "w");
    
    /* Check if input file is empty or Does Not Exist,
     * If null, return error and exit 
     */
    
    if (in_file == NULL) {
        
        printf("File doesn't exist \n");
        return 1;
        
    } else {
        
        /* Loop to end of file, perform shift, output to out_file */
        while (!feof(in_file) && !ferror(in_file)) {
            
            if (fgets(message, sizeof(message), in_file) != '\0') {
                
                shift(message, n);
                fputs(message, out_file);
                
            }
        }
        
    }
    
    fclose(in_file);
    fclose(out_file);
    
    return 0;
    
}

void shift(char *message, int shift_amount) {
    
/* The function expects message to point to a string containing the message to
 * be shifted; shift_amount represents the amount by which each letter in the
 * message to be shifted. Lower-case letters remain lower-case when shifted, and
 * upper-case remain upper-case.
 */
    
    /* Loop through message, check for lower case and upper case, 
     * perform shift
     */
    char *p;
    for (p = message; *p != '\0'; p++) {
        // Lower case check
        if (*p >= 'a' && *p <= 'z') {
            // Shift by shift amount
            *p = ((*p - 'a') + shift_amount) % 26 + 'a';
            // Upper case check
        } else if (*p >= 'A' && *p <= 'Z') {
            // Shift by shift amount
            *p = ((*p - 'A') + shift_amount) % 26 + 'A';
            
        }
        
    }
    
    // Store NULL character at end of message
    *p = '\0';
    
}
