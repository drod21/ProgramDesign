#include <stdio.h>
#define MAX_LEN 1000
int main(void) {

    char str[MAX_LEN];

    FILE *pFile;

    pFile = fopen("test.txt", "r");

    if (pFile == NULL) {
    printf("Error opening file\n");
    return 1;
    }

    while (fgets(str, MAX_LEN, pFile) != NULL) {
	printf("%s", str);
    }
    
    fclose(pFile);
    return 0;
}
