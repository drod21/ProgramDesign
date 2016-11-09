//
//  read_numbers.c
//  
//
//  Created by Derek Rodriguez on 10/26/16.
//
//

#include <stdio.h>

void selection_sort(int a[], int n);

int main() {
    
    int num[1000];
    FILE *fp, *out;
    int count = 0, i = 0;
    
    char *out_file;
    out_file = "sorted_numbers.txt";
    
    fp = fopen("numbers.txt", "r");
    out = fopen(out_file, "w");
    
    if (fp == NULL) {
        
        printf("File can't be opened. \n");
        return 1;
        
    } else {
        
        while (!feof(fp) && !ferror(fp)) {
            
            if (fscanf(fp, "%d", &num[count]) == 1) {
                
                count++;
                
            }
                
            }
        }
    
     selection_sort(num, count);
    
    for (i = 0; i < count; i++) {
        
        printf("%d\t", num[i]);
        fprintf(out, "%d\n", num[i]);
        
    }
    
    printf("There are %d numbers. \n", i);
    fclose(fp);
    fclose(out);
    
    return 0;
}


void selection_sort(int a[], int n) {
    
    int i, largest = 0, temp;
    /* Selection sort to order in ascending order (smallest to largest) */
    if (n == 1)
        return;
    
    for (i = 1; i < n; i++)
        if (a[i] > a[largest])
            largest = i;
    
    if (largest < n - 1) {
        temp = a[n-1];
        a[n-1] = a[largest];
        a[largest] = temp;
    }
    
    selection_sort(a, n - 1);
    
}
