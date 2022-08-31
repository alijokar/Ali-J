/*
No complete yet!
This script is supposed to receive some certain numbers and print sum, min and max.

Inputs:
First input: How many numbers?
Second input: All numbers one by one.

Outputs: 
Print Sum, Min and Max values.
Not complete yet!
This script is supposed to receive some certain numbers and print sum, min and max.


**********************************
**********|           |***********
**********|In Progress|***********
**********|           |***********
**********************************
*/

#include<stdio.h>

float min ( float , float);
float max ( float , float);
float sum ( float , float);

int main()
{
    float a, b;
    printf("Two new iputs needed:\n");
    scanf("%f %f", &a, &b);
    printf("The sum is: %f\n", sum ( a , b ));
    printf("The min value is: %f\n", min ( a , b));
    printf("The max value is: %f\n", max ( a , b));
    return 0;
}

/* min function with two inputs*/
float min ( float x, float y){
    return ( x < y ? x : y); 
}

/* max function with two inputs*/
float max ( float x, float y){
    return ( x > y ? x : y);
}

/* sum function with two inputs*/
float sum ( float x, float y){
    return ( x + y );
}