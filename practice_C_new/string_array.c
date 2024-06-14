// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

#define NUM 9

int main() {

    char *planets[NUM] = {
        "Mercury", "Venus", "Earth",
        "Mars", "Jupiter", "Saturn",
        "Uranus", "Neptune", "Pluto"
        };
    printf("------------------------\n");

    // Print planets starts with 'M'
    for (int i = 0; i < NUM; i++){
        if (planets[i][0] == 'M'){
            printf("%s begins with M\n", planets[i]);
        }
    }

    printf("------------------------\n");
    
    // Print second planet in the array    
    printf("The second in solar system is %s\n", planets[1]);
    printf("------------------------\n");
    return 0;
}