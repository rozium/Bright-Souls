#include "map.h"
#include <stdio.h>
#include <time.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void CreateEmptyMAP(TabMat *M)
//membuat MAP baru
{
  int n;

  for(n=1;n<=MaxArea*2 +1;n++) {
    MakeMATRIKS(BrsArea,KolArea,&Area(*M,n));
  }
}

void SearchJALANAtas (MATRIKS M, indeks *i, indeks *j)
//Mencari karakter JALAN pada tepian area atas
{
  boolean found = false;
  int m = GetFirstIdxBrs(M);
  int n = GetFirstIdxKol(M);
  while ((n<=GetLastIdxKol(M))&&(!found)) {
    if(Elmt(M,m,n)==JALAN) {
      found = true;
    }
    else {
      n++;
    }
  }

  if(found) {
    *i = m;
    *j = n;
  }
  else {
    *i = 0;
    *j = 0;
  }
}

void SearchJALANKanan (MATRIKS M, indeks *i, indeks *j)
//Mencari karakter JALAN pada tepian area kanan
{
  boolean found = false;
  int m = GetFirstIdxBrs(M);
  int n = GetLastIdxKol(M);
  while ((m<=GetLastIdxBrs(M))&&(!found)) {
    if(Elmt(M,m,n)==JALAN) {
      found = true;
    }
    else {
      m++;
    }
  }

  if(found) {
    *i = m;
    *j = n;
  }
  else {
    *i = 0;
    *j = 0;
  }
}

void SearchJALANBawah (MATRIKS M, indeks *i, indeks *j)
//Mencari karakter JALAN pada tepian area bawah
{
  boolean found = false;
  int m = GetLastIdxBrs(M);
  int n = GetFirstIdxKol(M);
  while ((n<=GetLastIdxKol(M))&&(!found)) {
    if(Elmt(M,m,n)==JALAN) {
      found = true;
    }
    else {
      n++;
    }
  }

  if(found) {
    *i = m;
    *j = n;
  }
  else {
    *i = 0;
    *j = 0;
  }
}

void SearchJALANKiri (MATRIKS M, indeks *i, indeks *j)
//Mencari karakter JALAN pada tepian area kiri
{
  boolean found = false;
  int m = GetFirstIdxBrs(M);
  int n = GetFirstIdxKol(M);
  while ((m<=GetLastIdxBrs(M))&&(!found)) {
    if(Elmt(M,m,n)==JALAN) {
      found = true;
    }
    else {
      m++;
    }
  }

  if(found) {
    *i = m;
    *j = n;
  }
  else {
    *i = 0;
    *j = 0;
  }
}

