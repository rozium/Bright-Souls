#ifndef _MAP_H
#define _MAP_H

#include "boolean.h"
#include <stdlib.h>
#include "../MATRIKS/matriks.h"
#include "../GRAPH/graf.h"
#include "../SKILL/skill.h"
#include "../DISPLAY/display.h"
#include "../PLAYER/player.h"
#include "../ENEMY/enemy.h"


#define MaxArea 8
#define BrsArea 10 //ukuran baris tiap area, bisa diubah-ubah ; min 5
#define KolArea 10//ukuran kolom tiap area,bisa diubah-ubah ; min 5
#define POHON '#'
#define JALAN ' '


typedef struct {
	MATRIKS Area[(MaxArea*5)+1];
	int brcount; //array of matriks, indeks ke 0 tidak dipakai
} TabMat;

extern TabMat minimaps;

#define Area(M,i) (M).Area[(i)]
#define BranchCount(M) (M).brcount
/* ********** DEFINISI PRIMITIF ********** */
void CreateEmptyMAP (TabMat *M);
//membuat TabMat dengan ukuran tiap area ixj

void SearchJALANAtas (MATRIKS M, indeks *i, indeks *j);
//Mencari karakter JALAN pada tepian area atas

void SearchJALANKanan (MATRIKS M, indeks *i, indeks *j);
//Mencari karakter JALAN pada tepian area kanan

void SearchJALANBawah (MATRIKS M, indeks *i, indeks *j);
//Mencari karakter JALAN pada tepian area bawah

void SearchJALANKiri (MATRIKS M, indeks *i, indeks *j);
//Mencari karakter JALAN pada tepian area kiri
void RandomDrunkard(MATRIKS *M, int entpos, int *expos, int * branchcount, TabMat *MapHasil);
//prosedur untuk me-random isi area penyusun TabMat

void RandomMap(TabMat *MapHasil);
//membuat area-area yang menyusun map dengan isi random, setiap area berukuran ixj

// void SearchPintu (MAP M, int idxTab, char *in, char *out);
// //mencari di sisi mana jalan dari dan menuju area lain.
// //in dan out dapat bernilai U=Atas, R=kanan, D=Bawah, L=Kiri

void connectMap(TabMat M,  GRAF *G);
//menyatukan area-area yang telah terbentuk menjadi satu map dengan menggunakan GRAF,
//*G adalah GRAF yg terbentuk

void GenerateMap(GRAF * bigmap, TabMat * minimaps, PLAYERPOS * pos);
//Menggenerate Map dengan prosedur yang ada, bigmap dan minimaps berisi map yang digenerate dan
//pos berisi posisi awal player pada map
//Mengupdate posisi dari enemy pada TabEnemy sesuai dengan posisinya dimap

void PrintMap(TabMat minimaps, PLAYERPOS pos);
//Print Map dimana player berada sesuai dengan spesifikasi dan memberikan space untuk input user

char CheckTile(PLAYERPOS pos, TabMat minmap);
//menghasilkan apa jenis Tile yang diinjak player, apakah E, M, atau kosong ' '

void DelM(PLAYERPOS pos, TabMat *minmap);
//menubah Elmt(M,i,j) menjadi ' ' di peta

void DelS(PLAYERPOS pos, TabMat *minmap);
//menubah Elmt(M,i,j) menjadi ' ' di peta


char TitikMatch(char dir);

void GenerateSkillOnMap(BinTree playerskill, TabMat * minimaps);
//Men-generate skill pada MAP dan menghasilkan posisi-posisi pada map

#endif
