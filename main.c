/*
	How to Compile :
		ketik "make" di terminal pada direktori yang sama 
*/

//Main Program Brightsouls

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <time.h>
//Include semua header lain
#include "MODUL/SKILL/skill.h"
#include "MODUL/ENEMY/enemy.h"
#include "MODUL/MAP/map.h"
#include "MODUL/PLAYER/player.h"
#include "MODUL/DATA/data.h"
#include "MODUL/NAVIGATION/navigation.h"
#include "MODUL/BATTLE/battle.h"
#include "MODUL/DISPLAY/display.h"
#include "MODUL/DATA/mesinkata.h"
#include "MODUL/NARASI/narasi.h"

//Deklarasi variabel
char* user_name;
PLAYERPOS player_pos;
PLAYER player;
//Map
GRAF mainmap;
TabMat minimaps;
BinTree playerskill;
//Enemy
//ENEMY TabEnemy[14];
boolean isExiting;
Kata uname;

JAM starttime;

char ic[MAX_SCAN_LENGTH];
char suname[MAX_SCAN_LENGTH];
char pil[MAX_SCAN_LENGTH];

//headers;
void SelectMenu();
//Menampilkan main menu
void OnMap();
//Pemrosesan saat berada di map
void OnEnemy(ENEMY * enemy, PLAYER * player, boolean * menang);
//Pemrosesan saat bertemu musuh
void GameOver();
//Saat gammeover
void Ending();
//Saat Ending
void Credits();
//Tampilkan credits
char* scan_line(char* buffer, int buffer_size);
//Scanf dengan spasi

char* scan_line(char* buffer, int buffer_size) {
		char* p = buffer;
		int count = 0;
		do {
				char c;
				scanf("%c", &c); // scan a single character
				// break on end of line, string terminating NUL, or end of file
				if (c == '\r' || c == '\n' || c == 0 || c == EOF) {
						*p = 0;
						break;
				}
				*p++ = c; // add the valid character into the buffer
		} while (count < buffer_size - 1);  // don't overrun the buffer
		// ensure the string is null terminated
		buffer[buffer_size - 1] = 0;
		return buffer;
}

int main()
{
	clrscr;
	// Opening(7,5);
	SelectMenu();
	return 0;
}

void newGame(){
	int x = 0, xx = 1;
	boolean benar;
	Kata user;
	inputusername(); // Manggil tampilan input
	do {
		x = 0;
		benar = true;
		scan_line(suname, MAX_SCAN_LENGTH); // Scan string

		while(suname[x]!=0 && benar) {
			if(suname[x] == ' '){ // cek spasi
				benar = false;
			} else {
				user.TabKata[x+1] = suname[x];
				x++; // len(suname)
			}
			if (x > 20) {
				benar = false;
			}
		}
		user.Length = x;
		user.Val = 0;
		if (x == 0) benar = false;
		if (!benar) {
			gotoXY(15,50);printf(COLOR_RED"Max. 20 char, Tidak mengandung spasi");
		}
		if (benar) {
			if(CheckExistence(user))
			{
				gotoXY(15,50);printf(COLOR_RED"Username Taken                      ");
				benar = false;
			}
		}
		// sleep(100);
		printf(COLOR_BLUE);
		gotoXY(15,23);printf("                        │  ");
		// gotoXY(15,50);printf("                                    ");
		printf(COLOR_GREEN);gotoXY(15,23);
	} while (!benar);

	uname.Length = x;
	while(x--){
			uname.TabKata[xx] = suname[xx-1];
			xx++;
	}
	username(&player,uname); // input uname ke player
	GenerateMap(&mainmap, &minimaps, &player_pos);

	InitializeSkill(&playerskill);
	GenerateSkillOnMap(playerskill, &minimaps);
	LoadEnemy(mainmap);
	PilihJob(&player);
	LoadStatusPlayer(player);
	Lvl1Player(&player);

///////////    NARASI   /////////////
	switch (Job(player)) {
		case 1:
			mahasiswaProlog();
			break;
		case 2:
			begalProlog();
			break;
		case 3:
			satpamProlog();
			break;
		case 4:
			kuliProlog();
			break;			
	}

	loading();
	OnMap();
}

