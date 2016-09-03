//
//  calculateGPA.c
//  
//
//  Created by Derek Rodriguez on 9/1/16.
//
//

#include <stdio.h>

float compute_GPA(char grades[], int n);

int main(void) {
    
    char letter_grades[10], ch;
    int i = 0, count = 0;
    float gpa_avg;
    
    printf("Please enter letter grades: \n");
    while ((ch = getchar()) != '\n') {
        letter_grades[i++] = ch;
        count++;
    }
    
    gpa_avg = compute_GPA(letter_grades, 10);
    
    printf("GPA is: %.2f\n", gpa_avg);
    
    
    return 0;
}

float compute_GPA(char grades[], int n) {
    
    float gpa = 0;
    
    for (int i = 0; i < n; i++) {
        if (grades[i] == 'A') {
            gpa += 4;
        } else if (grades[i] == 'B') {
            gpa += 3;
        } else if (grades[i] == 'C') {
            gpa += 2;
        } else if (grades[i] == 'D') {
            gpa += 1;
        } else {
            gpa += 0;
        }
    }
    
    return gpa / n;
}