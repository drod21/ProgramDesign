/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* remind.c (Chapter 13, page 294) */
/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void) {
    
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN+1],  hour_str[3];
    char combine[6];
  
    int day, i, j, num_remind = 0;
    int hour;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day, 24-hour time, and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        
        
        sprintf(day_str, "%2d", day);
        scanf("%3d", &hour);
        sprintf(hour_str, "%3d", hour);
        read_line(msg_str, MSG_LEN);
      
        if (day > 31 || day < 0) {
            printf("Please enter a day between 1 and 31. Entry Ignored. \n");
            continue;
        }
       

        
        
        if (hour > 23 || hour < 0) {
            
            printf("Please enter a time between 0 and 23");
            break;
            
        }
        
        strcpy(combine, day_str);
        strcat(combine, hour_str);
        
        
        for (i = 0; i < num_remind; i++)
            if (strcmp(combine, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], hour_str);
        strcat(reminders[i], msg_str);

        num_remind++;
      
    }

    printf("\nDay Reminder\n");
    
    for (i = 0; i < num_remind; i++)
        
        printf(" %s\n", reminders[i]);

    return 0;

}

int read_line(char str[], int n) {
    
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
       
        if (i < n)
    
            str[i++] = ch;
    
    str[i] = '\0';
    return i;
    
}
