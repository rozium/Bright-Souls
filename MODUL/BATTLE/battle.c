#include "battle.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void PushEnemyMoveE(Stack * moves)
//Memasukkan moves enemy secara random dari file eksternal ke dalam stacck
// I.S : moves terdefinisi
// F.S : moves telah terisi oleh moves enemy secara random

{
	Kata TabMove[10+1]; // Mulai dari 1..10
	int i = 1;

	CreateEmptyS(moves);
	STARTMOVESE();
	ADVKATA();
	EndKata = false;
	while (!EndKata) {
		TabMove[i] = CopyKata(CKata);
		i++;
		ADVKATA();
	}
	for (i=1;i<=10;i++)
	{
		PushS(moves,TabMove[(rand()%10)+1]);
	}
}

void PushEnemyMoveB(Stack * moves)
//Memasukkan moves Boss secara random dari file eksternal ke dalam stack
// I.S : moves terdefinisi
// F.S : moves telah terisi oleh moves Boss secara random

{
	Kata TabMove[20+1]; // Mulai dari 1..20
	int i = 1;

	CreateEmptyS(moves);
	STARTMOVESB();
	ADVKATA();
	EndKata = false;
	while (!EndKata) {
		TabMove[i] = CopyKata(CKata);
		i++;
		ADVKATA();
	}
	for (i=1;i<=20;i++)
	{
		PushS(moves,TabMove[(rand()%20)+1]);
	}
}

void PrintBattleInterface(ENEMY enemy,Queue *EnemyMove, Queue *PlayerMove, PLAYER player, int ronde, int turn, int tutup1, int tutup2, boolean tarung)
//Memprint pada layar interface pertarungan sesuai spesifikasi
//Termasuk menulis secara random
//I.S : enemy, EnemyMove, PlayerMove, player, ronde, turn, tutup1, tutup2, tarung terdefinisi
// F.S : layar sudah menampilkan sesuai dengan spesifikasi

