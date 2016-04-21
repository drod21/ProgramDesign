/* Derek Rodriguez
 * U37516832
 * 4/21/16
 * sorts a series of words as command-line arguments
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_comp(const void *p, const void *q);

int main(int argc, char *argv[]) {
    int i = 0;
    
    /* Checks for command line args <= 1,
     *if no args, return error message and exit the program */
    if (argc <= 1) {
        printf("Invalid option.\n");
        return 0;
    }
    
    /* Sort the arguments with qsort */
    qsort(argv, argc, sizeof(*argv), str_comp);
    
    for (i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    
    return 0;
}

int str_comp(const void *p, const void *q) {
    /* Use strcmp to compare the strings */
    return strcmp(*(char **)p, *(char **)q);
}