//LOAD GAME
void loadGame()
{	
	clrscr;
	int MAX = 16, PAGES = 6;
	int idxmax[PAGES];
	Kata nama[PAGES][MAX],job[PAGES][MAX];
	JAM waktujam[PAGES][MAX], durasi[PAGES][MAX];
	int idx = 0,page = -1,maxpage = 0;
	int i,j,k;
	idxmax[0] = 0;idxmax[1] = 0;idxmax[2] = 0;idxmax[3] = 0;idxmax[4] = 0;idxmax[5] = 0;
  	//Membuka files yang tersedia
  	STARTSAVEFILES();
  	EndKata = false;
  	while (!EndKata) {
  		ADVKATA(); // Idx
	  		idx = CKata.Val;
	  		if ((idx%15) == 1 && CKata.Val != 0) {
	  			idxmax[page] = 15;
	  			page++;
	  			maxpage = page;
	  		}
	  		if (idx > 15) {
	  			idx = ((idx-1) % 15) + 1;
	  		}
  		ADVKATA(); // Nama
  			nama[page][idx] = CopyKata(CKata);
  		ADVKATA(); // Job
  			job[page][idx] = CopyKata(CKata);
  		ADVKATA(); // Guard
  		if (CheckExistence(nama[page][idx])){
			STARTFILE(KataToChar(nama[page][idx]));
				ADVKATA2(); // nama
				ADVKATA2(); // waktu
				waktujam[page][idx] = DetikToJAM(CKata2.Val);
				ADVKATA2(); // dur
				durasi[page][idx] = DetikToJAM(CKata2.Val);		
		}
		if (idx > idxmax[page])
			idxmax[page] = idx;
	}

	setWin(35,98);
	gotoXY(1,1);
	CetakBingkai(35,98);
	gotoXY(3,11);printf("  ██╗      ██████╗  █████╗ ██████╗      ██████╗  █████╗ ███╗   ███╗███████╗ ");
	gotoXY(4,11);printf("  ██║     ██╔═══██╗██╔══██╗██╔══██╗    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝ ");
	gotoXY(5,11);printf("  ██║     ██║   ██║███████║██║  ██║    ██║  ███╗███████║██╔████╔██║█████╗   ");
	gotoXY(6,11);printf("  ██║     ██║   ██║██╔══██║██║  ██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝   ");
	gotoXY(7,11);printf("  ███████╗╚██████╔╝██║  ██║██████╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗ ");
	gotoXY(8,11);printf("  ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ");
	gotoXY(10,2);for (int i=1;i<=96;i++) printf(COLOR_CYAN"\u2503");

	gotoXY(13,13);printf(COLOR_RED"Username"COLOR_RESET);
	gotoXY(13,40);printf(COLOR_MAGENTA"Job"COLOR_RESET);
	gotoXY(13,60);printf(COLOR_BLUE"Play Time"COLOR_RESET);
	gotoXY(13,77);printf(COLOR_YELLOW"Save Time"COLOR_RESET);
	
	int pil = 0,um;
	char cc;

	page = 0;
	while (1)
	{	
		if (page == 0 && pil == idxmax[page]+1) pil = 0;
		if (page == maxpage && pil == idxmax[page]+2) pil = 0;
		for (i = 1 ; i <= 15 ; i++) {
			gotoXY(14+i,13);	
			printf("                                                                                   ");
		}
		gotoXY(33,6);printf("\u27F0 Back");
		if (page != 0) {gotoXY(33,80);printf("\u25C4 Prev");} else {gotoXY(33,80);printf("      ");}
		if (page != maxpage) {gotoXY(33,87);printf("Next ►");} else {gotoXY(33,87);printf("      ");}
		for (i = 1 ; i <= idxmax[page] ; i++) {
			gotoXY(14+i,13);	
			PrintKata(nama[page][i]);
			gotoXY(14+i,40);
			PrintKata(job[page][i]);
			gotoXY(14+i,60);	
			printf("%02d:%02d:%02d ",Hour(durasi[page][i]),Minute(durasi[page][i]),Second(durasi[page][i]));
			gotoXY(14+i,77);	
			printf("%02d:%02d:%02d ",Hour(waktujam[page][i]),Minute(waktujam[page][i]),Second(waktujam[page][i]));
		}		
		for (um = 0 ; um < idxmax[page] ; um++) {
			if (pil == um) { gotoXY(15+pil,10); printf("\u25B7\u25B8"); } else { gotoXY(15+um,10); printf("  "); }
		}
		if (pil == idxmax[page]) { gotoXY(33,6);printf(COLOR_WHITE"\u27F0 \e[4mBack"COLOR_RESET); } else { gotoXY(33,6);printf("\u27F0 Back"); }
		if (page != 0) {if (pil == idxmax[page]+1) { gotoXY(33,80);printf(COLOR_WHITE"\u25C4 \e[4mPrev"COLOR_RESET); } else { gotoXY(33,80);printf("\u25C4 Prev"); }}
		if (page != maxpage) {if (pil == idxmax[page]+2) { gotoXY(33,87);printf(COLOR_WHITE"\e[4mNext"COLOR_RESET" ►"); } else { gotoXY(33,87);printf("Next ►"); }}
		initTermios(); // use new terminal setting again to make kbhit() and getch() work
		cc = getch();
		resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
		if(cc == 27 ) {
			initTermios();
			cc = getch();
			cc = getch();
			resetTermios();
			switch (cc) {
				case 'A':
					if (pil == idxmax[page]+1 || pil == idxmax[page]+2)
						pil = idxmax[page]-1;
					else {
						pil = (pil - 1);
						if (pil == -1)
							pil = idxmax[page];
					}
					break;
				case 'B':
					if (pil == idxmax[page]+1 || pil == idxmax[page]+2)
						pil = 0;
					else {
						pil = (pil + 1) % (idxmax[page]+1);
					}	
					break;
				case 'C':
					if (pil == idxmax[page])
						pil = idxmax[page]+1;
					else if (pil == idxmax[page]+1)
						pil = idxmax[page]+2;
					else if (pil == idxmax[page]+2)
						pil = idxmax[page];
					if (page == 0 && pil == idxmax[page]+1)
						pil = idxmax[page]+2;
					if (page == maxpage && pil == idxmax[page]+2)
						pil = idxmax[page];
					break;
				case 'D':
					if (pil == idxmax[page])
						pil = idxmax[page]+2;
					else if (pil == idxmax[page]+1)
						pil = idxmax[page];
					else if (pil == idxmax[page]+2)
						pil = idxmax[page]+1;
					if (page == 0 && pil == idxmax[page]+1)
						pil = idxmax[page];
					if (page == maxpage && pil == idxmax[page]+2)
						pil = idxmax[page]+1;
					break;
			}

		} else if (cc == 10) {
			if (pil <= idxmax[page]) {
				break;
			} else if (pil == idxmax[page]+1) { // (prev)
				if (page != 0){
					page--;
					pil = idxmax[page]+1;
				}
			} else { // idxmax[page]+2 (next)
				if (page != maxpage){
					page++;
					pil = idxmax[page]+2;
				}
			}
		}
	}

	if (pil == idxmax[page]) return; // Back

	pil++;
	int pagex = -1;
	// Mencari savean pilihan player
	STARTSAVEFILES();
	EndKata = false;
	boolean found = false;
	while(!EndKata && !found){
		ADVKATA(); // idx
		idx = CKata.Val;
  		if ((idx%15) == 1 && CKata.Val != 0) {
  			pagex++;
  		}
		if (idx > 15) {
	  		idx = ((idx-1) % 15) + 1;
	  	}
		if (idx == pil && page == pagex) {
			ADVKATA(); // nama
			nama[page][idx] = CopyKata(CKata);
			found = true;
		}
		ADVKATA(); // nama
		ADVKATA(); // job
		ADVKATA(); // guard
	}
	int waktu,dur;
	InitializeSkill(&playerskill);
	//Generate Empty map
	for(k = 1; k <= MaxArea*2-1; k++)
	{	
		for(i = 1; i <= BrsArea; i++)
		{	
			for(j = 1;j <= KolArea; j++)
			{
				Elmt(Area(minimaps, k), i,j) = ' ';
			}
		}
	}
	//Masukin nama ke player
	Name(player) = CopyKata(nama[page][idx]);
	//LoadStatusPlayer(player);
	Load(&nama[page][idx], &minimaps, &player, &player_pos, &dur, &playerskill, &waktu);

	InitializeSkill(&playerskill);
	IsiTabSkillPos(playerskill);
	LoadStatusPlayer(player);
	LoadPlayer(&player,&playerskill);

	connectMap(minimaps,  &mainmap);
	LoadEnemy(mainmap);
	Load(&nama[page][idx] , &minimaps, &player, &player_pos, &dur, &playerskill, &waktu);
	//Mengkonek Map
	loading();
	OnMap();
}


