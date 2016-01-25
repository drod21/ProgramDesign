/* Calculates voltage for an experiment that will be repeated 
   using an AC voltage signal
   Derek Rodriguez
   U37516832
   01/25/2016 */

#include <stdio.h>
#include <math.h>

int main(void) 
{
    double t, volts;
    
    printf("time (sec)\t voltage\n");
    
    for (t=0; t<=12; t+=0.5) {
        
        if (t < 1) {
            volts = 0.5 * sin(2*t);
        }
        
       if (1.0 <= t && t <= 10.0) {
            volts = sin(t);
        }
        
       if (t > 10.0) {
            volts = sin(10.0);
        }
        
        printf("%.2f\t%.2f\n", t, volts);
    }
    return 0;
}
