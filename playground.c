#include <stdio.h>
#include <stdlib.h>
#include "libraries/complex_numbers.h"


void superscript_selector(char c);


int main() {
    char string[20];

    printf("Enter a function: ");
    fgets(string, LEN(string), stdin);

    size_t i = 0;
    while(string[i]){
        if(string[i] == '^' && string[i+1]){
            superscript_selector(string[i+1]);
            i = i+2;
            continue;
        }
        printf("%c", string[i]);
        i++;
    }

    return 0;
}


void superscript_selector(char c){
    switch (c) {
        default:
            printf("\nError code 1: '%c' is an invalid superscript\n", c);
            exit(1);

        case '1':
            printf("%s", SUPER_ONE);
            break;

        case '2':
            printf("%s", SUPER_TWO);
            break;

        case '3':
            printf("%s", SUPER_THREE);
            break;

        case '4':
            printf("%s", SUPER_FOUR);
            break;

        case '5':
            printf("%s", SUPER_FIVE);
            break;

        case '6':
            printf("%s", SUPER_SIX);
            break;

        case '7':
            printf("%s", SUPER_SEVEN);
            break;

        case '8':
            printf("%s", SUPER_EIGHT);
            break;

        case '9':
            printf("%s", SUPER_NINE);
            break;

        case '0':
            printf("%s", SUPER_ZERO);
            break;
    }
    return;
}
