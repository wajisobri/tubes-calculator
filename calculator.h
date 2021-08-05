#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "binarytree.h"

#define UNDEFINE -9999
#define PI 3.14159265

void printToScreen(char* expression);

/* 	Type: Function
	Deskripsi: Menampilkan ui lalu menerima ekpresi matematika dari user input dan mengembalikan ekpresi matematikanya
	Penanggung Jawab: Luthfi Maajid
	*/
char* calculatorMenu();

/*	Type: Function
	Deskripsi: Mendapatkan derajat dari suatu operator, mengembalikan dalam bentuk integer
	Penanggung Jawab: Sobri Waskito Aji
	*/
int getDegree(char operator);

/*	Type: Function
	Deskripsi: Mendapatkan jenis/tipe dari suatu karakter, apakah angka, tanda kurung, atau operator,
			mengembalikan dalam bentuk integer
	Penanggung Jawab: Sobri Waskito Aji
	*/
int getCharType(char value);

/*	Type: Function
	Deskripsi: Melakukan perhitungan terhadap Binary Expression Tree dengan Root = T yang dilakukan secara PostOrder
			Mengembalikan dalam bentuk float
	Penanggung Jawab: Sobri Waskito Aji
	*/
float evaluateTree(addrNode T, bool *isValid);

/*	Type: Function
	Deskripsi: Memvalidasi input ekspresi matematika dengan mencocokkan jumlah tanda kurung
			Mengembalikan dalam bentuk boolean
	Penanggung Jawab: Sobri Waskito Aji
	*/
bool validateExpression(char *expression);

/* 	Type: Procedure
	Membangun Tree dengan aturan Binary Expression Tree
	I.S. : Tree belum terbentuk
	F.S. : Tree telah terbentuk berjenis Binary Expression Tree
	Penanggung Jawab: Sobri Waskito Aji
	*/
void convertExpression(char **expression, float *calculateResult, bool *isValid);

#endif