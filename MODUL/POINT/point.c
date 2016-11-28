#include "point.h"
#include <stdio.h>
#include <math.h>

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	POINT P;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	return ((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	return ((Absis(P1)!=Absis(P2))||(Ordinat(P1)!=Ordinat(P2)));
}
