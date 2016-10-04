/* 
 * Sort its command-line arguments of 10 numbers, which are assumed to be integers. 
 * The first command-line argument indicate whether the sorting is in 
 * Descending order (-d) or ascending order (-a),
 *
 * Derek Rodriguez
 * 10/3/2016
 * U37516832
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(int a[], int n);
void sort_descending(int a[], int n);
int main(int argc, char *argv[]) {
    
    /* Checks for command line args <= 1 (no -a/-d nor values provided),
     *if no args, return error message and exit the program */
    if (argc <= 1) {
        printf("Invalid option. -a for ascending order or -d for descending\n");
        printf("number followed by ten numbers.\n");
        return 0;
    }
    
    int i;
    int num[argc];
    char *argv1 = argv[1];
    char *desc = "-d";
    char *asc = "-a";
    
    // Check that the number of arguments matches.
    if (argc == 12) {
    
        if (strcmp(argv1, asc) == 0) { //Check that argv is -a
        
            for (i = 2; i < argc; i++) {
            // Convert argv at each element after program name, arg option, to integer format
                num[i] = atoi(argv[i]);
            
            }
            printf("In ascending order: ");
            selection_sort(num, argc); // Sort in ascending order
        
    
        } else if (strcmp(argv1, desc) == 0) { ////Check that argv is -d
        
            for (i = 2; i < argc; i++) {
            // Convert argv at each element after program name, arg option, to integer format
                num[i] = atoi(argv[i]);
            
            }
        
            printf("In descending order: ");
        
            sort_descending(num, argc); // Sort in descending order
    
        } else {
        
            printf("Invalid option for sorting. \n");
            return 0;
        
        }

        for (i = 2; i < argc; i++) {
        
            printf("%d ", num[i]);
        
        }
    
        printf("\n");

    } else {
        // Error message for too few arguments
        printf("Invalid number of arguments. \n");
        return 0;
        
    }
    
    return 0;
    
}

void selection_sort(int a[], int n) {
    
    int i, largest = 2, temp;
    /* Selection sort to order in ascending order (smallest to largest) */
    if (n == 1)
        return;
    
    for (i = 2; i < n; i++)
        if (a[i] > a[largest])
            largest = i;
    
    if (largest < n - 1) {
        temp = a[n-1];
        a[n-1] = a[largest];
        a[largest] = temp;
    }
    
    selection_sort(a, n - 1);
    
}

void sort_descending(int a[], int n) {
    
    int i, smallest = 2, temp;
    /* Selection sort, modified to order in descending order (largest to smallest) */
    if (n == 1)
        return;
    
    for (i = n - 1; i > 2; i--)
        if (a[i] < a[smallest])
            smallest = i;
    
    if (smallest < n - 1) {
        temp = a[n-1];
        a[n-1] = a[smallest];
        a[smallest] = temp;
    }
    
    sort_descending(a, n - 1);
}
