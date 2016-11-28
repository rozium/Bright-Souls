//
//  enenmy.c
//
//
//  Created by Akmal Fadlurohman on 11/5/16.
//
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"

ENEMY TabEnemy[MaxEnemy +1];
Kata Fairy;
Kata Spider;
Kata Bat;
Kata Skeleton;
Kata JackOLantern;
Kata Devil;
Kata Casper;
Kata Centaur;
Kata Eagle;
Kata Cobra;
Kata Phoenix;
Kata Reaper;
Kata Dragon;

TabMat minimaps;
void LoadEnemy(GRAF graf)//TabMat minimaps)
/* Menload seluruh data enemy dari file eksternal */
{
    int i,j;

    STARTKATA();
    i = 1;
    while ((CC != ENTER) && (i <= 13))
    {
        for (j =1;j<=CKata.Length;j++)
        {
            //printf("%c",CKata.TabKata[j]);
            EnemyName(TabEnemy[i]).TabKata[j] = CKata.TabKata[j];
            //printf("%c",EnemyName(TabEnemy[i]).TabKata[j]);
        }
        EnemyName(TabEnemy[i]).Length = CKata.Length;
        //printf(" ");
        ADVKATA();
        i++;
    }
    i = 1;
    while ((CC != ENTER) && (i <= 13))
    {
        EnemyLvl(TabEnemy[i]) = CKata.Val;
        //printf("%d ",EnemyLvl(TabEnemy[i]));
        i++;;
        ADVKATA();
    }
    i = 1;
    while ((CC != ENTER) && (i <= 13))
    {
        EnemyMaxHP(TabEnemy[i]) = CKata.Val;
        i++;
        ADVKATA();
    }
    i = 1;
    while ((CC != ENTER) && (i <= 13))
    {
        EnemySTR(TabEnemy[i]) = CKata.Val;
        i++;
        ADVKATA();
    }
    i = 1;
    while ((CC != ENTER) && (i <= 13))
    {
        EnemyDEF(TabEnemy[i]) = CKata.Val;
        i++;
        ADVKATA();
    }
    i = 1;
    while ((CC != ENTER) && (i <= 13))
    {
        EnemyExp(TabEnemy[i]) = CKata.Val;
        i++;
        ADVKATA();
    }

 // #############################################

    // i = 1;
    // while ((CC != ENTER) && (i <= 13))
    // {
    //     tempx[i] = CKata.Val;
    //     i++;
    //     ADVKATA();
    // }
    // i = 1;
    // while ((CC != ENTER) && (i <= 13))
    // {
    //     tempy[i] = CKata.Val;
    //     i++;
    //     ADVKATA();
    // }
    // i = 1;
    // for (i = 1;i <= 13;i++)
    // {
    //     X = tempx[i];
    //     Y = tempy[i];
    //     P = MakePOINT(X,Y);
    //     EnemyPos(TabEnemy[i]) = P;
    // }
    // i = 1;
    // while ((CC != MARK) && (i <= 13))
    // {
    //     EnemyMap(TabEnemy[i]) = CKata.Val;
    //     i++;
    //     ADVKATA();
    // }
    int pi;
    int idxe = 1;
    for (pi = 2; pi < MaxArea; pi++)
    {
        //RAndom posisi enemy1
        time_t t;
        srand((unsigned) time(&t));
        int i1 = rand() % (BrsArea - 2) + 2;
        int j1 = rand() % (KolArea - 2) + 2;

        unsigned int vr = 100;
        while(Elmt (Area(minimaps,pi +MaxArea -1),i1,j1) != JALAN )
        {
            vr = vr  +1;
            srand(vr);
            i1 = rand() % (BrsArea - 2) + 2;
            j1 = rand() % (KolArea - 2) + 2;
        }

        POINT EnemyPos1 = MakePOINT(i1,j1);
        //RAndom posisi enemy2
        srand((unsigned) time(&t));
        int i2 = rand() % (BrsArea - 2) + 2;
        int j2 = rand() % (KolArea - 2) + 2;

        vr = 100;
        while(Elmt (Area(minimaps,pi),i2,j2) != JALAN || (i1 == i2 && j1 == j2  ))
        {
            vr = vr  +1;
            srand(vr);
            i2 = rand() % (BrsArea - 2) + 2;
            j2 = rand() % (KolArea - 2) + 2;
        }



        POINT EnemyPos2 = MakePOINT(i2,j2);
        EnemyPos(TabEnemy[idxe]) = EnemyPos1;
        EnemyMap(TabEnemy[idxe]) = pi+MaxArea-1;

        idxe++;

        EnemyPos(TabEnemy[idxe]) = EnemyPos2;
        EnemyMap(TabEnemy[idxe]) = pi;

        idxe++;

    }
    //Assign posisi untuk Bos
    boolean found = false;
    boolean placed = false;
    adrTitik PT;
    PT = FirstTitik(SearchGraf(graf, MaxArea, &found));

    while (!placed && PT != Nil)
    {
        if(ConnectTo(PT) == Nil)
        {
            EnemyPos(TabEnemy[MaxEnemy]) = Titik(PT);
            EnemyMap(TabEnemy[MaxEnemy]) = MaxArea;
            placed = true;
        }
        else
        {
            PT = NextTitik(PT);
        }
    }
}

// ###############################################

