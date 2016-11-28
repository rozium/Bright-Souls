#include "graf.h"
#include <stdio.h>

int main ()
{
  adrGraf g,g1;
  adrTitik T;
  GRAF G;
  POINT P;
  boolean cek;
  P = MakePOINT (2,3);
  CreateEmptyGraf(&G);
  if (IsEmptyGraf(G))
  {
    printf("kosong\n");
  }
  T = AlokasiTitik('u',P);
  printf ("absis t:%d\n",Absis(Titik(T)));
  g = AlokasiGraf(1);
  printf("indeks g:%d\n",Index(g));
  g1 = AlokasiGraf(2);
  printf("indeks g1:%d\n",Index(g1));
  DealokasiGraf(&g);
  printf("indeks g:%d\n",Index(g));
  InsGraf(&G,2,&g);
  printf("indeks g:%d\n",Index(g));
  InsTitik (g,'u',P,g1);
  printf("indeks g1:%d\n",Index(g1));
  g1 = SearchGraf (G,1,&cek);
  T = SearchTitik (G,2,'u');
  printf("absis t:%d\n",Absis(Titik(T)));

  return 0;
}
