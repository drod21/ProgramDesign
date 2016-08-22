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
    
    int day, D, dayDue;
    
    printf("Please enter todays day (0 = Sunday, 1 = Monday..) 0-6: \n");
    scanf("%d", &day);
    if (day < 0 || day > 6) {
        printf("Invalid input. The day should be in the range of 0 to 6.\n");
        return 0;
    } else {
    printf("Please enter the number of days to do the work: \n");
    scanf("%d", &dayDue);
        
        D = (day + dayDue) % 7;
        
    
    //Calculate number of days based on today's day
    switch(D) {
        case 0: printf("The work is due on Monday. The number of days until its due is %d.\n", dayDue + 1);
            break;
            
        case 1: printf("The work is due on Monday. The number of days until its due is %d.\n", dayDue);
            break;
            
        case 2: printf("The work is due on Tuesday. The number of days until its due is %d.\n", dayDue);
            break;
            
        case 3: printf("The work is due on Wednesday. The number of days until its due is %d.\n", dayDue);
            break;
            
        case 4: printf("The work is due on Thursday. The number of days until its due is %d.\n", dayDue);
            break;
            
        case 5: printf("The work is due on Monday. The number of days until its due is %d.\n", dayDue + 3);
            break;
        
        case 6: printf("The work is due on Monday. The number of days until its due is %d.\n", dayDue + 2);
            break;
        
    }
        
    }
    
    
    return 0;
    
}