ENEMY GetEnemy(PLAYERPOS P, int *x)
/* Menghasilkan enemy yang terletak di pos */
{

    ENEMY E;
    int i,b = 0;
    boolean stop;

    stop = false;
    i = 1;

    while ((!stop) && (i <= 13))
    {
        if (EnemyMap(TabEnemy[i]) == Map(P) && EQ(EnemyPos(TabEnemy[i]),Pos(P)))
        {
            stop = true;
        } else {
            i++;
        }
        if (b == 20) stop = true;
    }
    *x = i;
    EnemyName(E) = EnemyName(TabEnemy[i]);
    EnemyLvl(E) = EnemyLvl(TabEnemy[i]);
    EnemyMaxHP(E) = EnemyMaxHP(TabEnemy[i]);
    EnemyHP(E) = EnemyMaxHP(TabEnemy[i]);
    EnemySTR(E) = EnemySTR(TabEnemy[i]);
    EnemyDEF(E) = EnemyDEF(TabEnemy[i]);
    EnemyExp(E) = EnemyExp(TabEnemy[i]);
    EnemyPos(E) = EnemyPos(TabEnemy[i]);
    EnemyMap(E) = EnemyMap(TabEnemy[i]);

    return E;
}

void GetBoss(ENEMY *E) {
        EnemyName(*E) = EnemyName(TabEnemy[13]);
        EnemyLvl(*E) = EnemyLvl(TabEnemy[13]);
        EnemyMaxHP(*E) = EnemyMaxHP(TabEnemy[13]);
        EnemyHP(*E) = EnemyMaxHP(TabEnemy[13]);
        EnemySTR(*E) = EnemySTR(TabEnemy[13]);
        EnemyDEF(*E) = EnemyDEF(TabEnemy[13]);
        EnemyExp(*E) = EnemyExp(TabEnemy[13]);
        EnemyPos(*E) = EnemyPos(TabEnemy[13]);
        EnemyMap(*E) = EnemyMap(TabEnemy[13]);
}

boolean IsDeadE(ENEMY E)
/* True jika enemi mati, hp = 0 */
{
    return (EnemyHP(E) <= 0);
}

boolean IsBoss(ENEMY E)
/* True jika enemy adalah boss, diperkisa dengan Name(Enemy) = Boss Name */
{
    return (IsKataSama(EnemyName(E),Dragon));
}
void IncreaseHPE(ENEMY * E, int X)
/* Menambah current HP dari enemy sebanyak X */
/* Mungkin jadi full */
{
    EnemyHP(*E) += X;
    if (EnemyHP(*E) > EnemyMaxHP(*E)) {
        EnemyHP(*E) = EnemyMaxHP(*E);
    }
}

void DecreaseHPE(ENEMY * E, int X)
//Mengurangi current HP dari enemy sebanyak X
//Mungkin jadi  kosong
{
    EnemyHP(*E) -= X;
    if (EnemyHP(*E) < 0) {
        EnemyHP(*E) = 0;
    }
}

void PrintEnemy(ENEMY E, int x, int y)
/* Print interface enemy APPEARS! dari enemy */
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
    if (IsKataSama(EnemyName(E),Fairy)) { fairy(x, y); }
    else if (IsKataSama(EnemyName(E),Spider)) { spider(x, y); }
    else if (IsKataSama(EnemyName(E),Bat)) { bat(x, y); }
    else if (IsKataSama(EnemyName(E),Skeleton)) { skeleton(x, y); }
    else if (IsKataSama(EnemyName(E),JackOLantern)) { jacklantern(x, y); }
    else if (IsKataSama(EnemyName(E),Devil)) { devil(x, y); }
    else if (IsKataSama(EnemyName(E),Casper)) { casper(x, y); }
    else if (IsKataSama(EnemyName(E),Centaur)) { centaur(x, y); }
    else if (IsKataSama(EnemyName(E),Eagle)) { eagle(x, y); }
    else if (IsKataSama(EnemyName(E),Cobra)) { cobra(x, y); }
    else if (IsKataSama(EnemyName(E),Phoenix)) { phoenix(x, y); }
    else if (IsKataSama(EnemyName(E),Reaper)) { reaper(x, y); }
    else if (IsKataSama(EnemyName(E),Dragon)) { bossdragon2(x, y); }
}

// ┌─┬─┐
// │ │ │
// ├─┼─┤
// └─┴─┘

void PrintStatE(ENEMY E, int x){

    int i,y = 2;
    Kata Nama20;
    Nama20 = CopyKata(EnemyName(E));
    i = Nama20.Length;
    for (i = Nama20.Length + 1 ; i <= 20 ; i++)
        Nama20.TabKata[i] = ' ';
    Nama20.Length = 20;

    gotoXY(x++,y);printf(" ┌───────────────────────┬────────┐");
    gotoXY(x++,y);printf(" │ "COLOR_WHITE);PrintKata(Nama20);printf(COLOR_RESET"  │"COLOR_YELLOW" LVL: %d "COLOR_RESET"│",EnemyLvl(E));
    gotoXY(x++,y);printf(" ├───────────────────┬───┴─────┬──┴───────┐");
    gotoXY(x++,y);printf(" │ "COLOR_GREEN"HP: %3d "COLOR_RESET"│ "COLOR_RED"STR: %2d"COLOR_RESET" │ "COLOR_BLUE"DEF: %2d "COLOR_RESET"│ "COLOR_CYAN"EXP: %3d "COLOR_RESET"│",EnemyMaxHP(E),EnemySTR(E),EnemyDEF(E),EnemyExp(E));
    gotoXY(x++,y);printf(" └─────────┴─────────┴─────────┴──────────┘");
}

void DeleteEnemyPos(ENEMY *E, PLAYERPOS pos, int i)
/* Menghapus enemy dari map */
{

    int X = 0;
    int Y = 0;
    POINT P;
    P = MakePOINT(X,Y);
    EnemyPos(*E) = P;
    EnemyPos(TabEnemy[i]) = P;
}
