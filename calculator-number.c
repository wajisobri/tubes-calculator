#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "calculator-number.h"
#include <string.h>

void reverseString(char* str) {
	int n = strlen(str);
	int i, j;
	char c;

	for (i=0, j = n -1; i < j; i++, j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

char* decimalToBinary(int decimal) {
	static char binaryNum[1001];

	int i = 0;

	while (decimal != 0) {
		int temp = 0;

		temp = decimal % 2;

		binaryNum[i] = temp + 48;
		i++;

		decimal /= 2;
	}

	reverseString(binaryNum);

	return (char*) binaryNum;

}

char* decimalToOctal(int decimal) {
	static char octalNum[1001];

	int i = 0;

	while (decimal != 0) {
		int temp = 0;

		temp = decimal % 8;

		octalNum[i] = temp + 48;
		i++;

		decimal /= 8;
	}

	reverseString(octalNum);

	return (char*) octalNum;

}

char* decimalToHexadecimal(int decimal) {
	static char hexaNum[1001];

	int i = 0;

	while (decimal != 0) {
		int temp = 0;

		temp = decimal % 16;

		if (temp < 10) {
			hexaNum[i] = temp + 48;
			i++;
		} else {
			hexaNum[i] = temp + 55;
			i++;
		}

		decimal /= 16;
	}

	reverseString(hexaNum);

	return (char*) hexaNum;
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
	char result_hexa[1001];
	char result_binary[1001];
	char result_octal[1001];
	
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
			strcpy(result_binary, decimalToBinary(selected_value));
			strcpy(result_octal, decimalToOctal(selected_value));
			strcpy(result_hexa, decimalToHexadecimal(selected_value));

            printf("Binary : %s\n", result_binary);
            printf("Octal : %s\n", result_octal);
            printf("Hexa : %s\n", result_hexa);
			break;
		case 2:
			printf("Masukkan angka biner: \n");
            scanf("%d",&selected_value);
			result[0] = binaryToDecimal(selected_value);
			strcpy(result_octal, decimalToOctal(result[0]));
			strcpy(result_hexa, decimalToHexadecimal(result[0]));

            printf("Decimal : %d\n", result[0]);
            printf("Octal : %s\n", result_octal);
            printf("Hexa : %s\n", result_hexa);
			break;
		case 3:
			printf("Masukkan angka oktal: \n");
            scanf("%d",&selected_value);
			result[0] = octalToDecimal(selected_value,0);
			strcpy(result_binary, decimalToBinary(result[0]));
			strcpy(result_hexa, decimalToHexadecimal(result[0]));

            printf("Decimal : %d\n", result[0]);
            printf("Binary : %s\n", result_binary);
            printf("Hexa : %s\n", result_hexa);
			break;
		default:
			break;
	}
}