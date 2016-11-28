/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '.'
#define ENTER 10
/* State Mesin */
extern char CC,CC2;
extern boolean EOP,EOP2;

char* SAVES(char * filename);
void STARTFILEW(char * filename);
void STARTFILE(char * filename);
void STARTGAME(int ID); 
void STARTSKILL();
void STARTMOVESE();
void STARTMOVESB();
void STARTSAVEFILES();
void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
void ADV2();
void ADVSAVEFILES();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

void IgnoreEnter();
/* Mengabaikan ENTER */

#endif