void RandomDrunkard(MATRIKS *M, int entpos, int *expos, int *branchcount, TabMat *MapHasil)
//prosedur untuk me-random isi area penyusun map
{
  // printf("adsadada:%d", *branchcount);
  //untuk switch
  boolean x = false;
  boolean y = false;
  int branchrand = 3;
  if(entpos == -1)
  {
      entpos = rand() % 4;
      x = true;
  }
  else if(*expos == -1){
    y = true;
     entpos = (entpos +2) % 4;
  }
  else
  {
      entpos = (entpos +2) % 4;

      //Randomasi cabang
      // printf("%d\n", *branchcount);
      if(*branchcount < MaxArea)
      {
        branchrand = rand() % 1 +1;
      }

  }
  int brsaw, kolaw;
  switch(entpos)
  {
  case 0:
      brsaw = 1;
      kolaw = rand() % (NKolEff(*M)-4) +3;
      if(!x)
       Elmt(*M,brsaw,kolaw) = JALAN;
      brsaw++;
      if(IsIdxValid(kolaw, brsaw))
          Elmt(*M,brsaw,kolaw) = JALAN;
      break;
  case 2:
      brsaw = GetLastIdxBrs(*M);
      kolaw = rand() %(NKolEff(*M)-4) +3;
      if(!x)
      Elmt(*M,brsaw,kolaw) = JALAN;
      brsaw--;
      if(IsIdxValid(brsaw,kolaw))
          Elmt(*M,brsaw,kolaw) = JALAN;
      break;
  case 1:
      kolaw = 1;
      brsaw = rand() % (NBrsEff(*M)-4) +3;
      if(!x)
      Elmt(*M,brsaw,kolaw) = JALAN;
      kolaw ++;
      if(IsIdxValid(brsaw,kolaw))
          Elmt(*M,brsaw,kolaw) = JALAN;
      break;
  case 3:
      kolaw = GetLastIdxKol(*M);
      brsaw = rand() % (NBrsEff(*M) -4) +3;
      if(!x)
      Elmt(*M,brsaw,kolaw) = JALAN;
       kolaw --;
      if(IsIdxValid(brsaw,kolaw))
          Elmt(*M,brsaw,kolaw) = JALAN;
      break;
  }
  *expos = rand() % 4;
  while(*expos == entpos)
  {
      *expos = rand() % 4;
  }
  int brsak, kolak;
  switch(*expos)
  {
  case 0:
      brsak = 1;
      kolak = rand() % (NKolEff(*M)-4) +3;
      if(!y)
      Elmt(*M,brsak,kolak) = JALAN;
      brsak++;
      if(IsIdxValid(brsak,kolak))
          Elmt(*M,brsak,kolak) = JALAN;
      break;
  case 2:
      brsak = GetLastIdxBrs(*M);
      kolak = rand() %(NKolEff(*M)-4) +3;
      if(!y)
      Elmt(*M,brsak,kolak) = JALAN;
      brsak--;
      if(IsIdxValid(brsak,kolak))
          Elmt(*M,brsak,kolak) = JALAN;
      break;
  case 1:
      kolak = 1;
      brsak = rand() % (NBrsEff(*M)-4) +3;
      if(!y)
      Elmt(*M,brsak,kolak) = JALAN;
      kolak++;
      if(IsIdxValid(brsak,kolak))
          Elmt(*M,brsak,kolak) = JALAN;
      break;
  case 3:
      kolak = GetLastIdxKol(*M);
      brsak = rand() % (NBrsEff(*M) -4) +3;
      if(!y)
      Elmt(*M,brsak,kolak) = JALAN;
      kolak--;
      if(IsIdxValid(brsak,kolak))
          Elmt(*M,brsak,kolak) = JALAN;
      break;
  }

  //Peletakkan pintu cabang
  int branchpos;
  int kolbr;
  int brsbr;
  if(branchrand == 1)
  {
      branchpos = rand() % 4;
      while(branchpos == entpos || branchpos == *expos)
      {
          branchpos = rand() % 4;
      }

      switch(branchpos)
      {
      case 0:
          brsbr = 1;
          kolbr = rand() % (NKolEff(*M)-4) +3;
          Elmt(*M,brsbr,kolbr) = JALAN;
          brsbr++;
          if(IsIdxValid(brsbr,kolbr))
              Elmt(*M,brsbr,kolbr) = JALAN;
          break;
      case 2:
          brsbr = GetLastIdxBrs(*M);
          kolbr = rand() %(NKolEff(*M)-4) +3;
          Elmt(*M,brsbr,kolbr) = JALAN;
          brsbr--;
          if(IsIdxValid(brsbr,kolbr))
              Elmt(*M,brsbr,kolbr) = JALAN;
          break;
      case 1:
          kolbr = 1;
          brsbr = rand() % (NBrsEff(*M)-4) +3;
          Elmt(*M,brsbr,kolbr) = JALAN;
          kolbr++;
          if(IsIdxValid(brsbr,kolbr))
              Elmt(*M,brsbr,kolbr) = JALAN;
          break;
      case 3:
          kolbr = GetLastIdxKol(*M);
          brsbr = rand() % (NBrsEff(*M) -4) +3;
          Elmt(*M,brsbr,kolbr) = JALAN;
          kolbr--;
          if(IsIdxValid(brsbr,kolbr))
              Elmt(*M,brsbr,kolbr) = JALAN;
          break;
      }

      //Penggenerasi Map Baru Cabang----------------------------
      MATRIKS M;

      MakeMATRIKS(BrsArea,KolArea,&M);
      int i = 1;
      int j;
      for (; i <= GetLastIdxBrs(M);i++)
      {
          j = 1;
          for (; j <= GetLastIdxKol(M);j++)
          {
              Elmt(M,i,j) = POHON;

          }
      }
      *branchcount = *branchcount +1;
      int exb = -1;

      RandomDrunkard(&M, branchpos, &exb, branchcount, MapHasil);
      // printf("point2\n");

      // printf("brbrrr%d\n", (*branchcount ));

      CopyMATRIKS (M, &Area(*MapHasil, (MaxArea + *branchcount)));
      // printf("point4");


     // --------------------------------------------------------------------

  }

  int n = 0;
  int mintile = 10;
  boolean isexit = false;
  boolean conbrach = false;
    int tempkol, tempbrs;
    int dir;
  while (!isexit || n < mintile || (!conbrach && branchrand ==1))
  {
      dir = rand() % 4 +1;

      tempkol = kolaw;
      tempbrs = brsaw;
      switch (dir)
      {
      case 1:
          tempbrs = brsaw -1;
          if(/*Elmt(*M, tempbrs, kolaw) != JALAN &&*/tempbrs != GetLastIdxBrs(*M) && tempbrs !=1)
          {

              brsaw = tempbrs;
              Elmt(*M, brsaw,kolaw) = JALAN;

              n++;
          }
          break;
      case 2:
          tempkol = kolaw +1;
          if(/*Elmt(*M, brsaw,tempkol) != JALAN &&*/tempkol != GetLastIdxKol(*M) &&tempkol !=1)
          {

              kolaw = tempkol;
              Elmt(*M, brsaw,kolaw) = JALAN;
              n++;

          }
          break;
      case 3:
          tempbrs = brsaw +1;
           if(/*Elmt(*M, tempbrs, kolaw) != JALAN &&*/tempbrs != GetLastIdxBrs(*M)&&tempbrs !=1)
          {


              brsaw = tempbrs;
              Elmt(*M, brsaw,kolaw) = JALAN;
              n++;
          }
          break;
      case 4:
          tempkol = kolaw -1;
          if(/*Elmt(*M, brsaw,tempkol) != JALAN &&*/tempkol != GetLastIdxKol(*M)&&tempkol !=1)
          {
              kolaw = tempkol;

              Elmt(*M, brsaw,kolaw) = JALAN;
              n++;
          }
          break;
      }

      if( brsaw == brsak &&  kolaw == kolak)
      {
          isexit = true;
      }
      if(brsaw == brsbr && kolaw == kolbr)
      {
        conbrach = true;
      }
  }
}