{
	gotoXY(1,1);
	CetakBingkai(41,100);
	Dragon.Length = 6;
    for (int i = 1;i <= EnemyName(TabEnemy[13]).Length;i++) { Dragon.TabKata[i] = EnemyName(TabEnemy[13]).TabKata[i];  }

	if (IsKataSama(EnemyName(enemy),Dragon)) {
		PrintEnemy(enemy,3,7);
	} else {
		vs(9,40);
		if (Job(player) == 1) {
				mahasiswa(4,2);
				PrintEnemy(enemy,4,60);
		} else if (Job(player) == 2) {
				begal(4,60);
				PrintEnemy(enemy,4,2);
		} else if (Job(player) == 3) {
				PrintEnemy(enemy,4,2);
				satpam(4,60);
		} else {
				PrintEnemy(enemy,4,60);
				kuli(4,2);
		}
	}

	int np;
	Kata NamaP;
	NamaP = CopyKata(Name(player));
	np = NamaP.Length;
	for (np = NamaP.Length + 1 ; np <= 20 ; np++)
		NamaP.TabKata[np] = ' ';
	NamaP.Length = 20;

	int ne;
	Kata NamaE;
	NamaE = CopyKata(EnemyName(enemy));
	ne = NamaE.Length;
	for (ne = NamaE.Length + 1 ; ne <= 20 ; ne++)
		NamaE.TabKata[ne] = ' ';
	NamaE.Length = 20;

	int x = 24, y = 3;

	gotoXY(x++,y);printf("┌──────────────────────┬────────┬─────────┬─────────┬─────────┬─────────┬──────────┬───────────┐");
	gotoXY(x++,y);printf("│ ");PrintKata(NamaP);printf(" │ LVL: %d │ HP: %3d │ STR: %2d │ DEF: %2d │ Round%2d │          │           │",Level(player),HP(player),STR(player),DEF(player),ronde);
	gotoXY(x++,y);printf("├──────────────────────┼────────┴┬────────┴─────────┴─────────┴─────────┤          │           │");
	gotoXY(x++,y);printf("│ ");PrintKata(NamaE);printf(" │ HP: %3d │ ",EnemyHP(enemy));



	if (!tarung) {
		printf("Command: ");PrintQueueE(*EnemyMove,tutup1,tutup2);printf("          │           │");
	} else {
		char Move1 = Info(Head(*EnemyMove));
		char Move2 = Info(Next(Head(*EnemyMove)));
		char Move3 = Info(Next(Next(Head(*EnemyMove))));
		char Move4 = Info(Tail(*EnemyMove));
		if ((tutup1 == 1 && tutup2 == 2) || (tutup1 == 2 && tutup2 == 1)) {
			switch (turn) {
				case 1 :
	                printf("Command: >%c # %c %c",Move1,Move3,Move4); break;
				case 2 :
	                printf("Command: %c >%c %c %c",Move1,Move2,Move3,Move4); break;
				case 3 :
	                printf("Command: %c %c >%c %c",Move1,Move2,Move3,Move4); break;
				case 4 :
	                printf("Command: %c %c %c >%c",Move1,Move2,Move3,Move4); break;
			}
		} else if ((tutup1 == 1 && tutup2 == 3) || (tutup1 == 3 && tutup2 == 1)) {
			switch (turn) {
				case 1 :
	                printf("Command: >%c %c # %c",Move1,Move2,Move4); break;
				case 2 :
	                printf("Command: %c >%c # %c",Move1,Move2,Move4); break;
				case 3 :
	                printf("Command: %c %c >%c %c",Move1,Move2,Move3,Move4); break;
				case 4 :
	                printf("Command: %c %c %c >%c",Move1,Move2,Move3,Move4); break;
			}
		} else if ((tutup1 == 1 && tutup2 == 4) || (tutup1 == 4 && tutup2 == 1)) {
			switch (turn) {
				case 1 :
	                printf("Command: >%c %c %c #",Move1,Move2,Move3); break;
				case 2 :
	                printf("Command: %c >%c %c #",Move1,Move2,Move3); break;
				case 3 :
	                printf("Command: %c %c >%c #",Move1,Move2,Move3); break;
				case 4 :
	                printf("Command: %c %c %c >%c",Move1,Move2,Move3,Move4); break;
			}
		} else if ((tutup1 == 2 && tutup2 == 3) || (tutup1 == 3 && tutup2 == 2)) {
			switch (turn) {
				case 1 :
	                printf("Command: >%c # # %c",Move1,Move4); break;
				case 2 :
	                printf("Command: %c >%c # %c",Move1,Move2,Move4); break;
				case 3 :
	                printf("Command: %c %c >%c %c",Move1,Move2,Move3,Move4); break;
				case 4 :
	                printf("Command: %c %c %c >%c",Move1,Move2,Move3,Move4); break;
			}
		} else if ((tutup1 == 2 && tutup2 == 4) || (tutup1 == 4 && tutup2 == 2)) {
			switch (turn) {
				case 1 :
	                printf("Command: >%c # %c #",Move1,Move3); break;
				case 2 :
	                printf("Command: %c >%c %c #",Move1,Move2,Move3); break;
				case 3 :
	                printf("Command: %c %c >%c #",Move1,Move2,Move3); break;
				case 4 :
	                printf("Command: %c %c %c >%c",Move1,Move2,Move3,Move4); break;
			}
		} else if ((tutup1 == 3 && tutup2 == 4) || (tutup1 == 4 && tutup2 == 3)) {
			switch (turn) {
				case 1 :
	                printf("Command: >%c %c # #",Move1,Move2); break;
				case 2 :
	                printf("Command: %c >%c # #",Move1,Move2); break;
				case 3 :
	                printf("Command: %c %c >%c #",Move1,Move2,Move3); break;
				case 4 :
	                printf("Command: %c %c %c >%c",Move1,Move2,Move3,Move4); break;
			}
		}
		gotoXY(27,75);printf("│                      │");
	}
	gotoXY(x++,y);   printf("├──────────────────────┴─────────┴──────────────────────────────────────┴──────────┴───────────┤");
	gotoXY(x++,y);printf("│ ");
	for (int i = 1 ; i <= EnemyName(enemy).Length ; i++)
		printf("%c",EnemyName(enemy).TabKata[i]);
	printf(" Attacked!");gotoXY(x-1,y+83);printf("            │");
	if (!tarung) {
		gotoXY(x++,y);printf("│ Please input your command");gotoXY(x-1,y+95);printf("│");
	} else {
		gotoXY(24,86);printf("┬");
		gotoXY(25,86);printf("│");
		gotoXY(26,86);printf("│    DMG   ");
		gotoXY(27,86);printf("│");
		gotoXY(28,86);printf("┼─────┬");
		gotoXY(29,86);printf("│  E  │  P  │");
		gotoXY(34,3);printf("│                                                                                  │     │     │");
		gotoXY(35,3);printf("│                                                                                  │     │     │");
		gotoXY(36,3);printf("├──────────────────────────────────────────────────────────────────────────────────┴─────┴─────┤");
		switch (turn) {
			case 1 :
				//Print kejadian 1
                gotoXY(37,3);printf("│ Inserted Command: >%c %c %c %c",Info(Head(*PlayerMove)),Info(Next(Head(*PlayerMove))),Info(Next(Next(Head(*PlayerMove)))),InfoTail(*PlayerMove));
				break;
			case 2 :
				//Print kejadian 1 2
                gotoXY(37,3);printf("│ Inserted Command: %c >%c %c %c",Info(Head(*PlayerMove)),Info(Next(Head(*PlayerMove))),Info(Next(Next(Head(*PlayerMove)))),InfoTail(*PlayerMove));
				break;
			case 3 :
				//Print kejadian 1 2 3
                gotoXY(37,3);printf("│ Inserted Command: %c %c >%c %c",Info(Head(*PlayerMove)),Info(Next(Head(*PlayerMove))),Info(Next(Next(Head(*PlayerMove)))),InfoTail(*PlayerMove));
				break;
			case 4 :
				//Print kejadian 1 2 3 4
                gotoXY(37,3);printf("│ Inserted Command: %c %c %c >%c",Info(Head(*PlayerMove)),Info(Next(Head(*PlayerMove))),Info(Next(Next(Head(*PlayerMove)))),InfoTail(*PlayerMove));
				break;
		}
		gotoXY(37,98);printf("│");
		gotoXY(38,3) ;printf("└──────────────────────────────────────────────────────────────────────────────────────────────┘");
	}
}