void SelectMenu()
{
	HIDEKURSOR;
	char cc, bef[4][23] = {"  Start a New Game   ", "  Load a Game   ", "  About   ", "  Quit   "}, aft[5][30] = {"\u25B7 Start a New Game \u25C1 ", "\u25B7 Load a Game \u25C1 ", "\u25B7 About \u25C1 ","\u25B7 Quit \u25C1 "};
	int pil = 0, id[4] = {43, 45, 48, 49};
	while(pil != 3)
	{
		menu();
		gotoXY(13+2*pil, id[pil]);
		printf("\e[1;37m%s"COLOR_RESET"\n", aft[pil]);
		while (1)
		{
			initTermios(); // use new terminal setting again to make kbhit() and getch() work
			cc = getch();
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
			if(cc == 27 )
			{
				initTermios();
				cc = getch();
				cc = getch();
				resetTermios();
				gotoXY(13+2*pil, id[pil]);
				printf("%s", bef[pil]);
				switch(cc)
				{
					case 'A' :
					pil = (pil+3) % 4;
					break;
					case 'B' :
					pil = (pil+1) % 4;
					break;
				}
				gotoXY(13+2*pil, id[pil]);
				printf("\e[1;37m%s"COLOR_RESET, aft[pil]);
			} else if(cc == 10) {
				switch(pil)
				{
					case 0 :
						newGame();
						break;
					case 1 :
						loadGame();
						break;
					case 2 :
						credit();
						break;
					case 3 :
						clrscr;
						break;
				}
				break;
			}
		}
	}
	printf(COLOR_RESET);
	SHOWKURSOR;
}

