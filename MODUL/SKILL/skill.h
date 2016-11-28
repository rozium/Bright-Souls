#ifndef _SKILL_H
#define _SKILL_H

#include <stdlib.h>
#include "boolean.h"
#include "../BINTREE/bintree.h"
#include "../MESINKATA/mesinkata.h"
#include "../DISPLAY/display.h"
#include "../POINT/point.h"

#define MaxArea 8

typedef struct {
	Kata SkillName;
	POINT Pos; //array of matriks, indeks ke 0 tidak dipakai
  int IdxMap;
} SkillPos;

extern SkillPos TabSkill[5]; //Tabskill[0] tidak dipakai

#define SkillName(M) (M).SkillName
#define SkillPos(M) (M).Pos
#define SkillIdxMap(M) (M).IdxMap

//Include ADT lain yang diperlukan
void InitializeSkill(BinTree *Skill);
void SkillMenu(BinTree P, int h);
//Menampilkan skill menu sesuai spesifikasi

//Tambahkan prosedur lain
void IsiTabSkillPos(BinTree Skill);
//Mengisi TabSkillPos dengan posisi pada map

void PrintLvlUp(BinTree *Skill);

#endif
