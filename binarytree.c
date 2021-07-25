#include "binarytree.h"
#include <stdio.h>

/* *** Konstruktor *** */
addrNode Tree(infotype data){
	addrNode Root;
	
	Root = Alokasi(data);
	if(Root != Nil){
		Left(Root) = Nil;
		Right(Root) = Nil;
		Parent(Root) = Nil;
		return Root;
	} else{
		return Nil;
	}
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void CreateTree(infotype data, addrNode *Root) {
	*Root = Tree(data);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */

/* Manajemen Memory */
addrNode Alokasi(infotype data) {
	addrNode P;
	
	P = (addrNode) malloc(sizeof(Node));
	if(P != Nil){
		Info(P) = data;
		Left(P) = Nil;
		Right(P) = Nil;
		Parent(P) = Nil;
		return P;
	} else {
		return Nil;
	}
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi(addrNode T) {
	free(T);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

infotype CreateInfo(float value, char operator) {
	infotype tempInfo;

	tempInfo.value = value;
	tempInfo.operator = operator;

	return tempInfo;
}

/* *** Predikat-Predikat Penting *** */
bool IsEmpty(addrNode T) {
	return(T == Nil);
}
/* Mengirimkan true jika P adalah pohon biner kosong */

bool IsLeaf(addrNode T) {
	return((Right(T) == Nil) && (Left(T) == Nil));
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */

bool HasLeftChild(addrNode T) {
	return((Right(T) == Nil) && (Left(T) != Nil));
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */

bool HasRightChild(addrNode T) {
	return((Right(T) != Nil) && (Left(T) == Nil));
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/

bool HasBinerChild(addrNode T) {
	return((Right(T) != Nil) && (Left(T) != Nil));
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Operasi lain *** */
void ChangeRoot(addrNode *T, infotype data, bool isLeft) {
	addrNode P;
	P = Alokasi(data);
	
	if (*T != Nil) {
		if(isLeft)
			Left(P) = *T;
		else
			Right(P) = *T;
		

		Parent(P) = Parent(*T);
		Parent(*T) = P;

		if (Parent(P) != Nil) {
			if (Left(Parent(P)) == *T)
				Left(Parent(P)) = P;
			else
				Right(Parent(P)) = P;
		}
	}
	*T = P;
}

void AddLeaf(addrNode *T, bool isLeft, infotype data){
	addrNode P;
	P = Alokasi(data);
	
	if(IsEmpty(*T)) {
		*T = P;
	} else {
		if(isLeft) {
			Left(P) = Left(*T);
			if(Left(P) != Nil)
				Parent(Left(*T)) = P;
			Left(*T) = P;
		} else {
			Left(P) = Right(*T);
			if(Left(P) != Nil)
				Parent(Right(*T)) = P;
			Right(*T) = P;
		}
		Parent(P) = *T;
	}
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */

void PrintTree(addrNode T) {
	if (IsEmpty(T)) {
		printf("[]");
	} else {
		printf("[%.2f(%c)", Info(T).value, Info(T).operator);
		PrintTree(Left(T));
		printf(" ");
		PrintTree(Right(T));
		printf("]");
	}
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (a (b (d () ()) ()) (c () ())) */

void DestroyTree(addrNode T) {
	//menghapus dan dealokasi tree
	if(HasLeftChild(T)) DestroyTree(Left(T));
	if(HasRightChild(T)) DestroyTree(Right(T));
	Dealokasi(T);
}