void RandomMap(TabMat *MapHasil)
//membuat area-area yang menyusun map dengan isi random, setiap area berukuran ixj
{
  MATRIKS M;

  MakeMATRIKS(BrsArea,KolArea,&M);
  int i = 1;
   int j;
  for (; i <= GetLastIdxBrs(M);i++)
  {
      j = 1;
      for (; j <= GetLastIdxKol(M);j++)
      {
          Elmt(M,i,j) = POHON;

      }
  }
 time_t t;

 int k;
 /* Intializes random number generator */
 srand((unsigned) time(&t));
 int in = -1;
 int ex;
 int brcount = 0;
 CreateEmptyMAP(MapHasil);
   for( k = 1 ; k<=MaxArea ; k++ )
   {
     i = 1;
     for (; i <= GetLastIdxBrs(M);i++)
      {
      j = 1;
      for (; j <= GetLastIdxKol(M);j++)
      {
          Elmt(M,i,j) = POHON;

      }
      }
      ex = 0;
      RandomDrunkard(&M, in, &ex, &brcount, MapHasil);
      // printf("sasas\n");
      in = ex;
      CopyMATRIKS (M, &Area(*MapHasil,k));
    }
    // printf("BranchCoun: %d",brcount);
    BranchCount(*MapHasil) = brcount;
    // printf("point3\n");
}
void connectMap(TabMat M,  GRAF *G)
//menyatukan area-area yang telah terbentuk menjadi satu map dengan menggunakan GRAF,
//*G adalah GRAF yg terbentuk
{
  int i;
  indeks m,n;

  CreateEmptyGraf(G);
  char dir;
  int br = 1;
  for(i = 1; i<= BranchCount(M);i++)
  {
    adrGraf PG;
    InsGraf(G, MaxArea + i, &PG);
    SearchJALANAtas(Area(M,MaxArea + i),&m,&n);
    if ((m != 0)&&(n != 0)) {
        InsTitik(PG, 'U', MakePOINT(m,n),Nil);
    }
     SearchJALANKanan(Area(M,MaxArea + i),&m,&n);
     if ((m != 0)&&(n != 0)) {
      // InsTitik(SearchGraf(*G,i), 'R', MakePOINT(m,n));
     InsTitik(PG, 'R', MakePOINT(m,n),Nil);
     }
     SearchJALANBawah(Area(M,MaxArea + i),&m,&n);
     if ((m != 0)&&(n != 0)) {
        //InsTitik(SearchGraf(*G,i), 'D', MakePOINT(m,n));
        InsTitik(PG, 'D', MakePOINT(m,n),Nil);
     }
     SearchJALANKiri(Area(M,MaxArea + i),&m,&n);
     if ((m != 0)&&(n != 0)) {
    //   InsTitik(SearchGraf(*G,i), 'L', MakePOINT(m,n));
      InsTitik(PG, 'L', MakePOINT(m,n),Nil);
     }
  }
  for(i=1;i<=MaxArea;i++) {
    adrGraf PG;
    InsGraf(G, i, &PG);
    SearchJALANAtas(Area(M,i),&m,&n);
    if ((m != 0)&&(n != 0)) {
        InsTitik(PG, 'U', MakePOINT(m,n),Nil);
    }
     SearchJALANKanan(Area(M,i),&m,&n);
     if ((m != 0)&&(n != 0)) {
      // InsTitik(SearchGraf(*G,i), 'R', MakePOINT(m,n));
     InsTitik(PG, 'R', MakePOINT(m,n),Nil);
     }
     SearchJALANBawah(Area(M,i),&m,&n);
     if ((m != 0)&&(n != 0)) {
        //InsTitik(SearchGraf(*G,i), 'D', MakePOINT(m,n));
        InsTitik(PG, 'D', MakePOINT(m,n),Nil);
     }
     SearchJALANKiri(Area(M,i),&m,&n);
     if ((m != 0)&&(n != 0)) {
    //   InsTitik(SearchGraf(*G,i), 'L', MakePOINT(m,n));
      InsTitik(PG, 'L', MakePOINT(m,n),Nil);
     }
     // printf("bracll: %d, br: %d\n",BranchCount(M),br);

     //Membuat koneksi busur
     //mulai dari indeks map = 1
     if( i == 1)
     {
        dir = Dir(FirstTitik(PG));
        // printf("%d %c \n",i,dir);
     }
     else
     {
        //Connect Main Line
        char dirtemp;
        dirtemp = TitikMatch(dir);
        boolean found = false;
        adrGraf ConPG;
        ConPG = SearchGraf(*G, i-1, &found);
        if(found){
        //  printf("AUUUUUUUUUttt");
          ConnectTo(SearchTitik(*G, i, dirtemp)) = ConPG;;
          //  printf("AUUUUUUUUUeee");
            ConnectTo(SearchTitik(*G, i -1, dir)) = PG;
           // printf("AUUUUUUUUUqqq");
        }

      // printf("-a");

        adrTitik PT;
        PT = FirstTitik(PG);
          // printf("point11\n");
        boolean brachplaced = false;
        while (PT != Nil)
        {


          if(ConnectTo(PT) == Nil)
          {
            if(br <= BranchCount(M))
            {
                if(SearchTitik(*G, MaxArea + br, TitikMatch(Dir(PT))) !=Nil)
                {
                  // printf("point99\n");
                  boolean founds = false;
                  adrGraf brPG =  SearchGraf(*G, MaxArea + br, &founds);
                  if(found){
                    ConnectTo(PT) = brPG;
                    ConnectTo(SearchTitik(*G, MaxArea + br, TitikMatch(Dir(PT)))) = PG;
                    brachplaced = true;
                  }
                  else
                  {
                    // printf("notfound\n");
                  }

                }
                else
                {
                  dir = Dir(PT);
                  // printf("Placed\n");
                }
            }
            else
            {
              dir = Dir(PT);
                  // printf("Placed\n");

            }

          }
          // printf("point12\n");

              PT = NextTitik(PT);


        }
        if(brachplaced)
        {
          br++;
         // printf("point13\n");
        }
        // printf("%d %c \n",i,dir);
     }

  }
  // printf("point14\n");
}

