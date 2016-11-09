#include <stdio.h>
#define MAX_LEN 1000

int main(int argc, char *argv[]) {
    char str[MAX_LEN];
    FILE *pFile;

    if (argc != 2) {
        
        printf("Usage: ./a.out filename\n");
        return 1;
        
    }

    if ((pFile = fopen(argv[1], "r")) == NULL) {
        
        printf ("%s can't be opened\n", argv[1]);
        return 1;
        
    } else {

        while (fgets(str, MAX_LEN, pFile) != NULL) {
            
            printf("%s", str);
            
        }
    
    }
    
    fclose(pFile);
    return 0;
    
}

