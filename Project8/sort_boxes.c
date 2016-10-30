//
//  sort_boxes.c
//  
//
//  Created by Derek Rodriguez on 10/30/16.
//
//

#include <stdio.h>

struct box {
    
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
        
        while (!feof(in_file) && !ferror(in_file)) {
        
            fscanf(in_file, "%lf, %lf, %lf, %lf", &boxes[count].length, &boxes[count].width, &boxes[count].height, &boxes[count].weight);
            count++;
        
    }
        
        selection_sort(boxes, count);
        printProducts(out_file, boxes, count);
    }
    
    /* Close files and exit program */
    fclose(in_file);
    fclose(out_file);
    return 0;
    
}


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
        
        temp = boxes[n - 1];
        boxes[n - 1] = boxes[largest];
        boxes[largest] = temp;
        
    }
    
    selection_sort(boxes, n - 1);
    
}

void printProducts(FILE *out_file, struct box boxes[], int count) {
    
    int i = 0;
    
    
    fprintf(out_file, "#\t\tLength\t\tWidth\t\tHeight\t\tVolume\t\tWeight\n");
    
    for (i = 1; i < count; i++) {
        
        fprintf(out_file, "%d\t%lf\t%lf\t%lf\t%lf\t%lf\n", i, boxes[i].length,
                boxes[i].width, boxes[i].height, boxes[i].volume, boxes[i].weight);
    }
}

double getVolume(struct box boxes[]) {
    
    boxes->volume = boxes->length * boxes->width * boxes->height;
    
    return boxes->volume;
    
}
