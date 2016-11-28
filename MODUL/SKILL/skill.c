#include "skill.h"
#include <stdio.h>
#include <stdlib.h>
#define word_size 15
Kata CKata;
SkillPos TabSkill[5];
//Include ADT lain yang diperlukan
void InitializeSkill(BinTree *Skill)
{
  int k;
	BinTree T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18;
	infotype Akar;
	STARTKATASKILL();


	HasSkill(Akar) = false;
	NamaSkill(Akar) = CopyKata(CKata);
  ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k = 18;
  IndexSkill(Akar) = k;

	T18 = Tree(Akar, Nil, Nil);


	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
  ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
	k--;
  IndexSkill(Akar) = k;

  T17 = Tree(Akar, Nil, Nil);


	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T16 = Tree(Akar, T18, Nil);

	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T15 = Tree(Akar, T16, T17);


	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  
  IndexSkill(Akar) = k;
  k = 11;
  IndexSkill(Akar) = k;
  T11 = Tree(Akar, Nil, Nil);
	k = 12;
  IndexSkill(Akar) = k;
  T12 = Tree(Akar, Nil, Nil);
	k = 13;
  IndexSkill(Akar) = k;
  T13 = Tree(Akar, Nil, Nil);
	k = 14;
  IndexSkill(Akar) = k;
  T14 = Tree(Akar, Nil, Nil);
  k = 11;

	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T10 = Tree(Akar, T14, Nil);


	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T9 = Tree(Akar, T13, Nil);

	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T8 = Tree(Akar, T12, Nil);

	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T7 = Tree(Akar, T11, Nil);

	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T6 = Tree(Akar, T9, T10);

	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T5 = Tree(Akar, T7, T8);

	ADVKATA();
  NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T4 = Tree(Akar, T6, Nil);

	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T3 = Tree(Akar, T5, Nil);

	ADVKATA();
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T2 = Tree(Akar, T3, T4);

	ADVKATA();
	HasSkill(Akar) = true;
	NamaSkill(Akar) = CopyKata(CKata);
	ADVKATA();
  Deskripsi(Akar) = CopyKata(CKata);
  k--;
  IndexSkill(Akar) = k;

  T1 = Tree(Akar, T2,T15);

	*Skill = T1;
	}


void SkillMenuR(BinTree P, int a, int h, int level,boolean id, boolean idd, boolean iddd, boolean idddd, boolean iddddd)
{
  if(IsTreeEmpty(P))
  {
  }
  else
  {
    int i;
    printf("\n     ");
    for(i = 1; i <=a-2*h ;i++)
      {
        if(i %h == 1 && ((i/(h) == 0 && idd)|| (i/(h) == 1 && iddd)||(i/(h) == 3 && idddd && iddddd)))
        printf("│");
      else
        printf(" ");
      };

    if(id)
    {

    printf("├");
    }
    else
    {
       printf("└");
    }

    for (; i<= a-h-1; i++)
    {
      printf("─");
    }

   if(HasSkill(Akar(P)))
   {
      printf("Lv%d ", level);PrintKata(NamaSkill(Akar(P)));
   }
   else
   {
      printf("Lv%d ???", level);
   }

   if(Right(P) == Nil)
   {
   // }
     if(level ==1)
    {
       iddd =false;
    }
    if(level ==1)
    {
       idddd =false;
    }
    if(level ==3)
    {
       iddddd =false;
     }

    SkillMenuR(Left(P),a+h,h,level+1,false,idd, iddd,idddd, iddddd);
   }
   else
   {
    SkillMenuR(Left(P),a+h,h,level+1,true,idd,iddd,idddd, iddddd);
   }
   if(level ==1)
    {
       iddd =false;
    }
    if(level ==2)
    {
       idddd =false;
    }
    if(level ==3)
    {
       iddddd =false;
     }
    SkillMenuR(Right(P),a+h,h, level+1,false,idd,iddd,idddd, iddddd);

  }
}
void SkillMenu (BinTree P, int h)
{
  if(IsTreeEmpty(P))
  {

  }
  else
  {
    PrintKata(NamaSkill(Akar(P)));
    if(HasSkill(Akar(P)))
    {
    }
    else
    {
    }
    SkillMenuR(Left(P),2*h,h, 1,true, true,true,true,true);
    SkillMenuR(Right(P),2*h,h,1,false,false,true,true,true);
  }
  printf("\n");
}

