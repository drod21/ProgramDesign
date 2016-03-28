#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LEN 1000
void selection_sort(int a[], int n);
int find_largest(int a[], int n);


int main(int argc, char *argv[])
{
    char str[MAX_LEN];
    FILE* pFile;
    int a[MAX_LEN];
    int num;
    int count = 0;

    if (argc != 2) {
        printf("usage: cannot open file\n");
        exit(EXIT_FAILURE);
    }
    
    if ((pFile = fopen(argv[1], "r")) == NULL) {
        printf("%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    pFile = fopen(argv[1], "r");

    while(!feof(pFile)&&!ferror(pFile)) {
        if(fscanf (pFile, "%d", &a[count])==1)
            count++;
        
    }
    printf("read number: %d\n", count);
    
    selection_sort(a, count);
    
    printf("In ascending order:\n");
    int i;
    for (i = 0; i < count; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    

    return 0;
}

void selection_sort(int a[], int n)
{
    int largest = 0, temp;
    
    if (n == 1)
        return;
    
    
    largest = find_largest(a, n);
    
    if (largest < n - 1) {
        temp = a[n-1];
        a[n-1] = a[largest];
        a[largest] = temp;
    }
    
    selection_sort(a, n - 1);
}

int find_largest(int a[], int n)
{
    int largest_index = 0;
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > a[largest_index])
            largest_index = i;
    return largest_index;
}