void OnMap()
{
		clrscr;
		char cc;
		HIDEKURSOR;
		GetCurrentJAM(&starttime);
		isExiting = false;
		while(!isExiting)
		{
				resetTermios();
				setWin(31,79);
				gotoXY(1,1);
				CetakBingkai(31,79);
				//Print Map sesuai spesifikasi
				PrintStatus(player, player_pos);
				PrintMap(minimaps, player_pos);
				PrintCommand();
				BS();
				gotoXY(31,79);
				initTermios();
				cc = getch();
				resetTermios();
				if (cc == 27) {
						clrscr;
						initTermios();
						cc = getch();
						cc = getch();
						resetTermios();
						switch(cc) {
								case 'A':
										GoUp(&player_pos,minimaps, mainmap);
										break;
								case 'B':
										GoDown(&player_pos,minimaps, mainmap);
										break;
								case 'C':
										GoRight(&player_pos,minimaps, mainmap);
										break;
								case 'D':
										GoLeft(&player_pos,minimaps, mainmap);
										break;
						}
				} else if (cc == 'S' || cc == 's') {
						Yakinsave();
						do {
								initTermios();
								cc = getch();
								resetTermios();
								if (cc == 'Y' || cc == 'y') {
										Save(minimaps,player,player_pos,JAMToDetik(starttime), playerskill);
										YakinsaveD();
										Saveberhasil();
										GetCurrentJAM(&starttime); // Kalau nge-save Jam nya kembali ke 0
								} else if ( cc == 'N' || cc == 'n') {
										YakinsaveD();
										BS();
								}
						} while (cc != 'Y' && cc != 'y' && cc != 'N' && cc != 'n');
				} else if (cc == 'L' || cc == 'l') {
					loadGame();
				} else if (cc == 'X' || cc == 'x') {
						Yakinexit();
						do {
								initTermios();
								cc = getch();
								resetTermios();
								if (cc == 'Y' || cc == 'y') {
										isExiting = true;
								} else if ( cc == 'N' || cc == 'n') {
										YakinsaveD();
										BS();
								}
						} while (cc != 'Y' && cc != 'y' && cc != 'N' && cc != 'n');
				} else if (cc == 'T' || cc == 't') {
						clrscr;
						gotoXY(1,1);
						CetakBingkai(31,79);
						printf(COLOR_WHITE);
						gotoXY(9,3);SkillMenu(playerskill, 7);

						printf(COLOR_RED);
						gotoXY(3,25);printf("┌─┐┬┌─┬┬  ┬    ┌┬┐┌─┐┌┐┌┬ ┬");
						gotoXY(4,25);printf("└─┐├┴┐││  │    │││├┤ ││││ │");
						gotoXY(5,25);printf("└─┘┴ ┴┴┴─┘┴─┘  ┴ ┴└─┘┘└┘└─┘");

						printf(COLOR_CYAN);
						gotoXY(7,2);for (int i=1;i<=77;i++) printf("\u2501");
						for (int i = 0; i < 17; ++i)
						{
								gotoXY(10+i,1); printf("\u2503");
						}
						printf(COLOR_CYAN);
						gotoXY(29,2);for (int i=1;i<=77;i++) printf("\u2501");
						printf(COLOR_WHITE);
						gotoXY(30,54);printf("Press ENTER to continue");
						pressENTER();
						BS();
				} else if (cc == '1') { // CHEAT LEVEL UP (TEKEN 1 di MAP)
						LevelUp(&player,&playerskill);
				}
				if(!isExiting)
				{   //Mengecek apakah jenis kotak dimana player berada
						char tile = CheckTile(player_pos, minimaps);
						ENEMY enemy;

								boolean acq;
						int e;
						boolean menang = false;
						switch(tile)
						{
						case 'E':
								//mencari enemy apa yang ada diposisi tsb
								enemy = GetEnemy (player_pos, &e);
								// masuk mode berantem

								Dragon.Length = 6;
								int ii;
								for (ii = 1;ii <= EnemyName(TabEnemy[13]).Length;ii++) { Dragon.TabKata[ii] = EnemyName(TabEnemy[13]).TabKata[ii];  }
								if (IsKataSama(EnemyName(enemy),Dragon)) {
										clrscr;
										setWin(35,80);
										gotoXY(1,1);
										CetakBingkai(35,80);
										bossdragon1(11,11);
										pressENTER();
										clrscr;
										gotoXY(1,1);
										CetakBingkai(35,80);
										bossdragon3(3,3);
										PrintStatE(enemy,29);
										pressENTER();
										OnEnemy(&enemy, &player, &menang);
								} else {
										clrscr;
										gotoXY(1,1);
										clrscr;
										gotoXY(1,1);
										CetakBingkai(30,60);
										gotoXY(28,2);printf("                                                          ");
										gotoXY(29,2);printf(" ");
										EnemyAppeared();
										PrintEnemy(enemy,6,2);
										PrintStatE(enemy, 23);
										gotoXY(28,2); printf(COLOR_CYAN); for (int A=1;A<=58;A++) printf("\u2501"); printf(COLOR_RESET);
										gotoXY(29,3);printf(COLOR_MAGENTA"Press ENTER to continue.."COLOR_RESET);
										pressENTER();
										clrscr;
										OnEnemy(&enemy, &player, &menang);
										if (menang) {
												clrscr;
												DeleteEnemyPos(&enemy, player_pos, e);
										} else {
												switch(cc) {
														case 'A':
																GoDown(&player_pos,minimaps, mainmap);
																break;
														case 'B':
																GoUp(&player_pos,minimaps, mainmap);
																break;
														case 'C':
																GoLeft(&player_pos,minimaps, mainmap);
																break;
														case 'D':
																GoRight(&player_pos,minimaps, mainmap);
																break;
												}
										}
								}
								break;
						case 'M' :
								//nyembuhin
								gotoXY(1,1);
								CetakBingkai(31,79);
								Heal(&player);
								DelM(player_pos, &minimaps);
								PrintStatus(player, player_pos);
								PrintMap(minimaps, player_pos);
								PrintCommand();	
								BS();
								pressENTER();
								break;
						case 'S' :
								acq = false;
								CetakBingkai(31,79);
								PrintStatus(player, player_pos);
								PrintMap(minimaps, player_pos);
								PrintCommand();
								GetSkill(player_pos, &acq, &playerskill);
								if (acq)
								DelS(player_pos, &minimaps);
								BS();
								pressENTER();
								break;
						default:
								break;
						}
				}
		}

}

