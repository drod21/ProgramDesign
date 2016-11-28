//
//  date.c
//  
//
//  Created by Derek Rodriguez on 11/21/16.
//
//

#include <stdio.h>

struct date {
    int day, month, year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void) {
    
    
    struct date d, d1;
    
    d.day = 13;
    d.month = 8;
    d.year = 2015;
    
    d1.day = 12;
    d1.month = 8;
    d1.year = 2015;
    
    int day, compare;
    day = day_of_year(d);
    compare = compare_dates(d, d1);
    
    printf("%d/%d/%d is the %d day of the year. \n", d.month, d.day, d.year, day);
    
    if (compare == -1)
        printf("Date 1 is earlier than date 2. \n");
    else if (compare == 0)
        printf("Dates are the same. \n");
    else if (compare == 1)
        printf("Date 1 is later than date 2. \n");
    
    
    return 0;
    
}

int day_of_year(struct date d) {
    
    int i, day = 0, isLeap = 0;
    
    int days_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (d.year % 4 == 0) {
        
        isLeap = 1;
        
    } else {
        
        isLeap = 0;
        
    }
    
    for (i = 0; i < d.month; i++) {
        
        if (isLeap) {
            
            day += leap_days[i];
            
        } else {
            
            day += days_month[i];
            
        }
        
    }
    
    day += d.day;
    return day;
    
    
}

int compare_dates(struct date d1, struct date d2) {
    
    int flag = 0;
    
    if (d1.year < d2.year) {
        flag = -1;
    } else if (d1.year > d2.year) {
        flag = 1;
    } else if (d1.year == d2.year) {
        if (d1.month < d2.month) {
            flag = -1;
        } else if (d1.month > d2.month) {
            flag = 1;
        } else if (d1.month == d2.month) {
            if (d1.day < d2.day) {
                flag = -1;
            } else if (d1.day > d2.day) {
                flag = 1;
            } else {
                flag = 0;
            }
        }
    }
    return flag;
}
