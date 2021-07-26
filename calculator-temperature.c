#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "calculator-temperature.h"
#include "common.h"

/* 	Type: Functiom
    Menampilkan menu temperature
	I.S. : -
	F.S : Menampilkan Halaman Awal
	Penanggung Jawab: Luthfi Maajid
	*/
void calculatorTemperature(){
    int pilih = 0;
    float input_temperature;
    float hasil_konversi;

    do {
        printf("================================================================================\n");
    	printf("Pilih Bangun Ruang\n");
    	printf("1. Celcius to Fahrenheit\n2. Celcius to Reamur\n3. Celcius to Kelvin\n");
    	printf("4. Fahrenheit to Celcius\n5. Fahrenheit to Reamur\n6. Fahrenheit to Kelvin\n");
    	printf("7. Reamur to Celcius\n8. Reamuer to Fahrenheit\n9. Reamur to Kelvin\n");
    	printf("10. Kelvin to Celcius\n11. Kelvin to Fahrenheit\n12. Kelvin to Celcius\n");

        if ((pilih < 1) && (pilih > 12)) {
            printf("Pilih opsi yang benar!");
        }

    	printf(" Pilihan : ");
    	scanf("%i", &pilih);
    	system(CLEARSCREEN);

    } while ((pilih < 1) && (pilih > 12));

    printf("Masukkan Suhu: ");
    scanf("%f", &input_temperature);

	switch (pilih){
		case 1 :
            hasil_konversi = celciusConverter(input_temperature, 'F');
			
			break;
		case 2 :
            hasil_konversi = celciusConverter(input_temperature, 'R');

			break;
		case 3 :
            hasil_konversi = celciusConverter(input_temperature, 'K');

			break;
		case 4 :
            hasil_konversi = fahrenheitConverter(input_temperature, 'C');

			break;
		case 5 :
            hasil_konversi = fahrenheitConverter(input_temperature, 'R');

			break;
		case 6 :
            hasil_konversi = fahrenheitConverter(input_temperature, 'K');

			break;
		case 7 :
            hasil_konversi = reamurConverter(input_temperature, 'C');

			break;
 		case 8 :
            hasil_konversi = reamurConverter(input_temperature, 'F');

			break;
		case 9 :
            hasil_konversi = reamurConverter(input_temperature, 'K');

			break;
		case 10 :
            hasil_konversi = kelvinConverter(input_temperature, 'C');

			break;
		case 11 :
            hasil_konversi = kelvinConverter(input_temperature, 'F');

			break;
		case 12 :
            hasil_konversi = kelvinConverter(input_temperature, 'R');

			break;
       
		default:
			break;
	}

    printf("Hasil konversi: %.2f\n", hasil_konversi);
}


void gotoxy(int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

float celciusConverter(float c, char to) {
    float result;
    
    if(tolower(to) == 'r')
        result = (4.0/5.0) * c;
    else if(tolower(to) == 'f')
        result = (9.0/5.0) * c + 32;
    else if(tolower(to) == 'k')
        result = c + 32;
    else
        result = c;

    return result;
}

float reamurConverter(float r, char to) {
    float result;

    if(tolower(to) == 'C')
        result = (5.0/4.0) * r;
    else if(tolower(to) == 'F')
        result = (9.0/4.0) * r + 32;
    else if(tolower(to) == 'K')
        result = (5.0/4.0) * r + 273;
    else
        result = r;

    return result;
}

float fahrenheitConverter(float f, char to) {
    float result;

    if(tolower(to) == 'C')
        result = (5.0/9.0) * (f - 32);
    else if(tolower(to) == 'R')
        result = (4.0/9.0) * (f - 32);
    else if(tolower(to) == 'K')
        result = (5.0/9.0) * (f - 32) + 273;
    else
        result = f;

    return result;
}

float kelvinConverter(float k, char to) {
    float result;

    if(tolower(to) == 'C')
        result = k - 273;
    else if(tolower(to) == 'F')
        result = (9.0/5.0) * (k - 273) + 32;
    else if(tolower(to) == 'R')
        result = (4.0/5.0) * (k - 273);
    else
        result = k;

    return result;
}

bool validateInput(char c) {
    if(tolower(c) == 'c' || tolower(c) == 'r' || tolower(c) == 'f' || tolower(c) == 'k')
        return true;
    else
        return false;
}

void suhuConverterMenu() {
    char from, to;
    float fromTemp;
    char degree=248;

    printf("===============================\n");
    printf("=        Konversi Suhu        =\n");
    printf("===============================\n");
    printf("Unit Konversi\n");
    printf("R : Reamur      C : Celcius\n");
    printf("F : Fahrenheit  K : Kelvin\n");

    gotoxy(1,10);
    printf("DARI (C/R/F/K)  :");
    gotoxy(1,11);
    printf("SUHU (SATUAN%c)  :",degree);

    gotoxy(1,14);
    printf("KE (C/R/F/K)    :");
    gotoxy(1,15);
    printf("SUHU (SATUAN%c)  :",degree);

    do {
        gotoxy(19,10);
        scanf("%c",&from);
    } while(validateInput(from) == false);
    gotoxy(19,11);
    scanf("%f",&fromTemp);
    fflush(stdin);
    do {
        gotoxy(19,14);
        scanf("%c",&to);
    } while(validateInput(to) == false);

    float result;
    if(tolower(from) == 'c') {
        result = celciusConverter(fromTemp, to);
    } else if(tolower(from) == 'r') {
        result = reamurConverter(fromTemp, to);
    } else if(tolower(from) == 'f') {
        result = fahrenheitConverter(fromTemp, to);
    } else if(tolower(from) == 'k') {
        result = kelvinConverter(fromTemp, to);
    }

    gotoxy(19,15); printf("%.2f",result); 
}