#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "calculator-luas.h"
#include "common.h"

int awal;
int pilihan();
int persegi();
int persegiPanjang();
int segitiga();
int layang();
int trapesium();
int belahKetupat();
int lingkaran();
float sisi1,sisi2,tinggi;
float hasil;
int pilih;
float phi = 3.14;

/* 	Type: Functiom
	Menghitung luas Segitiga
	I.S. : -
	F.S : Menampilkan Halaman Awal
	Penanggung Jawab: Eben Ezer Napitu
	*/
int calculatorLuas(){
	printf("================================\n");
	printf("Pilih Bangun Ruang\n");
	printf("1. Persegi\n2. Persegi Panjang\n3. Segitiga\n4. Trapesium\n");
	printf("5. Layang-layang\n6. Belah Ketupat\n7. Lingkaran\n");
	printf(" Pilihan : %i\n", pilih);
	scanf("%i", &pilih);
	system(CLEARSCREEN);
	switch (pilih){
		case 1 :
			persegi();
			break;
		case 2 :
			persegiPanjang();
			break;
		case 3 :
			segitiga();
			break;
		case 4 :
			trapesium();
			break;
		case 5 :
			layang();
			break;
		case 6 :
			belahKetupat();
			break;
		case 7 :
			lingkaran();
			break;
		default:
			break;
	}
}
/* 	Type: Functiom
	Menghitung luas Persegi
	I.S. : sisi1=0,Luas=0
	F.S : Menampilkan luas Persegi
	Penanggung Jawab: Eben Ezer Napitu
	*/
int persegi(){
	printf("Masukkan sisi\n");
	scanf("%f",&sisi1);
	hasil=sisi1*sisi1;
	printf("Luas = %.2f",hasil);
}
/* 	Type: Functiom
	Menghitung luas Persegi Panjang
	I.S. : sisi1=0,sisi2,Luas=0
	F.S : Menampilkan luas Persegi Panjang
	Penanggung Jawab: Eben Ezer Napitu
	*/
int persegiPanjang(){
	printf("Masukkan panjang\n");
	scanf("%f",&sisi1);
	printf("Masukkan lebar\n");
	scanf("%f",&sisi2);
	hasil=sisi1*sisi2;
	printf("Luas = %.2f",hasil);
}
/* 	Type: Functiom
	Menghitung luas Segitiga
	I.S. : sisi1=0,sisi2,Luas=0
	F.S : Menampilkan luas Segitiga
	Penanggung Jawab: Eben Ezer Napitu
	*/
int segitiga(){
	printf("Masukkan sisi alas\n");
	scanf("%f",&sisi1);
	printf("Masukkan sisi tinggi\n");
	scanf("%f",&sisi2);
	hasil=0.5*sisi1*sisi2;
	printf("Luas = %.2f",hasil);
}

/* 	Type: Functiom
	Menghitung luas Trapesium
	I.S. : sisi1=0,sisi2,Luas=0
	F.S : Menampilkan luas Trapesium
	Penanggung Jawab: Eben Ezer Napitu
	*/
	
int trapesium(){
	printf("Masukkan sisi alas\n");
	scanf("%f",&sisi1);
	printf("Masukkan sisi atas\n");
	scanf("%f",&sisi2);
	printf("Masukkan sisi tinggi\n");
	scanf("%f",&tinggi);
	hasil=0.5*(sisi1+sisi2)*tinggi;
	printf("Luas = %.2f",hasil);
}

/* 	Type: Functiom
	Menghitung luas Layang-layang
	I.S. : sisi1=0,sisi2,Luas=0
	F.S : Menampilkan luas Layang-layang
	Penanggung Jawab: Eben Ezer Napitu
	*/
int layang(){
	printf("Masukkan diagonal panjang\n");
	scanf("%f",&sisi1);
	printf("Masukkan diagonal lebar\n");
	scanf("%f",&sisi2);
	hasil=0.5*sisi1*sisi2;
	printf("Luas = %.2f",hasil);
}
/* 	Type: Functiom
	Menghitung luas Belah Ketupat
	I.S. : sisi1=0,sisi2,Luas=0
	F.S : Menampilkan luas Belah Ketupat
	Penanggung Jawab: Eben Ezer Napitu
	*/
int belahKetupat(){
	printf("Masukkan diagonal 1\n");
	scanf("%f",&sisi1);
	printf("Masukkan diagonal 2\n");
	scanf("%f",&sisi2);
	hasil=0.5*sisi1*sisi2;
	printf("Luas = %.2f",hasil);
}

/* 	Type: Functiom
	Menghitung luas Lingkaran
	I.S. : sisi1=0,sisi2,Luas=0
	F.S : Menampilkan luas Lingkaran
	Penanggung Jawab: Eben Ezer Napitu
	*/
int lingkaran(){
	printf("Masukkan jari-jari\n");
	scanf("%f",&sisi1);
	hasil=phi*sisi1*sisi1;
	printf("Luas = %.2f",hasil);
}







