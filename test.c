// Daniel Knight
// CSCI 304
// 3/26q/24
// Assignment 6 - Base Calculator
// Program perform various bitwise and arithmetic operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include "calc.h"

void convert_to_binary(short val, bin_str bin){
    // convert short val to binary str for output
    // only needs to display val as binary, so don't return anything
    //take val 7 and turn it into 111; may use modulo to gett remainder
    bin_str new_bin;
    while(val > 0) { //proivdes a string but backwards 1101
        if (val%2 != 0) {
            strcpy(new_bin, "1"); 
        }
        else
            strcpy(new_bin, "0");
        val = val/2;
    }
    //reverse string 
    // retuns nothing, just changes binary string
    for (int i = 0, j = strlen(new_bin)-1; i <= j; i--) { 
        char c = new_bin[i];
        bin[i] = new_bin[j];
        bin[j] = c;
        printf("%c", bin[i]);
    }
    strcpy(bin, new_bin);
}

void print_bases(short val, char mode)
{
    //holds display characters for current mode
    char cmode[4];
    char oct_str[4] = "Oct"; 
    char hex_str[4] = "Hex";
    char dec_str[4] = "Dec";
    char bi_str[4] = "Bin";

    bin_str binary = "0000 0000 0000 0000";
    //convert_to_binary(val, binary);

    switch(mode)
    {
        case 'B':
            strcpy(cmode, bi_str);
            break;
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
    printf("* Base values:          Input Mode: %s\n", cmode);
    printf("*   Binary  : %s\n", binary);
   // convert_to_binary(val, binary);
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
    printf("B Binary Mode             & AND with Value             + Add to Value\n");
    printf("O Octal Mode              | OR with Value              - Subtract from Value\n");
    printf("H Hexidecimal Mode        ^ XOR with Value             N Negate Value\n");
    printf("D Decimal Mode            ~ Complement Value\n");
    printf("\n");
    printf("C Clear Value             < Shift Value Left\n");
    printf("S Set Value               > Shift Value Right\n");
    printf("\n");
    printf("Q Quit\n");
    printf("\n");
    printf("Option: ");

    /////get user input for option
    char option[10]; //10 char string for errors
    char input;
    char valid_input[16] = "OHDCSQB&|^~<>+-N";
    //char mode = "Pot"; //can't reassign strings??
    int valid = 0;
    while(valid == 0){
        scanf("%s", option);
        input = toupper(option[0]);

        if(strlen(option)>1 || !strchr(valid_input, input)){
            printf("Input is invalid. Please try again.\n");
            sleep(1);
            print_menu();
        }
        else {
            valid ++;
        }
    }
    return input;
}
//pass (array) by reference (not value) - you can change the contents of the array (python term-it's mutable)
//less than 16 characters, zeros on left -- strlen() == characters enter
//start at very first bit entered, shifting as your going so value ends up on the right
//check first character, if one, set it as value counter >>>you will be looping...checking until end of string character constatnly multipliying by 2 (counter) and adding 1 to stiing if theres a 1
//repeatedly multiply by 2 in a loop to get column values

unsigned short get_binary_op(bin_str bin){
    // convert bin str to short; return value
    //take 101 and turn it into 5
    short bin_value = 0;
    short column = 0;
    for (int i = strlen(bin)-1, j = 0; i >= 0; i--, j++) { //iterates through binary string right to left
        if (bin[i] == '1') {
            column = pow(2, j); //gets value for the current column 2^x
            bin_value += column;
        }
    }
    return bin_value;
}

//convert short value to binary and put in temp string; seperate loop copies bits with a space after every 4 (spaces based on indices)

short get_operand(char mode)//tells program how to interpret input
{
    bin_str bin;
    unsigned int baseVal;
    switch(mode) 
    {
        case 'B':
            //bin_str bin;
            scanf ("%s", bin); //read in as a char string, 
            //scanf("%s", bin); 
            baseVal = get_binary_op(bin); //then convert to binary to store as base value
            //baseVal = bin;
            break;
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



void add (short *val, char mode) {
    // call get_operand to get value in mode
    // to add to val; detect pos/neg overflow
    short second_val;
    printf("Please enter value to add\n");
    second_val = get_operand(mode);
    short result = *val + second_val;
    if (*val < 0 && second_val < 0 && result > 0 ) {
        printf("negative overflow\n");
    }
    else if (*val > 0 && second_val > 0 && result < 0) {
        printf("positive overflow\n");
    }
    *val = result;
}

//FIX THIS OVERFLOW, different for subtraction; 
void subtract(short *val, char mode) {
    // similar to add, but subtract
    short second_val;
    printf("Please enter value to subtract\n");
    second_val = get_operand(mode);
    short result = *val - second_val;
    if (*val < 0 && second_val > 0 && result > 0 ) {
        printf("negative overflow\n");
    }
    else if (*val > 0 && second_val < 0 && result < 0) {
        printf("positive overflow\n");
    }
    *val = result;

}

int main(void)
{
    int quit = 0;
    short val = 0;
    short num_two = 0;
    char mode[10] = "Dec";// default mode
    char opt;
    char o[10] = "Oct";
    char h[3] = "Hex";
    char d[3] = "Dec";
    char b[3] = "Bin";
    int shift = 0;
    while (quit == 0)
    {
        print_bases(val, mode[0]);
        opt = print_menu(); //returns option, opt is what user choose
        
        switch(opt) { //inquier about while(!q)
            case 'O':
                //char o[10] = "Oct";
                strcpy(mode, o);
                break;
            case 'H':
                strcpy(mode, h);
                break;
            case 'D': 
                strcpy(mode, d);
                break;
            case 'B':
                strcpy(mode, b);
                break;
            case '&':
                printf("please enter second number: ");
                num_two = get_operand(mode[0]);
                val = val & num_two;
                break;
            case '|':
                printf("please enter second number: ");
                num_two = get_operand(mode[0]);
                val = val | num_two;
                break;
            case '^':
                printf("please enter second number: ");
                num_two = get_operand(mode[0]);
                val = val ^ num_two;
                break;
            case '~':
                val = ~val;
                break;
            case '<':
                printf("please enter a shift value: ");
                //short shift;
                scanf("%d", &shift);
                val = val << shift;
                break;
            case '>':
                printf("please enter a shift value: ");
                //short shift;
                scanf("%d", &shift);
                val = val >> shift;
                break;
            case '+':
                add(&val, mode[0]); //takes current val; function will prompt for second val
                break;
            case '-':
                subtract(&val, mode[0]);
                break;
            case 'N':
                val = -val;
                break;
            case 'C':
                //printf("value cleared\n");
                val = 0;
                break;
            case 'S': //user should set value with base in mind
                printf("please enter a number: \n");
                int newVal = get_operand(mode[0]); //returns input in appropriate base form
                val = newVal; //updates menu value
                break;
            case 'Q':
                quit ++;
                break;
            default:
                quit++;
                break;
        }
    }

    return 0;
}

