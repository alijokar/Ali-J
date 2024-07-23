#include <stdio.h>

void print_string(char *string);
int string_len(char *string);
void double_string_func(char *string, char *double_string);

int main(){
    
    char *string = "Hello Ali!";
    
    printf("--------------------\n");
    print_string(string);
    printf("--------------------\n");
    int string_length = string_len(string);
    printf("The string length is %d\n", string_length);
    printf("--------------------\n");
    
    char double_string[string_length * 2 + 1];
    
    double_string_func(string, double_string);
    printf("The double string is: %s\n", double_string);
    printf("--------------------\n");

}

void print_string(char *string){
    
    printf("The string is: %s\n", string);
    
}

int string_len(char *string){
    int num = 0;
    
    for(num; *string != '\0'; string++){
        num++;
    }
    
    return num;
    
}

void double_string_func(char *string, char *double_string){
    
    for (; *string != '\0'; string++){
        *double_string = *string;
        double_string++;
        *double_string = *string;
        double_string++;
    }
    
}