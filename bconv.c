#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_bases(short val, char mode)
{
    int isValid = 0;
    for (; isValid == 1;)
    //char m = mode;
    {switch(mode) {
        case 'O':
            printf("Octal");
            isValid = 1;
            break;
        case 'H':
            printf("Hexadec");
            isValid = 1;
            break;
        case 'D':
            printf("Decimal");
            isValid = 1;
            break;
        case 'C':
            printf("clear value");
            isValid = 1;
            break;
        case 'S':
            printf("set value");
            isValid = 1;
        case 'Q':
            printf("quit");
            isValid = 1;
        defalut:
            printf("please enter a valid mode.");
            scanf(" %c", &mode);

        //steak

    }}
    printf("nilerodgers\n");
}

char print_menu(void) {
    int hex = 0000;
    int oct = 000000;
    int dec = 0;
    char mode[] = "Dec";

    char option[10]; //10 char string for errors
    for (size_t ii = 0; ii<41; ++ii)
        putchar('*');
    printf("\n");
    printf("* Base values:          ");
    printf("Input Mode: %s", mode); printf(" *\n");
    printf("*   Hex     : %d\n", hex);
    printf("*   Octal   : %d\n", oct);
    printf("*   Decimal : %d\n", dec);
    //printf("\n");
    for (size_t ii = 0; ii<41; ++ii)
        putchar('*');
    printf("\n");
    printf("Please select one of the following options\n");
    printf("\n");
    printf("O Octal Mode\n");
    printf("H Hexadecimal Mode\n");
    printf("D Decimal Mode\n");
    printf("\n");
    printf("C Clear Value\n")''
    printf("S Set Value\n");
    printf("\n");
    printf("Q Quit\n");
    printf("\n");
    printf("Option: \n");

    scanf("%s", option);
    char optChar = option[0]; //gets char at pos 0
    optChar = toupper(optChar);

    print_bases(0, optChar);

    printf("You choose: %c\n", optChar);
}



//int decConverter(){}
//int hexConvertor(){}
//int octConvertor(){}

int main(void)
{
    print_menu();

    return 0;
}