char TitikMatch(char dir)

//menghasilkan titik yang berlawanan dengan dir
{
      switch (dir)
      {
           case 'U': dir = 'D';
           break;

           case 'R': dir = 'L';
           break;

           case 'D': dir = 'U';
           break;
           case 'L': dir = 'R';
           break;


       }
       return dir;
}

void GenerateMap(GRAF * bigmap, TabMat * minimaps, PLAYERPOS * pos)
{
    RandomMap(minimaps);
    // printf("Point1");
    // for(;sfs <= MaxArea +BranchCount(*minimaps);sfs++)
    // {
    //   TulisMATRIKS(Area(*minimaps, sfs));
    // }
  connectMap(*minimaps, bigmap);
  // assign posiisi player
  Map(*pos) = 1;
  time_t t;
  srand((unsigned) time(&t));
  int i = rand() % (BrsArea - 2) + 2;
  int j = rand() % (KolArea - 2) + 2;

  unsigned int vr = 100;
  while(Elmt (Area(*minimaps,1),i,j) != JALAN )
  {
     vr = vr  +1;
     srand(vr);
     i = rand() % (BrsArea - 2) + 2;
     j = rand() % (KolArea - 2) + 2;

  }
  Pos(*pos) = MakePOINT(i,j);
  //assign medicine
  int mi;
  for (mi = 2; mi <= MaxArea + BranchCount(*minimaps); ++mi)
  {
     i = rand() % (BrsArea - 2) + 2;
      j = rand() % (KolArea - 2) + 2;

    vr = 100;
     while(Elmt (Area(*minimaps,mi),i,j) != JALAN )
     {

       vr = vr  +1;
       srand(vr);
       i = rand() % (BrsArea - 2) + 2;
       j = rand() % (KolArea - 2) + 2;


   }
  Elmt (Area(*minimaps,mi),i,j) = 'M';
  }

}
//Menggenerate Map dengan prosedur yang ada, bigmap dan minimaps berisi map yang digenerate dan
//pos berisi posisi awal player pada map
//Mengupdate posisi dari enemy pada TabEnemy sesuai dengan posisinya dimap

