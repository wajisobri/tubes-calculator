/* File    : binary-tree.h 					*/
/* Desk    : Header binary search tree 	*/
/* Oleh    : Kelompok 3 Tubes Algoritma dan Struktur Data D4-1B*/
/* Tgl	   : 22 / 07 / 2021	  			*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	...
*/
typedef struct infotype {
	char operasi;
	double operand;
}infotype;

typedef struct tNode *addrNode;

typedef struct tNode {
  addrNode parent;
  infotype info;
  addrNode left;
  addrNode right;
}Node;

/*
	...
*/
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Nil NULL 
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Parent(P) (P)->parent

/* *** Konstruktor *** */
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
BinTree Tree(infotype Akar, BinTree L, BinTree R, BinTree P);

/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree P, BinTree *T);

/* Manajemen Memory */

/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
addrNode AlokNode(infotype X);

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
void DealokNode(addrNode P);

/* *** Predikat-Predikat Penting *** */

/* Mengirimkan true jika P adalah pohon biner kosong */
bool IsTreeEmpty(BinTree P);

/*
	...
*/
void ChangeAkar(BinTree *P, infotype X, bool kiri);

/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void AddDaun(BinTree *P, infotype X, bool Kiri);

#endif
