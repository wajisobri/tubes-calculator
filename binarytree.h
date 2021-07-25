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
addrNode Tree(infotype data);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void CreateTree(infotype data, addrNode *Root);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */

/* Manajemen Memory */
addrNode Alokasi(infotype data);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi(addrNode T);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

infotype CreateInfo(float value, char operator);

/* *** Predikat-Predikat Penting *** */
bool IsEmpty(addrNode T);
/* Mengirimkan true jika P adalah pohon biner kosong */

bool IsLeaf(addrNode T);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */

bool HasLeftChild(addrNode T);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */

bool HasRightChild(addrNode T);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/

bool HasBinerChild(addrNode T);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

void ChangeRoot(addrNode *T, infotype data, bool isLeft);

void AddLeaf(addrNode *T, bool isLeft, infotype data);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */

void PrintTree(addrNode T);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (a (b (d () ()) ()) (c () ())) */

void DestroyTree(addrNode T);

#endif