#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  addrNode  Tre;
  Tre = AlokNode(Akar);
  if(Tre!= Nil)
  {
    Left(Tre) = L;
    Right(Tre) =R;
  }
  return Tre;
}
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
    *P = Tree(Akar,L,R);
}
/* Manajemen Memory */
addrNode AlokNode (infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  addrNode P;
    P = (addrNode) malloc (sizeof(Node));
    if(P == NULL)
    {
        return Nil;
    }
    else
    {
       Akar(P) = X;
       Left(P) = Nil;
       Right(P) = Nil;
       return P;
    }
}
void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
  free(P);
}
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
  return (P== Nil);
}
boolean IsTreeOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
  if(!IsTreeEmpty(P))
  {
    return ((Left(P) == Nil)&&(Right(P) == Nil));
  }
  else
  {
    return false;
  }
}

void PrintTreeR(BinTree P, int a, int h)
{
   if(IsTreeEmpty(P))
  {
  }
  else
  {
    int i;
    printf("\n");
    for (i = 1; i<= a-h; i++)
    {
      printf(" ");
    }

   PrintKata(NamaSkill(Akar(P)));
   if(HasSkill(Akar(P)))
   {
    printf(": skill terbuka");
   }
   else
   {
    printf(": skill belum terbuka");
   }

    // for (i = 1; i<=a; i++)
    // {
    //   printf(" ");
    // }
    PrintTreeR(Left(P),a+h,h);
    // for (i = 1; i<=a; i++)
    // {
    //   printf(" ");
    // }
    PrintTreeR(Right(P),a+h,h);

  }
}
void PrintTree (BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

//TC 17
{
    if(IsTreeEmpty(P))
  {

  }
  else
  {

   PrintKata(NamaSkill(Akar(P)));
       if(HasSkill(Akar(P)))
   {
    printf(": skill terbuka");
   }
   else
   {
    printf(": skill belum terbuka");
   }
    // for (i = 1; i<=h; i++)
    // {
    //   printf(" ");
    // }
    PrintTreeR(Left(P),2*h,h);
    // for (i = 1; i<=h; i++)
    // {
    //   printf(" ");
    // }
    PrintTreeR(Right(P),2*h,h);

  }
  printf("\n");
}

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if(IsTreeEmpty(P))
    {
      return false;
    }
    else
    {
      if(IsKataSama(NamaSkill(X),NamaSkill(Akar(P))))
      {
        return true;
      }

      else
      {
        return (SearchTree(Left(P),X) || SearchTree(Right(P),X));
      }
    }
}


boolean IsKataSamaString(Kata kata, char nama[30])
{
    boolean sama = true;
    int i =1;
    for (; i<= kata.Length; i++)
    {
      if(kata.TabKata[i] != nama[i-1])
      {
        sama =false;
      }
    }

    return sama;
}

BinTree SearchTreeString (BinTree P, char nama[30])
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if(IsTreeEmpty(P))
    {
      return Nil;
    }
    else
    {
      if(IsKataSamaString(NamaSkill(Akar(P)), nama))
      {
        return P;
      }

      else
      {
        BinTree left =  SearchTreeString(Left(P),nama);
        BinTree right = SearchTreeString(Right(P),nama);
        if (left == Nil && right == Nil)
        {
          return Nil;
        }
        else
        if(left != Nil)
        {
            return left;
        }
        else

          if(right != Nil)
          {
            return right;
          }

        else
        {
          return left;
        }
      }
    }
}


BinTree SearchTreeIndex (BinTree P, int X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if(IsTreeEmpty(P))
    {
      return Nil;
    }
    else
    {
      if(IndexSkill(Akar(P)) ==  X)
      {
        return P;
      }

      else
      {
        BinTree left =  SearchTreeIndex(Left(P),X);
        BinTree right = SearchTreeIndex(Right(P),X);
        if (left == Nil && right == Nil)
        {
          return Nil;
        }
        else
        if(left != Nil)
        {
            return left;
        }
        else

          if(right != Nil)
          {
            return right;
          }

        else
        {
          return left;
        }
      }
    }
}

