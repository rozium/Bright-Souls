#include "map.h"
#include <stdio.h>
#include <time.h>

// HOW TO COMPILE --> gcc -o mmap mmap.c display.c player.c queuelist.c mesintoken.c mesinkar.c enemy.c mesinkata.c point.c battle.c stacklist.c graf.c map.c matriks.c navigation.c queuelistl.c skill.c data.c jam.c bintree.c -lm
#define MaxEnemy 13
#define MaxArea 8
extern ENEMY TabEnemy[MaxEnemy +1];
extern Kata Fairy;
extern Kata Spider;
extern Kata Bat;
extern Kata Skeleton;
extern Kata JackOLantern;
extern Kata Devil;
extern Kata Casper;
extern Kata Centaur;
extern Kata Eagle;
extern Kata Cobra;
extern Kata Phoenix;
extern Kata Reaper;
extern Kata Dragon;

int main(){
	TabMat MAP;
	PLAYERPOS Pos;
	CreateEmptyMAP(&MAP);
	Pos.mapindex = 1;
	Pos.pos = MakePOINT(3,3);
	CreateEmptyMAP(&MAP);
	clrscr;
	PrintMap(MAP,Pos);
	printf("\n");
	printf("\n");
	printf("Cek fungsi CREATE EMPTY => program menghasilkan map kosong\n");
	usleep(1500000);
	RandomMap(&MAP);
	PrintMap(MAP,Pos);
	printf("\n");
	printf("\n");
	printf("Cek fungsi Random Map => program merandom isi map\n");
	printf("isi map telah di random namun memang belum pasti terbentuk jalur untuk lewat\n");
	usleep(1500000);
	GRAF BigMAP;
	GenerateMap(&BigMAP,&MAP,&Pos);
	PrintMap(MAP,Pos);
	printf("\n");
	printf("\n");
	printf("Cek fungsi program Generate Map & prosedur proseur yang lain yang sudah termasuk di dalam nya=> Map telah di bentuk dan disambungkan menjadi BIG MAP yang saling menyambung satu sama lain menjadi big map\n");
	printf("isi map telah di random dan sudah pasti terbentuk jalur lewat\n");
	usleep(3000000);
	clrscr;
	return 0;
}

/* 
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

*/