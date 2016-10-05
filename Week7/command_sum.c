//
//  command_sum.c
//  
//
//  Created by Derek Rodriguez on 10/5/16.
//
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int i;
    int num = 0;
    for (i = 1; i < argc; i++) {
     
        num += atoi(argv[i]);
        
        
    }
 
    printf("%d is the sum. \n", num);
    
    return 0;
    
}
