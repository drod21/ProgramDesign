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
    int first_earlier = 0;
    
    printf("Please enter a date (mm/dd/yy):\n");
    scanf("%d /%d /%d", &month1, &day1, &year1);
    printf("Please enter a second date (mm/dd/yy):\n");
    scanf("%d /%d /%d", &month2, &day2, &year2);
    
    if (year1 != year2) {
        first_earlier = year1 < year2;
    } else if (month1 != month2) {
        first_earlier = month1 < month2;
    } else {
        (day1 != day2);
        first_earlier = day1 < day2;
        printf("The date is: %d/%d/%d.\n", month1, day1, year1);
    }
    return 0;
    
}
