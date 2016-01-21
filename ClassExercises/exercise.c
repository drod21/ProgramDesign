//
//  exercise.c
//  
//
//  Created by Derek Rodriguez on 1/20/16.
//
//

#include <stdio.h>

int main(void) {

    int month1, month2, day1, day2, year1, year2;
    printf("Please enter a date (mm/dd/yy):\n");
    scanf("%d /%d /%d", &month1, &day1, &year1);
    printf("Please enter a second date (mm/dd/yy):\n");
    scanf("%d /%d /%d", &month2, &day2, &year2);
    
    if (year2 > year1 || day2 > day1 || month2 > month1) {
        printf("This date is earlier on the calendar: %d/%d/%d.\n", month1, day1, year1);
    } else if (year1 > year2 || day1 > day2 || month1 > month2){
        printf("This date is earlier on the calendar: %d/%d/%d.\n", month2, day2, year2);
    } else {
        printf("The date is the same.\n");
        printf("The date is: %d/%d/%d.\n", month1, day1, year1);
    }
    return 0;
    
}
