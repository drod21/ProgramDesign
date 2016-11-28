//
//  departure.c
//  
//
//  Created by Derek Rodriguez on 11/23/16.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct times {
    
    int depart, arrive;
    
};


int main() {
    
    struct times t[8] = {{8 * 60 + 0, 10 * 60 + 16}, {9 * 60 + 43, 11 * 60 + 52}, {11 * 60 + 19, 13 * 60 + 31}, {12 * 60 + 47, 15 * 60 + 0}, {14 * 60 + 0, 16 * 60 + 8}, {15 * 60 + 45, 17 * 60 + 55}, {19 * 60 + 0, 21 * 60 + 20}, {21 * 60 + 45, 23 * 60 + 58}};
   
    
    int hr, min, i;
    int dep_time, ch, t1, t2;
    char dep_suffix[] = "a.m.", arr_suffix[] = "a.m.";
    int dep_h, dep_m, arr_h, arr_m;
    int closest_dep = t[0].depart;
    int closest_arr = t[0].arrive;
    int min_delta;
    
    printf("Please enter a time in 24-hour time: \n");
    
    scanf("%d:%d", &hr, &min);
    
    printf("Minutes: \n");
    dep_time = hr * 60 + min;
    min_delta = abs(dep_time - t[0].depart);
    
    for (i = 0; i < 8; i++) {
     
        if (abs(dep_time - t[i].depart) < min_delta) {
            
            closest_dep = t[i].depart;
            closest_arr = t[i].arrive;
            min_delta = abs(dep_time - t[i].depart);
            
        }
        
    }
    
    
    dep_h = closest_dep / 60 % 12;
    dep_h = dep_h == 0 ? 12 : dep_h;
    
    dep_m = closest_dep % 60;
    
    if (closest_dep / 60 >= 12) {
        
        strcpy(dep_suffix, "p.m.");
    }

    arr_h = closest_arr / 60 % 12;
    arr_h = arr_h == 0 ? 12 : arr_h;
    arr_m = closest_arr % 60;
    
    if (closest_arr / 60 >= 12) {
        strcpy(arr_suffix, "p.m.");
    }
    
    printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s\n",
           dep_h, dep_m, dep_suffix,
           arr_h, arr_m, arr_suffix);

    return 0;
    
}
