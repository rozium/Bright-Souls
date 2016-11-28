#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '
#define BLANK1 '\n'
#define MARK '.'
typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
	int Val;
	int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata,EndKata2;
extern Kata CKata,CKata2;

void STARTFILE();

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
 I.S. : CC sembarang
 F.S. : CC ≠ BLANK atau CC = MARK */

void IgnoreBlank2();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void ADVKATA2();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
 I.S. : CC adalah karakter pertama dari kata
 F.S. : CKata berisi kata yang sudah diakuisisi;
 CC = BLANK atau CC = MARK;
 CC adalah karakter sesudah karakter terakhir yang diakuisisi.
 Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void SalinKata2();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsKataSama(Kata K1,Kata K2);
/* Menghasilkan true jika Kata K1 sama dengan Kata K2 */

char* KataToChar(Kata K);
//mengubah Kata mendjadi char

Kata CopyKata(Kata K);
//Menghassilkan Kata yang sama (mencopy kata)

void PrintKata(Kata K);
//Mencetak input Kata yangv diberrikan
//I.S : Kata K terdefinisi 
//F.S : Kata K ditampilkan pada layar

void STARTKATASKILL();
//Menggunakan file eksternal dan type pada skill
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

#endif

