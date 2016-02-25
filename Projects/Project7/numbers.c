//
//  command_line_args.c
//  
//
//  Created by Derek Rodriguez on 2/25/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int i;
    int min, max, num;
    char *argv1 = argv[1];
    char *SMALL = "-s";
    char *LARGE = "-l";
    min = max = 0;
    
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
        printf("Invalid option\n");
    }

        return 0;
}