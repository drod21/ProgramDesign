/* reads file sales.txt, store the data in an array of product structures, and sort the products by sale volume. Output the sorted products, including sale volumes in a text file called sorted_products.txt
 * Derek Rodriguez
 * U37516832
 */

#include <stdio.h>
#include <string.h>

#define len 1000

struct product {
    char name[10];
    double price;
    double num_pounds_sold;
    double sale_volume;
};

void separate(struct product products[], double prices, double sold);
void selection_sort(struct product products[], int n);
void printProducts(FILE *out_File, struct product products[], int count);
void display(struct product products[], int count);
double getVolume(struct product products[]);

int main() {
    FILE *in_File,*out_File;
    struct product products[len];
    char *in_File_Name = "sale.txt";
    char *out_File_Name = "sorted_products.txt";

    int count = 0;
    
    in_File = fopen(in_File_Name, "r");
    out_File = fopen(out_File_Name, "w");
    
    if (in_File == NULL) {
        printf("File does not exist.\n");
        return 1;
    } else {
        while (!feof(in_File) && !ferror(in_File)) {
            fscanf(in_File, "%s %lf %lf", products[count].name, &products[count].price, &products[count].num_pounds_sold);
            count++;

        }

        selection_sort(products, count);

        printProducts(out_File, products, count);
    }

    fclose(in_File);
    fclose(out_File);
    return 0;
    
}
void separate(struct product products[], double prices, double sold) {
    
}

void display(struct product products[], int count) {
    int i = 0;
    printf("#name\tunit price($)\tunit (pound) sold\tsale volume ($)\n");
    for (i = 1; i < count; i++) {
        printf("%d\t%s\t%lf\t%lf\t%lf\n", i, products[i].name, products[i].price, products[i].num_pounds_sold, getVolume(&products[i]));
    }
    printf("\n");
}

void selection_sort(struct product products[], int n) {
    int i, largest = 0;
    struct product temp;
    
    if (n == 1)
        return;
    
    for (i = 1; i < n; i++)
        if (getVolume(&products[i]) > getVolume(&products[largest]))
            largest = i;
    
    if (largest < n - 1) {
        temp = products[n-1];
        products[n-1] = products[largest];
        products[largest] = temp;
    }
    
    selection_sort(products, n - 1);
    
}

void printProducts(FILE *out_File, struct product products[], int count) {
    int i = 0;
    
    
    fprintf(out_File, "#name\tunit price($)\tunit (pound) sold\tsale volume ($)\n");
    
    for (i = 1; i < count; i++) {
    fprintf(out_File, "%d\t%s\t%lf\t%lf\t%lf\n", i, products[i].name, products[i].price, products[i].num_pounds_sold, getVolume(&products[i]));
            }


}

double getVolume(struct product products[]) {
    
    products->sale_volume = products->price * products->num_pounds_sold;

    return products->sale_volume;
}
