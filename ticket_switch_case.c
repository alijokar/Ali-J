/* 
A practice for switch and case in C

The input is:
             vehicle speed.

The output is:
    - "No Ticket" if Speed is less than 65mph.
    - "Cheap ticket" if speed is greater than 65mph and less than 90mph.
    - "Expensive ticket" if the speed is greater than 90mph.
 */

#include<stdio.h>

int main ()
{
    int speed;
    printf("Enter he speed as an integer:\n");
    scanf("%d", &speed);
    speed= (speed <0) ? -1: (speed <= 65) ? (65) : (speed <= 70) ? (70) : (90);
    switch (speed)
    {
        case -1: printf("The speed value is not valid!\n"); break;
        case 65: printf("No ticket needed!\n"); break;
        case 70: printf("Cheap ticket!\n"); break;
        case 90: printf("Expensive ticket needed!\n"); break;
        default: printf("The speed value is not valid!\n"); break;
    }
    return 0;
}