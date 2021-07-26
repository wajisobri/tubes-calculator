#include <stdio.h>
#include <stdlib.h>
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


float celciusConverter(float c, char to) {
    float result;
    
    if(to == 'R')
        result = (4/5) * c;
    else if(to == 'F')
        result = (9/5) * c + 32;
    else if(to == 'K')
        result = c + 32;
    else
        result = 0;

    return result;
}

float reamurConverter(float r, char to) {
    float result;

    if(to == 'C')
        result = (5/4) * r;
    else if(to == 'F')
        result = (9/4) * r + 32;
    else if(to == 'K')
        result = (5/4) * r + 273;
    else
        result = 0;

    return result;
}

float fahrenheitConverter(float f, char to) {
    float result;

    if(to == 'C')
        result = (5/9) * (f - 32);
    else if(to == 'R')
        result = (4/9) * (f - 32);
    else if(to == 'K')
        result = (5/9) * (f - 32) + 273;
    else
        result = 0;

    return result;
}

float kelvinConverter(float k, char to) {
    float result;

    if(to == 'C')
        result = k - 273;
    else if(to == 'F')
        result = (9/5) * (k - 273) + 32;
    else if(to == 'R')
        result = (4/5) * (k - 273);
    else
        result = 0;

    return result;
}