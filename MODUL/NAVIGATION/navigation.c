#include <stdlib.h>
#include <stdio.h>
#include "navigation.h"

void GoUp(PLAYERPOS * P, TabMat minimap, GRAF graf)
{
	if ((Elmt (Area(minimap,Map(*P)), (Absis(Pos(*P))-1), (Ordinat(Pos(*P)))) == '#'))
	{
		PNabrak();
	}
	else
	//Keluar dari map sekarang
	if(Absis(Pos(*P)) == 1)
	{
		MapTransition(minimap, graf, P);
		BS();
	}
	else
	{
		Absis(Pos(*P)) -= 1;
		Elmt(Area(minimap,Map(*P)), (Absis(Pos(*P))), (Ordinat(Pos(*P)))) = 'P';
		Elmt(Area(minimap,Map(*P)), (Absis(Pos(*P))+1), (Ordinat(Pos(*P)))) = '-';
	}
}
//Player bergerak keatas apabila memungkinkan dan pos berisi posisi player terupdate
void GoDown(PLAYERPOS * P, TabMat minimap, GRAF graf)
{
	if ((Elmt (Area(minimap,Map(*P)), (Absis(Pos(*P))+1), (Ordinat(Pos(*P)))) == '#'))
	{
		PNabrak();
	}
	else
	//Keluar dari map sekarang
	if(Absis(Pos(*P)) == BrsArea)
	{
		MapTransition(minimap, graf, P);
		BS();
	}
	else
	{
		Absis(Pos(*P)) += 1;
		Elmt(Area(minimap,Map(*P)), (Absis(Pos(*P))), (Ordinat(Pos(*P)))) = 'P';
		Elmt(Area(minimap,Map(*P)), (Absis(Pos(*P))-1), (Ordinat(Pos(*P)))) = '-';
	}
}
//Player bergerak kebawah apabila memungkinkan dan pos berisi posisi player terupdate
void GoLeft(PLAYERPOS * P, TabMat minimap, GRAF graf)
{
	if ((Elmt (Area(minimap,Map(*P)), (Absis(Pos(*P))), (Ordinat(Pos(*P))-1)) == '#'))
	{
		PNabrak();
	}
	else
	//Keluar dari map sekarang
	if(Ordinat(Pos(*P)) == 1)
	{
		MapTransition(minimap, graf, P);
		BS();
	}
	else
	{
		Ordinat(Pos(*P)) -= 1;
		Elmt(Area(minimap,Map(*P)), (Absis(Pos(*P))), (Ordinat(Pos(*P)))) = 'P';
		Elmt(Area(minimap,Map(*P)), (Absis(Pos(*P))), (Ordinat(Pos(*P))+1)) = '-';
	}
}
//Player bergerak kekiri apabila memungkinkan dan pos berisi posisi player terupdate
void GoRight(PLAYERPOS * P, TabMat minimap, GRAF graf)
{
	if ((Elmt (Area(minimap,Map(*P)), (Absis(Pos(*P))), (Ordinat(Pos(*P))+1)) == '#'))
	{
		PNabrak();
	}

	else
	//Keluar dari map sekarang
	if(Ordinat(Pos(*P)) == KolArea)
	{
		MapTransition(minimap, graf, P);
		BS();
	}
	else
	{
		Ordinat(Pos(*P)) += 1;
		Elmt(Area(minimap,Map(*P)), (Absis(Pos(*P))), (Ordinat(Pos(*P)))) = 'P';
		Elmt(Area(minimap,Map(*P)), (Absis(Pos(*P))), (Ordinat(Pos(*P))-1)) = '-';
	}
}

void MapTransition(TabMat minimap, GRAF graf, PLAYERPOS *pos)
{	//arah keluar

	int dir;
	if(Absis(Pos(*pos)) == 1){
		dir = 'U';
	}
	else if(Absis(Pos(*pos)) == BrsArea)
	{
		dir = 'D';
	}
	else if(Ordinat(Pos(*pos)) == 1)
	{
		dir = 'L';
	}
	else if(Ordinat(Pos(*pos)) == KolArea)
	{
		dir = 'R';
	}
	adrGraf Dest;
	Dest = ConnectTo(SearchTitik(graf, Map(*pos), dir));
	Map(*pos) = Index(Dest);
	Pos(*pos) = Titik(SearchTitik(graf, Map(*pos), TitikMatch(dir)));
}
