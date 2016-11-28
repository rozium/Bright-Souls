#ifndef _BATTLE_H
#define _BATTLE_H

#include "boolean.h"
#include "../MATRIKS/matriks.h"
#include "../JAM/jam.h"
#include "../SKILL/skill.h"
#include "../ENEMY/enemy.h"
#include "../MAP/map.h"
#include "../BATTLE/battle.h"
#include "../DISPLAY/display.h"
#include "../MESINKATA/mesinkata.h"
#include "../NARASI/narasi.h"
#include "../STACKLIST/stacklist.h"
#include "../QUEUELIST/queuelist.h"

#include <stdlib.h>
#include <math.h>
//Include ADT lain yang diperlukan

void PushEnemyMoveE(Stack * moves);
//Memasukkan moves enemy secara random dari file eksternal ke dalam stacck
// I.S : moves terdefinisi
// F.S : moves telah terisi oleh moves enemy secara random

void PushEnemyMoveB(Stack * moves);
//Memasukkan moves Boss secara random dari file eksternal ke dalam stacck
// I.S : moves terdefinisi
// F.S : moves telah terisi oleh moves Boss secara random

void PrintBattleInterface(ENEMY enemy,Queue *EnemyMove, Queue *PlayerMove, PLAYER player, int ronde, int turn, int tutup1, int tutup2, boolean tarung);
//Memprint pada layar interface pertarungan sesuai spesifikasi
//Termasuk menulis secara random
//I.S : enemy, EnemyMove, PlayerMove, player, ronde, turn, tutup1, tutup2, tarung terdefinisi
// F.S : layar sudah menampilkan sesuai dengan spesifikasi

void ProcessKata(char commandE, char commandP ,ENEMY* enemy, PLAYER* player, BinTree skill, int turn);
//Menampilkan damage pada layar
//I.S : commandE, commandP, enermy, player, skill, turn terdefinisi 
//F.S : Ditampilkan damage pada interface

void ProcessCommand(char commandE, char commandP, ENEMY* enemy, PLAYER* player, BinTree skill);
//mengecek masukan command player dengan command yang dikeluarkan enemy
//I.S : commandE, commandP, enemy, player, skill terdefinisi 
//F.S : menghasilkan hal yang terjadi berdasarkan command yang diinputkan

int CalculateDamage(char cek, int STR, int DEFx);
//menghitung dan menghasilkan damage yang didapat sebuah enemy

int CalculateDamageE(char cek, int STR, int DEF, BinTree skill);
//menghitung dan menghasilkan damage yang didapat sebuah player

void PrintMenang();
//Print pemberitahuan menang ketika menang
// I.S : sembarang
// F.S : menampilkan pemberitahuan bahwa player menang

void GetExp(PLAYER *player, ENEMY enemy, BinTree *Skill);
//Menambahkan EXP yang didapat dari enemy ke player. Mungkin menjadi level up
// I.S : player, enemy, skill
// F.S : player memperoleh exp dan membuka skill sesuai dengan enemy yang dikalahkan

#endif


