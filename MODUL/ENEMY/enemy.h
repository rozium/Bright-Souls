#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "boolean.h"
#include "../SKILL/skill.h"
#include "../POINT/point.h"
#include "../MESINKATA/mesinkata.h"
#include "../DISPLAY/display.h"
#include "../GRAPH/graf.h"
#include "../PLAYER/player.h"
#include "../MAP/map.h"

/* deklarasi type */
typedef struct{
    Kata name;
    int level;
    int max_hp;
    int cur_hp;
    int str;
    int def;
    int exp;
    POINT pos;
    int mapindex;
}ENEMY;

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

/* Selektor */
#define EnemyName(P)  (P).name
#define EnemyLvl(P) (P).level
#define EnemyMaxHP(P) (P).max_hp
#define EnemyHP(P) (P).cur_hp
#define EnemySTR(P) (P).str
#define EnemyDEF(P) (P).def
#define EnemyExp(P) (P).exp
#define EnemyPos(P) (P).pos
#define EnemyMap(P) (P).mapindex

/* Primitif Spawn Enemy */
void LoadEnemy(GRAF graf);//TabMat minimaps);
/* Menload seluruh data enemy dari file eksternal */
ENEMY GetEnemy(PLAYERPOS P, int *x);
/* Menghasilkan enemy yang terletak di pos */

/* Primitif Boolean */
boolean IsDeadE(ENEMY E);
/* True jika enemi mati, hp = 0; */

boolean IsBoss(ENEMY E);
/* True jika enemy adalah boss, diperkisa dengan Name(Enemy) = Boss NName */

/* Primitif Aritmatika HP enemy */
void IncreaseHPE(ENEMY * E, int X);
//Menambah current HP dari enemy sebanyak X
//Mungkin jadi full

void DecreaseHPE(ENEMY * E, int X);
//Mengurangi current HP dari enemy sebanyak X
//Mungkin jadi  kosong

/* Tampilkan Enemy */
void PrintEnemy(ENEMY E, int x, int y);
//Print interface enemy APPEARS! dari enemy

void PrintStatE(ENEMY E, int x);
//Print status Enemy

/* Hapus Enemy */
void DeleteEnemyPos(ENEMY *E, PLAYERPOS pos, int x);
/* Menghapus enemy dari map */

void GetBoss(ENEMY *E);
// Cheat biar langsung lawan boss

#endif
