//
//  splittime.c
//  
//
//  Created by Derek Rodriguez on 9/5/16.
//
//

#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void) {
    
    int hour, min, sec;
    long total_sec;
    
    printf("Enter total number of seconds: \n");
    scanf("%ld", &total_sec);
    
    split_time(total_sec, &hour, &min, &sec);
    
    printf("Time equivalent to %ld is: \n", total_sec);
    printf("\t%d hours, %d minutes, %d seconds.\n", hour, min, sec);
    
    return 0;
}




void split_time(long total_sec, int *hr, int *min, int *sec) {
    
    *sec = total_sec % 60;
    total_sec = total_sec / 60;
    *min = total_sec % 60;
    *hr = total_sec / 60;
    
    
}