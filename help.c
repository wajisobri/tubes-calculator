#include "help.h"
#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void helpMenu() {
	char ch = '\0';
	while (tolower(ch) != 'b') {
		system(CLEARSCREEN);
		puts("============BANTUAN================");
		puts("[1] Gunakan 'Kalkulator Umum' untuk menghitung ekpresi matematika");
		puts("    Simbol - simbol yang ada pada kalkulator umum:");
		puts("    1. 0 - 9, berarti angka dari 0 'nol' sampai 9 'sembilan");
		puts("    2. '(', berarti kurung buka");
		puts("    3. ')', berarti kurung tutup");
		puts("    4. ')', berarti kurung tutup");
		puts("    5. '+', berarti pertambahan");
		puts("    6. '-', berarti pengurangan");
		puts("    7. '*', berarti perkalian");
		puts("    8. '*', berarti pembagian");
		puts("    9. '^', berarti pangkat");
		puts("    10. 'v', berarti akar pangkat");
		puts("    11. 's', berarti sin");
		puts("    12. 'c', berarti cos");
		puts("    13. 't', berarti tan");
		puts("    14. 'l', berarti log");
		puts("    15. 'n', berarti ln (logaritma natural)");
		puts("    16. '.', berarti tanda koma ','");
		puts("    17. '=', berarti tanda sama dengan (menghitung ekpresi matematika)");
		puts("    18. '<-', berarti tanda hapus 1 huruf");
		puts("    19. 'CE', berarti tanda hapus semua ekpresi matematika\n");

		puts("[2] Gunakan 'Kalkulator Suhu' untuk mengkonversi suhu");
		puts("    Tersedia beberapa suhu: ");
		puts("    1. Celcius (c) ");
		puts("    2. Reamur (r) ");
		puts("    3. Fahrenheit (f) ");
		puts("    4. Kelvin (k)\n");

		puts("[3] Gunakan 'Kalkulator Bangun Datar' untuk meghitung luas bangun datar");
		puts("    Tersedia beberapa bangun datar: ");
		puts("    1. Persegi");
		puts("    2. Persegi Panjang ");
		puts("    3. Segitiga ");
		puts("    4. Trapesium ");
		puts("    5. Layang-layan ");
		puts("    4. Belah Ketupat ");
		puts("    4. Lingkaran\n");

		puts("[4] Gunakan 'Kalkulator Konversi Bilangan' untuk mengkonversi sistem bilangan");
		puts("    Tersedia beberapa sistem bilangan: ");
		puts("    1. Binary");
		puts("    2. Desimal");
		puts("    3. Oktal ");
		puts("    4. Hexadecimal\n\n");

		printf("ketik (b) untuk kembali ");
  	  	while ((ch = getchar()) != '\n' && ch != EOF);
		scanf("%c", &ch);
	}

}