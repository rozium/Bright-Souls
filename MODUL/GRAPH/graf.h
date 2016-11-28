#ifndef graf_H
#define graf_H

#include "boolean.h"
#include "../POINT/point.h"

#define Nil NULL

typedef struct tElmtTitik *adrTitik;
typedef struct tElmtGRAF *adrGraf;
typedef struct tElmtTitik{
	POINT titik;
 	char dir;
  	adrTitik nextTitik;
  	adrGraf connectedTo;
} ElmtTitik;


typedef struct tElmtGRAF {
	int index;
	adrTitik firstTitik;
  	adrGraf nextNode;
  	adrGraf prevNode;
} ElmtGRAF;

typedef struct {
	adrGraf firstGraf;
} GRAF;


#define FirstGraf(G) (G).firstGraf
#define NextNode(P) (P)->nextNode
#define PrevNode(P) (P)->prevNode
#define FirstTitik(P) (P)->firstTitik
#define Titik(P) (P)->titik
#define Dir(P) (P)->dir
#define NextTitik(P) (P)->nextTitik
#define Index(P) (P)->index
#define ConnectTo(P) (P)->connectedTo

/****************** TEST GRAF KOSONG ******************/
boolean IsEmptyGraf (GRAF G);
/* Mengirim true jika GRAF kosong */

/****************** PEMBUATAN GRAF KOSONG ******************/
void CreateEmptyGraf (GRAF *G);
/* I.S. sembarang             */
/* F.S. Terbentuk GRAF kosong */

/****************** Manajemen Memori ******************/

adrTitik AlokasiTitik (char dirr, POINT point);
/* Mengirimkan address hasil alokasi sebuah dirr dan point */
/* Jika alokasi berhasil, maka adrTitik tidak nil, dan misalnya */
/* menghasilkan P, maka Dir(P)=dirr, Titik(P)=point, NextTitik(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

adrGraf AlokasiGraf (int indeks);
/* Mengirimkan address hasil alokasi sebuah indeks */
/* Jika alokasi berhasil, maka adrGraf tidak nil, dan misalnya */
/* menghasilkan P, maka Index(P)=indeks, NextNode(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiGraf (adrGraf *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsGraf (GRAF *G, int indeks, adrGraf *Pgrf);
/* Menambahkan indeks ke Graf G dengan melakukan alokasi terlebh dahulu */

void InsTitik(adrGraf PG, char dir, POINT point , adrGraf ConPG);
//Menambahkan titik pada adrGraf PG dengan melakukan alokasi terlebih dahulu

adrGraf SearchGraf(GRAF G, int idx, boolean *found);
//menghasilkkan adrGraf dengan indeks idx

adrTitik SearchTitik(GRAF G ,int idx, char dir);
//menghasilkkan titik pada graf dengan index idx dengan char dir



#endif
