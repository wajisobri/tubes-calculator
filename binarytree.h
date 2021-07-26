#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <stdbool.h>
#include <stdlib.h>

#define Nil NULL

typedef struct {
	char operator;
	float value;
} infotype;

typedef struct tNode *addrNode;
typedef struct tNode {
  addrNode parent;
  infotype info;
  addrNode left;
  addrNode right;
} Node;

typedef addrNode root;

#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Parent(P) (P)->parent

/* *** Konstruktor *** */
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
/* Penanggung jawab: Luthfi Maajid */
addrNode Tree(infotype data);

/* Manajemen Memory */

/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
/* Penanggung jawab: Luthfi Maajid */
addrNode Alokasi(infotype data);

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
/* Penanggung jawab: Luthfi Maajid */
void Dealokasi(addrNode T);

/*
  konstruktor statis untuk infotype, menerima 2 input lalu mengembalikan dengan tipe struct infotype
  Penanggung jawab: Luthfi Maajid
*/
infotype CreateInfo(float value, char operator);

/* *** Predikat-Predikat Penting *** */

/* Mengirimkan true jika P adalah pohon biner kosong */
/* Penanggung jawab: Eben Ezer Napitu */
bool IsEmpty(addrNode T);

/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
/* Penanggung jawab: Eben Ezer Napitu */
bool IsLeaf(addrNode T);

/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
/* Penanggung jawab: Luthfi Maajid*/
bool HasLeftChild(addrNode T);

/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
/* Penanggung jawab: Eben Ezer Napitu */
bool HasRightChild(addrNode T);

/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
/* Penanggung jawab: Eben Ezer Napitu*/
bool HasBinerChild(addrNode T);

/* I.S. Root tree sembarang */
/* F.S. Root tree digantikan oleh T*/ 
/* Penanggung jawab: Sobri Waskito Aji */
void ChangeRoot(addrNode *T, infotype data, bool isLeft);

/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
/* Penanggung jawab: Sobri Waskito Aji */
void AddLeaf(addrNode *T, bool isLeft, infotype data);

/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (a (b (d () ()) ()) (c () ())) */
/* Penanggung jawab: Luthfi Maajid */
void PrintTree(addrNode T);

/* I.S. T terdefinisi */
/* F.S. Tree T beserta seluruh node nya ter dealokasi */
/* Penanggung jawab: Luthfi Maajid */
void DestroyTree(addrNode T);

#endif