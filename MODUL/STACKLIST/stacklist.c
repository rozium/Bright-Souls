	// NIM / Nama		: 13515026 / Achmad Fahrurrozi Maskur
// Nama File		: stacklist.c		
// Tanggal			: 1 November 2016

#include "boolean.h"
#include "stacklist.h"
#include <stdlib.h>
#include <stdio.h>

void CreateEmptyS (Stack * S) 
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
{
	Top(*S) = Nil;
}

void AlokasiS (addressS * P, infotypeS X) 
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */

{
	(*P) = (addressS) malloc (sizeof (ElmtStack));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void DealokasiS (addressS P) 
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

{
	free(P);
}

boolean IsEmptyS (Stack S) 
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
	return (Top(S) == Nil);
}

void PushS (Stack * S, infotypeS X) 
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */

{
	addressS P;
	AlokasiS(&P,X);
	if (P != Nil) {
		Next(P) = Top(*S);
		Top(*S) = P;
	}
}

void PopS (Stack * S, infotypeS * X) 
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
	addressS P;
	P = Top(*S);
	(*X) = InfoTop(*S);
	Top(*S) = Next(Top(*S));
	Next(P) = Nil;
	DealokasiS(P);
}

void PrintStack (Stack S)
// Menampilkan isi dari Stack S
{
	addressS P;
	P = Top(S);
	while (P != Nil) {
		for (int i = 1 ; i <= Info(P).Length ; i++)
			printf("%c",Info(P).TabKata[i]);
		P = Next(P);
		printf("\n");
	}
}