/* Help:
    We’ll use the codes i (insert), s (search), u (update), p (print), and q (quit) to represent
    the operations below: 

    i
    :Add a new part number, part name, and initial quantity on hand. The program
    must print an error message if the part is already in the database or if the
    database is full.
    
    s: 
    Given a part number, print the name of the part and the current quantity on
    hand. The program must print an error message if the part number isn’t in the
    database.

    u:
    Given a part number, change the quantity on hand. The program must print
    an error message if the part number isn’t in the database.
    
    p:
    Print a table showing all information in the database. Parts must be displayed
    in the order in which they were entered.

    q:
    Terminate program execution.

    **********************************************************
                                EXAMPLES
    **********************************************************
    Enter operation code: i
    Enter part number: 528
    Enter part name: Disk drive
    Enter quantity on hand: 10

    Enter operation code: s
    Enter part number: 528
    Part name: Disk drive
    Quantity on hand: 10

    Enter operation code: s
    Enter part number: 914
    Part not found.

    Enter operation code: i
    Enter part number: 914
    Enter part name: Printer cable
    Enter quantity on hand: 5

    Enter operation code: u
    Enter part number: 528
    Enter change in quantity on hand: -2

    Enter operation code: s
    Enter part number: 528
    Part name: Disk drive
    Quantity on hand: 8

    Enter operation code: p
    Part Number Part Name Quantity on Hand
    528 Disk drive 8
    914 Printer cable 5

    Enter operation code: q

    */

#include <stdio.h>
#include "readline.h"
#include "readline.c"


#define NAME_LEN 25  // max character in the name of the part
#define MAX_PARTS 100 // max number of parts in the array

// define a structure for the inventory
struct part
{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0; /* number of parts currently stored */

// Function prototypes
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);



int main(){

    /**********************************************************
    * main: Prompts the user to enter an operation code, *
    * then calls a function to perform the requested *
    * action. Repeats until the user enters the *
    * command 'q'. Prints an error message if the user *
    * enters an illegal code. *
    **********************************************************/
    char code;

    for (;;) {
        // Prompt user to enter operation code;
        printf("Enter operation code i (insert), s (search), u (update), p (print), and q (quit): ");
        /*
        The format string " %c" allows scanf to skip over
        white space before reading the operation code. The space in the format string is
        crucial; without it, scanf would sometimes read the new-line character that terminated
        a previous line of input.
        */
        scanf(" %c", &code);

        while (getchar() != '\n') /* skips to end of line */
        ;
        
        switch (code) {
            case 'i': insert();
                break;
            case 's': search();
                break;
            case 'u': update();
                break;
            case 'p': print();
                break;
            case 'q': return 0;
                default: printf("Illegal code\n");
        }

        printf("\n");
    }

}


void insert(void){
    
    /**********************************************************
    * insert: Prompts the user for information about a new *
    * part and then inserts the part into the *
    * database. Prints an error message and returns *
    * prematurely if the part already exists or the *
    * database is full. *
    **********************************************************/

    int part_number;

    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;

    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}


int find_part(int number){

    /**********************************************************
    * find_part: Looks up a part number in the inventory *
    * array. Returns the array index if the part *
    * number is found; otherwise, returns -1. *
    **********************************************************/

    int i;
    for (i = 0; i < num_parts; i++){
        if (inventory[i].number == number)
        return i;
    }

    return -1;
}


void search(void){

    /**********************************************************
    * search: Prompts the user to enter a part number, then *
    * looks up the part in the database. If the part *
    * exists, prints the name and quantity on hand; *
    * if not, prints an error message. *
    **********************************************************/

    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);

    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else{
        printf("Part not found.\n");
    } 
}


void update(void){

    /**********************************************************
    * update: Prompts the user to enter a part number. *
    * Prints an error message if the part doesn't *
    * exist; otherwise, prompts the user to enter *
    * change in quantity on hand and updates the *
    * database. *
    **********************************************************/

    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);

    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);

        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
    
}


void print(void){

    /**********************************************************
    * print: Prints a listing of all parts in the database, *
    * showing the part number, part name, and *
    * quantity on hand. Parts are printed in the *
    * order in which they were entered into the *
    * database. *
    **********************************************************/

    int i;

    printf("Part Number\tPart Name\tQuantity on Hand\n");

    for (i = 0; i < num_parts; i++){
        printf("---------------------------------------------------------\n");
        printf("%d\t\t%s\t\t\t%d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}