//
//  struct_time.c
//  
//
//  Created by Derek Rodriguez on 11/26/16.
//
//
struct time {
    
    int hours, seconds, minutes;
    
};

struct time split_time(long total_seconds);

#include <stdio.h>

int main() {
    
    struct time t;
    long sec = 86399;
    
    t = split_time(sec);
    
    printf("Hours: %d Minutes: %d Seconds: %d\n", t.hours, t.minutes, t.seconds);
    
    return 0;
    
}

struct time split_time(long total_seconds) {
    
    struct time t;
    
    t.seconds = total_seconds % 60;
    
    total_seconds = total_seconds / 60;
    
    t.minutes = total_seconds % 60;
    
    t.hours = total_seconds / 60;
    
    return t;
    
}
