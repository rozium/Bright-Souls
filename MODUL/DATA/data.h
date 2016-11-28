#ifndef _DATA_H
#define _DATA_H

#include "boolean.h"
#include <stdlib.h>
#include "../JAM/jam.h"
#include "../SKILL/skill.h"
#include "../ENEMY/enemy.h"
#include "../MAP/map.h"
#include "../PLAYER/player.h"
#include "data.h"
#include "mesinkata.h"
#include "../DISPLAY/display.h"
#include "../NARASI/narasi.h"
//Include ADT lain yang diperlukan

void Load(Kata *nama,TabMat *maps, PLAYER *player, PLAYERPOS *playerpos, int *dur, BinTree *skill, int *waktu);
//Menload semua data dari file eksternal
void Save(TabMat maps, PLAYER player, PLAYERPOS playerpos, int waktumulai, BinTree skill);
//Mensave semua datafile eksternal

void WriteSaves(Kata nama,TabMat maps, PLAYER player, PLAYERPOS playerpos, int dur, BinTree skill, int waktu);
int CheckExistence(Kata username);
//mengecek apakah save file dengan nama player sudah ada, jika ada return index, jika tidak return 0

#endif
