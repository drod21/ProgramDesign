//
//  date1.c
//  
//
//  Created by Derek Rodriguez on 8/29/16.
//
//

#include <stdio.h>

int main() {
    
    
    int m1, d1, y1, m2, d2, y2;
    int first_earlier = 0;
    
    printf("Please enter first date:\n");
    scanf("%d/%d/%d", &m1, &d1, &y1);
    printf("Please enter second date:\n");
    scanf("%d/%d/%d", &m2, &d2, &y2);
    
    if (y1 != y2) {
        first_earlier = y1 < y2;
    } else if (m1 != m2) {
        first_earlier = m1 < m2;
    } else {
        first_earlier = d1 < d2;
    }
    
    if (first_earlier == 1) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n",
               m1, d1, y1, m2, d2, y2);
    } else {
        printf("%d/%d/%d is earlier than %d/%d/%d\n",
               m2, d2, y2, m1, d1, y1);
    }
    return 0;
}
