//
//  sort_commands.c
//  
//
//  Created by Derek Rodriguez on 4/20/16.
//
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* Checks for command line args <= 1,
     *if no args, return error message and exit the program */
    if (argc <= 1) {
        printf("Invalid option. -l for largest number or -s for smallest\n");
        printf("number followed by ten numbers.\n");
        return 0;
    }



    return 0;
}