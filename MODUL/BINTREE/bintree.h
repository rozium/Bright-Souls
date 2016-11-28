/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_H_
#define _BINTREE_H_

/* Modul lain yang digunakan : */

#include "boolean.h"
#include "../MESINKATA/mesinkata.h"
#define Nil NULL
typedef struct{
  int index;
  boolean hasSkill;
  Kata namaSkill;
  Kata deskripsiSkill;
} infotype;
/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */ /* type infotype sesuai pada modul listrek */
typedef struct tNode *addrNode;
typedef struct tNode {
	infotype info;
	addrNode left;
	addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define IndexSkill(P) (P).index
#define Deskripsi(P) (P).deskripsiSkill
#define HasSkill(P) (P).hasSkill
#define NamaSkill(P) (P).namaSkill
/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
    boolean IsKataSamaString(Kata kata, char nama[30]);

BinTree SearchTreeString (BinTree P, char nama[30]);


boolean SearchHasSkill(BinTree P, char nama[30]);
/*mengirimkan true jika player punya skill dengan nama nama*/
/* Manajemen Memory */
addrNode AlokNode (infotype X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode (addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt (BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */

  // ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTree (BinTree P, int h);
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */
boolean HasTreeIndex(BinTree, int X);
//Mengembalikan true jika skill dengan idx X sudah dimiliki
/* *** Fungsi-Fungsi Lain *** */
BinTree SearchTreeIndex (BinTree P, int X);
int LevelT (BinTree P, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
int Tinggi (BinTree P);
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
BinTree SearchCurrentSkill(BinTree P);

#endif
