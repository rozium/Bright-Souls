/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _QUEUELISTL_H
#define _QUEUELISTL_H
#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotypeQL;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueueL * addressQL;
typedef struct tElmtQueueL { 
	infotypeQL Info;
	addressQL Next; 
} ElmtQueueL; 

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct { 
	addressQL HEAD;  /* alamat penghapusan */
	addressQL TAIL;  /* alamat penambahan */
} QueueL;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiQL (addressQL *P, infotypeQL X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiQL (addressQL  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyQL (QueueL Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmtQL(QueueL Q);
/* Mengirimkan banyaknya elemen queueL. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyQL(QueueL * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void AddQL (QueueL * Q, infotypeQL X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DelQL(QueueL * Q, infotypeQL * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
void PrintQueueQL(QueueL Q);

void PrintQueueEL(QueueL Q, int tutup1, int tutup2);
// Menampilkan isi dari Queue Q

#endif