void PrintMap(TabMat minimaps, PLAYERPOS pos)
//Print Map dimana player berada sesuai dengan spesifikasi dan memberikan space untuk input user
{
  MATRIKS M = Area(minimaps, Map(pos));

    int id;
    for(id = 1; id <= MaxEnemy ; id++)
    {
      if(EnemyMap(TabEnemy[id]) == Map(pos))
      {
        if (Map(pos) == MaxArea) {
          Elmt(M, Absis(EnemyPos(TabEnemy[id])), Ordinat(EnemyPos(TabEnemy[id]))) = 'B';
        } else if(IsBoss(TabEnemy[id])) {
          // printf("boosss\n");
          Elmt(M, Absis(EnemyPos(TabEnemy[id])), Ordinat(EnemyPos(TabEnemy[id]))) = 'B';
        } else {
           Elmt(M, Absis(EnemyPos(TabEnemy[id])), Ordinat(EnemyPos(TabEnemy[id]))) = 'E';
        }
      }
    }
    Elmt(M, Absis(Pos(pos)), Ordinat(Pos(pos))) = 'P';

    indeks i,j;
    int k;
    //Create garis-------

    i = GetFirstIdxBrs(M);
    j = GetFirstIdxKol(M);
    //Create garis horizontal-------
    gotoXY(7,3);
        for (k = 1; k<= NKolEff(M)*4;k++)
        {
            if(k == 1 ){
                printf("┌");
                printf("─");
            }
            else if (k == NKolEff(M)*4)
                printf("┐");
            else if(k % 4 == 0)
                printf("┬");

            else
                printf("─");
        }
        // printf("\n");
        //--------------------

    for (; i <= NBrsEff(M);i++)
    {
        gotoXY(6+i*2,3);
        // printf("um\n");
        // //Baris 1
        // for (k = 1; k<= NKolEff(M)*4;k++)
        // {
        //     if(k % 4 == 1)
        //     printf("│");
        //     else
        //       printf(" ");
        // }
        // printf("│");
        // printf("\n");
        // //--------------------

        //Baris 2
        j = GetFirstIdxKol(M);
        for (k = 1; k<= NKolEff(M)*4;k++)
        {


            if(k % 4 == 1)
            printf("│");
            else
            if(k%4 ==3)
            {

                //PENGEPRINTAN ELEMEN
                if (Elmt(M,i,j) == 'P'){
                  printf(COLOR_YELLOW"P"COLOR_RESET);
                } else if (Elmt(M,i,j) == 'E'){
                  printf(COLOR_RED"E"COLOR_RESET);
                } else if (Elmt(M,i,j) == 'M'){
                  printf(COLOR_BLUE"M"COLOR_RESET);
                } else if (Elmt(M,i,j) == 'B'){
                  printf(COLOR_GREEN"B"COLOR_RESET);
                } else if (Elmt(M,i,j) == '#'){
                  printf(COLOR_BLACK"█"COLOR_RESET);
                } else if (Elmt(M,i,j) == 'S'){
                  printf(COLOR_YELLOW"S"COLOR_RESET);
                }
                else {
                  printf(" ");
                }





                j++;
            }
            else
              printf(" ");
        }
        printf("│");
        // printf("\n");

        //Baris 3

        // j = GetFirstIdxKol(M);
        // for (k = 1; k<= NKolEff(M)*4;k++)
        // {
        //     if(k % 4 == 1)
        //     printf("│");
        //     else

        //       printf(" ");
        // }
        // printf("│");
        // printf("\n");
        //--------------------
//Baris 4
        if(i != NBrsEff(M)){
          gotoXY(i*2+7,3);
          for (k = 1; k<= NKolEff(M)*4;k++)
          {
            // gotoXY(6+k,3);
              if(k == 1 ){
                  printf("├");
                  printf("─");
              }
              else if (k == NKolEff(M)*4)
                  printf("┤");
              else if(k % 4 == 0)
                  printf("┼");

              else
                  printf("─");
          }
        }

        //--------------------

 //Create garis Penutup------

        //--------------------

// ┌─┬─┐
// │ │ │
// ├─┼─┤
// │ │ │
// └─┴─┘

    }
    gotoXY(BrsArea*3-3,3);
     for (k = 1; k<= NKolEff(M)*4;k++)
        {
            if(k == 1 ){
                printf("└");
                printf("─");
            }
            else if (k == NKolEff(M)*4)
                printf("┘");
            else if(k % 4 == 0)
                printf("┴");

            else
                printf("─");
        }
}

