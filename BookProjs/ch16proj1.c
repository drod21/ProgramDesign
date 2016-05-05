//
//  ch16proj1.c
//  ask user to enter international dialing code then looks it up in country codes array (16.3)
//  then displays name of corresponding country. if not, print error
//  Created by Derek Rodriguez on 4/27/16.
//
//
#define COUNTRY_COUNT ((int) (sizeof(country_codes) / sizeof(country_codes[0])))

struct dialing_code {
    char *country;
    int code;
};
const struct dialing_code country_codes[] =
{{"Argentina",  54}, {"Bangladesh", 880},
    {"Brazil",  55},    {"Burma (Myanmar)", 95},
    {"China",   86},    {"Colombia",    57},
    {"Congo, Dem. Rep. of", 243},   {"Egypt",   20},
    

#include <stdio.h>

    int main(void) {
        int dcode, i;
        printf("Enter dialing country code: ");
        scanf("%d", &dcode);
        
        for (i = 0; i < COUNTRY_COUNT; i++) {
            if (dcode == country_codes[i].code) {
                printf("%d is %s\n", dcode, country_codes[i].country);
            }
        }
    }