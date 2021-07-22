/* File    : binary-tree.c 					*/
/* Desk    : Implementasi dari header binary search tree 	*/
/* Oleh    : Kelompok 3 Tubes Algoritma dan Struktur Data D4-1B*/
/* Tgl	   : 22 / 07 / 2021	  			*/

#include "binary-tree.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* *** Konstruktor *** */

/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
BinTree Tree(infotype Akar, BinTree L, BinTree R, BinTree P){
	BinTree T;
	
	T = AlokNode(Akar);
	if(T != Nil){
		Left(T) = L;
		Right(T) = R;
		Parent(T) = P;
		
		return T;
	}
	else{
		return Nil;
	}
}

/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree P, BinTree *T){
	*T = Tree(Akar,L,R,P);
}

/* Manajemen Memory */

/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
addrNode AlokNode(infotype X){
	BinTree T;
	
	T = (addrNode) malloc (sizeof(Node));
	if(T != Nil){
		Akar(T) = X;
		Left(T) = Nil;
		Right(T) = Nil;
		Parent(T) = Nil;
		
		return T;
	}
	else{
		return Nil;
	}
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
void DealokNode(addrNode P){
	free(P);
}

/* *** Predikat-Predikat Penting *** */

/* Mengirimkan true jika P adalah pohon biner kosong */
bool IsTreeEmpty(BinTree P){
	return(P == Nil);
}

/* *** Operasi lain *** */

/* I.S.  */
/* F.S.  */
void ChangeAkar(BinTree *P, infotype X, bool kiri){
	addrNode M;
	
	M = AlokNode(X);
	
	if (*P != Nil){
		if (kiri) {
			Left(M) = *P;
		}
		else {
			Right(M) = *P;
		}

		Parent(M) = Parent(*P);
		Parent(*P) = M;

		if (Parent(M) != Nil) {
			if (Left(Parent(M)) == *P) {
				Left(Parent(M)) = M;
			}
			else {
				Right(Parent(M)) = M;
			}
		}
	}
	
	*P = M;
}

/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void AddDaun(BinTree *P, infotype X, bool Kiri){
	addrNode M;
	
	M = AlokNode(X);
	
	if(IsTreeEmpty(*P)){
		*P = M;
	}
	else{
		if(Kiri){
			Left(M) = Left(*P);
			if(Left(M) != Nil){
				Parent(Left(*P)) = M;
			}
			Left(*P) = M;
		}
		else{
			Left(M) = Right(*P);
			if(Left(M) != Nil){
				Parent(Right(*P)) = M;
			}
			Right(*P) = M;
		}
		
		Parent(M) = *P;
	}
}