void ProcessKata(char commandE, char commandP ,ENEMY* enemy, PLAYER* player, BinTree skill, int turn)
//Menampilkan damage pada layar
//I.S : commandE, commandP, enermy, player, skill, turn terdefinisi 
//F.S : Ditampilkan damage pada interface
{
	int dmgP = 0, dmgE = 0;
	if (commandE ==  'A') //kasus saat enemy memberi command attack
	{
		if (commandP == 'A')
		{
			dmgP = CalculateDamageE (commandP, STR(*player), EnemyDEF(*enemy),skill);
			dmgE = CalculateDamage (commandE, EnemySTR(*enemy), DEF(*player));
			PrintKata(EnemyName(*enemy)); printf(" menyerang ");PrintKata(Name(*player));printf(", tapi ");PrintKata(Name(*player));printf(" juga menyerang ");PrintKata(EnemyName(*enemy));printf("!");
		} else if (commandP == 'F')
		{
			dmgE = CalculateDamage (commandE, EnemySTR(*enemy), DEF(*player));
			PrintKata(EnemyName(*enemy)); printf(" menyerang ");PrintKata(Name(*player));printf(", ");PrintKata(Name(*player));printf(" malah Flank, Oh no !");
		} else if (commandP == 'B')
		{
			//Kalo ngeblock dan punya skill counter block
			if (HasSkill(Akar(SearchTreeString (skill, "CounterBlock"))))
			{
				dmgP = CalculateDamageE ('A', STR(*player), EnemyDEF(*enemy),skill);
				PrintKata(EnemyName(*enemy)); printf(" attack, tapi diblock, lalu dicounter berkat skill CounterBlock!");
			}
			else
			{
			PrintKata(EnemyName(*enemy)); printf(" menyerang ");PrintKata(Name(*player));printf(", tapi diblock oleh ");PrintKata(Name(*player));printf("! Bagus!");
			}
		}
	} else if (commandE == 'F') //kasus saat enemy memberi command flank
	{
		if (commandP == 'A')
		{
			dmgP = CalculateDamageE (commandP, STR(*player), EnemyDEF(*enemy),skill);
			PrintKata(EnemyName(*enemy)); printf(" menggunakan Flank, ");PrintKata(Name(*player));printf(" Attack! Bagus!");
		} else if (commandP == 'B')
		{
			dmgE = CalculateDamage (commandE, EnemySTR(*enemy), DEF(*player));
			PrintKata(EnemyName(*enemy)); printf(" menggunakan Flank, ");PrintKata(Name(*player));printf(" block tidak berfungsi!");
		} else if (commandP == 'F')
		{
			dmgP = CalculateDamageE (commandP, STR(*player), EnemyDEF(*enemy),skill);
			dmgE = CalculateDamage (commandE, EnemySTR(*enemy), DEF(*player));
			PrintKata(EnemyName(*enemy)); printf(" menggunakan Flank, tapi ");PrintKata(Name(*player));printf(" juga menggunakan Flank!");
		}
	} else if (commandE == 'B') //kasus saat enemy memberi command block
	{
		if (commandP == 'A')
		{
			PrintKata(EnemyName(*enemy)); printf(" melakukan block, ");PrintKata(Name(*player));printf(" menyerang. Blocked!");
		} else if (commandP == 'B')
		{
			PrintKata(EnemyName(*enemy)); printf(" melakukan block, ");PrintKata(Name(*player));printf(" juga block, main aman ya..");
		} else if (commandP == 'F')
		{
			dmgP = CalculateDamageE (commandP, STR(*player), EnemyDEF(*enemy),skill);
			PrintKata(EnemyName(*enemy)); printf(" melakukan block, ");PrintKata(Name(*player));printf(" Flank! Bagus!");
		}
	}
	gotoXY(29+turn,86);printf("│ %03d │ %03d │",dmgE,dmgP);
}

