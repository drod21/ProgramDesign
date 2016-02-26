/* This program uses command line arguments -l or -s followed by ten numbers to calculate the largest
 * or smallest value present *
 * Derek Rodriguez *
 * U37516832 *
 * 2/25/16 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /* Checks for command line args <= 1 (no -l/-s nor values provided),
     *if no args, return error message */
    if (argc <= 1) {
        printf("Invalid option. -l for largest number or -s for smallest\n");
        printf("number followed by ten numbers.\n");
        return 0;
    }

    int i;
    int min, max, num;
    char *argv1 = argv[1];
    char *SMALL = "-s";
    char *LARGE = "-l";
    min = max = 0;
    
    /* String comparison for -s arg, and loop to find the smallest number */
    if (strcmp(argv1, SMALL) == 0) {
        for (i = 2; i < argc; i++) {
            num = atoi(argv[i]);
            if(i == 2) {
                min = num;
            } else if(min > num) {
                min = num;
            }
        }
        printf("The smallest number is %d\n",min);
        
        /*String Comparison for -l arg, then loop to find the largest number */
    } else if (strcmp(argv1, LARGE) == 0) {
        for (i = 2; i < argc; i++) {
            num = atoi(argv[i]);
            if(i == 2) {
                max = num;
            } else if(max < num) {
                max = num;
            }
        }
        printf("The largest number is %d\n",max);
    } else {
        printf("Invalid option\n"); /* Prints error message and exits if -l or -s are not provided */
        return 0;
    }

        return 0;
}