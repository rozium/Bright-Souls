/* File : stacklist.h */
#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include <stdlib.h>
#include "../MESINKATA/mesinkata.h"

/* Konstanta */
#define Nil NULL

/* Deklarasi infotypeS */
typedef Kata infotypeS;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * addressS;
typedef struct tElmtStack { 
	infotypeS Info;
	addressS Next; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
typedef struct { 
	addressS TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info 
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiS (addressS *P, infotypeS X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiS (addressS P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyS (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyS (Stack * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void PushS (Stack * S, infotypeS X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void PopS (Stack * S, infotypeS * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
void PrintStack (Stack S);
// Menampilkan isi dari Stack S

#endif