void ProcessCommand(char commandE, char commandP ,ENEMY* enemy, PLAYER* player, BinTree skill)
//mengecek masukan command player dengan command yang dikeluarkan enemy
//I.S : commandE, commandP, enemy, player, skill terdefinisi 
//F.S : menghasilkan hal yang terjadi berdasarkan command yang diinputkan

{
	if (commandE ==  'A') //kasus saat enemy memberi command attack
	{
		if (commandP == 'A')
		{
			DecreaseHP (player, CalculateDamage (commandE, EnemySTR(*enemy), DEF(*player)));
			DecreaseHPE (enemy, CalculateDamageE (commandP, STR(*player), EnemyDEF(*enemy),skill));
		} else if (commandP == 'F')
		{
			DecreaseHP (player, CalculateDamage (commandE, EnemySTR(*enemy), DEF(*player)));
		} else if (commandP == 'B')
		{
			//Kalo ngeblock dan punya skill counter block
			if (HasSkill(Akar(SearchTreeString (skill, "CounterBlock"))))
			{
				DecreaseHPE (enemy, CalculateDamageE ('A', STR(*player), EnemyDEF(*enemy),skill));
			}
		}
	} else if (commandE == 'F') //kasus saat enemy memberi command flank
	{
		if (commandP == 'A')
		{
			DecreaseHPE (enemy, CalculateDamageE (commandP, STR(*player), EnemyDEF(*enemy),skill));
		} else if (commandP == 'B')
		{
			DecreaseHP (player, CalculateDamage (commandE, EnemySTR(*enemy), DEF(*player)));
		} else if (commandP == 'F')
		{
			DecreaseHPE (enemy, CalculateDamageE (commandP, STR(*player), EnemyDEF(*enemy),skill));
			DecreaseHP (player, CalculateDamage (commandE, EnemySTR(*enemy), DEF(*player)));
		}
	} else if (commandE == 'B') //kasus saat enemy memberi command block
	{
		if (commandP == 'A')
		{
			// Do nothing
		} else if (commandP == 'B')
		{
			// Do nothing
		} else if (commandP == 'F')
		{
			DecreaseHPE (enemy, CalculateDamageE (commandP, STR(*player), EnemyDEF(*enemy),skill));
		}
	}
}

int CalculateDamageE(char cek, int STR, int DEF, BinTree skill)
//menghitung dan menghasilkan damage yang didapat sebuah player

{
	int dmg = 1; // inisialisasi awal
	if (cek == 'A') {
		if (HasSkill(Akar(SearchTreeString (skill, "ProAttacker")))) {
			dmg = round(((STR*1.5) - DEF)*1.5);
		} 	else if (HasSkill(Akar(SearchTreeString (skill, "GoodAttacker")))) {
			dmg = round(((STR*1.5) - DEF)*1.2);
		} 	else {
			dmg = round((STR*1.5) - DEF);
		}
	} else if (cek == 'F') {
		if (HasSkill(Akar(SearchTreeString (skill, "ProFlanker")))) {
			dmg = round(((STR*1.5) - DEF)*2);
		} else if (HasSkill(Akar(SearchTreeString (skill, "GoodFlanker")))) {
			dmg = round(((STR*1.5) - DEF)*1.7);
		} else {
			dmg = round((STR*1.5) - DEF);
		}
	} else if (cek == 'B') { // Boxing Punch
		dmg = round((STR*1.5) - DEF);
	} else if (cek == 'G') { // Gatling Gun
		dmg = round(STR*0.5);
	} else if (cek == 'X') { // Exorcist
		dmg = round((STR*1.5) - DEF); //DEF == STR saat pemanggilan fungsi
	}

	if (dmg < 1) dmg = 1;

	return dmg;
}

