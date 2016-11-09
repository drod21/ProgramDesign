/*
 * Reads file boxes.txt and sort the boxes by volume. 
 * Output the sorted boxes, including volumes in
 * a text file called sorted_boxes.txt.
 *
 * Derek Rodriguez
 * U37516832
 * 10/30/2016
 *
 */
 
 
 
#include <stdio.h>


struct box {
    // Structure for boxes
    double length;
    double width;
    double height;
    double weight;
    double volume;
    
};

void selection_sort(struct box boxes[], int n);
void printProducts(FILE *out_file, struct box boxes[], int n);
double getVolume(struct box boxes[]);

#define N 100

int main() {
    
    FILE *in_file, *out_file;
    // Array of structures
    struct box boxes[N];
    
    char *in = "boxes.txt";
    char *out = "sorted_boxes.txt";
    
    int count = 0;
    
    /* Open in and out files */
    
    in_file = fopen(in, "r");
    out_file = fopen(out, "w");
    
    if (in_file == NULL) {
        
        printf("Input file does not exist. \n");
        return 1;
    
    } else {
        // While loop to store values from in_file
        while (!feof(in_file) && !ferror(in_file)) {
        
            fscanf(in_file, "%lf, %lf, %lf, %lf", &boxes[count].length, &boxes[count].width, &boxes[count].height, &boxes[count].weight);
            count++;
        
    }
        // Sort the structure by volume
        selection_sort(boxes, count);
        // Print the structure
        printProducts(out_file, boxes, count);
    }
    
    /* Close files and exit program */
    fclose(in_file);
    fclose(out_file);
    return 0;
    
}

// Sort the array of structures boxes by volume
void selection_sort(struct box boxes[], int n) {
        
    int i, largest = 0;
    struct box temp;
    
    if (n == 1)
        return;
    
    /* Sort by volume */
    for (i = 1; i < n; i++) {
    
        if (getVolume(&boxes[i]) > getVolume(&boxes[largest])) {
            
            largest = i;
            
        }
    }

    if (largest < n - 1) {
        // Swap largest with n - 1
        temp = boxes[n - 1];
        boxes[n - 1] = boxes[largest];
        boxes[largest] = temp;
        
    }
    
    // Recursive call
    selection_sort(boxes, n - 1);
    
}

void printProducts(FILE *out_file, struct box boxes[], int count) {
    // Function to print the structure to out_file
    int i = 0;
    
    printf( "# Length   Width    Height   Volume\tWeight\n");
    
    for (i = 1; i < count; i++) {
        
        printf("%d %lf %lf %lf %lf %lf\n", i, boxes[i].length,
                boxes[i].width, boxes[i].height, boxes[i].volume, boxes[i].weight);
    }
    
    
    fprintf(out_file, "# Length   Width    Height   Volume\tWeight\n");
    
    for (i = 1; i < count; i++) {
        
        fprintf(out_file,"%d %lf %lf %lf   %lf   %lf\n", i, boxes[i].length,
               boxes[i].width, boxes[i].height, boxes[i].volume, boxes[i].weight);
    }
    
    
}

double getVolume(struct box boxes[]) {
    // Use array of structure to compute volume
    boxes->volume = boxes->length * boxes->width * boxes->height;
    
    return boxes->volume;
    
}