//Tambahkan prosedur lain
void IsiTabSkillPos(BinTree Skill)
//Mengisi TabSkillPos dengan posisi pada map
{
	//Nama skill
	SkillName(TabSkill[1]) = NamaSkill(Akar(Right(Skill)));
	SkillName(TabSkill[2]) = NamaSkill(Akar(Left(Right(Skill))));
	SkillName(TabSkill[3]) = NamaSkill(Akar(Right(Right(Skill))));
	SkillName(TabSkill[4]) = NamaSkill(Akar(Left(Left(Right(Skill)))));

	//Indeks Map
	SkillIdxMap(TabSkill[1]) = MaxArea*2 - 4;
	SkillIdxMap(TabSkill[2]) = MaxArea*2 - 3;
	SkillIdxMap(TabSkill[3]) = MaxArea*2 - 2;
	SkillIdxMap(TabSkill[4]) = MaxArea*2 - 1;
}


//Tambahkan prosedur lain
void PrintLvlUp(BinTree *Skill){
  clrscr;
  setWin(31,79);
  gotoXY(1,1);
  CetakBingkai(31,79);
  int x = 5, y = 12;
  char pil;
  gotoXY(x++,y);printf(COLOR_RED"  __    _____ _____ _____ __     "COLOR_WHITE"  _____ _____ "COLOR_YELLOW"   _"COLOR_RESET);
  gotoXY(x++,y);printf(COLOR_RED" |  |  |   __|  |  |   __|  |    "COLOR_WHITE" |  |  |  _  |"COLOR_YELLOW"  | |"COLOR_RESET);
  gotoXY(x++,y);printf(COLOR_RED" |  |__|   __|  |  |   __|  |__  "COLOR_WHITE" |  |  |   __|"COLOR_YELLOW"  |_|"COLOR_RESET);
  gotoXY(x++,y);printf(COLOR_RED" |_____|_____|\\___/|_____|_____|"COLOR_WHITE"  |_____|__|  "COLOR_YELLOW"   |_|"COLOR_RESET);
  gotoXY(13,2); printf(COLOR_CYAN); for (int A=1;A<=77;A++) printf("\u2501"); printf(COLOR_RESET);
  BinTree CurrentSkill = SearchCurrentSkill(*Skill);
  // if (CurrentSkill != Nil)
  //   printf("Berhasil\n");
  // else
  //   printf("NIL\n");
  // // PrintTree(CurrentSkill,3);
  x = 15;
  gotoXY(x++,3);printf("Pilih nomor skill yang mau diunlock :");

  int i = 1;
  if (Left(CurrentSkill) != Nil)
  {
    gotoXY(x++,3);printf("%d. ",i); PrintKata(NamaSkill(Akar(Left(CurrentSkill)))); printf(": ");PrintKata(Deskripsi(Akar(Left(CurrentSkill))));
  }
  if (Right(CurrentSkill)!= Nil && (CurrentSkill != *Skill))
  {
    i++;
    gotoXY(x++,3);printf("%d. ",i); PrintKata(NamaSkill(Akar(Right(CurrentSkill)))); printf(": ");PrintKata(Deskripsi(Akar(Right(CurrentSkill))));
  }

  SHOWKURSOR;
  do {
    gotoXY(x+1,4);printf("          ");
    gotoXY(x+1,3);printf("> ");scanf("%c",&pil);
    if (pil-'0' < 1 || pil-'0' > i) {
      gotoXY(15,50);printf(COLOR_RED"Nomor tidak ditemukan!"COLOR_RESET);
    }
  } while (pil-'0' < 1 || pil-'0' > i);
  HIDEKURSOR;
  gotoXY(15,50);printf("                      ");
  switch (pil) {
    case '1' :

      gotoXY(27,3);printf("Skill ");PrintKata(NamaSkill(Akar(Left(CurrentSkill))));printf(" Terbuka!");
      HasSkill(Akar(Left(CurrentSkill))) = true;
      break;
    case '2' :
      gotoXY(27,3);printf("Skill ");PrintKata(NamaSkill(Akar(Right(CurrentSkill))));printf(" Terbuka!");
      HasSkill(Akar(Right(CurrentSkill))) = true;
      break;
  }
  getchar();
  gotoXY(30,55);printf("Press ENTER to continue");
	char c;
	while (1) {
		initTermios();
		c = getch();
		resetTermios();
		if (c == 10) break;
	}
}



// ┌─┬─┐
// │ │ │
// ├─┼─┤
// │ │ │
// └─┴─┘
