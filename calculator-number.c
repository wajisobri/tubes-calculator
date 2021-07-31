#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "calculator-number.h"

int decimalToBinary(int decimal) {
	static int counter = 0;
	counter++;
	if (decimal==0) return 0;
	if (decimal==1) return pow(10,counter-1);
	int r = (decimal % 2) * (pow(10,counter-1));
	return decimalToBinary(decimal/2) + r;
}

int decimalToOctal(int decimal) {
	static int counter = 0;
	counter++;
	if(decimal==0) return 0;
	if(decimal==1) return pow(10, counter-1);
	int r = (decimal % 8) * (pow(10, counter-1));
	return decimalToOctal(decimal/8) + r;
}

int decimalToHexadecimal(int decimal) {
	static int counter = 0;
	counter++;
	if (decimal==0) return 0;
	if (decimal==1) return pow(10,counter-1);
	int r = (decimal % 16) * (pow(10,counter-1));
	return decimalToHexadecimal(decimal/16) + r;
}

int binaryToDecimal(int binary) {
    if(binary == 0) return 0;
    else return (binary % 10 + 2* binaryToDecimal(binary / 10));
}

int octalToDecimal(int octal, int i) {
	/*
        *'i' represents the nth recursive call as well as
        *nth digit from right, so it can be used as an exponent
    */
    if(octal >= 0 && octal <= 7)
        return pow(8,i)*octal;
        
    int digit = octal%10;
    
    return (pow(8,i) * digit) + octalToDecimal(octal/10, ++i);
}

void bilanganConverterMenu() {
	int selected_value, option, result[3];
	
	printf("===============================\n");
    printf("=      Konversi Bilangan      =\n");
    printf("===============================\n");
    printf("Unit Konversi\n");
    printf("(1) Decimal to Binary, Octal, Hexa\n");
    printf("(2) Binary to Decimal, Octal, Hexa\n");
	printf("(3) Octal to Binary, Decimal, Hexa\n");

	printf("Pilih Unit Konversi:\n");
	scanf("%i", &option);
	switch(option){
		case 1:
            printf("Masukkan angka desimal: \n");
            scanf("%d",&selected_value);
			result[0] = decimalToBinary(selected_value);
            result[1] = decimalToOctal(selected_value);
            result[2] = decimalToHexadecimal(selected_value);

            printf("Binary : %d\n", result[0]);
            printf("Octal : %o\n", result[1]);
            printf("Hexa : %X\n", result[2]);
			break;
		case 2:
			printf("Masukkan angka biner: \n");
            scanf("%d",&selected_value);
			result[0] = binaryToDecimal(selected_value);
            result[1] = decimalToOctal(result[0]);
            result[2] = decimalToHexadecimal(result[0]);

            printf("Decimal : %d\n", result[0]);
            printf("Octal : %o\n", result[1]);
            printf("Hexa : %X\n", result[2]);
			break;
		case 3:
			printf("Masukkan angka oktal: \n");
            scanf("%d",&selected_value);
			result[0] = octalToDecimal(selected_value,0);
            result[1] = decimalToBinary(result[0]);
            result[2] = decimalToHexadecimal(result[0]);

            printf("Decimal : %d\n", result[0]);
            printf("Binary : %o\n", result[1]);
            printf("Hexa : %X\n", result[2]);
			break;
		default:
			break;
	}
}