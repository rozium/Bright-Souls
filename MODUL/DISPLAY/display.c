/* File : display.c */
/* Created by : Achmad Fahrurrozi Maskur */

#include <unistd.h>
#include "display.h"
#include <stdio.h>
#include <stdlib.h>

static struct termios old_termios, new_termios;

/* restore new terminal i/o settings */
void resetTermios(){
    tcsetattr(0,TCSANOW,&old_termios);
}
/* initialize new terminal i/o settings */
void initTermios(){
    tcgetattr(0,&old_termios); // store old terminal
    new_termios = old_termios; // assign to new setting
    new_termios.c_lflag &= ~ICANON; // disable buffer i/o
    new_termios.c_lflag &= ~ECHO; // disable echo mode
    tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting
}
/* detect keyboard press */
int kbhit()
{
    struct timeval tv = {0L,0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0,&fds);
    return select(1,&fds,NULL,NULL,&tv);
}
/* read 1 character */
char getch()
{
    char ch;
    ch = getchar();
    return ch;
}
void pressKey()
{
    initTermios();
    getch();
    resetTermios();
}

void pressENTER(){
	char c;
	while (1) {
	  initTermios();
	  c = getch();
	  resetTermios();
	  if (c == 10) break;
	}	
}

void SlowPrint(const char* str, int sleeptime) 
{
    int i = 0;
	while(str[i] != '\0')    
	{       
		printf("%c", str[i]);
		i++;
		fflush(stdout);
		usleep(sleeptime);
	}
}

void PGMed(){
	printf(COLOR_BLUE);
    gotoXY(10,45);printf("┌─vVv───────────────────────vVv─┐");
    gotoXY(11,45);printf("│          Dapet obat!          │");
    gotoXY(12,45);printf("├───────────────────────────────┤");
    gotoXY(13,45);printf("│                               │");
    gotoXY(14,45);printf("│               "COLOR_RED".-."COLOR_BLUE"             │");
    gotoXY(15,45);printf("│              "COLOR_RED"/:::\\"COLOR_BLUE"            │");
    gotoXY(16,45);printf("│             "COLOR_RED"/::::/"COLOR_BLUE"            │");
    gotoXY(17,45);printf("│            "COLOR_WHITE"/ "COLOR_RED"`-:/"COLOR_BLUE"             │");
    gotoXY(18,45);printf("│           "COLOR_WHITE"/    /"COLOR_BLUE"              │");
    gotoXY(19,45);printf("│           "COLOR_WHITE"\\   /"COLOR_BLUE"               │");
    gotoXY(20,45);printf("│            "COLOR_WHITE"`\"`"COLOR_BLUE"                │");
    gotoXY(21,45);printf("│                               │");
    gotoXY(22,45);printf("│                               │");
    gotoXY(23,45);printf("├───────────────────────────────┤");
    gotoXY(24,45);printf("│                               │");
    gotoXY(25,45);printf("├───────────────────────────────┤");
    gotoXY(26,45);printf("│    "COLOR_WHITE"Press ENTER to continue."COLOR_BLUE"   │");
    gotoXY(27,45);printf("└───────────────────────────────┘");
	printf(COLOR_RESET);
}

void BS(){
	gotoXY(28,2);printf(" ┌───vVv─────────────────────────────────────────────────────────────vVv───┐");
	gotoXY(29,2);printf(" │                       "COLOR_WHITE" ＢＲＩＧＨＴ ＳＯＵＬＳ "COLOR_RESET"                         │");
	gotoXY(30,2);printf(" └─────────────────────────────────────────────────────────────────────────┘");
}

void CetakBingkai(int x, int y)
{// cetak kotak tebel (bingkai)
    /*kamus lokal*/
    int i;
    /*algoritma*/
    clrscr;

    /*cetak ukuran layar*/
    setWin(x,y);
    /*cetak atap*/
    printf(COLOR_CYAN);
    printf("\u250f"); for (i=1;i<=y-2;i++) printf("\u2501"); printf("\u2513");

    /*cetak dinding kiri kanan*/
    for (i =2;i<=x-1;i++) {
    printf("\u2503"); gotoXY(i,y); printf("\u2503");}

    /*cetak alas*/
    printf("\u2517"); for (i=1;i<=y-2;i++) printf("\u2501"); printf("\u251b");
    printf(COLOR_RESET);
}

void PNabrak(){
	printf(COLOR_RED);
    gotoXY(25,45);printf("┌───vVv───────────────────vVv───┐");
    gotoXY(26,45);printf("│        Ga bisa lewat !        │");
    gotoXY(27,45);printf("└───────────────────────────────┘");
	printf(COLOR_RESET);
}

void Yakinexit(){
	printf(COLOR_RED);
    gotoXY(23,45);printf("┌─vVv───────────────────────vVv─┐");
    gotoXY(24,45);printf("│         "COLOR_WHITE"  Exit game?      "COLOR_RED"    │");
    gotoXY(25,45);printf("├───────────────┬───────────────┤");
    gotoXY(26,45);printf("│   "COLOR_WHITE"   (Y)es  "COLOR_RED"  │   "COLOR_WHITE"  (N)o  "COLOR_RED"    │");
    gotoXY(27,45);printf("└───────────────┴───────────────┘");
	printf(COLOR_RESET);
}

void Yakinsave(){
	printf(COLOR_YELLOW);
    gotoXY(23,45);printf("┌─vVv───────────────────────vVv─┐");
    gotoXY(24,45);printf("│         "COLOR_RED"  Save game?      "COLOR_YELLOW"    │");
    gotoXY(25,45);printf("├───────────────┬───────────────┤");
    gotoXY(26,45);printf("│   "COLOR_WHITE"   (Y)es  "COLOR_YELLOW"  │   "COLOR_WHITE"  (N)o  "COLOR_YELLOW"    │");
    gotoXY(27,45);printf("└───────────────┴───────────────┘");
	printf(COLOR_RESET);
}

void YakinsaveD(){
    gotoXY(23,45);printf("                                 ");
    gotoXY(24,45);printf("                                 ");
    gotoXY(25,45);printf("                                 ");
    gotoXY(26,45);printf("                                 ");
    gotoXY(27,45);printf("                                 ");
}

void Saveberhasil(){
	printf(COLOR_MAGENTA);
    gotoXY(28,2);printf(" ┌───vVv─────────────────────────────────────────────────────────────vVv───┐");
    gotoXY(29,2);printf(" │                             Save berhasil  !!                           │");
    gotoXY(30,2);printf(" └─────────────────────────────────────────────────────────────────────────┘");
	printf(COLOR_RESET);
}
// 1                   2                   3                   4                   5
//  234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
//  │  1               |  2               |  3               |  4               |  5               │
//  │  6               |  7               |  8               |  9               |  0               │
void pilihancommand(){
  printf(COLOR_WHITE);
  gotoXY(37,5+2);printf("Attack");// 1
  gotoXY(38,5+2);printf("Flank");//  2
  gotoXY(37,24+2);printf("Block");// 3
  gotoXY(38,24+2);printf("Erase");// 4
  printf(COLOR_RESET);
  gotoXY(37,43+2);printf("???");//   5
  gotoXY(38,43+2);printf("???");//   6
  gotoXY(37,62+2);printf("???");//   7
  gotoXY(38,62+2);printf("???");//   8
  gotoXY(37,81+2);printf("???");//   9
  gotoXY(38,81+2);printf("???");//   0
}

