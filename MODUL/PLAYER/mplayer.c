#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <time.h>
//Include semua header lain

#include "player.h"

// HOW TO COMPILE --> gcc -o mplayer mplayer.c display.c player.c queuelist.c mesintoken.c mesinkar.c enemy.c mesinkata.c point.c battle.c stacklist.c graf.c map.c matriks.c navigation.c queuelistl.c skill.c data.c jam.c bintree.c -lm

void PrintStatusPlayer(PLAYER P);

int main(){
	PLAYER dummy;
	Kata Uname;
	//Uname 1 akan diberi nama ferdi
	printf("uname 1 akan diberi nama FERDI\n");
	usleep(1500000);
	Uname.Length = 5;
	Uname.Val = 0;
	Uname.TabKata[1] = 'F';
	Uname.TabKata[2] = 'E';
	Uname.TabKata[3] = 'R';
	Uname.TabKata[4] = 'D';
	Uname.TabKata[5] = 'I';
	username(&dummy,Uname);
	clrscr;
	PilihJob(&dummy);
	LoadStatusPlayer(dummy);
	Lvl1Player(&dummy);
	PrintStatusPlayer(dummy);
	printf("HP PLAYER => %d/%d\n",HP(dummy),MaxHP(dummy));
	printf("player terkena damage 10\n");		
	DecreaseHP(&dummy,10);
	printf("HP PLAYER => %d/%d\n",HP(dummy),MaxHP(dummy));
	if (IsDead(dummy)){
		printf("karakter anda mati\n");
	}
	printf("\n");
	printf("karakter menambah hp 5\n");
	IncreaseHP(&dummy,5);
	printf("HP PLAYER => %d/%d\n",HP(dummy),MaxHP(dummy));
	if (IsDead(dummy)){
		printf("karakter anda mati\n");
	}
	printf("\n");
	printf("karakter menambah hp 100\n");
	IncreaseHP(&dummy,100);
	printf("HP PLAYER => %d/%d\n",HP(dummy),MaxHP(dummy));
	if (IsDead(dummy)){
		printf("karakter anda mati\n");
	}
	printf("\n");
	printf("kena damage 1000\n");		
	DecreaseHP(&dummy,1000);
	printf("HP PLAYER => %d/%d\n",HP(dummy),MaxHP(dummy));
	
	if (IsDead(dummy)){
		printf("karakter anda mati\n");
	}

	printf("\n");
	printf("karakter memakai heal\n");
	Heal(&dummy);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("HP PLAYER => %d/%d\n",HP(dummy),MaxHP(dummy));
	usleep(5000000);
	clrscr;
	return 0;
}


void PrintStatusPlayer(PLAYER P){
clrscr;
BinTree playerskill;
InitializeSkill(&playerskill);
 for (int i = 1;i<=Name(P).Length;i++){
 	printf("%c",Name(P).TabKata[i]);	
 }
 printf("\n");
 if (Job(P) == 1){
 printf("Job = Mahasiswa\n",Job(P));
 }
 if (Job(P) == 2){
 printf("Job = Begal\n",Job(P));
 }
 if (Job(P) == 3){
 printf("Job = Satpam\n",Job(P));
 }
 if (Job(P) == 4){
 printf("Job = Kuli\n",Job(P));
 }
 printf("status LEVEL 1\n");
 printf("Max HP = %d\n",MaxHP(P));
 printf("HP = %d\n",HP(P));
 printf("STR = %d\n",STR(P));
 printf("DEF = %d\n",DEF(P));
 printf("Level = %d\n",Level(P)); 	
 usleep(2000000);
clrscr;
 LevelUp(&P,&playerskill);
clrscr;
 printf("status LEVEL 2\n");
 printf("Max HP = %d\n",MaxHP(P));
 printf("HP = %d\n",HP(P));
 printf("STR = %d\n",STR(P));
 printf("DEF = %d\n",DEF(P));
 printf("Level = %d\n",Level(P)); 	
 usleep(2000000);
clrscr; 
 LevelUp(&P,&playerskill);
clrscr;
 printf("status LEVEL 3\n");
 printf("Max HP = %d\n",MaxHP(P));
 printf("HP = %d\n",HP(P));
 printf("STR = %d\n",STR(P));
 printf("DEF = %d\n",DEF(P));
 printf("Level = %d\n",Level(P)); 	
 usleep(2000000);
clrscr;
 LevelUp(&P,&playerskill);
 clrscr;
 printf("status LEVEL 4\n");
 printf("Max HP = %d\n",MaxHP(P));
 printf("HP = %d\n",HP(P));
 printf("STR = %d\n",STR(P));
 printf("DEF = %d\n",DEF(P));
 printf("Level = %d\n",Level(P)); 	
 usleep(2000000);
clrscr;
 LevelUp(&P,&playerskill);
 clrscr;
 printf("status LEVEL 5\n");
 printf("Max HP = %d\n",MaxHP(P));
 printf("HP = %d\n",HP(P));
 printf("STR = %d\n",STR(P));
 printf("DEF = %d\n",DEF(P));
 printf("Level = %d\n",Level(P)); 	
 usleep(2000000);
clrscr;
 LevelUp(&P,&playerskill);
clrscr;
 printf("status LEVEL 6 (MAX)\n");
 printf("Max HP = %d\n",MaxHP(P));
 printf("HP = %d\n",HP(P));
 printf("STR = %d\n",STR(P));
 printf("DEF = %d\n",DEF(P));
 printf("Level = %d\n",Level(P)); 	
 usleep(2000000);
clrscr;
LevelUp(&P,&playerskill);
clrscr;
}


/*

void username(PLAYER *player, Kata uname);

void PrintStatus(PLAYER player, PLAYERPOS pos);

void Lvl1Player(PLAYER *player);

boolean IsDead(PLAYER player);
//True jika player mati, hp = 0;

void IncreaseHP(PLAYER * player, int X);
//Nambah current HP dari player sebanyak X
//Mungkin jadi full

void DecreaseHP(PLAYER * player, int X);
//Kurang current HP dari player sebanyak X
//Mungkin jadi  kosong

void AddExp(PLAYER * player, int X, BinTree *Skill);
//Nambah EXP sebanyak X

void LevelUp(PLAYER * player, BinTree *Skill);
//level up dan mengupdate status sesuai chart dan job

void Heal(PLAYER * player);
//menyembuhkan player

void GetSkill(PLAYERPOS pos, boolean * del, BinTree *skill);

void PilihJob(PLAYER * player);
//Menampilkan menu pilih job ,dan mengupdate status player berdasarkan job yang dipilih
int NextExp(PLAYER player);
//Menghasilkan ekperiens yang dibutuhkan untuk naik level

void LoadStatusPlayer(PLAYER player);
#endif

*/

