/*This script is supposed to receive some certain numbers and print sum, min and max.

Inputs:
First input: How many numbers?
Second input: All numbers one by one.

Outputs: 
Print Sum, Min and Max values.

*/


#include<stdio.h>

float min ( float x[] , int y);
float max ( float x[] , int y);
float sum ( float x[] , int y);

int main()
{
    // "num" is the number of input data 
    int num;
    printf("How many numbers does the function expect to receive:");
    scanf("%d", &num);

    // "all_numbers" is an array with length of "num"
    // The for loop will ask each number one-by-one and save to "all_numbers"
    float all_numbers[num];
    for (int i=0; i < num; i++){
        printf("Enter input number %d =", i+1);
        scanf("%f", &all_numbers[i]);
    }
    
    // Print all input numbers.
    printf("------ Outputs---------\n");
    printf("All numbers are: [");
    for (int i=0; i < num; i++){
        printf("%f ", all_numbers[i]);
    }
    printf("]\n");
    
    // Calling min, max and sum functions and report.
    printf("The Min value is: %f\n", min ( all_numbers , num));

    printf("The Max value is: %f\n", max ( all_numbers , num));

    printf("The sum value is: %f\n", sum ( all_numbers , num));

    return 0;
}

/* 
min function: This function returns the min value of n input numbers.
Inputs: 1) an array including all numbers, 2) the length of the array
 */
float min ( float x[] , int y){
    float min_value = x[0];
    for (int i=1; i < y; i++){
        min_value = ( x[i] < min_value ) ? x[i] : min_value;
    }
    return min_value;
}

/* 
max function: This function returns the max value of n input numbers.
Inputs: 1) an array including all numbers, 2) the length of the array
 */
float max ( float x[] , int y){
    float max_value = x[0];
    for (int i=1; i < y; i++){
        max_value = ( x[i] > max_value ) ? x[i] : max_value;
    }
    return max_value;
}

/* 
sum function: This function returns the summation n input numbers.
Inputs: 1) an array including all numbers, 2) the length of the array
 */
float sum ( float x[] , int y){
    float sum_tot = 0;
    for (int i=0; i < y; i++){
        sum_tot += x [i];
    }
    return sum_tot;
}
