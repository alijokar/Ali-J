/*
Guessing a Number
To get more experience with external variables, we’ll write a simple game-playing
program. The program generates a random number between 1 and 100, which the
user attempts to guess in as few tries as possible. Here’s what the user will see
when the program is run:

Guess the secret number between 1 and 100.
A new number has been chosen.
Enter guess: 55
Too low; try again.
Enter guess: 65
Too high; try again.
Enter guess: 60
Too high; try again.
Enter guess: 58
You won in 4 guesses!
Play again? (Y/N) y
A new number has been chosen.
Enter guess: 78
Too high; try again.
Enter guess: 34
You won in 2 guesses!
Play again? (Y/N) n

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LOW_RANGE 1
#define HIGH_RANGE 100
#define TOO_HIGH_RANGE 10
#define TOO_LOW_RANGE 10

int select_rand_num(void);
void read_guesses(int rand_number);

int main(){

    int rand_number, tot_try_number;
    char command = 'Y';

    printf("---------------------------------------------\n\n");
    printf("OK lets get started:\n\n");
    printf("---------------------------------------------\n\n");
    printf("A new number between %d and %d has been chosen.\n\n", LOW_RANGE, HIGH_RANGE);
    printf("---------------------------------------------\n\n");

    tot_try_number = 0;

    while (command == 'Y'){
        tot_try_number +=1;

        rand_number = select_rand_num();

        read_guesses(rand_number);

        printf("Do you want to try again (Y/N)? ");
        scanf(" %c", &command);
        printf("---------------------------------------------\n\n");

        }

    printf("You tried %d times. Thanks!", tot_try_number);

}

int select_rand_num (void){

    /* Intializes random number generator */
    srand((unsigned) time(NULL));

    return rand() % ((HIGH_RANGE - LOW_RANGE + 1) + LOW_RANGE);
}

void read_guesses(int rand_number){
    
    int guess_number;
    int try_number = 0;

    do{
        try_number += 1;

        printf("Enter guess: ");
        scanf("%d", &guess_number);

        if (guess_number > (rand_number + TOO_HIGH_RANGE)){

            printf("Too high; try again.\n");

        } else if (guess_number < (rand_number - TOO_LOW_RANGE)){

            printf("Too low; try again.\n");

        } else if ((guess_number < (rand_number + TOO_HIGH_RANGE)) && (guess_number > rand_number)){

            printf("Nice, a little high; try again.\n");
        } else if ((guess_number > (rand_number - TOO_HIGH_RANGE)) && (guess_number < rand_number)){

            printf("Nice, a little low; try again.\n");
        } 

        printf("---------------------------------------------\n\n");

        } while (guess_number != rand_number);

        printf("Good job, you won in %d guesses!\n\n", try_number);
    
}


