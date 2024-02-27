#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_bases(short val, char mode)
{

    
    for (size_t i = 0; i<41; ++i)
        putchar('*');
    printf("\n");
    printf("* Base values:          ");
    printf("Input Mode: %s", mode); printf(" *\n");
    printf("*   Hex     : %d\n", val);
    printf("*   Octal   : %d\n", val);
    printf("*   Decimal : %d\n", val);
    //printf("\n");
    for (size_t i = 0; i<41; ++i)
        putchar('*');
    printf("\n");
    printf("Please select one of the following options\n");
    printf("\n");
    printf("O Octal Mode\n");
    printf("H Hexadecimal Mode\n");
    printf("D Decimal Mode\n");
    printf("\n");
    printf("C Clear Value\n");
    printf("S Set Value\n");
    printf("\n");
    printf("Q Quit\n");
    printf("\n");
    printf("Option: \n");
}

char print_menu(void) {
    int hex = 0;
    int oct = 0;
    int dec = 0;
    int val = 0;
    //char mode[] = "Dec";
    char mode = "D";

    print_bases(val, mode);

    char option[10]; //10 char string for errors
    //char mode = "Pot"; //can't reassign strings??

    int isValid = 0;
    while (isValid != 1) 
        {
            scanf("%s", option);
            char optChar = option[0]; //gets char at pos 0
            optChar = toupper(optChar);
            //printf("please print valid mode \n");
            
            switch(optChar) {
                case 'O':
                    printf("Octal\n");
                    //char mode = "Oct";
                    isValid = 1;
                    //octConv(val);
                    break;
                case 'H':
                    printf("Hexadec\n");
                    isValid = 1;
                    //hexConv(val);
                    break;
                case 'D':
                    printf("Decimal\n");
                    isValid = 1;
                    //decVal(val);
                    break;
                case 'C':
                    printf("clear value\n");
                    isValid = 1;
                    //val = 0;
                    break;
                case 'S':
                    printf("set value\n");
                    //isValid = 1;
                    //scanf("%d", newVal)
                    //val = newVal
                    break;
                case 'Q':
                    printf("quit\n");
                    isValid = 1;
                    //terminate program
                    break;
                defalut:  //NOT WORKING???
                    printf("please enter a valid mode.\n");
                    //scanf(" %c", &optChar);
                    break;
        }
        printf("please enter a valid mode.\n");
    }
    //print_bases(0, optChar);
    print_bases(val, mode);
    printf("no more lupin!");
    //printf("U CHOOSE: %c\n", optChar);
}

//int decConverter(){}
//int hexConvertor(){}
//int octConvertor(){}

int main(void)
{
    print_menu();

    return 0;
}

