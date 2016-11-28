#ifndef _NAVIGATION_H
#define _NAVIGATION_H

#include <stdlib.h>
#include "boolean.h"

#include "../MATRIKS/matriks.h"
#include "../JAM/jam.h"
#include "../SKILL/skill.h"
#include "../MAP/map.h"
#include "../DISPLAY/display.h"
#include "../MESINKATA/mesinkata.h"
#include "../NARASI/narasi.h"
#include "../STACKLIST/stacklist.h"
#include "../PLAYER/player.h"
#include "../QUEUELIST/queuelist.h"

//Include ADT lain yang diperlukan

void GoUp(PLAYERPOS * P, TabMat minimap, GRAF graf);
//Player bergerak keatas apabila memungkinkan dan pos berisi posisi player terupdate
void GoDown(PLAYERPOS * P, TabMat minimap, GRAF graf);
//Player bergerak kebawah apabila memungkinkan dan pos berisi posisi player terupdate
void GoLeft(PLAYERPOS * P, TabMat minimap, GRAF graf);
//Player bergerak kekiri apabila memungkinkan dan pos berisi posisi player terupdate
void GoRight(PLAYERPOS * P, TabMat minimap, GRAF graf);
//Player bergerak kekanan apabila memungkinkan dan pos berisi posisi player terupdate
void MapTransition(TabMat minimap, GRAF graf, PLAYERPOS *pos);
#endif
