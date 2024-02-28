// Daniel Knight
// CSCI 304
// 2/27/24
// Assignment 4 - Base Convertor
// Program shall display a value in various base representations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void print_bases(short val, char mode)
{
    char cmode[4];
    char oct_str[4] = "Oct"; 
    char hex_str[4] = "Hex";
    char dec_str[4] = "Dec";
    
    switch(mode)
    {
        case 'O':
            strcpy(cmode, oct_str);
            break;
        case 'H':
            strcpy(cmode, hex_str);
            break;
        case 'D':
            strcpy(cmode, dec_str);
            break;

    }

    for (size_t i = 0; i<41; ++i)
        putchar('*');
    printf("\n");
    printf("* Base values:          ");
    printf("Input Mode: %s", cmode); printf(" *\n");
    printf("*   Hex     : %04hX\n", val);
    printf("*   Octal   : %06ho\n", val);
    printf("*   Decimal : %hd\n", val);
    for (size_t i = 0; i<41; ++i)
        putchar('*');
}

char print_menu(void) {

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
    printf("Option: ");

    char option[10]; //10 char string for errors
    char ohd;
    char valid_input[7] = "OHDCSQ";
    //char mode = "Pot"; //can't reassign strings??
    int valid = 0;
    while(valid == 0){
       // printf("Please enter a valid option: ");
        scanf("%s", option);
        ohd = toupper(option[0]);

        if(strlen(option)>1 || !strchr(valid_input, ohd)){
            printf("Input is invalid. Please try again.\n");
            sleep(1);
            print_menu();
        }
        else {
            valid ++;
        }
    }
    return ohd;
}

short get_operand(char mode)
{
    unsigned int baseVal;
    switch(mode) 
    {
        case 'O':
            scanf("%o", &baseVal);
            break;
        case 'H':
            scanf("%x", &baseVal); //scan in input as hex
            break;
        case 'D':
            scanf("%d", &baseVal);
            break;
        default:
            break;
    }
    return baseVal;
};

int main(void)
{
    int quit = 0;
    int val = 0;
    char mode[10] = "Dec";
    char opt;
    while (quit == 0)
    {
        print_bases(val, mode[0]);
        opt = print_menu(); //returns option, opt is what user choose
        
        switch(opt) {
            case 'O':
                printf("you chose O");
                //mode[10] = "O";
                char o[10] = "Oct";
                strcpy(mode, o);
                //get_operand(mode[0]); //changes input type to octal mode, ie user enters number with an octal base
                break;
            case 'H':
                printf("you chose H");
                char h[3] = "Hex";
                strcpy(mode, h);
                break;
            case 'D': 
                printf("you chose D");
                char d[3] = "Dec";
                strcpy(mode, d);
                break;
            case 'C':
                printf("this clears the value\n");
                val = 0;
                break;
            case 'S': //user should set value with base in mind
                //int newVal;
                printf("please enter a number: ");
                int newVal = get_operand(mode[0]); //returns input in appropriate base form
                val = newVal; //updates menu value
                break;
            case 'Q':
                printf("Ending program....\n");
                sleep(1);
                quit ++;
                break;
            default:
                quit++;
                break;
        }
        
    }

    return 0;
}

