//
//  extension.c
//  
//
//  Created by Derek Rodriguez on 3/2/16.
//
//

#include <stdio.h>
#include <string.h>
void get_extension(const char *file_name, char *extension);
#define STR_LEN 1000
int main()
{
    char file[STR_LEN + 1] = "test.txt";
    char ext[STR_LEN + 1];
    
    get_extension(file, ext);
    
    printf("Extension: %s\n", ext);
    
    return 0;
}

void get_extension(const char *file_name, char *extension) {
    extension = "";
    while(*file_name != '\0') {
        if(*file_name == '.') {
            extension = file_name + 1;
        }
        
        file_name++;
    }
    extension++;
}