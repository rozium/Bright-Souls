#include "graf.h"
#include <stdio.h>
#include <stdlib.h>
/* PROTOTYPE */
/****************** TEST GRAF KOSONG ******************/
boolean IsEmptyGraf (GRAF G)
/* Mengirim true jika GRAF kosong */
{
	return FirstGraf(G) == Nil;
}


/****************** PEMBUATAN GRAF KOSONG ******************/
void CreateEmptyGraf (GRAF *G)
/* I.S. sembarang             */
/* F.S. Terbentuk GRAF kosong */

{
	FirstGraf(*G) = Nil;
}

/****************** Manajemen Memori ******************/

adrTitik AlokasiTitik (char dirr, POINT point)
{
		adrTitik PTitik;

		PTitik = (adrTitik) malloc (sizeof (ElmtTitik));
		if (PTitik != Nil) {

			NextTitik(PTitik) = Nil;
			Titik (PTitik) = point;
			Dir(PTitik) = dirr;
			ConnectTo(PTitik) = Nil;

		}
	return PTitik;
}
adrGraf AlokasiGraf (int indeks)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	adrGraf PGraf;

	PGraf = (adrGraf) malloc (sizeof (ElmtGRAF));

	if (PGraf != Nil) {

		NextNode(PGraf) = Nil;
		PrevNode(PGraf) = Nil;
		Index(PGraf) = indeks;
		FirstTitik (PGraf) = Nil;

	}
	return PGraf;
}

void DealokasiGraf (adrGraf *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsGraf (GRAF *G, int indeks, adrGraf *Pgrf)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	adrGraf PGraf;

	PGraf = AlokasiGraf(indeks);
	if (PGraf != Nil) {
			if(FirstGraf(*G) == Nil) //BErarti grafnya kosong
			{
					FirstGraf(*G) = PGraf;
					NextNode(PGraf) = Nil;
					PrevNode(PGraf) = Nil;

			}
			else
			{
				adrGraf PG = FirstGraf(*G);
					while(NextNode(PG)!= Nil) //kita cari terus ampe ketemu last
					{
						PG = NextNode(PG);
					}
					//PG adalah last dari graf
					//insert setelah PG
					NextNode(PG) = PGraf;
					PrevNode(PGraf) = PG;
					NextNode(PGraf) = Nil;

			}
			*Pgrf = PGraf;
	}

}

void InsTitik(adrGraf PG, char dir, POINT point, adrGraf ConPG )
{
		adrTitik PT;
		PT = AlokasiTitik(dir,point);
		if(PT != Nil){ //TAmbahkan PT ke list

				if(FirstTitik(PG) == Nil) //Kosong, add sebagai first el
				{
					FirstTitik(PG) = PT;
					NextTitik(PT) = Nil;
					ConnectTo(PT) = ConPG;
				}
				else{
					
						adrTitik last;
						last = FirstTitik(PG);
						while(NextTitik(last)!= Nil) //kita cari terus ampe ketemu last
						{
							last = NextTitik(last);
						}
						//firstTTK adalah last dari point
						//insert setelah PG
						NextTitik(last) = PT;
						NextTitik(PT) = Nil;
						ConnectTo(PT) = ConPG;
				}
		}

}

adrGraf SearchGraf(GRAF G, int idx, boolean *found)

//menghasilkkan adrGraf dengan indeks idx
{
	*found = false;
	adrGraf PG = FirstGraf(G);

	while(PG != Nil && !(*found))
	{
		if(Index(PG) == idx)
		{
				*found = true;
		}
		else{
			PG = NextNode(PG);
		}
			
	}
	if (*found){
		return PG;
	}
	else{
		return Nil;
	}
}

adrTitik SearchTitik(GRAF G ,int idx, char dir)
//menghasilkkan titik pada graf dengan index idx dengan dir dir
{
	boolean found = false;
	boolean dumm;
	if( SearchGraf(G, idx, &dumm) == Nil)
	{
		return Nil;
	}
	else
	{
		adrGraf PG = SearchGraf(G, idx, &dumm);
		adrTitik PT = FirstTitik(PG);
		while(PT != Nil && !found)
		{
			if(Dir(PT) == dir)
			{
					found = true;
			}
			else
			{
				PT = NextTitik(PT);
			}
		}
		if (found)
		{
			return PT;
		}
		else
		{
			return Nil;
		}
	}
}