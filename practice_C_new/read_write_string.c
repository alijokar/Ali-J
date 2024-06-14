/******************************************************************************

Read and write string, then counts how many a given characters it has!

*******************************************************************************/
#include <stdio.h>

#define NUM 63

int read_line(char str[], int n);
int count_spaces(const char str[], char search_ch);
int count_spaces_with_pointer(const char *s, char search_ch);

void main()
{
    char string[NUM], search_char;
    int count = 0;

    printf("Enter a message less than %d characters: ", NUM);
    read_line(string, NUM);

    search_char = 'H';
    count = count_spaces_with_pointer(string, search_char);

    printf("%s\n", string);
    if (count > 1){
        printf("The message has %d %c characters!\n", count, search_char);
    } else {
        printf("The message has %d %c character!\n", count, search_char);
    }
    
}

/* This function will read the message with max n length and 
retuns the actial length */

int read_line(char str[], int n){
    int ch, i = 0;
    
    while((ch = getchar()) != '\n'){
        if (i < n){
            str[i++] = ch;    
        }
    }
    
    str[i] = '\0';   
    return i;   
    
}

/* Using array subscripting, the function bellow counts 
the number of a given character (search_ch) in a string: 
Two version:
1) using subscription           ----> count_spaces_with_subscription
2) using pointer (prefered)     ----> count_spaces_with_pointer
*/

int count_spaces_with_subscription(const char str[], char search_ch){
    int count = 0, i;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == search_ch){
            count++;
        }
    }
    return count;
}

int count_spaces_with_pointer(const char *s, char search_ch)
{
    int count = 0;

    for (; *s != '\0'; s++){
        if (*s == search_ch)
        count++;
    }
    return count;
}