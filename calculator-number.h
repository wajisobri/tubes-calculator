#ifndef _CALCULATORNUMBER_H_
#define _CALCULATORNUMBER_H_

#include <stdio.h>
#include <stdlib.h>

void reverseString(char* str);
char* decimalToBinary(int decimal);
char* decimalToOctal(int decimal);
char* decimalToHexadecimal(int decimal);
int binaryToDecimal(int binary);
int octalToDecimal(int octal, int i);
void bilanganConverterMenu();

#endif