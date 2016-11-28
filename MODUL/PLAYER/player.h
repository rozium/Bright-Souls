#ifndef _PLAYER_H
#define _PLAYER_H

#include "boolean.h"
#include <stdlib.h>
#include "../QUEUELIST/queuelistl.h"
#include "../SKILL/skill.h"
#include "../DISPLAY/display.h"
#include "../MESINKATA/mesinkata.h"
#include "../MESINTOKEN/mesintoken.h"
//deklarasi type
//Posisi player
typedef struct{
    int mapindex;
    POINT pos;
}PLAYERPOS;

extern QueueL StrPlayer;
extern QueueL DefPlayer;
extern QueueL HpPlayer;
extern QueueL NextExpPlayer;


//player
typedef struct{
	Kata name;
    int max_hp;
    int cur_hp;
    int str;
    int def;
    int cur_exp;
    int lvl;
    int job;
}PLAYER;

//Selektor
#define Map(P) (P).mapindex
#define Pos(P) (P).pos

#define Name(P) (P).name
#define MaxHP(P) (P).max_hp
#define HP(P) (P).cur_hp
#define STR(P) (P).str
#define DEF(P) (P).def
#define Exp(P) (P).cur_exp
#define Level(P) (P).lvl
#define Job(P) (P).job
#define MaxLevel 6
#define MaxExp -999
#define JumlahStat 3
#define JumlahJob 4

void username(PLAYER *player, Kata uname);
// nama player telah terdefinisi
// I.S = player telah terdefinisi
// F.S = nama player telah terdefinisi

void PrintStatus(PLAYER player, PLAYERPOS pos);
// menampilkan status karakter.
// I.S = karakter telah terdefinisi
// F.S = status karakter telah teretak ke layar

void Lvl1Player(PLAYER *player);
// menciptakan karakter level 1
// I.S = job player telah terdefinisi
// F.S = karakter player menjadi level 1

boolean IsDead(PLAYER player);
// prekondisi = karakter player telah terdefinisi
// menghasilkan boolean berdasarkan kondisi karakter sudah mati atau belum.

void IncreaseHP(PLAYER * player, int X);
// menambah current HP dari player sebanyak X
// current hp tidak lebih dari max hp.
// I.S = current hp dan max hp sudah terdefinisi
// F.S = current hp telah berhasil tertambah

void DecreaseHP(PLAYER * player, int X);
// Kurang current HP dari player sebanyak X
// Mungkin jadi  kosong tidak mungkin kurang dari 0
// I.S = current hp telah terdefinisi
// F.S = current hp telah berkurang

void AddExp(PLAYER * player, int X, BinTree *Skill);
// Nambah EXP sebanyak X
// jika EXP bertambah lebih dari next exp, karakter akan level up, dan exp akan mulai dari 0 lagi
// dimungkinkan naik exp lebih dari 1 kali
// I.S = exp karakter telah bertambah sebanyak x
// F.S = exp karakter telah bertambah sebnayak x

void LevelUp(PLAYER * player, BinTree *Skill);
// level up dan menaikan status sesuai chart dan job
// level up hanya akan terjadi jika level belum maksimal
// I.S = level karakter telah terdefinisi
// F.S = level karakter telah bertambah

void Heal(PLAYER * player);
// meningkatkan current hp player hingga max hp
// I.S karakter telah terdefinisi
// F.S current hp player = max hp player


void GetSkill(PLAYERPOS pos, boolean * del, BinTree *skill);
// mendapatkan skill untuk player
// I.S = skill telah diinisialisasi
// F.S = skill telah terbuat

void PilihJob(PLAYER * player);
// Menampilkan menu pilih job ,dan mengupdate status player berdasarkan job yang dipilih
// I.S = player telah terdefinisi
// F.S = job player telah terdefinisi
int NextExp(PLAYER player);
// memasukan nilai next exp ke dalam queue next exp
// I.S = sembarang
// F.S = NextExp karakter telah dimasukan dalam queue list

void LoadPlayer(PLAYER *player, BinTree *Skill);
// meload status player dari file eksternal
// I.S = sembarang
// F.S = Player posisi dan status berhasil di load 

void LoadStatusPlayer(PLAYER player);
// meload status player dari level ke level ke dalam sebuah queue
// I.S = file eksternal telah tersiapkan.
// F.S = status player telah terload dari file eksternal

#endif
