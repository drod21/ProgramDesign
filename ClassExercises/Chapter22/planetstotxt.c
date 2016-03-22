//
//  planetstotxt.c
//  
//
//  Created by Derek Rodriguez on 3/21/16.
//
//

#include <stdio.h>

#define MAX_LEN 1000
int main(void) {
    
    char str[MAX_LEN];
    char *planets[] = {"Mercury", "Venus", "Earth",
        "Mars", "Jupiter", "Saturn",
        "Uranus", "Neptune", "Pluto"};
    FILE *pFile;
    int i;
    pFile = fopen("planets.txt", "w");
    
    if (pFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    for (i = 0; i < 9; i++) {
        fputs(planets[i], pFile);
        fputs("\n", pFile);
    }
    
    fclose(pFile);
    return 0;
}
