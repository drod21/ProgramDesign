/* Derek Rodriguez 
   U37516832
   1/18/2016
 This program displays menus for length conversion metric -> imperial & reverse.
 */

#include <stdio.h>

#define mToKm 1.6093
#define kmToM 0.6214
#define inToCm 2.54
#define cmToIn 0.3937

int main(void)
{
    double d, dM, dKm, dIn, dCm;
    int menu;
    /* Conversion Menu */
    printf("Please select a number for your desired conversion:\n");
    printf("1: Miles to Kilometers.\n2: Kilometers to Miles.\n3: Inches to Centimeters.\n4: Centimeters to Inches.\n ");
    scanf("%d", &menu);
    
    /* Case/Switch Conditional Statements */
    switch (menu) {
        case 1: printf("Enter the distance in miles:\n");
            scanf("%lf", &d);
            dKm = (d * mToKm);
            printf("%.2lf miles converts to %.2lf kilometers\n", d, dKm);
            break;
        case 2: printf("Enter the distance in kilometers:\n");
            scanf("%lf", &d);
            dM = (d * kmToM);
            printf("%.2lf kilometers converts to %.2lf miles\n", d, dM);
            break;
        case 3: printf("Enter the distance in inches:\n");
            scanf("%lf", &d);
            dCm = (d * inToCm);
            printf("%.2lf inches converts to %.2lf centimeters\n", d, dCm);
            break;
        case 4: printf("Enter the distance in centimeters:\n");
            scanf("%lf", &d);
            dIn = (d * cmToIn);
            printf("%.2lf centimeters converts to %.2lf inches\n", d, dIn);
            break;
        default:
            printf("Invalid selection, please run the program again");
            break;
    }
    return 0;
}