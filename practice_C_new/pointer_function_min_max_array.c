#include <stdio.h>

#define LEN 10

void max_min(int array[], int *max, int *min);

int main(){
    int array[LEN], max, min;

    printf("Enter 10 numbers: ");
    for (int i = 0; i < LEN; i++){
        scanf(" %d", &array[i]);
    }

    printf("array is: [ ");
    for (int i = 0; i < LEN; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");

    max_min(array, &max, &min);

    printf("max and min values in array are %d and %d.\n", max, min);

}

void max_min(int array[], int *max, int *min){
    int temp_max = array[0];
    int temp_min = array[0];

    for (int i = 1; i < LEN; i++){
        
        if (temp_max < array[i]){
            temp_max = array[i];
        }

        if (temp_min > array[i]){
            temp_min = array[i];
        }

    }

    *max = temp_max;
    *min = temp_min;

}


