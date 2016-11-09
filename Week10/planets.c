//
//  planets.c
//  
//
//  Created by Derek Rodriguez on 10/24/16.
//
//

#include <stdio.h>


int main() {
    
    int i;
    char *planets[] = {"Mercury", "Venus", "Earth",
                        "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptune", "Pluto"};
    
    FILE *pFile;
    
    pFile = fopen("planets.txt", "w");
    
    if (pFile == NULL) {
        
        printf("Error opening file. \n");
        return 1;
        
    }
    
    for (i = 0; i < 9; i++) {
        fputs(planets[i], pFile);
        fputs("\n", pFile);
    }
    
    fclose(pFile);
    printf("File planets.txt written. \n");
    
    return 0;
    
}
