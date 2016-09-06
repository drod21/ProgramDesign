/*
 *   Derek Rodriguez
 *   U37516832
 *   9/6/2016
 *   Calculates the voltage across the capacitor in a circuit from 0 to 1 second in
 *   increments of 1/15 second, with switch closed at time 0

 *   v(t) = V x (1 - e^(-t/(time-constant)))
 * time constant = resistance x capacitance = 0.15
 
 */

#include <stdio.h>
#include <math.h>

#define VOLTS 10
#define RESIST 3000
#define C 50E-6
#define t_const 0.15

int main(void) {
    
    double volt, time;
    
    printf("time(sec) \t voltage\n");
    
    for (time = 0.0; time < 1.01; time += 0.06667) {
        
        volt = VOLTS * (1 - exp(-(time/t_const)));
                        
                        printf("%.2f \t %.2f\n", time, volt);
        
    }
    
}