//
//  reverse.c
//  echoes command line arguments in reverse order
//
//  Created by Derek Rodriguez on 9/19/16.
//
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;
    for (i = argc - 1; i > 0; i--) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
    
}
