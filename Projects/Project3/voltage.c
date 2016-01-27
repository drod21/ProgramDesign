/* Calculates voltage for an experiment that will be repeated 
   using an AC voltage signal
   Derek Rodriguez
   U37516832
   01/25/2016 */

#include <stdio.h>
#include <math.h>

int main(void) {
    
    double t, volts;  /* Declare variables */
    
    printf("time (sec)\t voltage\n");
    
   /* Begin for loop, start at 0, increment time by 0.5 seconds
        Time cannot exceed 12 */
    for (t=0; t<=12; t+=0.5) {
        
        if (t < 1) {
            volts = 0.5 * sin(2*t); /* Increments voltage between t = 0 && 1 */
        }
        
        if (1.0 <= t && t <= 10.0) {
            volts = sin(t); /* Incremenets voltage between and including t = 1 && 10 */
        }
        
        if (t > 10.0) {
            volts = sin(10.0);/* Increments voltage between 10 and 12 seconds */
        }
        /* Print the time in seconds and voltages (to 2 decimal places)
         for each condition in the for loop */
        printf("%.2f\t%.2f\n", t, volts);
    }
    return 0;
}