void InputCommand2(Queue *Q, int *X, BinTree skill, int *bp, int *gg, int *ex, int *gt, int *hl, boolean *isFlee) {
	HIDEKURSOR;
	char cc,um;
	int pil = 0;
			pilihancommand();
			// CEK ADA TIDAKNYA SKILL, JIKA ADA MENAMPILKAN KE LAYAR
			if (HasSkill(Akar(SearchTreeString (skill, "Flee")))) {
				gotoXY(37,45);
				printf(COLOR_WHITE);
				printf("Flee");
			}
			if (HasSkill(Akar(SearchTreeString (skill, "BoxingPunch")))) {
				gotoXY(37,64);
				printf(COLOR_WHITE);
				if (*bp == 1)
					printf("Boxing Punch");
				else {
					printf(COLOR_RESET);
					printf("Boxing Punch");
				}
			}
			if (HasSkill(Akar(SearchTreeString (skill, "GatlingGun")))) {
				gotoXY(37,83);
				printf(COLOR_WHITE);
				if (*gg == 1)
					printf("Gatling Gun");
				else {
					printf(COLOR_RESET);
					printf("Gatling Gun");
				}
			}
			if (HasSkill(Akar(SearchTreeString (skill, "Exorcist")))) {
				gotoXY(38,45);
				printf(COLOR_WHITE);
				if (*ex == 1)
					printf("Exorcist");
				else {
					printf(COLOR_RESET);
					printf("Exorcist");
				}
			}
			if (HasSkill(Akar(SearchTreeString (skill, "Giant")))) {
				gotoXY(38,64);
				printf(COLOR_WHITE);
				if (*gt == 1)
					printf("Giant");
				else {
					printf(COLOR_RESET);
					printf("Giant");
				}
			}
			if (SearchHasSkill(skill, "Heal")) {
				gotoXY(38,83);
				printf(COLOR_WHITE);
				if (*hl == 1)
					printf("Heal");
				else {
					printf(COLOR_RESET);
					printf("Heal");
				}
			}
			while (1)
	    	{
				gotoXY(37,5); if (pil == 0) printf("\u25B6"); else printf(" ");
				gotoXY(38,5); if (pil == 5) printf("\u25B6"); else printf(" ");
				gotoXY(37,24); if (pil == 1) printf("\u25B6"); else printf(" ");
				gotoXY(38,24); if (pil == 6) printf("\u25B6"); else printf(" ");
				gotoXY(37,43); if (pil == 2) printf("\u25B6"); else printf(" ");
				gotoXY(38,43); if (pil == 7) printf("\u25B6"); else printf(" ");
				gotoXY(37,62); if (pil == 3) printf("\u25B6"); else printf(" ");
				gotoXY(38,62); if (pil == 8) printf("\u25B6"); else printf(" ");
				gotoXY(37,81); if (pil == 4) printf("\u25B6"); else printf(" ");
				gotoXY(38,81); if (pil == 9) printf("\u25B6"); else printf(" ");
				initTermios();
				cc = getch();
				resetTermios();
				if(cc == 27 ) {
					gotoXY(34,63);printf("                                   ");
					initTermios();
					cc = getch();
					cc = getch();
					resetTermios();
					switch (cc) {
						case 'A':
						case 'B':
							pil = (pil + 5) % 10;
							break;
						case 'C':
							pil = (pil + 1) % 10;
							break;
						case 'D':
							pil = pil - 1;
							if (pil == -1) pil = 9;
							break;
					}
				} else if (cc == 10) {
					if (pil == 6) {
						if (*X != 1) {
							break;
						} else {
							 gotoXY(34,63); printf(" There's no command can be deleted.");
						}
					} else if (pil == 2) {
						if (HasSkill(Akar(SearchTreeString (skill, "Flee")))) {
							if (*hl == -1) {
								gotoXY(34,71); printf(" You can't flee after heal.");
							} else {
								break;
							}
						} else {
							gotoXY(34,72); printf(" Skill ini masih terkunci.");
						}
					} else if (pil == 3) {
						if (HasSkill(Akar(SearchTreeString (skill, "BoxingPunch")))) {
							if (*bp == -1) {
								gotoXY(34,72); printf("Skill ini sudah digunakan.");
							} else {
								break;
							}
						} else {
							gotoXY(34,72); printf(" Skill ini masih terkunci.");
						}
					} else if (pil == 4) {
						if (HasSkill(Akar(SearchTreeString (skill, "GatlingGun")))) {
							if (*gg == -1) {
								gotoXY(34,72); printf("Skill ini sudah digunakan.");
							} else {
								break;
							}
						} else {
							gotoXY(34,72); printf(" Skill ini masih terkunci.");
						}
					} else if (pil == 7) {
						if (HasSkill(Akar(SearchTreeString (skill, "Exorcist")))) {
							if (*ex == -1) {
								gotoXY(34,72); printf("Skill ini sudah digunakan.");
							} else {
								break;
							}
						} else {
							gotoXY(34,72); printf(" Skill ini masih terkunci.");
						}
					} else if (pil == 8) {
						if (HasSkill(Akar(SearchTreeString (skill, "Giant")))) {
							if (*gt == -1 || *gt == -2) {
								gotoXY(34,72); printf("Skill ini sudah digunakan.");
							} else {
								break;
							}
						} else {
							gotoXY(34,72); printf(" Skill ini masih terkunci.");
						}
					} else if (pil == 9) {
						if (SearchHasSkill(skill, "Heal")) {
							if (*hl == -1) {
								gotoXY(34,72); printf("Skill ini sudah digunakan.");
							} else {
								break;
							}
						} else {
							gotoXY(34,72); printf(" Skill ini masih terkunci.");
						}
					} else {
						break;
					}
				}
			}
			if (pil == 0) { // A
				*X = *X + 1;
				AddQ(Q,'A');
			} else if (pil == 1) { // B
				*X = *X + 1;
				AddQ(Q,'B');
			} else if (pil == 2) { // Flee
				*isFlee = true;
			} else if (pil == 3) { // BoxingPunch
				*bp = 0;
			} else if (pil == 4) { // GatlingGun
				*gg = 0;
			} else if (pil == 5) { // F
				*X = *X + 1;
				AddQ(Q,'F');
			} else if (pil == 6) { // E
				*X = *X - 1;
				DelQBATTLE(Q,&um);
			} else if (pil == 7) { // Exorcist
				*ex = 0;
			} else if (pil == 8) { // Giant
				*gt = 0;
			} else { // Heal
				*hl = 0;
			}
		printf(COLOR_RESET);
}
//Mode berantem
void OnEnemy(ENEMY * enemy, PLAYER * player, boolean *menang)
{
	boolean isFlee = false;
	clrscr;
	gotoXY(1,1);
	CetakBingkai(42,77);
	int ronde = 1;
	int maxronde;

	Stack EnemyMove;
	CreateEmptyS(&EnemyMove);

	//Inisialisai maxronde
	//Kalo boss max ronde nya 20
	//Generate enemy moves dari file ke stack
	if(IsBoss(*enemy)) {
			maxronde = 20;
			PushEnemyMoveB(&EnemyMove);
	} else {
			maxronde = 10;
			PushEnemyMoveE(&EnemyMove);
	}

	Queue EnemyMoveQ;
	Queue PlayerMoveQ;
	// skill bisa dipake 1x dalam 1 battle
	int bp = 1, gg = 1, ex = 1, gt = 1, hl = 1, plustr, plusdf;
	NextRound(1);
	//Berantem terus ampe ada yang mati ato ronde abis
	while (!IsDead(*player) && !IsDeadE(*enemy) && ronde <= maxronde && !isFlee)
	{
			//Mindahin Top Stack EnemyMove ke Queue EnemyMove
			CreateEmptyQ(&EnemyMoveQ);
			CreateEmptyQ(&PlayerMoveQ);
			for (int i = 1 ; i <= InfoTop(EnemyMove).Length ; i++){
					printf("%d\n",i);
					AddQ(&EnemyMoveQ,InfoTop(EnemyMove).TabKata[i]);
			}
			int turn = 1;
			boolean tarung = false;

			int tutup1 = rand()%4 + 1;
			int tutup2;
			do {
					tutup2 = rand()%4 + 1;
			} while (tutup2 == tutup1);

			int x = 1;
			while (x != 5 && !isFlee && !IsDead(*player) && !IsDeadE(*enemy)) {
					if (x <= 1) {
							PrintBattleInterface(*enemy, &EnemyMoveQ, &PlayerMoveQ, *player, ronde, turn, tutup1, tutup2, tarung);
							gotoXY(31,3);printf("│                                                                                              │");
							gotoXY(32,3);printf("│                                                                                              │");
							gotoXY(33,3);printf("├──────────────────────────────────────────────────────────────────────────────────────────────┤");
							gotoXY(34,3);printf("│ Inserted Command: _ _ _ _                                                                    │");
							gotoXY(35,3);printf("├──────────────────────────────────────────────────────────────────────────────────────────────┤");
							gotoXY(36,3);printf("│                                                                                              │");
							gotoXY(37,3);printf("│                                                                                              │");
							gotoXY(38,3);printf("│                                                                                              │");
							gotoXY(39,3);printf("│                                                                                              │");
							gotoXY(40,3);printf("└──────────────────────────────────────────────────────────────────────────────────────────────┘");
							InputCommand2(&PlayerMoveQ,&x,playerskill,&bp,&gg,&ex,&gt,&hl,&isFlee);
					} else if (x == 2) {
							PrintBattleInterface(*enemy, &EnemyMoveQ, &PlayerMoveQ, *player, ronde, turn, tutup1, tutup2, tarung);
							gotoXY(31,3);printf("│                                                                                              │");
							gotoXY(32,3);printf("│                                                                                              │");
							gotoXY(33,3);printf("├──────────────────────────────────────────────────────────────────────────────────────────────┤");
							gotoXY(34,3);printf("│ Inserted Command: %c _ _ _                                                                    │",Info(Head(PlayerMoveQ)));
							gotoXY(35,3);printf("├──────────────────────────────────────────────────────────────────────────────────────────────┤");
							gotoXY(36,3);printf("│                                                                                              │");
							gotoXY(37,3);printf("│                                                                                              │");
							gotoXY(38,3);printf("│                                                                                              │");
							gotoXY(39,3);printf("│                                                                                              │");
							gotoXY(40,3);printf("└──────────────────────────────────────────────────────────────────────────────────────────────┘");
							InputCommand2(&PlayerMoveQ,&x,playerskill,&bp,&gg,&ex,&gt,&hl,&isFlee);
					} else if (x == 3) {
							PrintBattleInterface(*enemy, &EnemyMoveQ, &PlayerMoveQ, *player, ronde, turn, tutup1, tutup2, tarung);
							gotoXY(31,3);printf("│                                                                                              │");
							gotoXY(32,3);printf("│                                                                                              │");
							gotoXY(33,3);printf("├──────────────────────────────────────────────────────────────────────────────────────────────┤");
							gotoXY(34,3);printf("│ Inserted Command: %c %c _ _                                                                    │",Info(Head(PlayerMoveQ)),Info(Next(Head(PlayerMoveQ))));
							gotoXY(35,3);printf("├──────────────────────────────────────────────────────────────────────────────────────────────┤");
							gotoXY(36,3);printf("│                                                                                              │");
							gotoXY(37,3);printf("│                                                                                              │");
							gotoXY(38,3);printf("│                                                                                              │");
							gotoXY(39,3);printf("│                                                                                              │");
							gotoXY(40,3);printf("└──────────────────────────────────────────────────────────────────────────────────────────────┘");
							InputCommand2(&PlayerMoveQ,&x,playerskill,&bp,&gg,&ex,&gt,&hl,&isFlee);
					} else if (x == 4) {
							PrintBattleInterface(*enemy, &EnemyMoveQ, &PlayerMoveQ, *player, ronde, turn, tutup1, tutup2, tarung);
							gotoXY(31,3);printf("│                                                                                              │");
							gotoXY(32,3);printf("│                                                                                              │");
							gotoXY(33,3);printf("├──────────────────────────────────────────────────────────────────────────────────────────────┤");
							gotoXY(34,3);printf("│ Inserted Command: %c %c %c _                                                                    │",Info(Head(PlayerMoveQ)),Info(Next(Head(PlayerMoveQ))),Info(Next(Next(Head(PlayerMoveQ)))));
							gotoXY(35,3);printf("├──────────────────────────────────────────────────────────────────────────────────────────────┤");
							gotoXY(36,3);printf("│                                                                                              │");
							gotoXY(37,3);printf("│                                                                                              │");
							gotoXY(38,3);printf("│                                                                                              │");
							gotoXY(39,3);printf("│                                                                                              │");
							gotoXY(40,3);printf("└──────────────────────────────────────────────────────────────────────────────────────────────┘");
							InputCommand2(&PlayerMoveQ,&x,playerskill,&bp,&gg,&ex,&gt,&hl,&isFlee);
							if (x == 5) tarung = true;
					}
					// CEK JIKA USER PAKAI SKILL
					if (bp == 0) {
						DecreaseHPE(enemy,CalculateDamageE('B',STR(*player),EnemyDEF(*enemy),playerskill));
						bp = -1;
					}
					if (gg == 0) {
						DecreaseHPE(enemy,CalculateDamageE('G',STR(*player),EnemyDEF(*enemy),playerskill));
						gg = -1;
					}
					if (ex == 0) {
						DecreaseHPE(enemy,CalculateDamageE('G',STR(*player),EnemySTR(*enemy),playerskill));
						ex = -1;
					}
					if (gt == 0) {
						plustr = round(STR(*player)*0.15);
						plusdf = round(DEF(*player)*0.15);
						STR(*player) = STR(*player) + plustr;
						DEF(*player) = DEF(*player) + plusdf;
						gt = -1;
					}
					if (hl == 0) {
						int plus = round(MaxHP(*player) * 0.7);
						HP(*player) += plus;
						if (HP(*player) > MaxHP(*player)) {
							HP(*player) = MaxHP(*player);
						}
						hl = -1;
					}

			}

			while (!IsDead(*player) && !IsDeadE(*enemy) && turn <= 4 && !isFlee) {
					switch (turn) {
							case 1 :
									gotoXY(31,3);printf("│ "); gotoXY(31,86);printf("│     │     │");
									gotoXY(32,3);printf("│ "); gotoXY(32,86);printf("│     │     │");
									gotoXY(33,3);printf("│ "); gotoXY(33,86);printf("│     │     │");
									ProcessCommand(InfoHead(EnemyMoveQ),Info(Head(PlayerMoveQ)),enemy,player,playerskill);
									PrintBattleInterface(*enemy, &EnemyMoveQ, &PlayerMoveQ, *player, ronde, turn, tutup1, tutup2, tarung);
									gotoXY(30,3);printf("│ "); ProcessKata(InfoHead(EnemyMoveQ),Info(Head(PlayerMoveQ)),enemy,player,playerskill,1);
									break;
							case 2 :
									gotoXY(32,3);printf("│ "); gotoXY(32,86);printf("│     │     │");
									gotoXY(33,3);printf("│ "); gotoXY(33,86);printf("│     │     │");
									ProcessCommand(Info(Next(Head(EnemyMoveQ))),Info(Next(Head(PlayerMoveQ))),enemy,player,playerskill);
									PrintBattleInterface(*enemy, &EnemyMoveQ, &PlayerMoveQ, *player, ronde, turn, tutup1, tutup2, tarung);
									gotoXY(30,3);printf("│ "); ProcessKata(InfoHead(EnemyMoveQ),Info(Head(PlayerMoveQ)),enemy,player,playerskill,1);
									gotoXY(31,3);printf("│ "); ProcessKata(Info(Next(Head(EnemyMoveQ))),Info(Next(Head(PlayerMoveQ))),enemy,player,playerskill,2);
									break;
							case 3 :
									gotoXY(33,3);printf("│ "); gotoXY(33,86);printf("│     │     │");
									ProcessCommand(Info(Next(Next(Head(EnemyMoveQ)))),Info(Next(Next(Head(PlayerMoveQ)))),enemy,player,playerskill);
									PrintBattleInterface(*enemy, &EnemyMoveQ, &PlayerMoveQ, *player, ronde, turn, tutup1, tutup2, tarung);
									gotoXY(30,3);printf("│ "); ProcessKata(InfoHead(EnemyMoveQ),Info(Head(PlayerMoveQ)),enemy,player,playerskill,1);
									gotoXY(31,3);printf("│ "); ProcessKata(Info(Next(Head(EnemyMoveQ))),Info(Next(Head(PlayerMoveQ))),enemy,player,playerskill,2);
									gotoXY(32,3);printf("│ "); ProcessKata(Info(Next(Next(Head(EnemyMoveQ)))),Info(Next(Next(Head(PlayerMoveQ)))),enemy,player,playerskill,3);
									break;
							case 4 :
									ProcessCommand(InfoTail(EnemyMoveQ),InfoTail(PlayerMoveQ),enemy,player,playerskill);
									PrintBattleInterface(*enemy, &EnemyMoveQ, &PlayerMoveQ, *player, ronde, turn, tutup1, tutup2, tarung);
									gotoXY(30,3);printf("│ "); ProcessKata(InfoHead(EnemyMoveQ),Info(Head(PlayerMoveQ)),enemy,player,playerskill,1);
									gotoXY(31,3);printf("│ "); ProcessKata(Info(Next(Head(EnemyMoveQ))),Info(Next(Head(PlayerMoveQ))),enemy,player,playerskill,2);
									gotoXY(32,3);printf("│ "); ProcessKata(Info(Next(Next(Head(EnemyMoveQ)))),Info(Next(Next(Head(PlayerMoveQ)))),enemy,player,playerskill,3);
									gotoXY(33,3);printf("│ "); ProcessKata(InfoTail(EnemyMoveQ),InfoTail(PlayerMoveQ),enemy,player,playerskill,4);
									break;
					}
					gotoXY(37,74);printf(COLOR_YELLOW"Press ENTER to continue"COLOR_RESET);
					pressENTER();
					turn++;
			}
			if (gt == -1) {
				STR(*player) = STR(*player) - plustr;
				DEF(*player) = DEF(*player) - plusdf;
				gt = -2;
			}
			if (!IsDead(*player) && !IsDeadE(*enemy) && !isFlee) {
					ronde++;
					clrscr;
					if (ronde <= maxronde) {
						NextRound(ronde);
					} else {
						RoundsUp();
					}
					Kata um; // Dummy
					PopS(&EnemyMove,&um);
			}

			if(IsDead(*player))
			{
					GameOver();
			}
			else if (IsDeadE(*enemy))
			{
					*menang = true;
					if(!IsBoss(*enemy))
					{
							//Menambahkan exp player
							PrintMenang();
							GetExp(player,*enemy, &playerskill);
							//hapus enemy dari map
							DelM(player_pos,&minimaps);
					}
					else //enemy adalah bossss!!!
					{
							Ending();
					}
			} else { 
				// isFlee
			}
	}
}

void GameOver()
{
	//  Gameover disini
	isExiting = true;
	switch (Job(player)) {
		case 1:
			mahasiswaGameOver();
			break;
		case 2:
			begalGameOver();
			break;
		case 3:
			satpamGameOver();
			break;
		case 4:
			kuliGameOver();
			break;			
	}
	gameover();
	Credits();
}

void Ending()
{
	//Ending Disinni
	isExiting = true;
	switch (Job(player)) {
		case 1:
			mahasiswaVictory();
			break;
		case 2:
			begalVictory();
			break;
		case 3:
			satpamVictory();
			break;
		case 4:
			kuliVictory();
			break;			
	}
	congrats();
	Credits();
}

void Credits()
{
	credit();
	ganesha();
}
