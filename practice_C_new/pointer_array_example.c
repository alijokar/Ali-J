/*
This is practice for usage of pointer in nD array
Writing and reading data
*/

#include <stdio.h>

#define ROW 4
#define COL 5

int main(){

    int array_1D[ROW];
    int array_2D[ROW][COL];  
    int *p_1;
    int *p_2;
    int (*p_3)[COL];

    // Writing 4 to all 1D array and 5 to 2D array

    for (p_1 = array_1D; p_1 <= &array_1D[ROW - 1]; p_1++){
            *p_1 = 4;
        }

    for (p_2 = &array_2D[0][0]; p_2 <= &array_2D[ROW - 1][COL - 1]; p_2++){
            *p_2 = 5;
        }
    
    // Print both 1D and 2D array (subscripton)

    printf("---------------------------------------------\n\n");
    printf("print 2D array using subscription for loop\n\n");

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){

            printf("%d ", array_2D[i][j]);

        }
        printf("\n");
    }

    printf("---------------------------------------------\n\n");
    printf("print 1D array using subscription for loop\n\n");

    for (int i = 0; i < ROW; i++){

        printf("%d ", array_1D[i]);

    }
    printf("\n");

    // Print 2D array (pointer)
    printf("---------------------------------------------\n\n");
    printf("print the 2D array using pointer for loop\n\n");

    for(p_3 = &array_2D[0]; p_3 < &array_2D[ROW]; p_3++){
        for (int j = 0; j < COL; j++){
            printf("%d ", (*p_3)[j]);
        }
        printf("\n");
    }

    // Print 1D array (pointer)
    printf("---------------------------------------------\n\n");
    printf("print the 1D array using pointer for loop\n\n");

    for(p_1 = array_1D; p_1 < (array_1D + ROW); p_1++){

        printf("%d ", *p_1);
    }
    printf("\n---------------------------------------------\n\n");

    // Update scond columns to 2 in 2D array
    int target_column = 2;
    for(p_3 = &array_2D[0]; p_3 < &array_2D[ROW]; p_3++){

        (*p_3)[target_column - 1] = 4;

    }

    printf("print the 2D array using pointer for loop after manipolation\n\n");

    for(p_3 = &array_2D[0]; p_3 < &array_2D[ROW]; p_3++){
        for (int j = 0; j < COL; j++){
            printf("%d ", (*p_3)[j]);
        }
        printf("\n");
    }
    printf("\n---------------------------------------------\n\n");

}