char CheckTile(PLAYERPOS pos, TabMat minmap)
{
    boolean foundEnemy = false;
    int id;
    for(id = 1; id <= MaxEnemy ; id++)
    {
      if(EnemyMap(TabEnemy[id]) == Map(pos))
      {
          if(Absis(Pos(pos)) == Absis(EnemyPos(TabEnemy[id])) && Ordinat(Pos(pos)) == Ordinat(EnemyPos(TabEnemy[id])))
          {
            foundEnemy = true;
          }
      }

    }
    if(foundEnemy)
    {
      return 'E';
    }
    else
    {
      return Elmt(Area(minmap, Map(pos)), Absis(Pos(pos)), Ordinat(Pos(pos))) ;
    }

}
//menghasilkan apa jenis Tile yang diinjak player, apakah E, M, atau kosong ' '

void DelM(PLAYERPOS pos, TabMat *minmap)
//menghapus 'M' setelah Heal Player
{
  Elmt(Area(*minmap, Map(pos)),Absis(Pos(pos)),Ordinat(Pos(pos))) = JALAN;
}

void DelS(PLAYERPOS pos, TabMat *minmap)
//menghapus 'M' setelah Heal Player
{
  Elmt(Area(*minmap, Map(pos)),Absis(Pos(pos)),Ordinat(Pos(pos))) = JALAN;
}

void GenerateSkillOnMap(BinTree playerskill, TabMat * minimaps)
//Men-generate skill pada MAP dan menghasilkan posisi-posisi pada map
{
  IsiTabSkillPos(playerskill); //Pos belum terisi
  time_t t;
  srand((unsigned) time(&t));
  //assign skill
  int mi, i, j, vr;
  int idx = 0;
  for (mi = MaxArea*2 - 4; mi <= MaxArea*2 - 1; mi++)
  {
     i = rand() % (BrsArea - 2) + 2;
     j = rand() % (KolArea - 2) + 2;

    vr = 100;
     while(Elmt (Area(*minimaps,mi),i,j) != JALAN )
     {
       vr = vr  +1;
       srand(vr);
       i = rand() % (BrsArea - 2) + 2;
       j = rand() % (KolArea - 2) + 2;
     }
    idx ++;
    Elmt (Area(*minimaps,mi),i,j) = 'S';
    SkillPos(TabSkill[idx]) = MakePOINT(i,j);
  }
}

// ┌─┬─┐
// │ │ │
// ├─┼─┤
// │ │ │
// └─┴─┘
