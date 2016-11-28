//
//  Header.h
//  
//
//  Created by Akmal Fadlurohman on 11/23/16.
//
//

#ifndef Narasi_h
#define Narasi_h

#define clrscr system("clear")
#include <stdio.h>
#include "../DISPLAY/display.h"

void mahasiswaProlog();
/* Menceritakan kehidupan awal mahasiswa */
void mahasiswaGameOver();
/* Menceritakan epilog jika mahasiswa kalah */
void mahasiswaVictory();
/* Menceritakan epilog jika mahasiswa kalah */

void begalProlog();
/* Menceritakan kehidupan awal begal */
void begalGameOver();
/* Menceritakan epilog jika begal kalah */
void begalVictory();
/* Menceritakan epilog jika begal menang */

void satpamProlog();
/* Menceritakan kehidupan awal satpam */
void satpamGameOver();
/* Menceritakan epilog jika satpam kalah */
void satpamVictory();
/* Menceritakan epilog jika satpam menang */

void kuliProlog();
/* Menceritakan kehidupan awal kuli */
void kuliGameOver();
/* Menceritakan epilog jika kuli kalah */
void kuliVictory();
/* Menceritakan epilog jika kuli menang */

void bossdragon1();
void bossdragon2();
#endif
