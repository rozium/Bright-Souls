/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char CC,CC2;
boolean EOP,EOP2;

static FILE * pita;
static FILE * pita2;
static int retval;
static int retval2;

void STARTSAVEFILES()
{
  pita = fopen("SAVES/savefiles.txt","r");
  ADV();
}

void STARTFILE(char * filename)
{
  int i = 6,j;
  char s1[100];
  s1[0] = 'S';
  s1[1] = 'A';
  s1[2] = 'V';
  s1[3] = 'E';
  s1[4] = 'S';
  s1[5] = '/';
    for(j = 0; filename[j] != '\0'; ++j, ++i)
    {
        s1[i] = filename[j];
    }
    s1[i] = '\0';
  pita2 = fopen(s1,"r");
  ADV2();
}

void STARTFILEW(char * filename)
{
  int i = 6,j;
  char s1[100];
  s1[0] = 'S';
  s1[1] = 'A';
  s1[2] = 'V';
  s1[3] = 'E';
  s1[4] = 'S';
  s1[5] = '/';
    for(j = 0; filename[j] != '\0'; ++j, ++i)
    {
        s1[i] = filename[j];
    }
    s1[i] = '\0';
  pita2 = fopen(s1,"ab+");
  ADV2();
}

void STARTGAME(int ID) 
{
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

  /* Algoritma */
  switch(ID) 
{
   case 1  :
      pita = fopen("MODUL/FILEEXT/MahasiswaStat.txt","r");
      break; /* optional */
  
   case 2  :
      pita = fopen("MODUL/FILEEXT/BegalStat.txt","r");
      break; /* optional */
   case 3  :
      pita = fopen("MODUL/FILEEXT/SatpamStat.txt","r");
      break; /* optional */
  
   /* you can have any number of case statements */
   default : /* Optional */
   pita = fopen("MODUL/FILEEXT/KuliStat.txt","r");
}
  ADV();
}

void STARTMOVESE() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

  /* Algoritma */
  pita = fopen("MODUL/FILEEXT/EnemyMoves.txt","r");
  ADV();
}

void STARTMOVESB() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

  /* Algoritma */
  pita = fopen("MODUL/FILEEXT/BossMoves.txt","r");
  ADV();
}

void STARTSKILL(){
    pita = fopen("MODUL/FILEEXT/skill.txt","r");
  ADV();

}

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	pita = fopen("MODUL/FILEEXT/monster.txt","r");
	ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
  IgnoreEnter();
	EOP = (CC == MARK || CC == '\0');
	if (EOP) {
    fclose(pita);
 	}
}

void ADV2() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
      Jika  CC = MARK maka EOP akan menyala (true) */

  /* Algoritma */
  retval2 = fscanf(pita2,"%c",&CC2);
  EOP2 = (CC2 == MARK || CC2 == '\0');
  if (EOP2) {
    fclose(pita2);
  }
}

void ADVSAVEFILES(){
  retval = fscanf(pita,"%c",&CC);
  EOP = (retval == EOF);
  if (EOP)  {
       fclose(pita);
  }
}

void IgnoreEnter()
/* Mengabaikan ENTER */
{
    if (CC == ENTER)
    {
        ADV();
    }
}
