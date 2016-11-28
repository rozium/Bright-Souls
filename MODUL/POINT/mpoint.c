#include "point.h"
#include <stdio.h>

int main ()
{
	POINT P,P2;
	P = MakePOINT(2,3);
	printf ("%d\n",Absis(P));
	printf ("%d\n",Ordinat(P));
	P2 = MakePOINT(2,3);
	if (EQ(P,P2))
	{
		printf ("sama\n");
	}
	if (NEQ(P,P2))
	{
		printf ("tidak sama\n");
	}

	return 0;
}
