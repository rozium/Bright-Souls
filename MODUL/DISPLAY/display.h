/* File : display.h */
/* Created by : Achmad Fahrurrozi Maskur */

#ifndef display_H
#define display_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <time.h>

#define COLOR_RESET   "\033[01;0m"
#define COLOR_BLACK   "\033[01;30m"
#define COLOR_RED     "\033[01;31m"
#define RED     "\033[00;31m"
#define COLOR_GREEN   "\033[01;32m"
#define COLOR_BROWN   "\033[00;33m"
#define COLOR_YELLOW  "\033[01;33m"
#define COLOR_BLUE    "\033[01;34m"
#define COLOR_MAGENTA "\033[01;35m"
#define COLOR_CYAN    "\033[01;36m"
#define COLOR_WHITE   "\033[01;37m"
#define COLOR_GRAY    "\033[37m"

#define MAX_SCAN_LENGTH 100
#define clrscr system("clear")
#define gotoXY(x,y)     printf("\x1B[%d;%df", (x), (y))
#define setWin(x,y)     printf("\e[8;%d;%d;t",(x), (y))
#define HIDEKURSOR  printf("\e[?25l")
#define SHOWKURSOR  printf("\e[?25h")
#define pext(c)			printf("\e(0%c\e(B",(c))

/* restore new terminal i/o settings */
void resetTermios();

/* initialize new terminal i/o settings */
void initTermios();

/* detect keyboard press */
int kbhit();

/* read 1 character */
char getch();

void pressKey();
void pressENTER();
void SlowPrint(const char* str, int sleeptime); 

void dialog();

void pilihjob();

void CetakBingkai(int x, int y);

void inputusername();

void PrintCommand();

void wronginput();
void BS();
void PGMed();
void PNabrak();
void Saveberhasil();
void Yakinexit();
void Yakinsave();
void YakinsaveD();

void blank();

void kuli();
void kuli1();
void satpam();
void satpam1();
void begal();
void begal1();
void mahasiswa();
void mahasiswa1();

void ayah();
void anak();
void ibu();

void Opening(int x, int y);
void menu();
void gameover();
void credit();

void EnemyAppeared();
void NextRound(int i);
void RoundsUp();
void pilihancommand();
void vs(int x, int y);

void reaper(int x, int y);
void centaur(int x, int y);
void fairy(int x, int y);
void devil(int x, int y);
void jacklantern(int x, int y);
void casper(int x, int y);
void phoenix(int x, int y);
void eagle(int x, int y);
void spider(int x, int y);
void skeleton(int x, int y);
void cobra(int x, int y);
void bat(int x, int y);

void loading();
void congrats();

void dragon();
void bossdragon1();
void bossdragon2();
void bossdragon3();

void ganesha();

#endif
