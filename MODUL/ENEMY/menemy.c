/*
	How to Compile :
		gcc -o menemy menemy.c display.c player.c queuelist.c mesintoken.c mesinkar.c enemy.c mesinkata.c point.c battle.c stacklist.c graf.c map.c matriks.c navigation.c queuelistl.c skill.c data.c jam.c bintree.c -lm
*/

//Main Program Brightsouls

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <time.h>

#include "enemy.h"

boolean EndKata;
Kata CKata;

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

void OnMap();
//Pemrosesan saat berada di map
void OnEnemy(ENEMY * enemy, PLAYER * player, boolean * menang);
//Pemrosesan saat bertemu musuh
void GameOver();

int main()
{
	newGame();
	return 0;
}

void newGame() {
	uname.Val = 0;
	uname.Length = 1;
	uname.TabKata[1] = 'a';
	username(&player,uname); // input uname ke player
	GenerateMap(&mainmap, &minimaps, &player_pos);
	InitializeSkill(&playerskill);
	GenerateSkillOnMap(playerskill, &minimaps);
	LoadEnemy(mainmap);
	Job(player) = 1;
	LoadStatusPlayer(player);
	Lvl1Player(&player);
	LevelUp(&player,&playerskill);
	LevelUp(&player,&playerskill);
	LevelUp(&player,&playerskill);
	LevelUp(&player,&playerskill);
	LevelUp(&player,&playerskill);
	clrscr;
	OnMap();
}


void OnMap()
{
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
				/*
						} else if (ic[0] == 'u' && ic[1] == 'm') {
								clrscr;
								LevelUp(&player,&playerskill);
						} else if (ic[0] == 'a' && ic[1] == 'k') {
								clrscr;
								printf("\n\n\t\tEntering arrow key..\n");
								sleep(1);
								int x;
								printf("mau pake brp kali ?\n> ");
								scanf("%d",&x);
								clrscr;
								printf("Key Left = %d\n",x);
								*/
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
				}
				else if (cc == '1') {
						LevelUp(&player,&playerskill);
				}
						/* else {
								clrscr;
								wronginput();
						}
				} else if (x == 4) { // Save atau Load atau Exit
						if (ic[0] == 'S' && ic[1] == 'A' && ic[2] == 'V' && ic[3] == 'E') {
								clrscr;
								Save(minimaps,player,player_pos,JAMToDetik(starttime));
								printf("Save Berhasil !\n");
						} else if (ic[0] == 'B' && ic[1] == 'O' && ic[2] == 'S' && ic[3] == 'S') {
								ENEMY enemy;
								boolean menang = false;
								GetBoss(&enemy);
								clrscr;

								int xx = 5;
								while (xx--) {
										EnemyAppeared();
										usleep(500000);
										clrscr;

										usleep(100000);
										printf("\n\n\n\n\n");
										clrscr;
								}

								bossdragon1();
								sleep(4);
								clrscr;

								bossdragon2();
								sleep(4);
								clrscr;

								bossdragon3();
								PrintStatE(enemy, 10);
								sleep(5);
								clrscr;

								OnEnemy(&enemy, &player, &menang);
						} else if (ic[0] == 'L' && ic[1] == 'O' && ic[2] == 'A' && ic[3] == 'D') {
								//LOAD
								clrscr;
								printf("load gagal\n");
						} else if ((ic[0] == 'E' && ic[1] == 'X' && ic[2] == 'I' && ic[3] == 'T')) {
								//Kasih pilihan mau save dulu atau tidak.
								printf("Ga di save dulu nih?\n");
								printf("1. Save dong\n");
								printf("2. Exit aja\n");
								int cy;
								printf("> ");scanf("%d",&cy);
								switch (cy) {
										case 1:
												clrscr;
												Save(minimaps,player,player_pos,JAMToDetik(starttime));
												system("exit");
												break;
										case 2:
												system("exit");
												break;
										default:
												clrscr;
												wronginput();
												break;
								}
						} else {
								clrscr;
								wronginput();
						}
				} else if (x == 5 && (ic[0] == 'S' && ic[1] == 'K' && ic[2] == 'I' && ic[3] == 'L' && ic[4] == 'L')) { // Skill
						//List Skill
						clrscr;
						SkillMenu(playerskill, 7);
						printf("Press ENTER to continue.."); getchar();
						clrscr;

				} else { // Input Salah
						clrscr;
						wronginput();
				}*/

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

										int xx = 5;
										while (xx--) {
												EnemyAppeared();
												usleep(500000);
												clrscr;

												usleep(100000);
												printf("\n\n\n\n\n");
												clrscr;
										}
										bossdragon1();
										sleep(4);
										clrscr;
										bossdragon2();
										sleep(4);
										clrscr;
										bossdragon3();
										PrintStatE(enemy, 10);
										sleep(5);
										clrscr;
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
				initTermios(); // use new terminal setting again to make kbhit() and getch() work
				cc = getch();
				resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
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
							break;
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
/*
void InputCommand(Queue *Q, int *X){
		char C;
		int y = 36;
		SHOWKURSOR;
		boolean benar = false;
		do {
				gotoXY(36,3); printf(" Command: ");scanf("%s",&C);
				gotoXY(37,3); printf("                            ");
				if (C == 'S') {
						benar = true;
				} else if (C == 'A') {
						*X = *X + 1;
						AddQ(Q,C);
						benar = true;
				} else if (C == 'B') {
						*X = *X + 1;
						AddQ(Q,C);
						benar = true;
				} else if (C == 'F') {
						*X = *X + 1;
						AddQ(Q,C);
						benar = true;
				} else if (C == 'E') {
						if (*X != 1) {
								*X = *X - 1;
								DelQBATTLE(Q,&C);
								benar = true;
						} else {
							 gotoXY(37,3); printf(" There's no command can be deleted.");
						}
				} else {
						gotoXY(37,3);printf(" Wrong input command!              ");
				}
		} while (!benar);
		HIDEKURSOR;
} */

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
	if(IsBoss(*enemy)) {
			maxronde = 20;
			PushEnemyMoveB(&EnemyMove);
	} else {
			maxronde = 10;
			PushEnemyMoveE(&EnemyMove);
	}
	//Generate enemy moves dari file ke stack

	Queue EnemyMoveQ;
	Queue PlayerMoveQ;
	//Berantem terus ampe ada yang mati ato ronde abis
	int bp = 1, gg = 1, ex = 1, gt = 1, hl = 1, plustr, plusdf;
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
					if (ronde < maxronde) {
							printf("Susah juga musuhnya, lanjut ke round %d\n",ronde);
							usleep(100000);
							printf("Fight!!\n");
							sleep(1);
					} else {
							printf("Sayang sekali, ronde habis.\n");
							sleep(1);
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
							GameOver();
					}
			} else { // isFlee
				//PRINTF BERHASIL KABUR
			}
	}
}

void GameOver(){
	newGame();
}