boolean SearchHasSkill(BinTree P, char nama[30])
/*mengirimkan true jika player punya skill dengan nama nama*/
{
  if(IsTreeEmpty(P))
    {
      return false;
    }
    else
    {
      if(IsKataSamaString(NamaSkill(Akar(P)), nama))
      {
        return HasSkill(Akar(P));
      }

      else
      {
        BinTree left =  SearchTreeString(Left(P),nama);
        BinTree right = SearchTreeString(Right(P),nama);
        if (left != Nil && right != Nil)
        {
          return (SearchHasSkill(Left(P), nama)||SearchHasSkill(Right(P), nama));
        }
        else
        if(left != Nil && right == Nil)
        {
            return SearchHasSkill(Left(P), nama);
        }
        else

          if(right != Nil&& left == Nil)
          {
            return SearchHasSkill(Right(P), nama);
           
          }

        else
        {
          return false;
        }
      }
    }
}


boolean HasTreeIndex(BinTree P, int X)
/*mengirimkan true jika player punya skill dengan nama nama*/
{
  if(IsTreeEmpty(P))
    {
      return false;
    }
    else
    {
      if(IndexSkill(Akar(P)) ==  X)
      {
        return HasSkill(Akar(P));
      }

      else
      {
        BinTree left =  SearchTreeIndex(Left(P),X);
        BinTree right = SearchTreeIndex(Right(P),X);
        if (left != Nil && right != Nil)
        {
          return (HasTreeIndex(Left(P), X)||HasTreeIndex(Right(P), X));
        }
        else
        if(left != Nil && right == Nil)
        {
            return HasTreeIndex(Left(P),X);
        }
        else

          if(right != Nil&& left == Nil)
          {
            return HasTreeIndex(Right(P), X);
           
          }

        else
        {
          return false;
        }
      }
    }
}

BinTree SearchCurrentSkill(BinTree P){

  if(IsKataSamaString(NamaSkill(Akar(P)), "PlayerSkill"))
  {
    if(HasSkill(Akar(Left(P))))
    {

      return SearchCurrentSkill(Left(P));
    }
    else
    {
      return P;
    }
  }
  else
  if(Left(P) != Nil && Right(P) != Nil)
  {
    BinTree Left, Right;
    if(HasSkill(Akar(Left(P)))&& HasSkill(Akar(Right(P))))
    {
        Left = SearchCurrentSkill(Left(P));
        Right = SearchCurrentSkill(Right(P));
        if(LevelT(P, Akar(Left))> LevelT(P, Akar(Right)))
        {
          return Left;
        }
        else
        {
          return Right;
        }
    }
    else
    if(HasSkill(Akar(Left(P))))
    {
        return SearchCurrentSkill(Left(P));


    }
    else
    if(HasSkill(Akar(Right(P))))
    {
        return SearchCurrentSkill(Right(P));
    }
    else
    {
      return P;
    }

  }
  else
  if(Left(P) != Nil)
  {
    if(HasSkill(Akar(Left(P))))
    {

      return SearchCurrentSkill(Left(P));
    }
    else
    {
      return P;
    }

  }
  else
  if(Right(P) != Nil)
  {
    if (HasSkill(Akar(Right(P))))
    {

      return SearchCurrentSkill(Right(P));
    }
    else
    {
      return P;
    }
  }
  else
  {
    return P;
  }

}


int LevelT (BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
{
  if (IsKataSama(NamaSkill(X),NamaSkill(Akar(P)))){
    return 1;
  }
  else
  if (SearchTree(Left(P), X)) {
    return 1+LevelT(Left(P), X);
  }
  else {
    return 1+LevelT(Right(P), X);
  }

}
int Tinggi (BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
  if(IsTreeEmpty(P))
  {
    return 0;
  }
  else
  {
    if(Tinggi(Left(P))> Tinggi(Right(P)))
    {
      return 1 + Tinggi(Left(P));
    }
    else
    {
        return 1 + Tinggi(Right(P));
    }
  }
}
