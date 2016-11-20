/* Sorts a series of words as command-line arguments. 
 *
 * Derek Rodriguez
 * U37516832
 * 11/16/16
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_cmp(const void *p, const void *q);

int main(int argc, char *argv[]) {
    
    int i = 0;
    
    /* Checks for command line args <= 1,
     *if no args, return error message and exit the program */
    if (argc <= 1) {
        printf("Invalid option.\n");
        return 0;
    }
    
    qsort(argv, argc, sizeof(*argv), str_cmp);
    
    for (i = 1; i < argc; i++) {
        
        printf("%s ", argv[i]);
        
    }
    
    printf("\n");
    
    return 0;
    
}

int str_cmp(const void *p, const void *q) {
    
    return strcmp(*((char **) p), *((char **) q));
    
}