int CalculateDamage(char cek, int STR, int DEF)
//menghitung dan menghasilkan damage yang didapat sebuah enemy

{
	int dmg = 1; // inisialisasi awal
	if (cek == 'A') {
		dmg = round((STR*1.5) - DEF);
	}

	else if (cek == 'F'){
		dmg = round(((STR*1.5) - DEF)*1.5);
	}

	if (dmg < 1) dmg = 1;

	return dmg;
}
// ┌─┬─┐
// │ │ │
// ├─┼─┤
// └─┴─┘
void PrintMenang()
//Print pemberitahuan menang ketika menang
// I.S : sembarang
// F.S : menampilkan pemberitahuan bahwa player menang

{
	clrscr;
	gotoXY(1,1);
	CetakBingkai(20,90);
	gotoXY(4+3,15);printf("  ██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗ ██████╗ ███╗   ██╗  ");
	gotoXY(5+3,15);printf("  ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██╔═══██╗████╗  ██║  ");
	gotoXY(6+3,15);printf("   ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║   ██║██╔██╗ ██║  ");
	gotoXY(7+3,15);printf("    ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║   ██║██║╚██╗██║  ");
	gotoXY(8+3,15);printf("     ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝╚██████╔╝██║ ╚████║  ");
	gotoXY(9+3,15);printf("     ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝  ");
	
	gotoXY(18,15);printf("                  Press ENTER to continue                       ");
	pressENTER();
	
}

void GetExp(PLAYER *player, ENEMY enemy, BinTree *Skill)
//Menambahkan EXP yang didapat dari enemy ke player. Mungkin menjadi level up
// I.S : player, enemy, skill
// F.S : player memperoleh exp dan membuka skill sesuai dengan enemy yang dikalahkan

{
    int i;
    Fairy.Length = 5;               // 1
    Spider.Length = 6;              // 2
    Bat.Length = 3;
    Skeleton.Length = 8;
    JackOLantern.Length = 12;
    Devil.Length = 5;
    Casper.Length = 6;
    Centaur.Length = 7;
    Eagle.Length = 5;
    Cobra.Length = 5;
    Phoenix.Length = 7;
    Reaper.Length = 6;
    Dragon.Length = 6;
    for (i = 1;i <= EnemyName(TabEnemy[1]).Length;i++) { Fairy.TabKata[i] = EnemyName(TabEnemy[1]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[2]).Length;i++) { Spider.TabKata[i] = EnemyName(TabEnemy[2]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[3]).Length;i++) { Bat.TabKata[i] = EnemyName(TabEnemy[3]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[4]).Length;i++) { Skeleton.TabKata[i] = EnemyName(TabEnemy[4]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[5]).Length;i++) { JackOLantern.TabKata[i] = EnemyName(TabEnemy[5]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[6]).Length;i++) { Devil.TabKata[i] = EnemyName(TabEnemy[6]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[7]).Length;i++) { Casper.TabKata[i] = EnemyName(TabEnemy[7]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[8]).Length;i++) { Centaur.TabKata[i] = EnemyName(TabEnemy[8]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[9]).Length;i++) { Eagle.TabKata[i] = EnemyName(TabEnemy[9]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[10]).Length;i++) { Cobra.TabKata[i] = EnemyName(TabEnemy[10]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[11]).Length;i++) { Phoenix.TabKata[i] = EnemyName(TabEnemy[11]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[12]).Length;i++) { Reaper.TabKata[i] = EnemyName(TabEnemy[12]).TabKata[i];  }
    for (i = 1;i <= EnemyName(TabEnemy[13]).Length;i++) { Dragon.TabKata[i] = EnemyName(TabEnemy[13]).TabKata[i];  }

	if (IsKataSama(EnemyName(enemy),Fairy)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Spider)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Bat)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Skeleton)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),JackOLantern)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Devil)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Casper)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Centaur)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Eagle)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Cobra)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Phoenix)) { AddExp(player,EnemyExp(enemy), Skill); }
 	else if (IsKataSama(EnemyName(enemy),Reaper)) { AddExp(player,EnemyExp(enemy), Skill);
	}
}
