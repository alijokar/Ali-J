/*
Since read_line is unrelated to the other functions in inventory.c, and
since it’s potentially reusable in other programs, I’ve decided to separate it from
inventory.c. The prototype for read_line will go in the readline.h
header file.
*/


#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
    int ch, i = 0;
    while (isspace(ch = getchar()))
    ;
    while (ch != '\n' && ch != EOF) {
    if (i < n)
    str[i++] = ch;
    ch = getchar();
    }
    str[i] = '\0';
    return i;
}