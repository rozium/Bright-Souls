//
//  masinkata.c
//  
//
//  Created by Akmal Fadlurohman on 9/21/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"


boolean EndKata,EndKata2;
Kata CKata,CKata2;

void IgnoreBlankK()
/* Mengabaikan satu atau beberapa BLANK
 I.S. : CC sembarang
 F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC == BLANK) && (CC != MARK))
    {
        ADV();
    }
}

void IgnoreBlankK2()
/* Mengabaikan satu atau beberapa BLANK
 I.S. : CC sembarang
 F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC2 == BLANK) && (CC2 != MARK))
    {
        ADV2();
    }
}

void STARTKATASKILL()
//Menggunakan file eksternal dan type pada skill
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{

    STARTSKILL();
    IgnoreBlankK();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
}


void STARTKATA()
/* I.S. : CC sembarang
 F.S. : EndKata = true, dan CC = MARK;
 atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
 CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlankK();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
 F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
 CC adalah karakter pertama dari kata berikutnya, mungkin MARK
 Jika CC = MARK, EndKata = true.
 Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlankK();
    IgnoreEnter();
    // printf("ADV = %c\n", CC);
    if (CC == MARK || CC == EOF)
    {
        EndKata = true;
    }
    else
    {
        SalinKata();
    }
    //IgnoreBlankK();
    //IgnoreEnter();
}

void ADVKATA2()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
 F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
 CC adalah karakter pertama dari kata berikutnya, mungkin MARK
 Jika CC = MARK, EndKata = true.
 Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlankK2();
    // printf("ADV = %c\n", CC);
    if (CC2 == MARK || CC2 == EOF)
    {
        EndKata2 = true;
    }
    else
    {
        SalinKata2();
    }
    //IgnoreBlankK();
    //IgnoreEnter();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
 I.S. : CC adalah karakter pertama dari kata
 F.S. : CKata berisi kata yang sudah diakuisisi;
 CC = BLANK atau CC = MARK;
 CC adalah karakter sesudah karakter terakhir yang diakuisisi.
 Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    /* Kamus */
    int i = 1;
    int temp = 0;
    boolean over;
    
    /* Algoritma */
    
    over = false;
    CKata.Val = 0;
    for (;;)
    {
        if (i <= NMax)
        {
            if ((CC == '0') || (CC == '1') || (CC == '2') || (CC == '3') || (CC == '4') || (CC =='5') || (CC == '6') || (CC == '7') || (CC == '8') || (CC == '9'))
            {
                temp = CC - '0';
                CKata.Val = (CKata.Val * 10) + temp;

                //!!UNTUK SKILL, MUNGKIN BERPENGARUH KE ENEMY DAN ADT LAIN YANG PAKE MESINKATA
                CKata.TabKata[i] = CC;
            }
            if(CC=='_')
            {
                CKata.TabKata[i] = ' ';
            }
            else
            {
                CKata.TabKata[i] = CC;
            }
        }
        else
        {
            over = true;
        }
        ADV();
        // printf("CC = = (%c)\n",CC);
        if ((CC == MARK) || (CC == BLANK) || (CC == '\0'))
        {
            break;
        }
        else
        {
            i++;
        }
    }
    if (over)
    {
        CKata.Length = NMax;
    }
    else
    {
        CKata.Length = i;
    }
}

void SalinKata2()
/* Mengakuisisi kata, menyimpan dalam CKata
 I.S. : CC adalah karakter pertama dari kata
 F.S. : CKata berisi kata yang sudah diakuisisi;
 CC = BLANK atau CC = MARK;
 CC adalah karakter sesudah karakter terakhir yang diakuisisi.
 Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    /* Kamus */
    int i = 1;
    int temp = 0;
    boolean over;
    
    /* Algoritma */
    
    over = false;
    CKata2.Val = 0;
    for (;;)
    {
        if (i <= NMax)
        {
            if ((CC2 == '0') || (CC2 == '1') || (CC2 == '2') || (CC2 == '3') || (CC2 == '4') || (CC2 =='5') || (CC2 == '6') || (CC2 == '7') || (CC2 == '8') || (CC2 == '9'))
            {
                temp = CC2 - '0';
                CKata2.Val = (CKata2.Val * 10) + temp;

                //!!UNTUK SKILL, MUNGKIN BERPENGARUH KE ENEMY DAN ADT LAIN YANG PAKE MESINKATA
                CKata2.TabKata[i] = CC2;
            }
            if(CC2=='_')
            {
                CKata2.TabKata[i] = ' ';
            }
            else
            {
                CKata2.TabKata[i] = CC2;
            }
        }
        else
        {
            over = true;
        }
        ADV2();
        // printf("CC2 = = (%c)\n",CC2);
        if ((CC2 == MARK) || (CC2 == BLANK) || (CC2 == '\0'))
        {
            break;
        }
        else
        {
            i++;
        }
    }
    if (over)
    {
        CKata2.Length = NMax;
    }
    else
    {
        CKata2.Length = i;
    }
}

boolean IsKataSama(Kata K1, Kata K2)
{
    int j;
    
    if (K1.Length != K2.Length)
    {
        return false;
    }
    else
    {
        j = 1;
        while ((j<K1.Length) && (K1.TabKata[j] == K2.TabKata[j]))
        {
            j++;
        }
        return (K1.TabKata[j] == K2.TabKata[j]);
    }
}

Kata CopyKata(Kata K){
    Kata Kn;
    Kn.Length = K.Length;
    int i;
    for (i = 1 ; i <= K.Length ; i++){
        Kn.TabKata[i] = K.TabKata[i];
    }
    return Kn;
}

char* KataToChar(Kata K){
    char* cc = malloc (sizeof (100));
    int i;
    for (i = 1; i <= K.Length ; i++) {
        cc[i-1] = K.TabKata[i];
    } 
    cc[i-1] = '\0';
    return cc;
}

void PrintKata(Kata K){
    int i;
    for (i = 1 ; i <= K.Length ; i++){
        printf("%c",K.TabKata[i]);
    }    
}