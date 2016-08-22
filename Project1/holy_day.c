//
//  Derek Rodriguez
//  U37516832
//  8/22/2016
//
//  Calculates the day of the week on which the work would be due,
//  skips over holy days and goes to the next Monday.
//

#include <stdio.h>


int main(void) {
    
    int day, D;
    
    printf("Please enter todays day (0 = Sunday, 1 = Monday..) 0-6: \n");
    scanf("%d", &day);
    if (day > 6) {
        printf("Please enter a day between 0-6");
    } else {
    printf("Please enter the number of days to do the work: \n");
    scanf("%d", &D);
    
    //Calculate number of days based on todays day
    switch(day) {
        case 0: printf("Sunday");
            break;
        case 1: printf("Monday");
            break;
        case 2: printf("Tuesday");
            break;
        case 3: printf("Wednesday");
            break;
        case 4: printf("Thursday");
            break;
        case 5: printf("Friday");
            break;
        case 6: printf("Saturday");
            break;
    }
    
    }
    
    
    
    return 0;
    
}