void dialog(){
	HIDEKURSOR;
	int slept = 20000;
	gotoXY(21,2);printf("                                                                                                                      ");
	gotoXY(22,2);printf("                                                                                                                      ");
	gotoXY(23,2);printf("                                                                                                                      ");
	gotoXY(24,2);printf("                                                                                                                      ");
	gotoXY(25,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(26,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(27,2);printf("                                                                                                                      ");
	gotoXY(28,2);printf("                                                                                                                      ");
	gotoXY(29,2);printf("                                                                                                                      ");
	gotoXY(30,2);printf("                                                                                                                      ");

	usleep(slept);
	
	gotoXY(21,2);
	gotoXY(22,2);
	gotoXY(23,2);
	gotoXY(24,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(25,2);printf("                                                                                                                      ");
	gotoXY(26,2);printf("                                                                                                                      ");
	gotoXY(27,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(28,2);
	gotoXY(29,2);
	gotoXY(30,2);

	usleep(slept);

	gotoXY(21,2);printf("                                                                                                                      ");
	gotoXY(22,2);printf("                                                                                                                      ");
	gotoXY(23,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(24,2);printf("                                                                                                                      ");
	gotoXY(25,2);printf("                                                                                                                      ");
	gotoXY(26,2);printf("                                                                                                                      ");
	gotoXY(27,2);printf("                                                                                                                      ");
	gotoXY(28,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(29,2);printf("                                                                                                                      ");
	gotoXY(30,2);printf("                                                                                                                      ");

	usleep(slept);
	// gotoXY(1,1);
	// gotoXY(22,2);

	gotoXY(21,2);printf("                                                                                                                      ");
	gotoXY(22,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(23,2);printf("                                                                                                                      ");
	gotoXY(24,2);printf("                                                                                                                      ");
	gotoXY(25,2);printf("                                                                                                                      ");
	gotoXY(26,2);printf("                                                                                                                      ");
	gotoXY(27,2);printf("                                                                                                                      ");
	gotoXY(28,2);printf("                                                                                                                      ");
	gotoXY(29,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(30,2);printf("                                                                                                                      ");

	usleep(slept);
	// gotoXY(1,1);
	// gotoXY(21,2);

	gotoXY(21,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	gotoXY(22,2);printf("                                                                                                                      ");
	gotoXY(23,2);printf("                                                                                                                      ");
	gotoXY(24,2);printf("                                                                                                                      ");
	gotoXY(25,2);printf("                                                                                                                      ");
	gotoXY(26,2);printf("                                                                                                                      ");
	gotoXY(27,2);printf("                                                                                                                      ");
	gotoXY(28,2);printf("                                                                                                                      ");
	gotoXY(29,2);printf("                                                                                                                      ");
	gotoXY(30,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
	
}

void pilihjob(){
	HIDEKURSOR;
	int x = 3;
	int y = 2;
	clrscr;
	setWin(32,100);
	gotoXY(1,1);
	CetakBingkai(32,100);
	gotoXY(x++,y);printf(COLOR_CYAN"       |^^^|     ");
	gotoXY(x++,y);printf(COLOR_RED"        }-{      ");
	gotoXY(x++,y);printf(COLOR_RED"        }-{      ");
	gotoXY(x++,y);printf(COLOR_CYAN"    /|_/---\\_|\\  ");
	gotoXY(x++,y);printf(COLOR_CYAN"    I _|\\_/|_ I  ");
	gotoXY(x++,y);printf(COLOR_CYAN"    \\|"COLOR_WHITE" |   | "COLOR_CYAN"|/ ");
	gotoXY(x++,y); printf("     "COLOR_WHITE"  | ` |        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                   ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                     ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |  "COLOR_RESET"        Mahasiswa                                                         ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |  "COLOR_RESET"        Begal                                                   ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |  "COLOR_RESET"        Satpam                                ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |  "COLOR_RESET"        Kuli                        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                        ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                       ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                                    ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  | ` |                              ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"  \\ ` /");
	gotoXY(x++,y);printf("     "COLOR_WHITE"   \\ /");
	gotoXY(x++,y);printf("     "COLOR_WHITE"    Y"COLOR_RESET"     ");

/*	gotoXY(x++,y);printf(COLOR_RESET" ┌──────────────────────────────────────────┐");
	gotoXY(x++,y);printf(COLOR_RESET" ├─ ─ ─ ─ ─<<< "COLOR_MAGENTA"Choose Your HERO"COLOR_RESET" >>>─ ─ ─ ─ ─┤");
	gotoXY(x++,y);printf(COLOR_RESET" ├──────────────────────────────────────────┤");
	gotoXY(x++,y);printf(COLOR_WHITE" │ 1 │"COLOR_WHITE" :- "COLOR_WHITE"Mahasiswa   "COLOR_WHITE"(Average Stats)       │");
	gotoXY(x++,y);printf(COLOR_WHITE" │ 2 │"COLOR_WHITE" :- "COLOR_RED"Begal   "COLOR_WHITE"    (High "COLOR_RED"STR"COLOR_WHITE")            │");
	gotoXY(x++,y);printf(COLOR_WHITE" │ 3 │"COLOR_WHITE" :- "COLOR_BLUE"Satpam   "COLOR_WHITE"   (High "COLOR_BLUE"DEF"COLOR_WHITE")            │");
	gotoXY(x++,y);printf(COLOR_WHITE" │ 4 │"COLOR_WHITE" :- "COLOR_GREEN"Kuli   "COLOR_WHITE"     (High "COLOR_GREEN"HP"COLOR_WHITE")             │");
	gotoXY(x++,y);printf(COLOR_RESET" └──────────────────────────────────────────┘");
	*/

	gotoXY(3,20);printf(COLOR_YELLOW"   _____ _                            "COLOR_RED" _   _                ");
	gotoXY(4,20);printf(COLOR_YELLOW"  /  __ \\ |                           "COLOR_RED"| | | |               ");
	gotoXY(5,20);printf(COLOR_YELLOW"  | /  \\/ |__   ___   ___  ___  ___   "COLOR_RED"| |_| | ___ _ __ ___  ");
	gotoXY(6,20);printf(COLOR_YELLOW"  | |   | '_ \\ / _ \\ / _ \\/ __|/ _ \\  "COLOR_RED"|  _  |/ _ \\ '__/ _ \\ ");
	gotoXY(7,20);printf(COLOR_YELLOW"  | \\__/\\ | | | (_) | (_) \\__ \\  __/  "COLOR_RED"| | | |  __/ | | (_) |");
	gotoXY(8,20);printf(COLOR_YELLOW"   \\____/_| |_|\\___/ \\___/|___/\\___|  "COLOR_RED"\\_| |_/\\___|_|  \\___/ ");
	printf(COLOR_RESET);

}

void vs(int x, int y){
    printf(COLOR_RED);
    gotoXY(x++,y);printf("██╗   ██╗███████╗");
    gotoXY(x++,y);printf("██║   ██║██╔════╝");
    gotoXY(x++,y);printf("██║   ██║███████╗");
    gotoXY(x++,y);printf("╚██╗ ██╔╝╚════██║");
    gotoXY(x++,y);printf(" ╚████╔╝ ███████║");
    gotoXY(x++,y);printf("  ╚═══╝  ╚══════╝");
    printf(COLOR_RESET);
}

void kuli(int x, int y){

	gotoXY(x++,y);printf(COLOR_YELLOW"               ___          ");
	gotoXY(x++,y);printf(COLOR_YELLOW"             .\"   \".          ");
	gotoXY(x++,y);printf(COLOR_YELLOW"             |  ___(          ");
	gotoXY(x++,y);printf(COLOR_YELLOW"             )"COLOR_RESET".' -(          ");
	gotoXY(x++,y);printf("              )  _/          ");
	gotoXY(x++,y);printf("            "COLOR_RED".'_`"COLOR_RESET"(           ");
	gotoXY(x++,y);printf("           "COLOR_RED"/ ( ,/;          ");
	gotoXY(x++,y);printf("          "COLOR_RED"/   "COLOR_RESET"\\ ) "COLOR_BROWN"\\\\"COLOR_RESET".          "); 
	gotoXY(x++,y);printf("         "COLOR_CYAN"/'-."COLOR_RED"/ "COLOR_RESET"\\ '."COLOR_BROWN"\\\\"COLOR_RESET")          ");
	gotoXY(x++,y);printf("         "COLOR_CYAN"\\   \\"COLOR_RESET"  '---;"COLOR_BROWN"\\"COLOR_RESET"          ");
	gotoXY(x++,y);printf("         "COLOR_CYAN"|`\\  \\      "COLOR_BROWN"\\\\"COLOR_RESET"          ");
	gotoXY(x++,y);printf("        / / \\  \\      "COLOR_BROWN"\\\\"COLOR_RESET"          ");
	gotoXY(x++,y);printf("      "COLOR_BROWN"_"COLOR_RESET"/ /   / /      "COLOR_BLACK"_"COLOR_BROWN"\\\\"COLOR_BLACK"_"COLOR_RESET"          ");
	gotoXY(x++,y);printf("     "COLOR_BROWN"( \\"COLOR_RESET"/   /_/       "COLOR_BLACK"\\   |"COLOR_RESET"          ");
	gotoXY(x++,y);printf("      "COLOR_BROWN"\\_)  (___)"COLOR_RESET"       "COLOR_BLACK"'._/"COLOR_RESET"          ");
	gotoXY(x++,y);printf("   ^^^^^^^^^^^^^^^^^^^^~~~~~^^^");
	printf(COLOR_RESET);

}

void mahasiswa1(int x, int y){
	gotoXY(x++,y);printf("                           ");
	gotoXY(x++,y);printf("      .-\"\"\"\"\"-.            ");
	gotoXY(x++,y);printf("     / _____/\\_\\           ");
	gotoXY(x++,y);printf("    //`__   __ \\\\          ");
	gotoXY(x++,y);printf("   //  (a) (a)  \\\\         ");
	gotoXY(x++,y);printf("  (_    (___)    _)        ");
	gotoXY(x++,y);printf("    \\  \\_____/  /          ");
	gotoXY(x++,y);printf("     `-._   _.-'           ");
	gotoXY(x++,y);printf("     __.-)_(-,__           ");
	gotoXY(x++,y);printf("  ./'/   |_|   \\`\\.        ");
	gotoXY(x++,y);printf(" /   `\"\"\"\"\"\"\"\"\"\"`  \\     ");
}

void satpam1(int x, int y){
	gotoXY(x++,y);printf("           ,       ");
	gotoXY(x++,y);printf("      _.-\"` `'-.   ");
	gotoXY(x++,y);printf("     '._ __{}_(    ");
	gotoXY(x++,y);printf("       |'--.__\\    ");
	gotoXY(x++,y);printf("      (   ^_\\^     ");
	gotoXY(x++,y);printf("       |   _ |     ");
	gotoXY(x++,y);printf("       )\\___/      ");
	gotoXY(x++,y);printf("   .--'`:._]       ");
	gotoXY(x++,y);printf("  /  \\      '-.    ");
	gotoXY(x++,y);printf(" /              '. ");
}

void kuli1(int x, int y){
	gotoXY(x++,y);printf("          ___        ");
	gotoXY(x++,y);printf("       .-' \\\\\".      ");
	gotoXY(x++,y);printf("      /`    ;--:     ");
	gotoXY(x++,y);printf("     |     (  (_)==  ");
	gotoXY(x++,y);printf("     |_ ._ '.__.;    ");
	gotoXY(x++,y);printf("     \\_/`--_---_(    ");
	gotoXY(x++,y);printf("      (`--(./-\\.)    ");
	gotoXY(x++,y);printf("      `|     _\\ |    ");
	gotoXY(x++,y);printf("       | \\  __ /     ");
	gotoXY(x++,y);printf("      /|  '.__/      ");
	gotoXY(x++,y);printf("    '` \\     |_      ");
	gotoXY(x++,y);printf("        '-__ / `-	   ");
}

void begal1(int x, int y){
	gotoXY(x++,y);printf("         .-----.          ");
	gotoXY(x++,y);printf("        / '. ' .\\         ");
	gotoXY(x++,y);printf("        |_.__'_.|}        ");
	gotoXY(x++,y);printf("       (;  6 6  ;)        ");
	gotoXY(x++,y);printf("        ;,  >  ,;         ");
	gotoXY(x++,y);printf("        ;;;~~~;;;         ");
	gotoXY(x++,y);printf("     ___.';;;;;'.__       ");
	gotoXY(x++,y);printf("   /'`\\  `\\   /`  /`'\\    ");
	gotoXY(x++,y);printf("  /   |   |   |   |   \\   ");
	gotoXY(x++,y);printf(" (    |   |\\_/|   | @~ )  ");
	gotoXY(x++,y);printf(" |    |   |   |   |    |  ");
	gotoXY(x++,y);printf(" |   /|   |   |   |\\   |  ");
	gotoXY(x++,y);printf(" \\   ||   |   |   ||   /  ");
}

void ayah(int x, int y){
	gotoXY(x++,y);printf("     .======.       ");
	gotoXY(x++,y);printf("    /((((((()\\      ");
	gotoXY(x++,y);printf("   ((///    \\))     ");
	gotoXY(x++,y);printf("  ((/`__   __())    ");
	gotoXY(x++,y);printf("  /`-{_o}^{o_}'\\    ");
	gotoXY(x++,y);printf("  \\_     _\\   _/    ");
	gotoXY(x++,y);printf("    \\  .__,  /      ");
	gotoXY(x++,y);printf("     \\  `-' /       ");
	gotoXY(x++,y);printf("     /`----'\\       ");
	gotoXY(x++,y);printf(".-\"\"\"`------'`\"\"-.  ");
}

void anak(int x, int y){
	gotoXY(x++,y);printf("          _.-\"\"\"-.       ");
	gotoXY(x++,y);printf("        .\" \\      `\".    ");
	gotoXY(x++,y);printf("       /  .-\"---._   \\   ");
	gotoXY(x++,y);printf("       |_/  _   _ `\\_|   ");
	gotoXY(x++,y);printf("       / |  o   o  | \\   ");
	gotoXY(x++,y);printf("       \\/     7     \\/   ");
	gotoXY(x++,y);printf("        \\   .___.   /    ");
	gotoXY(x++,y);printf("         '._  _  _.'     ");
	gotoXY(x++,y);printf("            )   (	       ");
	gotoXY(x++,y);printf("          .-`   `-.      ");
	gotoXY(x++,y);printf("       -``         ``-   ");
}

void ibu(int x, int y){
	gotoXY(x++,y);printf("         _,,,_         ");
	gotoXY(x++,y);printf("       .'     `'.      ");
	gotoXY(x++,y);printf("      /     ____ \\     ");
	gotoXY(x++,y);printf("     |    .'_  _\\/     ");
	gotoXY(x++,y);printf("     /    ) a  a|      ");
	gotoXY(x++,y);printf("    /    (    > |      ");
	gotoXY(x++,y);printf("   (      ) ._  /      ");
	gotoXY(x++,y);printf("   )    _/-.__.'`\\     ");
	gotoXY(x++,y);printf("  (  .-'`-.   \\__ )    ");
	gotoXY(x++,y);printf("   `/      `-./  `.    ");
	gotoXY(x++,y);printf("    |    \\      \\  \\   ");
	gotoXY(x++,y);printf("    |     \\   \\  \\  \\  ");
	gotoXY(x++,y);printf("    |\\     `. /  /   \\ ");
}

void satpam(int x, int y){

	gotoXY(x++,y);printf("            "COLOR_BLUE","COLOR_RESET"	 ");
	gotoXY(x++,y);printf("   __  "COLOR_BLUE"_.-\"` `'-.    ");
	gotoXY(x++,y);printf(" "COLOR_RESET" /||\\"COLOR_BLUE"'._ __"COLOR_BLACK"{}"COLOR_BLUE"_(     ");
	gotoXY(x++,y);printf(" "COLOR_RESET" ||||  |"COLOR_BLUE"'--.__\\     ");
	gotoXY(x++,y);printf(" "COLOR_RESET" |  L.(   ^_\\^	 ");
	gotoXY(x++,y);printf("  \\ .-' |   _ |	 ");
	gotoXY(x++,y);printf("  | |   )\\___/	 ");
	gotoXY(x++,y);printf("  |  \\"COLOR_BLUE"-'`:._"COLOR_RESET"]	 ");
	gotoXY(x++,y);printf("  \\__/"COLOR_BLUE";      '-.	 ");
	gotoXY(x++,y);printf("  "COLOR_BLUE"|   |o     "COLOR_BLACK"__"COLOR_BLUE" \\	 ");
	gotoXY(x++,y);printf("  "COLOR_BLUE"|   |o     "COLOR_BLACK")("COLOR_BLUE" |	 ");
	gotoXY(x++,y);printf("  "COLOR_BLUE"|   |o     "COLOR_BLACK"\\/"COLOR_BLUE" |	 ");
	gotoXY(x++,y);printf("  "COLOR_BLUE"|   |       ` \\	 "COLOR_RESET"");
	gotoXY(x++,y);printf("  "COLOR_BLUE"|   |          \\"COLOR_RESET" ");
	printf(COLOR_RESET);

}
void blank(int x, int y){ //21 x 44
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
	gotoXY(x++,y);printf("                                            ");
}

void begal(int x, int y){ //16 x 34
	gotoXY(x++,y);printf("                "COLOR_CYAN"_                 ");
	gotoXY(x++,y);printf("               "COLOR_CYAN" \\`\\"COLOR_RESET"               ");
	gotoXY(x++,y);printf("                 "COLOR_CYAN"\\.\\"COLOR_RESET"              ");
	gotoXY(x++,y);printf("        _         "COLOR_CYAN"\\.\\"COLOR_RESET"/)           ");
	gotoXY(x++,y);printf("   _ _-' ')__     ("COLOR_CYAN"\\.\\"COLOR_RESET"/)          ");
	gotoXY(x++,y);printf("  /       /  \\"COLOR_RED".'`'"COLOR_RESET"-\\/)"COLOR_CYAN"\\"COLOR_RESET"\\          ");
	gotoXY(x++,y);printf("  \\__ ,.-'(_  Y    (_"COLOR_CYAN"\\.\\"COLOR_RESET")         ");
	gotoXY(x++,y);printf("   / <     ,\\  \\    "COLOR_RED","COLOR_RESET"\\"COLOR_CYAN"\\.\\"COLOR_RESET"\\        ");
	gotoXY(x++,y);printf("   \\_ \\ _. /y(_|    "COLOR_RED": "COLOR_RESET"|"COLOR_CYAN"\\.\\"COLOR_RESET"|       ");
	gotoXY(x++,y);printf("    "COLOR_RED"_"COLOR_RESET"\\_\\\\   |       "COLOR_RED": "COLOR_RESET"| "COLOR_CYAN"\\.\\"COLOR_RESET"       ");
	gotoXY(x++,y);printf("   "COLOR_RED"(   `'-._"COLOR_RESET">/ )     "COLOR_RED"\\"COLOR_RESET"|  "COLOR_CYAN"\\.\\"COLOR_RESET"      ");
	gotoXY(x++,y);printf("   "COLOR_RED"\\         ("COLOR_RESET"`'-.    (   "COLOR_CYAN"\\.\\"COLOR_RESET"     ");
	gotoXY(x++,y);printf("    "COLOR_RED"\\_      ("COLOR_RESET"    `--._)`--'"COLOR_CYAN"\\.\\"COLOR_RESET"  ");
	gotoXY(x++,y);printf("     "COLOR_RED"|\\_    \\"COLOR_RESET"-._     `-:_ /`` \\ ");
	gotoXY(x++,y);printf("     "COLOR_RED"|  `-   \\"COLOR_RESET"  t--._        _ | ");
	gotoXY(x++,y);printf("     "COLOR_RED"|       /"COLOR_RESET"  |   /``'-.\\-- \\ ");
	printf(COLOR_RESET);
}

void mahasiswa(int x, int y){ //15 x 29

	gotoXY(x++,y);printf("           "COLOR_BLACK",/////\\\\,         ");
	gotoXY(x++,y);printf("         ,/////////\\\\\\       ");
	gotoXY(x++,y);printf("       "COLOR_BLACK",///////////\\\\\\\\      ");
	gotoXY(x++,y);printf("       "COLOR_BLACK"////  "COLOR_RESET"__     _"COLOR_BLACK"\\\\      ");
	gotoXY(x++,y);printf("       "COLOR_BLACK"///"COLOR_RESET" //  \\  //  \\      ");
	gotoXY(x++,y);printf("       /,  \\\\_O/  \\\\_O/      ");
	gotoXY(x++,y);printf("       \\_         \\   |      ");
	gotoXY(x++,y);printf("         \\      ,__>  /      ");
	gotoXY(x++,y);printf("         |\\   ,____  /       ");
	gotoXY(x++,y);printf("         | \\   \\__| /        ");
	gotoXY(x++,y);printf("         |  '._____/         ");
	gotoXY(x++,y);printf("         |      |            ");
	gotoXY(x++,y);printf("       "COLOR_BLUE"/``\"--._ \\/`\\         ");
	gotoXY(x++,y);printf("      /        \\|  /`--.     ");
	gotoXY(x++,y);printf("    /```\"\"--..__;.'     `\\"COLOR_RESET"   ");
	printf(COLOR_RESET);

}

void Opening(int x, int y){
	int xx;
	int sleept = 30000;
	HIDEKURSOR;
	setWin(24,127);
	gotoXY(1,1);
	CetakBingkai(24,127);
	printf(COLOR_WHITE);
	
	// xx = x;
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");
	// gotoXY(xx++,2);printf("                                                                                                                             ");

	xx = x;
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(11,50-7);printf("  ____     _        _____     ____     ___  ");
	gotoXY(12,50-7);printf(" | |_     | |\\ |     | |     | |_     | |_) ");
	gotoXY(13,50-7);printf(" |_|__    |_| \\|     |_|     |_|__    |_| \\ ");
// ------------------------------------------
// -------------------------------------
	pressENTER();

	xx = x;
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");

	xx = x;
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);printf("  ▄███▄▄▄██▀ ▄███▄▄▄▄██▀ ███▌▄███       ▄███▄▄▄▄███▄▄  ███   ▀    ███        ███    ███ ███    ███ ███       ███        ");
	gotoXY(xx++,y);printf(" ▀▀███▀▀▀██▄▀▀███▀▀▀▀▀   ███▀▀███ ████▄▀▀███▀▀▀▀███▀   ███      ▀███████████ ███    ███ ███    ███ ███     ▀███████████ ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	
	usleep(sleept);

	xx = x;
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");

	xx = x;
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███▌ ███    █▀  ███    ███   ▀███▀▀██    ███    █▀  ███    ███ ███    ███ ███       ███    █▀  ");
	gotoXY(xx++,y);printf("  ▄███▄▄▄██▀ ▄███▄▄▄▄██▀ ███▌▄███       ▄███▄▄▄▄███▄▄  ███   ▀    ███        ███    ███ ███    ███ ███       ███        ");
	gotoXY(xx++,y);printf(" ▀▀███▀▀▀██▄▀▀███▀▀▀▀▀   ███▀▀███ ████▄▀▀███▀▀▀▀███▀   ███      ▀███████████ ███    ███ ███    ███ ███     ▀███████████ ");
	gotoXY(xx++,y);printf("   ███    ███ ██████████ ███  ███    ███ ███    ███    ███               ███ ███    ███ ███    ███ ███              ███ ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	
	usleep(sleept);

	xx = x;
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");

	xx = x;
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███  ███    ███ ███    ███▀█████████▄    ███    ███ ███    ███ ███    ███ ███       ███    ███ ");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███▌ ███    █▀  ███    ███   ▀███▀▀██    ███    █▀  ███    ███ ███    ███ ███       ███    █▀  ");
	gotoXY(xx++,y);printf("  ▄███▄▄▄██▀ ▄███▄▄▄▄██▀ ███▌▄███       ▄███▄▄▄▄███▄▄  ███   ▀    ███        ███    ███ ███    ███ ███       ███        ");
	gotoXY(xx++,y);printf(" ▀▀███▀▀▀██▄▀▀███▀▀▀▀▀   ███▀▀███ ████▄▀▀███▀▀▀▀███▀   ███      ▀███████████ ███    ███ ███    ███ ███     ▀███████████ ");
	gotoXY(xx++,y);printf("   ███    ███ ██████████ ███  ███    ███ ███    ███    ███               ███ ███    ███ ███    ███ ███              ███ ");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███  ███    ███ ███    ███    ███         ▄█    ███ ███    ███ ███    ███ ███▌    ▄  ▄█    ███ ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,y);//printf("                                                                                                                        ");

	usleep(sleept);

	xx = x;
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");

	xx = x;
	gotoXY(xx++,y);//printf("                                                                                                                        ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);printf(" ▀█████████▄   ▄████████  ▄█   ▄██████▄   ▄█    █▄     ███         ▄████████  ▄██████▄  ███    █▄   ▄█        ▄████████ ");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███  ███    ███ ███    ███▀█████████▄    ███    ███ ███    ███ ███    ███ ███       ███    ███ ");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███▌ ███    █▀  ███    ███   ▀███▀▀██    ███    █▀  ███    ███ ███    ███ ███       ███    █▀  ");
	gotoXY(xx++,y);printf("  ▄███▄▄▄██▀ ▄███▄▄▄▄██▀ ███▌▄███       ▄███▄▄▄▄███▄▄  ███   ▀    ███        ███    ███ ███    ███ ███       ███        ");
	gotoXY(xx++,y);printf(" ▀▀███▀▀▀██▄▀▀███▀▀▀▀▀   ███▀▀███ ████▄▀▀███▀▀▀▀███▀   ███      ▀███████████ ███    ███ ███    ███ ███     ▀███████████ ");
	gotoXY(xx++,y);printf("   ███    ███ ██████████ ███  ███    ███ ███    ███    ███               ███ ███    ███ ███    ███ ███              ███ ");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███  ███    ███ ███    ███    ███         ▄█    ███ ███    ███ ███    ███ ███▌    ▄  ▄█    ███ ");
	gotoXY(xx++,y);printf(" ▄█████████▀  ███    ███ █▀   ████████▀  ███    █▀    ▄████▀     ▄████████▀   ▀██████▀  ████████▀  █████▄▄██▄████████▀  ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);//printf("                                                                                                                        ");

	usleep(sleept);

	xx = x;
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);printf("                                                                                                                             ");
	gotoXY(xx++,2);//printf("                                                                                                                                                              ");

	xx = x;
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");
	gotoXY(xx++,y);printf("                                                                                                                        ");
	gotoXY(xx++,y);printf(" ▀█████████▄   ▄████████  ▄█   ▄██████▄   ▄█    █▄     ███         ▄████████  ▄██████▄  ███    █▄   ▄█        ▄████████ ");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███  ███    ███ ███    ███▀█████████▄    ███    ███ ███    ███ ███    ███ ███       ███    ███ ");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███▌ ███    █▀  ███    ███   ▀███▀▀██    ███    █▀  ███    ███ ███    ███ ███       ███    █▀  ");
	gotoXY(xx++,y);printf("  ▄███▄▄▄██▀ ▄███▄▄▄▄██▀ ███▌▄███       ▄███▄▄▄▄███▄▄  ███   ▀    ███        ███    ███ ███    ███ ███       ███        ");
	gotoXY(xx++,y);printf(" ▀▀███▀▀▀██▄▀▀███▀▀▀▀▀   ███▀▀███ ████▄▀▀███▀▀▀▀███▀   ███      ▀███████████ ███    ███ ███    ███ ███     ▀███████████ ");
	gotoXY(xx++,y);printf("   ███    ███ ██████████ ███  ███    ███ ███    ███    ███               ███ ███    ███ ███    ███ ███              ███ ");
	gotoXY(xx++,y);printf("   ███    ███ ███    ███ ███  ███    ███ ███    ███    ███         ▄█    ███ ███    ███ ███    ███ ███▌    ▄  ▄█    ███ ");
	gotoXY(xx++,y);printf(" ▄█████████▀  ███    ███ █▀   ████████▀  ███    █▀    ▄████▀     ▄████████▀   ▀██████▀  ████████▀  █████▄▄██▄████████▀  ");
	gotoXY(xx++,y);printf("                                                                                                                        ");
	gotoXY(xx++,2);printf("+---------------------------------------------------------------------------------------------------------------------------+");

	gotoXY(xx,9);SlowPrint("                                                                                             Press ENTER to continue",8000);
	printf(COLOR_RED);
	gotoXY(xx,92);SlowPrint("          Press ENTER to continue",30000);
	pressENTER();
	printf(COLOR_RESET);
}

void PrintCommand(){
	int x = 2, y = 45;
    gotoXY(x++,y);printf("┌─vVv───────────────────────vVv─┐");
    gotoXY(x++,y);printf("│         "COLOR_MAGENTA"Input command"COLOR_RESET"         │");
    gotoXY(x++,y);printf("├───────────────┬───────────────┤");
    gotoXY(x++,y);printf("│"COLOR_WHITE" ▲ :"COLOR_RESET" Go Up     │ "COLOR_WHITE"S :"COLOR_RESET" Save Game │");
    gotoXY(x++,y);printf("│"COLOR_WHITE" ▼ :"COLOR_RESET" Go Down   │ "COLOR_WHITE"L :"COLOR_RESET" Load Game │");
    gotoXY(x++,y);printf("│"COLOR_WHITE" ► :"COLOR_RESET" Go Right  │ "COLOR_WHITE"T :"COLOR_RESET" See Skill │");
    gotoXY(x++,y);printf("│"COLOR_WHITE" ◄ :"COLOR_RESET" Go Left   │ "COLOR_WHITE"X :"COLOR_RESET" Exit Game │");
    gotoXY(x++,y);printf("└───────────────┴───────────────┘");
	printf(COLOR_RESET);
}

// ┌─┬─┐
// │ │ │
// ├─┼─┤
// └─┴─┘

void wronginput(){
	printf(COLOR_YELLOW);
    gotoXY(28,2);printf(" ┌───vVv─────────────────────────────────────────────────────────────vVv───┐");
    gotoXY(29,2);printf(" │                            Wrong Command !                              │");
    gotoXY(30,2);printf(" └─────────────────────────────────────────────────────────────────────────┘");
	printf(COLOR_RESET);
}

void inputusername(){
	int i, l = 25;
	clrscr;
	CetakBingkai(26,98);
	gotoXY(3,2);printf(COLOR_CYAN"       |^^^|     ");
	gotoXY(4,2);printf(COLOR_RED"        }-{      ");
	gotoXY(5,2);printf(COLOR_RED"        }-{      ");
	gotoXY(6,2);printf(COLOR_CYAN"    /|_/---\\_|\\  ");
	gotoXY(7,2);printf(COLOR_CYAN"    I _|\\_/|_ I  ");
	gotoXY(8,2);printf(COLOR_CYAN"    \\|"COLOR_WHITE" |   | "COLOR_CYAN"|/ ");
	gotoXY(9,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_RESET"     ");
	gotoXY(10,2);printf("     "COLOR_WHITE"  | ` |");
	gotoXY(11,2);printf("     "COLOR_WHITE"  | ` |                                                         ");
	gotoXY(12,2);printf("     "COLOR_WHITE"  | ` |                                                         ");
	gotoXY(13,2);printf("     "COLOR_WHITE"  | ` |                               ");
	gotoXY(14,2);printf("     "COLOR_WHITE"  | ` |                              ");
	gotoXY(15,2);printf("     "COLOR_WHITE"  | ` |                                 ");
	gotoXY(16,2);printf("     "COLOR_WHITE"  | ` |                                     ");
	gotoXY(17,2);printf("     "COLOR_WHITE"  | ` |                                       ");
	gotoXY(18,2);printf("     "COLOR_WHITE"  | ` |                                       ");
	gotoXY(19,2);printf("     "COLOR_WHITE"  | ` |                                 ");
	gotoXY(20,2);printf("     "COLOR_WHITE"  | ` |                              "/*| "COLOR_YELLOW"2."COLOR_WHITE" | "COLOR_GREEN"Start Game"COLOR_WHITE"         |*/"");
	gotoXY(21,2);printf("     "COLOR_WHITE"  \\ ` /");
	gotoXY(22,2);printf("     "COLOR_WHITE"   \\ /");
	gotoXY(23,2);printf("     "COLOR_WHITE"    Y"COLOR_RESET"     ");

	gotoXY(3,20);printf(COLOR_YELLOW"   _   _  _____ _    _   "COLOR_RED" _____   ___  ___  ___ _____ ");
	gotoXY(4,20);printf(COLOR_YELLOW"  | \\ | ||  ___| |  | | "COLOR_RED" |  __ \\ / _ \\ |  \\/  ||  ___|");
	gotoXY(5,20);printf(COLOR_YELLOW"  |  \\| || |__ | |  | | "COLOR_RED" | |  \\// /_\\ \\| .  . || |__  ");
	gotoXY(6,20);printf(COLOR_YELLOW"  | . ` ||  __|| |/\\| | "COLOR_RED" | | __ |  _  || |\\/| ||  __| ");
	gotoXY(7,20);printf(COLOR_YELLOW"  | |\\  || |___\\  /\\  /  "COLOR_RED"| |_\\ \\| | | || |  | || |___ ");
	gotoXY(8,20);printf(COLOR_YELLOW"  \\_| \\_/\\____/ \\/  \\/ "COLOR_RED"   \\____/\\_| |_/\\_|  |_/\\____/");

	gotoXY(12,22);printf(COLOR_MAGENTA"Masukkan username : "COLOR_BLUE);
	gotoXY(14,21);pext(108);for(i=0;i<l;i++)pext(113);pext(107);
	gotoXY(15,21);pext(120);gotoXY(15,22+l);pext(120);
	gotoXY(16,21);pext(109);for(i=0;i<l;i++)pext(113);pext(106);
	gotoXY(15,23);printf(COLOR_GREEN);
	SHOWKURSOR;
}


void menu(){
	clrscr;
	HIDEKURSOR;
	setWin(26,98);
	gotoXY(1,1);
	CetakBingkai(26,98);
	gotoXY(3,2);printf(COLOR_CYAN"       |^^^|     "COLOR_YELLOW"  ____________ _____ _____  _   _ _____ "COLOR_RED"  _____  _____ _   _ _      _____ ");
	gotoXY(4,2);printf(COLOR_RED"        }-{      "COLOR_YELLOW"  | ___ \\ ___ \\_   _|  __ \\| | | |_   _| "COLOR_RED"/  ___||  _  | | | | |    /  ___|");
	gotoXY(5,2);printf(COLOR_RED"        }-{      "COLOR_YELLOW"  | |_/ / |_/ / | | | |  \\/| |_| | | |  "COLOR_RED" \\ `--. | | | | | | | |    \\ `--. ");
	gotoXY(6,2);printf(COLOR_CYAN"    /|_/---\\_|\\  "COLOR_YELLOW"  | ___ \\    /  | | | | __ |  _  | | |   "COLOR_RED" `--. \\| | | | | | | |     `--. \\");
	gotoXY(7,2);printf(COLOR_CYAN"    I _|\\_/|_ I  "COLOR_YELLOW"  | |_/ / |\\ \\ _| |_| |_\\ \\| | | | | |  "COLOR_RED" /\\__/ /\\ \\_/ / |_| | |____/\\__/ /");
	gotoXY(8,2);printf(COLOR_CYAN"    \\|"COLOR_WHITE" |   | "COLOR_CYAN"|/  "COLOR_YELLOW"  \\____/\\_| \\_|\\___/ \\____/\\_| |_/ \\_/ "COLOR_RED"  \\____/  \\___/ \\___/\\_____/\\____/ ");
	gotoXY(9,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_RESET"     ");
	gotoXY(10,2);printf("     "COLOR_WHITE"  | ` |");
	gotoXY(11,2);printf("     "COLOR_WHITE"  | ` |                                                         ");
	gotoXY(12,2);printf("     "COLOR_WHITE"  | ` |                                                         ");
	gotoXY(13,2);printf("     "COLOR_WHITE"  | ` |                               "COLOR_RESET"Start a New Game         "COLOR_WHITE"         ");
	gotoXY(14,2);printf("     "COLOR_WHITE"  | ` |                              ");
	gotoXY(15,2);printf("     "COLOR_WHITE"  | ` |                                 "COLOR_RESET"Load a Game        "COLOR_WHITE"      ");
	gotoXY(16,2);printf("     "COLOR_WHITE"  | ` |                                     ");
	gotoXY(17,2);printf("     "COLOR_WHITE"  | ` |                                    "COLOR_RESET"About         "COLOR_WHITE"       ");
	gotoXY(18,2);printf("     "COLOR_WHITE"  | ` |                                       ");
	gotoXY(19,2);printf("     "COLOR_WHITE"  | ` |                                     "COLOR_RESET"Quit         "COLOR_WHITE"");
	gotoXY(20,2);printf("     "COLOR_WHITE"  | ` | ");
	gotoXY(21,2);printf("     "COLOR_WHITE"  \\ ` /");
	gotoXY(22,2);printf("     "COLOR_WHITE"   \\ /");
	gotoXY(23,2);printf("     "COLOR_WHITE"    Y"COLOR_RESET"     ");
	printf(COLOR_RESET);
}

// ┌─┬─┐
// │ │ │
// ├─┼─┤
// └─┴─┘
void loading(){
	clrscr;
	HIDEKURSOR;
	setWin(26,98);
	gotoXY(1,1);
	CetakBingkai(26,98);
	int x = 6, y = 13;
	gotoXY(x++,y);printf("   ___                         ___                            ");
	gotoXY(x++,y);printf("  (   )                       (   )  .-.                      ");
	gotoXY(x++,y);printf("   | |    .--.     .---.    .-.| |  ( __)  ___ .-.     .--.   ");
	gotoXY(x++,y);printf("   | |   /    \\   / .-, \\  /   \\ |  (''\") (   )   \\   /    \\  ");
	gotoXY(x++,y);printf("   | |  |  .-. ; (__) ; | |  .-. |   | |   |  .-. .  ;  ,-. ' ");
	gotoXY(x++,y);printf("   | |  | |  | |   .'`  | | |  | |   | |   | |  | |  | |  | | ");
	gotoXY(x++,y);printf("   | |  | |  | |  / .'| | | |  | |   | |   | |  | |  | |  | | ");
	gotoXY(x++,y);printf("   | |  | |  | | | /  | | | |  | |   | |   | |  | |  | |  | | ");
	gotoXY(x++,y);printf("   | |  | '  | | ; |  ; | | '  | |   | |   | |  | |  | '  | |  .-.  .-.  .-.   ");
	gotoXY(x++,y);printf("   | |  '  `-' / ' `-'  | ' `-'  /   | |   | |  | |  '  `-' | (   )(   )(   ) ");
	gotoXY(x++,y);printf("  (___)  `.__.'  `.__.'_.  `.__,'   (___) (___)(___)  `.__. |  `-'  `-'  `-'  ");
	gotoXY(x++,y);printf("                                                      ( `-' ; ");
	gotoXY(x++,y);printf("                                                       `.__.  ");
	gotoXY(18+3,3);printf("                                                                                              ");
	gotoXY(19+3,3);printf("                                                                                              ");
	gotoXY(20+3,3);printf("┌────────────────────────────────────────────────────────────────────────────────────────────┐");
	gotoXY(21+3,3);printf("│                                                                                            │");
	gotoXY(22+3,3);printf("└────────────────────────────────────────────────────────────────────────────────────────────┘");
	gotoXY(21+3,4);printf(COLOR_GREEN);SlowPrint(" ██████████████████████████████████████████████████████████████████████████████████████████ ",5000);
	printf(COLOR_RESET);
}

void gameover(){
	clrscr;
	int x = 3,y = 5;
	gotoXY(1,1);
	CetakBingkai(30,98);
	gotoXY(x++,y);printf("                             "COLOR_CYAN",--.     ");
	gotoXY(x++,y);printf("                            {    }    ");
	gotoXY(x++,y);printf("                            K,   }    ");
	gotoXY(x++,y);printf("                           "COLOR_RED"/  "COLOR_CYAN"`Y`"COLOR_RED"     ");
	gotoXY(x++,y);printf("                      "COLOR_CYAN"_"COLOR_RED"   /   /       ");
	gotoXY(x++,y);printf("                     "COLOR_CYAN"{_'-K.__"COLOR_RED"/        ");
	gotoXY(x++,y);printf("                       "COLOR_CYAN"`"COLOR_WHITE"/"COLOR_CYAN"-.__L._"COLOR_WHITE"      ");
	gotoXY(x++,y);printf("                       /    /"COLOR_CYAN"`\\_}"COLOR_WHITE"            _/_/_/    _/_/    _/      _/  _/_/_/_/");
	gotoXY(x++,y);printf("                      "COLOR_WHITE"/  ' /              _/        _/    _/  _/_/  _/_/  _/       ");
	gotoXY(x++,y);printf(COLOR_YELLOW"              "COLOR_YELLOW"____"COLOR_WHITE"   /  ' /              _/  _/_/  _/_/_/_/  _/  _/  _/  _/_/_/    ");
	gotoXY(x++,y);printf(COLOR_YELLOW"       ,-'~~~~    ~~"COLOR_WHITE"/  ' /"COLOR_YELLOW"_        "COLOR_WHITE"     _/    _/  _/    _/  _/      _/  _/         ");
	gotoXY(x++,y);printf(COLOR_YELLOW"     ,'             ``~~~"COLOR_BLACK"%%%%"COLOR_YELLOW"',    "COLOR_WHITE"        _/_/_/  _/    _/  _/      _/  _/_/_/_/    ");
	gotoXY(x++,y);printf(COLOR_YELLOW"    (                     "COLOR_BLACK"%%"COLOR_YELLOW"  Y    "COLOR_WHITE"                                                 ");
	gotoXY(x++,y);printf(COLOR_YELLOW"   {                      "COLOR_BLACK"%%%%"COLOR_YELLOW" I   "COLOR_WHITE"            _/_/    _/      _/  _/_/_/_/  _/_/_/  ");
	gotoXY(x++,y);printf(COLOR_YELLOW"  {      -                 "COLOR_BLACK"%%"COLOR_YELLOW"  `.  "COLOR_WHITE"        _/    _/  _/      _/  _/        _/    _/ ");
	gotoXY(x++,y);printf(COLOR_YELLOW"  |       ',                "COLOR_BLACK"%%"COLOR_YELLOW"  )  "COLOR_WHITE"       _/    _/  _/      _/  _/_/_/    _/_/_/    ");
	gotoXY(x++,y);printf(COLOR_YELLOW"  |        |   ,..__      __. Y    "COLOR_WHITE"     _/    _/    _/  _/    _/        _/    _/   ");
	gotoXY(x++,y);printf(COLOR_YELLOW"  |    .,_./  Y "COLOR_WHITE"' /"COLOR_YELLOW" ^Y   J   )|    "COLOR_WHITE"      _/_/        _/      _/_/_/_/  _/    _/    ");
	gotoXY(x++,y);printf(COLOR_YELLOW"  \\           |"COLOR_WHITE"' /"COLOR_YELLOW"   |   |   ||   "COLOR_WHITE"    ");
	gotoXY(x++,y);printf(COLOR_YELLOW"   \\          L_"COLOR_WHITE"/"COLOR_YELLOW"    . _ (_,.'(   "COLOR_WHITE"    ");
	gotoXY(x++,y);printf(COLOR_YELLOW"    \\,   ,      ^^\"\"' / |      )"COLOR_WHITE"      ");
	gotoXY(x++,y);printf(COLOR_YELLOW"      \\_  \\          /,L]     /  "COLOR_WHITE"     ");
	gotoXY(x++,y);printf(COLOR_YELLOW"        '-_`-,       ` `   ./`     "COLOR_WHITE"   ");
	gotoXY(x++,y);printf(COLOR_YELLOW"           `-(_            )       "COLOR_WHITE"   ");
	gotoXY(x++,y);printf(COLOR_YELLOW"               ^^\\..___,.--`      "COLOR_WHITE"    ");
	gotoXY(29,74);printf(COLOR_RESET"Press ENTER to continue.");
	pressENTER();
	printf(COLOR_RESET);
}

void congrats(){
	clrscr;
	int x = 5,y = 3;
	gotoXY(1,1);
	CetakBingkai(25,98);
	gotoXY(x++,y);printf(COLOR_WHITE"                                             "COLOR_GREEN"/   \\"COLOR_WHITE"                                     ");
	gotoXY(x++,y);printf("            _                        "COLOR_GREEN")      ((   ))     ("COLOR_WHITE"                              ");
	gotoXY(x++,y);printf("           (@)                      "COLOR_GREEN"/|\\      ))_((     /|\\"COLOR_WHITE"                        _  ");
	gotoXY(x++,y);printf("           │─│                     "COLOR_GREEN"/ | \\    (/\\|/\\)   / | \\"COLOR_WHITE"                      (@)   ");
	gotoXY(x++,y);printf("           │ │\\,                  "COLOR_GREEN"/  | voV   \\`|'/  Vov |  \\"COLOR_WHITE"                     │─│   ");
	gotoXY(x++,y);printf("           │─│"COLOR_YELLOW"─────────────────────────"COLOR_GREEN"'^`"COLOR_YELLOW"───"COLOR_GREEN"(o o)"COLOR_YELLOW"──"COLOR_GREEN"'^`"COLOR_YELLOW"──────────────────────────"COLOR_WHITE"│ │   ");
	gotoXY(x++,y);printf("           │ │                               "COLOR_GREEN"`\\Y/'"COLOR_WHITE"                               │─│   ");
	gotoXY(x++,y);printf("           │─│"COLOR_WHITE"           "COLOR_RED" ┌─┐   ┌─┐   ┌┐┌   ┌─┐   ┬─┐   ┌─┐   ┌┬┐   ┌─┐ "COLOR_WHITE"         "COLOR_WHITE"│ │   ");
	gotoXY(x++,y);printf("           │ │"COLOR_WHITE"           "COLOR_RED" │     │ │   │││   │ ┬   ├┬┘   ├─┤    │    └─┐ "COLOR_WHITE"         "COLOR_WHITE"│─│   ");
	gotoXY(x++,y);printf("           │─│"COLOR_WHITE"           "COLOR_RED" └─┘   └─┘   ┘└┘   └─┘   ┴└─   ┴ ┴    ┴    └─┘ "COLOR_WHITE"         "COLOR_WHITE"│ │   ");
	gotoXY(x++,y);printf("           │ │                                                                   │─│   ");
	gotoXY(x++,y);printf("           │_│"COLOR_YELLOW"───────────────────────────────────────────────────────────────────"COLOR_WHITE"│ │   ");
	gotoXY(x++,y);printf("           (@)              "COLOR_GREEN"l   /\\ /         ( (       \\ /\\   l"COLOR_WHITE"                `\\│─│   ");
	gotoXY(x++,y);printf("                            "COLOR_GREEN"l /   V           \\ \\       V   \\ l"COLOR_WHITE"                  (@)   ");
	gotoXY(x++,y);printf("                            "COLOR_GREEN"l/                _) )_          \\I  "COLOR_WHITE"                      ");
	gotoXY(x++,y);printf("                                              "COLOR_GREEN"`\\ /'"COLOR_RESET"	                               ");
	gotoXY(24,74);printf("Press ENTER to continue.");
	pressENTER();
	printf(COLOR_RESET);
}

void credit(){
	setWin(26,98);
	gotoXY(1,1);
	clrscr;
	CetakBingkai(26,98);
	gotoXY(3,2);printf(COLOR_CYAN"       |^^^|     "COLOR_YELLOW"  ____________ _____ _____  _   _ _____ "COLOR_RED"  _____  _____ _   _ _      _____ ");
	gotoXY(4,2);printf(COLOR_RED"        }-{      "COLOR_YELLOW"  | ___ \\ ___ \\_   _|  __ \\| | | |_   _| "COLOR_RED"/  ___||  _  | | | | |    /  ___|");
	gotoXY(5,2);printf(COLOR_RED"        }-{      "COLOR_YELLOW"  | |_/ / |_/ / | | | |  \\/| |_| | | |  "COLOR_RED" \\ `--. | | | | | | | |    \\ `--. ");
	gotoXY(6,2);printf(COLOR_CYAN"    /|_/---\\_|\\  "COLOR_YELLOW"  | ___ \\    /  | | | | __ |  _  | | |   "COLOR_RED" `--. \\| | | | | | | |     `--. \\");
	gotoXY(7,2);printf(COLOR_CYAN"    I _|\\_/|_ I  "COLOR_YELLOW"  | |_/ / |\\ \\ _| |_| |_\\ \\| | | | | |  "COLOR_RED" /\\__/ /\\ \\_/ / |_| | |____/\\__/ /");
	gotoXY(8,2);printf(COLOR_CYAN"    \\|"COLOR_WHITE" |   | "COLOR_CYAN"|/  "COLOR_YELLOW"  \\____/\\_| \\_|\\___/ \\____/\\_| |_/ \\_/ "COLOR_RED"  \\____/  \\___/ \\___/\\_____/\\____/ ");
	gotoXY(9,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_RESET"     ");
	gotoXY(10,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_RESET"     ");
	gotoXY(11,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_MAGENTA"     	Created by :");
	gotoXY(12,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_RESET"     ");
	gotoXY(13,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_YELLOW"         	13515014 "COLOR_GREEN"Mokhammad Ferdi Ghozali");
	gotoXY(14,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_YELLOW"         	13515023 "COLOR_GREEN"Radiyya Dwisaputra");
	gotoXY(15,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_YELLOW"         	13515026 "COLOR_GREEN"Achmad Fahrurrozi Maskur");
	gotoXY(16,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_YELLOW"         	13515074 "COLOR_GREEN"Akmal Fadlurohman");
	gotoXY(17,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_YELLOW"         	13515092 "COLOR_GREEN"Diki Ardian Wirasandi");
	gotoXY(18,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_YELLOW"         	13515131 "COLOR_GREEN"David Theosaksomo");
	gotoXY(19,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_RESET"     ");
	gotoXY(20,2);printf("     "COLOR_WHITE"  | ` |   "COLOR_RESET"     ");
	gotoXY(21,2);printf("     "COLOR_WHITE"  \\ ` /  "COLOR_MAGENTA"      	Teknik Informatika 2015");
	gotoXY(22,2);printf("     "COLOR_WHITE"   \\ /   "COLOR_MAGENTA"      	Institut Teknologi Bandung");
	gotoXY(23,2);printf("     "COLOR_WHITE"    Y     "COLOR_RESET"     ");
	pressKey();
	printf(COLOR_RESET);
}

void bossdragon1(int x, int y){

	printf(COLOR_RED);
	gotoXY(x++,y);printf("       _________,---------.____------.___           ");
	gotoXY(x++,y);printf("      /_______    `--._______  `--.____ \\\\          ");
	gotoXY(x++,y);printf("       /__.-' `-----.____    `--.____\\\\`_/          ");
	gotoXY(x++,y);printf("       ,'       ___      `---.___ ___//    `-.      ");
	gotoXY(x++,y);printf("      /     _.-'   )'           ``---'     \\  \\     ");
	gotoXY(x++,y);printf("     |     /       |           . '             |    ");
	gotoXY(x++,y);printf("    /    /     /   |          '    ___  )   |  |    ");
	gotoXY(x++,y);printf("    |   |     |  _/` _        ` _,' _ `/) '    |    ");
	gotoXY(x++,y);printf("     \\_  `--._\\__`--'_\\-___ _,-'   '-`  ___   _/    ");
	gotoXY(x++,y);printf("       `---.____ `--.__----_  /_)____,  __/  ,`-'   ");
	gotoXY(x++,y);printf("                `------__>  `-------(/(/-'-\\)\\)     ");
	printf(COLOR_RESET);

}

void bossdragon2(int x, int y){

	gotoXY(x++,y);printf(COLOR_RED"                                                _   __,----'~~~~~~~~~`-----.__     ");
	gotoXY(x++,y);printf("                                         .  .    `//====-              ____,-'~`   ");   
	gotoXY(x++,y);printf("                        -.            \\_|// .   /||\\\\  `~~~~`---.___./       "); 
	gotoXY(x++,y);printf("                  ______-==.       _-~"COLOR_GREEN"o"COLOR_RED"  `\\/    |||  \\\\           _,'`       ");  
	gotoXY(x++,y);printf("            __,--'   ,=='||\\=_    ;_,_,/ _-'|-   |`\\   \\\\        ,'          ");  
	gotoXY(x++,y);printf("         _-'      ,='    | \\\\`.    '',/~7  /-   /  ||   `\\.     /            ");     
	gotoXY(x++,y);printf("       .'       ,'       |  \\\\  \\_  \"  /  /-   /   ||      \\   /             ");     
	gotoXY(x++,y);printf("      / _____  /         |     \\\\.`-_/  /|- _/   ,||       \\ /               ");   
	gotoXY(x++,y);printf("     ,-'     `-|--'~~`--_ \\     `==-/  `| \\'--===-'       _/`                ");     
	gotoXY(x++,y);printf("               '         `-|      /|    )-'\\~'      _,--\"'                   "); 
	gotoXY(x++,y);printf("                           '-~^\\_/ |    |   `\\_   ,^             /\\          ");    
	gotoXY(x++,y);printf("                                /  \\     \\__   \\/~               `\\__        ");    
	gotoXY(x++,y);printf("                            _,-' _/'\\ ,-'~____-'`-/                 ``===\\   ");   
	gotoXY(x++,y);printf("                           ((->/'    \\|||' `.     `\\.  ,                _||  ");    
	gotoXY(x++,y);printf("             "COLOR_WHITE"."COLOR_CYAN"/"COLOR_RED"                       \\_     `\\      `~---|__i__i__\\--~'_/   ");     
	gotoXY(x++,y);printf("            "COLOR_WHITE"<_n_"COLOR_RED"                     __-^-_    `)  \\-.______________,-~'     ");    
	gotoXY(x++,y);printf("             "COLOR_WHITE"`B'\\"COLOR_BLUE")"COLOR_RED"                  ///,-'~`__--^-  |-------~~~~^'           ");     
	gotoXY(x++,y);printf("             "COLOR_WHITE"/^>"COLOR_RED"                           ///,--~`-\\	                       ");    
	printf(COLOR_RESET);
}

void bossdragon3(int x, int y){

	gotoXY(x++,y);printf(""COLOR_RED"                        \\                                              ");
	gotoXY(x++,y);printf("      '.                 \\.                                            ");
	gotoXY(x++,y);printf("       '.                 \"\\                                           ");
	gotoXY(x++,y);printf("       ::                  \\\\                                         ");
	gotoXY(x++,y);printf("       \" .                 \".\\                                         ");
	gotoXY(x++,y);printf("        \"\"    ;.   ,        \" .                                         ");
	gotoXY(x++,y);printf("        \".~   .\"-  .^  .     \\ \\                                      ");
	gotoXY(x++,y);printf("     -.._\" \\   \\ \\  \\\\  \\    \"  \\                                ");
	gotoXY(x++,y);printf("       \".\"\\ \\._ ) \\ ) \\.)\\-\\..\\  :                               ");
	gotoXY(x++,y);printf("         \"\"\\ \",\\\"_.);-.).) )) \"~~).                                   ");
	gotoXY(x++,y);printf(" ~\"~~.._    '  -\"         \"\"~.)    \"~,                                  ");
	gotoXY(x++,y);printf("  \"\"~.  \"\"~~)\". \"-,           \",.\"\"\"\" \"~.                               ");
	gotoXY(x++,y);printf("      \" ..~\",\" '-'\"~~...___.~\"\"  \"~.     ~.                             ");
	gotoXY(x++,y);printf("       .\"  .\"      _.~~\"\"\"\".,       \"~.   \"~~~.~.  _..._                ");
	gotoXY(x++,y);printf("     .\"    |       '. ( "COLOR_GREEN" ()"COLOR_RED" )\";>       \"\"~.      \"(.___.)..             ");
	gotoXY(x++,y);printf("    /      \"       ..\"\"~~~~\"\"_.~  ....._.  \"~.             \"\"~.         ");
	gotoXY(x++,y);printf("   \"     ___\\~-      \"\"\"\"\"\"\"\"    \"       \"\"~~.\"\"\":==>..        \"~.     ");
	gotoXY(x++,y);printf(" .\"          \\_~               .              \"~((####)) ..       \".   ");
	gotoXY(x++,y);printf(".|       _.-\"\", /          ..~\"                  \"\"~~~\"    \"\"~~~~~  :>  ");
	gotoXY(x++,y);printf("              /\".                       .~\"~~..___............~;>~\"\"    ");
	gotoXY(x++,y);printf("           .~\"  \"~.         \"-~~....--\"\"__________,,....~~~~\"\"\"         ");
	gotoXY(x++,y);printf("                   \"--\"\"~~..._____,..~~\"                                ");
	gotoXY(x++,y);printf("                  .\"                                                    ");
	gotoXY(x++,y);printf("                  | "COLOR_RESET"                                                    ");
	printf(COLOR_RESET);

}

void dragon(int x, int y){
	gotoXY(x++,y);printf("              /           /        ");
	gotoXY(x++,y);printf("             /' .,,,,  ./          ");
	gotoXY(x++,y);printf("            /';'     ,/            ");
	gotoXY(x++,y);printf("           / /   ,,//,`'`          ");
	gotoXY(x++,y);printf("          ( ,, '_,  ,,,' ``        ");
	gotoXY(x++,y);printf("          |    /@  ,,, ;\" `        ");
	gotoXY(x++,y);printf("         /    .   ,''/' `,``       ");
	gotoXY(x++,y);printf("        /   .     ./, `,, ` ;      ");
	gotoXY(x++,y);printf("     ,./  .   ,-,',` ,,/''\\,'      ");
	gotoXY(x++,y);printf("    |   /; ./,,'`,,'' |   |        ");
	gotoXY(x++,y);printf("    |     /   ','    /    |        ");
	gotoXY(x++,y);printf("     \\___/'   '     |     |        ");
	gotoXY(x++,y);printf("       `,,'  |      /     `\\       ");
	gotoXY(x++,y);printf("            /      |        ~\\     ");
	gotoXY(x++,y);printf("           '       (               ");
	gotoXY(x++,y);printf("          :                        ");
}

void EnemyAppeared(){
	int x = 2, y = 2;
	gotoXY(x++,y);printf(" ┌──────────────────────────────────────────────────────┐");
	gotoXY(x++,y);printf(" │              "COLOR_RED"  An enemy has appeared!              "COLOR_RESET"  │");
	gotoXY(x++,y);printf(" └──────────────────────────────────────────────────────┘");
	printf(COLOR_RESET);
}

void NextRound(int i){
	gotoXY(1,1);
	CetakBingkai(41,100);
	int x = 10, y = 13;
	gotoXY(x++,y);printf("+------------------------------------------------------------------------+");
	x++;
	gotoXY(x++,y);printf("   ooooooooo.     .oooooo.   ooooo     ooo ooooo      ooo oooooooooo.     ");
	gotoXY(x++,y);printf("   `888   `Y88.  d8P'  `Y8b  `888'     `8' `888b.     `8' `888'   `Y8b    ");
	gotoXY(x++,y);printf("    888   .d88' 888      888  888       8   8 `88b.    8   888      888   ");
	gotoXY(x++,y);printf("    888ooo88P'  888      888  888       8   8   `88b.  8   888      888   ");
	gotoXY(x++,y);printf("    888`88b.    888      888  888       8   8     `88b.8   888      888   ");
	gotoXY(x++,y);printf("    888  `88b.  `88b    d88'  `88.    .8'   8       `888   888     d88'   ");
	gotoXY(x++,y);printf("   o888o  o888o  `Y8bood8P'     `YbodP'    o8o        `8  o888bood8P'     ");
	x++;
	switch (i) {
		case 1 :
			gotoXY(x++,y);printf("                                    .o                                       ");
			gotoXY(x++,y);printf("                                  o888                                       ");
			gotoXY(x++,y);printf("                                   888                                       ");
			gotoXY(x++,y);printf("                                   888                                       ");
			gotoXY(x++,y);printf("                                   888                                       ");
			gotoXY(x++,y);printf("                                   888                                       ");
			gotoXY(x++,y);printf("                                  o888o                                      ");
			break;
		case 2 :
			gotoXY(x++,y);printf("                                  .oooo.                                    ");
			gotoXY(x++,y);printf("                                .dP""Y88b                                   ");
			gotoXY(x++,y);printf("                                      ]8P'                                  ");
			gotoXY(x++,y);printf("                                    .d8P'                                   ");
			gotoXY(x++,y);printf("                                  .dP'                                      ");
			gotoXY(x++,y);printf("                                .oP     .o                                  ");
			gotoXY(x++,y);printf("                                8888888888                                  ");
			break;
		case 3 :
			gotoXY(x++,y);printf("                                  .oooo.                                    ");
			gotoXY(x++,y);printf("                                .dP""Y88b                                   ");
			gotoXY(x++,y);printf("                                      ]8P'                                  ");
			gotoXY(x++,y);printf("                                    <88b.                                   ");
			gotoXY(x++,y);printf("                                     `88b.                                  ");
			gotoXY(x++,y);printf("                                o.   .88P                                   ");
			gotoXY(x++,y);printf("                                `8bd88P'                                    ");
			break;
		case 4 :
			gotoXY(x++,y);printf("                                      .o                                    ");
			gotoXY(x++,y);printf("                                    .d88                                    ");
			gotoXY(x++,y);printf("                                  .d'888                                    ");
			gotoXY(x++,y);printf("                                .d'  888                                    ");
			gotoXY(x++,y);printf("                                88ooo888oo                                  ");
			gotoXY(x++,y);printf("                                     888                                    ");
			gotoXY(x++,y);printf("                                    o888o                                   ");
			break;
		case 5 :
			gotoXY(x++,y);printf("                                  oooooooo                                  ");
			gotoXY(x++,y);printf("                                 dP\"\"\"\"\"\"\"                                  ");
			gotoXY(x++,y);printf("                                d88888b.                                    ");
			gotoXY(x++,y);printf("                                    `Y88b                                   ");
			gotoXY(x++,y);printf("                                      ]88                                   ");
			gotoXY(x++,y);printf("                                o.   .88P                                   ");
			gotoXY(x++,y);printf("                                `8bd88P'                                    ");
			break;
		case 6 :
			gotoXY(x++,y);printf("                                    .ooo                                    ");
			gotoXY(x++,y);printf("                                  .88'                                      ");
			gotoXY(x++,y);printf("                                 d88'                                       ");
			gotoXY(x++,y);printf("                                d888P\"Ybo.                                  ");
			gotoXY(x++,y);printf("                                Y88[   ]88                                  ");
			gotoXY(x++,y);printf("                                `Y88   88P                                  ");
			gotoXY(x++,y);printf("                                 `88bod8'                                   ");
			break;
		case 7 :
			gotoXY(x++,y);printf("                                 ooooooooo                                  ");
			gotoXY(x++,y);printf("                                d\"\"\"\"\"\"\"8'                                  ");
			gotoXY(x++,y);printf("                                      .8'                                   ");
			gotoXY(x++,y);printf("                                     .8'                                    ");
			gotoXY(x++,y);printf("                                    .8'                                     ");
			gotoXY(x++,y);printf("                                   .8'                                      ");
			gotoXY(x++,y);printf("                                  .8'                                       ");
			break;
		case 8 :
			gotoXY(x++,y);printf("                                 .ooooo.                                    ");
			gotoXY(x++,y);printf("                                d88'   `8.                                  ");
			gotoXY(x++,y);printf("                                Y88..  .8'                                  ");
			gotoXY(x++,y);printf("                                 `88888b.                                   ");
			gotoXY(x++,y);printf("                                .8'  ``88b                                  ");
			gotoXY(x++,y);printf("                                `8.   .88P                                  ");
			gotoXY(x++,y);printf("                                 `boood8'                                   ");
			break;
		case 9 :
			gotoXY(x++,y);printf("                                 .ooooo.                                    ");
			gotoXY(x++,y);printf("                                888' `Y88.                                  ");
			gotoXY(x++,y);printf("                                888    888                                  ");
			gotoXY(x++,y);printf("                                 `Vbood888                                  ");
			gotoXY(x++,y);printf("                                      888'                                  ");
			gotoXY(x++,y);printf("                                    .88P'                                   ");
			gotoXY(x++,y);printf("                                  .oP'                                      ");
			break;
		case 10 :
			gotoXY(x++,y);printf("                                .o    .oooo.                                ");
			gotoXY(x++,y);printf("                              o888   d8P'`Y8b                               ");
			gotoXY(x++,y);printf("                               888  888    888                              ");
			gotoXY(x++,y);printf("                               888  888    888                              ");
			gotoXY(x++,y);printf("                               888  888    888                              ");
			gotoXY(x++,y);printf("                               888  `88b  d88'                              ");
			gotoXY(x++,y);printf("                              o888o  `Y8bd8P'                               ");
			break;
		case 11 :
			gotoXY(x++,y);printf("                                 .o    .o                                   ");
			gotoXY(x++,y);printf("                               o888  o888                                   ");
			gotoXY(x++,y);printf("                                888   888                                   ");
			gotoXY(x++,y);printf("                                888   888                                   ");
			gotoXY(x++,y);printf("                                888   888                                   ");
			gotoXY(x++,y);printf("                                888   888                                   ");
			gotoXY(x++,y);printf("                               o888o o888o                                  ");
			break;
		case 12 :
			gotoXY(x++,y);printf("                                .o    .oooo.                                ");
			gotoXY(x++,y);printf("                              o888  .dP""Y88b                               ");
			gotoXY(x++,y);printf("                               888        ]8P'                              ");
			gotoXY(x++,y);printf("                               888      .d8P'                               ");
			gotoXY(x++,y);printf("                               888    .dP'                                  ");
			gotoXY(x++,y);printf("                               888  .oP     .o                              ");
			gotoXY(x++,y);printf("                              o888o 8888888888                              ");
			break;
		case 13 :
			gotoXY(x++,y);printf("                                .o    .oooo.                                ");
			gotoXY(x++,y);printf("                              o888  .dP""Y88b                               ");
			gotoXY(x++,y);printf("                               888        ]8P'                              ");
			gotoXY(x++,y);printf("                               888      <88b.                               ");
			gotoXY(x++,y);printf("                               888       `88b.                              ");
			gotoXY(x++,y);printf("                               888  o.   .88P                               ");
			gotoXY(x++,y);printf("                              o888o `8bd88P'                                ");
			break;
		case 14 :
			gotoXY(x++,y);printf("                                .o        .o                                ");
			gotoXY(x++,y);printf("                              o888      .d88                                ");
			gotoXY(x++,y);printf("                               888    .d'888                                ");
			gotoXY(x++,y);printf("                               888  .d'  888                                ");
			gotoXY(x++,y);printf("                               888  88ooo888oo                              ");
			gotoXY(x++,y);printf("                               888       888                                ");
			gotoXY(x++,y);printf("                              o888o     o888o                               ");
			break;
		case 15 :
			gotoXY(x++,y);printf("                                .o    oooooooo                              ");
			gotoXY(x++,y);printf("                              o888   dP\"\"\"\"\"\"\"                              ");
			gotoXY(x++,y);printf("                               888  d88888b.                                ");
			gotoXY(x++,y);printf("                               888      `Y88b                               ");
			gotoXY(x++,y);printf("                               888        ]88                               ");
			gotoXY(x++,y);printf("                               888  o.   .88P                               ");
			gotoXY(x++,y);printf("                              o888o `8bd88P'                                ");
			break;
		case 16 :
			gotoXY(x++,y);printf("                                .o      .ooo                                ");
			gotoXY(x++,y);printf("                              o888    .88'                                  ");
			gotoXY(x++,y);printf("                               888   d88'                                   ");
			gotoXY(x++,y);printf("                               888  d888P\"Ybo.                              ");
			gotoXY(x++,y);printf("                               888  Y88[   ]88                              ");
			gotoXY(x++,y);printf("                               888  `Y88   88P                              ");
			gotoXY(x++,y);printf("                              o888o  `88bod8'                               ");
			break;
		case 17 :
			gotoXY(x++,y);printf("                                .o   ooooooooo                              ");
			gotoXY(x++,y);printf("                              o888  d\"\"\"\"\"\"\"8'                              ");
			gotoXY(x++,y);printf("                               888        .8'                               ");
			gotoXY(x++,y);printf("                               888       .8'                                ");
			gotoXY(x++,y);printf("                               888      .8'                                 ");
			gotoXY(x++,y);printf("                               888     .8'                                  ");
			gotoXY(x++,y);printf("                              o888o   .8'                                   ");
			break;
		case 18 :
			gotoXY(x++,y);printf("                                .o   .ooooo.                                ");
			gotoXY(x++,y);printf("                              o888  d88'   `8.                              ");
			gotoXY(x++,y);printf("                               888  Y88..  .8'                              ");
			gotoXY(x++,y);printf("                               888   `88888b.                               ");
			gotoXY(x++,y);printf("                               888  .8'  ``88b                              ");
			gotoXY(x++,y);printf("                               888  `8.   .88P                              ");
			gotoXY(x++,y);printf("                              o888o  `boood8'                               ");
			break;
		case 19 :
			gotoXY(x++,y);printf("                                .o   .ooooo.                                ");
			gotoXY(x++,y);printf("                              o888  888' `Y88.                              ");
			gotoXY(x++,y);printf("                               888  888    888                              ");
			gotoXY(x++,y);printf("                               888   `Vbood888                              ");
			gotoXY(x++,y);printf("                               888        888'                              ");
			gotoXY(x++,y);printf("                               888      .88P'                               ");
			gotoXY(x++,y);printf("                              o888o   .oP'                                  ");
			break;
		case 20 :
			gotoXY(x++,y);printf("                                .oooo.     .oooo.                           ");
			gotoXY(x++,y);printf("                              .dP""Y88b   d8P'`Y8b                          ");
			gotoXY(x++,y);printf("                                    ]8P' 888    888                         ");
			gotoXY(x++,y);printf("                                  .d8P'  888    888                         ");
			gotoXY(x++,y);printf("                                .dP'     888    888                         ");
			gotoXY(x++,y);printf("                              .oP     .o `88b  d88'                         ");
			gotoXY(x++,y);printf("                              8888888888  `Y8bd8P'                          ");
			break;
	}
	x++;
	gotoXY(x++,y);printf("+------------------------------------------------------------------------+");
	gotoXY(34,38);printf("Press ENTER to continue");
	pressENTER();
}

void RoundsUp(){

}

void phoenix(int x, int y){

	gotoXY(x++,y);printf(COLOR_BLUE"                .-========     ");
	gotoXY(x++,y);printf("             .-' "COLOR_MAGENTA"O"COLOR_BLUE"   ====     ");
	gotoXY(x++,y);printf("            /___      ==     ");
	gotoXY(x++,y);printf("               \\_     |     ");
	gotoXY(x++,y);printf(""COLOR_YELLOW"______"COLOR_BLUE"___________)    (___________"COLOR_YELLOW"______"COLOR_BLUE);
	gotoXY(x++,y);printf(""COLOR_YELLOW"\\____"COLOR_BLUE"`._  || <   `-..-'   > ||  _.'"COLOR_YELLOW"____/"COLOR_BLUE);
	gotoXY(x++,y);printf("   "COLOR_YELLOW"\\____"COLOR_BLUE"`-.|_ _ <      > _ _|.-'"COLOR_YELLOW"____/"COLOR_BLUE);
	gotoXY(x++,y);printf("      "COLOR_YELLOW"\\_____"COLOR_BLUE"|_| //    \\\\ |_|"COLOR_YELLOW"_____/"COLOR_BLUE);
	gotoXY(x++,y);printf("         "COLOR_RED".-\\   "COLOR_BLUE"//      \\\\ "COLOR_RED"/-.");
	gotoXY(x++,y);printf("      _.'.- `._        _.' -.`._     ");
	gotoXY(x++,y);printf("    .' .'  /  '``----''`  \\  `. `.  ");
	gotoXY(x++,y);printf("      /  .' .'.'/|..|\\`.`. `.  \\   ");
	gotoXY(x++,y);printf("      ::_.' .' /| || |\\ `. `._::    ");
	gotoXY(x++,y);printf("          .` .` | || | '. '.         ");
	gotoXY(x++,y);printf("             `  | `' |  '            ");
	printf(COLOR_RESET);

}

void centaur(int x, int y){

	gotoXY(x++,y);printf("                     __             ");
	gotoXY(x++,y);printf("                    / _\\ "COLOR_BLUE"#"COLOR_RESET"         ");
	gotoXY(x++,y);printf("                    \\c /  "COLOR_BLUE"#"COLOR_RESET"        ");
	gotoXY(x++,y);printf("                    / \\___ "COLOR_BLUE"#"COLOR_RESET"       ");
	gotoXY(x++,y);printf("                    \\`----`"COLOR_BLUE"#"COLOR_RED"==>"COLOR_RESET"    ");
	gotoXY(x++,y);printf("                    |  \\  "COLOR_BLUE"#"COLOR_RESET"        ");
	gotoXY(x++,y);printf("         "COLOR_BLACK",%%"COLOR_BROWN".-\"\"\"---'`--'\\"COLOR_BLUE"#"COLOR_BROWN"_    ");
	gotoXY(x++,y);printf("        "COLOR_BLACK"%%%%"COLOR_BROWN"/             |__`\\    ");
	gotoXY(x++,y);printf("       "COLOR_BLACK".%%'"COLOR_BROWN"\\     |   \\   /  //    ");
	gotoXY(x++,y);printf("       "COLOR_BLACK",%%' "COLOR_BROWN">   .'----\\ |  [/      ");
	gotoXY(x++,y);printf("          < <<`       ||            ");
	gotoXY(x++,y);printf("           `\\\\\\       ||         ");
	gotoXY(x++,y);printf("             )\\\\      )\\         ");
	gotoXY(x++,y);printf("        "COLOR_BLACK"^^^^^"COLOR_BROWN"\"\"\""COLOR_BLACK"^^^^^^"COLOR_BROWN"\"\""COLOR_BLACK"^^^^^^ ");
	printf(COLOR_RESET);
}

void reaper(int x, int y){

	gotoXY(x++,y);printf("                     "COLOR_BLACK","COLOR_RED"____       ");
	gotoXY(x++,y);printf("                     "COLOR_BLACK"|"COLOR_RED"---.\\     ");
	gotoXY(x++,y);printf("             "COLOR_BLACK"___     |    "COLOR_RED"`      ");
	gotoXY(x++,y);printf("            "COLOR_BLACK"/ .-\\  ."COLOR_RESET"/=)         ");
	gotoXY(x++,y);printf("           "COLOR_BLACK"|  |\"|_/\\/|         ");
	gotoXY(x++,y);printf("           ;  |-;| /_|           ");
	gotoXY(x++,y);printf("          / \\_| |/ \\ |         ");
	gotoXY(x++,y);printf("         /      \\/\\( |         ");
	gotoXY(x++,y);printf("         |   /  |` ) |           ");
	gotoXY(x++,y);printf("         /   \\ _/    |          ");
	gotoXY(x++,y);printf("        /--._/  \\    |          ");
	gotoXY(x++,y);printf("        `"COLOR_RESET"/|)"COLOR_BLACK"    |    /           ");
	gotoXY(x++,y);printf("          /     |   |            ");
	gotoXY(x++,y);printf("        .'      |   |            ");
	gotoXY(x++,y);printf("       /         \\  |           ");
	gotoXY(x++,y);printf("      (_.-.__.__./  /	         ");
	printf(COLOR_RESET);

}

void fairy(int x, int y){

	gotoXY(x++,y);printf("  "COLOR_CYAN"__       __          "COLOR_YELLOW".--."COLOR_RESET"        ");
	gotoXY(x++,y);printf(" "COLOR_CYAN"(  \"\"--__(  \"\"-_    "COLOR_YELLOW",' .-.\\"COLOR_RESET"        "COLOR_YELLOW"*");
	gotoXY(x++,y);printf("  "COLOR_CYAN"\"-_ __  \"\"--__ \"-_"COLOR_YELLOW"(  ("COLOR_RESET"-.-))      "COLOR_YELLOW"/ ");
	gotoXY(x++,y);printf("     "COLOR_CYAN"(  \"\"\"--___\"\"--__"COLOR_RESET"\" )-'(      "COLOR_YELLOW"/");
	gotoXY(x++,y);printf("      "COLOR_CYAN"\"-__      \"\"---"COLOR_RESET"/ ,(., )__o-"COLOR_YELLOW"/"COLOR_RESET",");
	gotoXY(x++,y);printf("          "COLOR_CYAN"\"\"\"----___"COLOR_RESET"(.'.   /--\"--'");
	gotoXY(x++,y);printf("                    (\"-_\"/(    "COLOR_YELLOW"/"COLOR_RESET"");
	gotoXY(x++,y);printf("                     \\   \\ \\");
	gotoXY(x++,y);printf("                      `.  \\ |   ");
	gotoXY(x++,y);printf("                        \\  \\/   ");
	gotoXY(x++,y);printf("                        ||  \\    ");
	gotoXY(x++,y);printf("                      "COLOR_RED",-'/"COLOR_RESET"`. \\   ");
	gotoXY(x++,y);printf("                      "COLOR_RED") /   ) \\  ");
	gotoXY(x++,y);printf("                      |/    `-.\\ ");
	gotoXY(x++,y);printf("                               `\\"COLOR_RESET"");
	printf(COLOR_RESET);

}

void eagle(int x, int y){

	gotoXY(x++,y);printf(" "COLOR_RED"        .---.        .-----------  ");
	gotoXY(x++,y);printf("        /     \\  __  /    ------    ");
	gotoXY(x++,y);printf("       / /     \\(  )/    -----      ");
	gotoXY(x++,y);printf("      //////   ' \\/ `   ---         ");
	gotoXY(x++,y);printf("     //// / // :    : ---           ");
	gotoXY(x++,y);printf("    // /   /  /`    '--             ");
	gotoXY(x++,y);printf("   //          //..\\\\               ");
	gotoXY(x++,y);printf("          "COLOR_BROWN"===="COLOR_RED"UU"COLOR_BROWN"===="COLOR_RED"UU"COLOR_BROWN"====          ");
	gotoXY(x++,y);printf("              "COLOR_RED"'//||\\\\`              ");
	gotoXY(x++,y);printf("                 ''``"COLOR_RESET"               ");

	printf(COLOR_RESET);
}

void cobra(int x, int y){
	printf(COLOR_GREEN);
	gotoXY(x++,y);printf("                     __       ");
	gotoXY(x++,y);printf("       ---_ ...... _/_ -      ");
	gotoXY(x++,y);printf("      /  .      ./ .'*\\ \\     ");
	gotoXY(x++,y);printf("      : '        \\___-'   \\.  ");
	gotoXY(x++,y);printf("     /                      ) ");
	gotoXY(x++,y);printf("   _/                  >   .' ");
	gotoXY(x++,y);printf(" /   "COLOR_WHITE".   ."COLOR_GREEN"       _.-\" /  .'   ");
	gotoXY(x++,y);printf(" \\           __/\"     /.'"COLOR_YELLOW"/"COLOR_GREEN"|   ");
	gotoXY(x++,y);printf("   \\ '--  .-\"/      //' "COLOR_YELLOW"|"COLOR_GREEN"\\|   ");
	gotoXY(x++,y);printf("    "COLOR_WHITE"\\|  \\ |"COLOR_GREEN" /     //"COLOR_YELLOW"_ _ |"COLOR_GREEN"/|   ");
	gotoXY(x++,y);printf("     "COLOR_WHITE"`.  \\:"COLOR_GREEN"/    //"COLOR_YELLOW"|_ _ _|"COLOR_GREEN"\\|   ");
	gotoXY(x++,y);printf("      "COLOR_WHITE"|\\ |\\"COLOR_GREEN"    // "COLOR_YELLOW"| _ _ |"COLOR_GREEN"/|   ");
	gotoXY(x++,y);printf("      \\_ | \\"COLOR_GREEN"/ //  "COLOR_YELLOW" \\ _ _ \\"COLOR_GREEN"\\\\  ");
	gotoXY(x++,y);printf("          \\__//     "COLOR_YELLOW"\\ _ _ \\"COLOR_GREEN"|\\ ");
	printf(COLOR_RESET);

}

void bat(int x, int y){

 	gotoXY(x++,y);printf("      "COLOR_WHITE"="COLOR_BLACK"/\\                 /\\"COLOR_WHITE"="COLOR_BLACK" ");
	gotoXY(x++,y);printf("      / \\'._   (\\_/)   _.'/ \\");
	gotoXY(x++,y);printf("     / .''._'--("COLOR_RED"o"COLOR_BLACK"."COLOR_RED"o"COLOR_BLACK")--'_.''. \\");
	gotoXY(x++,y);printf("    /.' _/ |`'=/ \" \\='`| \\_ `.\\");
	gotoXY(x++,y);printf("   /` .' `\\;-,'\\___/',-;/` '. '\\");
	gotoXY(x++,y);printf("  /.-'       `\\(-V-)/`       `-.\\");
	gotoXY(x++,y);printf("  `            "COLOR_WHITE"\"   \""COLOR_RESET"            `");

	printf(COLOR_RESET);
}

void skeleton(int x, int y){

	gotoXY(x++,y);printf(COLOR_WHITE"          .-.       ");
	gotoXY(x++,y);printf("         ("COLOR_RED"o"COLOR_WHITE"."COLOR_RED"o"COLOR_WHITE")       ");
	gotoXY(x++,y);printf("          (n)        ");
	gotoXY(x++,y);printf("        .-=\"=-.  \\)  ");
	gotoXY(x++,y);printf("       // =T= \\\\,/   ");
	gotoXY(x++,y);printf("      () ==|== ()    ");
	gotoXY(x++,y);printf("       \\  =\"=        ");
	gotoXY(x++,y);printf("       /)(0V0)       ");
	gotoXY(x++,y);printf("         // \\\\       ");
	gotoXY(x++,y);printf("        //   \\\\      ");
	gotoXY(x++,y);printf("       ()     ()    ");
	gotoXY(x++,y);printf("        \\\\    ||    ");
	gotoXY(x++,y);printf("         \\'   '|    ");
	gotoXY(x++,y);printf("       ==\"     \"==  ");
	printf(COLOR_RESET);

}

void spider(int x, int y){

	gotoXY(x++,y);printf("             (                  ");
	gotoXY(x++,y);printf("              )                 ");
	gotoXY(x++,y);printf("             (                 ");
	gotoXY(x++,y);printf("       "COLOR_RED"/\\  "COLOR_BLACK".-\"\"\"-.  "COLOR_RED"/\\         ");
	gotoXY(x++,y);printf("      //\\\\"COLOR_BLACK"/  ,,,  \\"COLOR_RED"//\\\\        ");
	gotoXY(x++,y);printf("      |/\\"COLOR_BLACK"| ,;;;;;, "COLOR_RED"|/\\|        ");
	gotoXY(x++,y);printf("      //\\\\"COLOR_BLACK"\\;-\"\"\"-;/"COLOR_RED"//\\\\        ");
	gotoXY(x++,y);printf("     //  \\"COLOR_BLACK"/   .   \\"COLOR_RED"/  \\\\       ");
	gotoXY(x++,y);printf("    (| ,-_"COLOR_BLACK"| \\ | / |"COLOR_RED"_-, |)      ");
	gotoXY(x++,y);printf("      //`__"COLOR_BLACK"\\.-.-./"COLOR_RED"__`\\\\        ");
	gotoXY(x++,y);printf("     // /.-"COLOR_BLACK"(() ()"COLOR_BLACK")"COLOR_RED"-.\\ \\\\       ");
	gotoXY(x++,y);printf("    (\\ |)   "COLOR_BLACK"'---'"COLOR_BLACK"   "COLOR_RED"(| /)       ");
	gotoXY(x++,y);printf("     ` (|           |) `        ");
	gotoXY(x++,y);printf("       \\)           (/          ");
	printf(COLOR_RESET);

}

void devil(int x, int y){

	gotoXY(x++,y);printf(""COLOR_RED"               ,        ,              ");
	gotoXY(x++,y);printf("              /(        )`             ");
	gotoXY(x++,y);printf("              \\ \\___   / |             ");
	gotoXY(x++,y);printf("              /"COLOR_YELLOW"- _"COLOR_RED"  `-/  '          ");
	gotoXY(x++,y);printf("             "COLOR_YELLOW"/ /   |"COLOR_RED" `    \\         ");
	gotoXY(x++,y);printf("             "COLOR_WHITE"O O   "COLOR_YELLOW")"COLOR_RED" /    |");
	gotoXY(x++,y);printf("             "COLOR_YELLOW"`-^--'`"COLOR_RED"<     '         ");
	gotoXY(x++,y);printf("            (_.)  _  )   /          ");
	gotoXY(x++,y);printf("             `.___/`    /           ");
	gotoXY(x++,y);printf("  <----.     __ / __   \\            ");
	gotoXY(x++,y);printf("  <----|"COLOR_BLACK"===="COLOR_RED"O)))"COLOR_BLACK"=="COLOR_RED") \\) /"COLOR_BLACK"===="COLOR_RED"           ");
	gotoXY(x++,y);printf("  <----'    `--' `.__,' \\              ");
	gotoXY(x++,y);printf("               |        |              ");
	gotoXY(x++,y);printf("                \\       /              ");
	gotoXY(x++,y);printf("           ______( (_  / "COLOR_WHITE"\\______"COLOR_RED"       ");
	gotoXY(x++,y);printf("         ,'  ,-----'   |       "COLOR_WHITE" \\"COLOR_RED"      ");
	gotoXY(x++,y);printf("         `--{__________)      "COLOR_WHITE"  \\/"COLOR_RESET"     ");
	printf(COLOR_RESET);

}

void jacklantern(int x, int y){

	gotoXY(x++,y);printf("              "COLOR_GREEN",_   "COLOR_RED".-.           ");
	gotoXY(x++,y);printf("              "COLOR_GREEN"\\ `\\"COLOR_RED"/ '`           ");
	gotoXY(x++,y);printf(""COLOR_BROWN"         _.--\""COLOR_GREEN"|  |"COLOR_BROWN"\"--._          ");
	gotoXY(x++,y);printf("       .' '  '"COLOR_GREEN"`--`"COLOR_BROWN"'  ' '.        ");
	gotoXY(x++,y);printf("      /  '  "COLOR_BROWN"/\\    /\\"COLOR_BROWN"  '  \\       ");
	gotoXY(x++,y);printf("     ;  '  "COLOR_BROWN"/"COLOR_WHITE"o"COLOR_BROWN"_\\  /"COLOR_WHITE"o"COLOR_BROWN"_\\"COLOR_BROWN"  '  ;      ");
	gotoXY(x++,y);printf("     |  .    . /\\ :    .  |      ");
	gotoXY(x++,y);printf("     ;  . "COLOR_BROWN"/\\ "COLOR_BROWN".'--'."COLOR_BROWN" "COLOR_BROWN"/\\"COLOR_BROWN" .  ;      ");
	gotoXY(x++,y);printf("      \\  ."COLOR_BROWN"\\ \\/\\/\\/\\/ /"COLOR_BROWN".  /       ");
	gotoXY(x++,y);printf("       '._:"COLOR_BROWN"\\_/\\__/\\_/"COLOR_BROWN"._.'        ");
	gotoXY(x++,y);printf("         `'--'--'--'`            ");
	printf(COLOR_RESET);

}

void casper(int x, int y){

	gotoXY(x++,y);printf("         "COLOR_WHITE".-\"\"\"\"-.         ");
	gotoXY(x++,y);printf("        / -   -  \\        ");
	gotoXY(x++,y);printf("       |  .-. .- |         ");
	gotoXY(x++,y);printf("       |  \\"COLOR_RED"o"COLOR_WHITE"| |"COLOR_RED"o"COLOR_WHITE" (         ");
	gotoXY(x++,y);printf("       \\     ^    \\        ");
	gotoXY(x++,y);printf("       |'.  )--'  /|       ");
	gotoXY(x++,y);printf("      / / '-. .-'`\\ \\      ");
	gotoXY(x++,y);printf("     / /'---` `---'\\ \\     ");
	gotoXY(x++,y);printf("     '.__.       .__.'     ");
	gotoXY(x++,y);printf("         `|     |`         ");
	gotoXY(x++,y);printf("          |     \\          ");
	gotoXY(x++,y);printf("          \\      '--.     ");
	gotoXY(x++,y);printf("           '.        `\\   ");
	gotoXY(x++,y);printf("             `'---.   |   ");
	gotoXY(x++,y);printf("                ,__) /    ");
	gotoXY(x++,y);printf("                 `..'     ");
	printf(COLOR_RESET);

}

void ganesha(){

	clrscr;
	setWin(36,88);
	gotoXY(1,1);
	CetakBingkai(36,88);
	gotoXY(3+1,2);printf(COLOR_BLUE"\t                           *** ### ### ### ***");
	gotoXY(4+1,2);printf("\t                       *##                    ##*");
	gotoXY(5+1,2);printf("\t                   *##                            ##*");
	gotoXY(6+1,2);printf("\t                *##                                  ##*");
	gotoXY(7+1,2);printf("\t              *##"COLOR_WHITE"                 _.!._               "COLOR_BLUE"  ##*");
	gotoXY(8+1,2);printf("\t            *##"COLOR_WHITE"                  /O*@*O\\                "COLOR_BLUE"  ##*");
	gotoXY(9+1,2);printf("\t           *##"COLOR_WHITE"                  <\\@(_)@/>                "COLOR_BLUE"  ##*");
	gotoXY(10+1,2);printf("\t          *##"COLOR_WHITE"          ,;,   .--;`     `;--.   ,          "COLOR_BLUE"  ##*");
	gotoXY(11+1,2);printf("\t         *##"COLOR_WHITE"           O@O_ /   |d     b|   \\ _hnn         "COLOR_BLUE"  ##*");
	gotoXY(12+1,2);printf("\t         *##"COLOR_WHITE"           | `/ \\   |       |   / \\` |         "COLOR_BLUE"  ##*");
	gotoXY(13+1,2);printf("\t         *##"COLOR_WHITE"           &&&&  :##;\\     /;##;  &&&&         "COLOR_BLUE"  ##*");
	gotoXY(14+1,2);printf("\t         *##"COLOR_WHITE"           |  \\ / `##/|   |##'  \\ /  |         "COLOR_BLUE"  ##*");
	gotoXY(15+1,2);printf("\t         *##"COLOR_WHITE"           \\   %%%%%%%%`</|   |#'`%%%%%%%%   /         "COLOR_BLUE"  ##*");
	gotoXY(16+1,2);printf("\t         *##"COLOR_WHITE"            '._|_ \\   |   |'  / _|_.'          "COLOR_BLUE"  ##*");
	gotoXY(17+1,2);printf("\t         *##"COLOR_WHITE"              _/  /   \\   \\   \\  \\             "COLOR_BLUE"  ##*");
	gotoXY(18+1,2);printf("\t         *##"COLOR_WHITE"             / (\\(     '.  '-._&&&&            "COLOR_BLUE"  ##*");
	gotoXY(19+1,2);printf("\t         *##"COLOR_WHITE"            (  ()##,    o'--.._`\\-)            "COLOR_BLUE"  ##*");
	gotoXY(20+1,2);printf("\t          *##"COLOR_WHITE"            '-():`##########'()()()          "COLOR_BLUE"  ##*");
	gotoXY(21+1,2);printf("\t           *##"COLOR_WHITE"            /:::::/()`Y`()\\:::::\\          "COLOR_BLUE"  ##*");
	gotoXY(22+1,2);printf("\t            *##"COLOR_WHITE"           \\::::( () | () )::::/         "COLOR_BLUE"  ##*");
	gotoXY(23+1,2);printf("\t              *##"COLOR_WHITE"          `\"\"\"`\\().'.()/'\"\"\"`        "COLOR_BLUE"  ##*");
	gotoXY(24+1,2);printf("\t                *#                                   ##*");
	gotoXY(25+1,2);printf("\t                   *##                            ##*");
	gotoXY(26+1,2);printf("\t                       *##                    ##*");
	gotoXY(27+1,2);printf("\t                           *** ### ### ### ***"COLOR_RESET);
	gotoXY(31+1,2);printf(COLOR_GREEN"\t ╦┌┐┌┌─┐┌┬┐┬┌┬┐┬ ┬┌┬┐  ╔╦╗┌─┐┬┌─┌┐┌┌─┐┬  ┌─┐┌─┐┬  ╔╗ ┌─┐┌┐┌┌┬┐┬ ┬┌┐┌┌─┐");
	gotoXY(32+1,2);printf("\t ║│││└─┐ │ │ │ │ │ │    ║ ├┤ ├┴┐││││ ││  │ ││ ┬│  ╠╩╗├─┤│││ │││ │││││ ┬");
	gotoXY(33+1,2);printf("\t ╩┘└┘└─┘ ┴ ┴ ┴ └─┘ ┴    ╩ └─┘┴ ┴┘└┘└─┘┴─┘└─┘└─┘┴  ╚═╝┴ ┴┘└┘─┴┘└─┘┘└┘└─┘"COLOR_BLUE);

	pressENTER();
	printf(COLOR_RESET);
}
