#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "binarytree.h"
#include "calculator.h"
#include "calculator-luas.h"
#include "calculator-temperature.h"
#include "calculator-number.h"
#include "credits.h"
#include "help.h"

int main(){
	int pilihan = 1;

	// variabel lokal untuk kalkulator umum
	char expressionInput[1001];
	char *expressionInputAddr;
	float calculateResult;
	bool isValid;


	while(pilihan != 7) {
		do {
			system(CLEARSCREEN);
			printf("MENU KALKULATOR\n");
			printf("1. Kalkulator Umum\n");
			printf("2. Kalkulator Suhu\n");
			printf("3. Kalkulator Bangun Datar\n");
			printf("4. Kalkulator Konversi Bilangan\n");
			printf("5. Bantuan\n");
			printf("6. Credits\n");
			printf("7. Keluar\n");

			if ((pilihan < 1) || (pilihan > 7)) {
				printf("Input opsi yang benar!\n");
			}


			printf("INPUT: ");
			scanf("%d", &pilihan);

		} while ((pilihan < 1) || (pilihan > 7));


		switch (pilihan) {
			case 1:
			// pilihan kalkulator umum
				system(CLEARSCREEN);

				strcpy(expressionInput, calculatorMenu());

				isValid = validateExpression(expressionInput);

				if(isValid) {
					// cek validitas ekpresi matematika
					expressionInputAddr = expressionInput;
					convertExpression(&expressionInputAddr, &calculateResult, &isValid);
				} else {
					printf("Expression Not Valid\n");
				}

				if (isValid) {
					printf("\nMATH EXPRESSION: "); printToScreen(expressionInput);
					printf("\nRESULT: %.2f\n", calculateResult);
				}

				break;
			
			case 2:
			// pilihan kalkulator suhu
				system(CLEARSCREEN);
				suhuConverterMenu();

				break;

			case 3:
			// pilihan kalkulator bangun ruang
				system(CLEARSCREEN);
				calculatorLuas();

				break;
				
			case 4:
			// pilihan kalkulator konversi bilangan
				system(CLEARSCREEN);
				bilanganConverterMenu();

				break;

			case 5:
			// pilihan menu bantuan
				system(CLEARSCREEN);
				helpMenu();

				break;

			case 6:
			// pilihan menu credits
				system(CLEARSCREEN);
				creditsMenu();

				break;

			default:
				break;
		}

		if ((pilihan != 7) && (pilihan != 5) && (pilihan != 6)){
			char ch;
			printf("\n\nUlangi? (y/n): ");
			scanf("%s", &ch);
			if (tolower(ch) != 'y') {
				break;
			}
		}

	}

}