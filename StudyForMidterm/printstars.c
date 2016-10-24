//
//  printstars.c
//  
//
//  Created by Derek Rodriguez on 10/16/16.
//
//

#include <stdio.h>

int printstars(int n);

int main() {
    
    int i, j, sum = 0;
    
    for (i = 0; i < 3; i++) {
        
        for (j = 0; j < 4; j++) {
            
            if (j == 1 || j == 2)
                continue;
            
            sum++;
            
        }
        
    }
    printf("%d\n", sum);
    
    return 0;
    
    
}

int printstars(int n) {
    
    int i;
    
    if (n == 0) {
        
        return 1;
        
    } else {
        printstars(n - 1);
        for (i = 0; i <= n; i++) {
            
            printf("%c", '*');
        }
        printf("\n");
    }
    
    
}
