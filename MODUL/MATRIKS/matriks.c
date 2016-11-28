//DAvid T 13515131
/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */
#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}
/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMin) && (i<= BrsMax) && (j >= BrsMin) && (j<= BrsMax));
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return (BrsMin);
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return (KolMin);
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return (NBrsEff(M));
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i >= GetFirstIdxBrs(M)) && (i<= NBrsEff(M)) && (j >=GetFirstIdxBrs(M)) && (j<= NKolEff(M)));
}
ElTypeM GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */

{
    return (Elmt(M, i, i));
}
/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn), MHsl);
    indeks i,j;
    i = GetFirstIdxBrs(MIn);
    j = GetFirstIdxKol(MIn);
    for (; i <= NBrsEff(MIn);i++)
        {
             j = GetFirstIdxKol(MIn);
            for (; j <= NKolEff(MIn);j++)
            {
                Elmt(*MHsl,i,j) = Elmt(MIn,i,j);

            }
        }
}
/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    MATRIKS mt;
    MakeMATRIKS(NB, NK, &mt);
    indeks i,j;
    i = GetFirstIdxBrs(mt);
    j = GetFirstIdxKol(mt);

    for (; i <= NBrsEff(mt);i++)
    {    
        j = GetFirstIdxKol(mt);
        for (; j <= NKolEff(mt);j++)
        {
            Elmt(mt,i,j) = (i+j)%3 +1;

        }
    }
    *M = mt;
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{   indeks i,j;
    int k;
    //Create garis-------

    i = GetFirstIdxBrs(M);
    j = GetFirstIdxKol(M);
    //Create garis horizontal-------
        for (k = 1; k<= NKolEff(M)*6;k++)
        {
            if(k == 1 )
            printf(" ");
            else
              printf("_");
        }
        printf("\n");
        //--------------------

    for (; i <= NBrsEff(M);i++)
    {


        //Baris 1
        for (k = 1; k<= NKolEff(M)*6;k++)
        {
            if(k % 6 == 1)
            printf("|");
            else
              printf(" ");
        }
        printf("|");
        printf("\n");
        //--------------------

        //Baris 2

        j = GetFirstIdxKol(M);
        for (k = 1; k<= NKolEff(M)*6;k++)
        {
            if(k % 6 == 1)
            printf("|");
            else
            if(k%6 ==4)
            {
                printf("%c", Elmt(M, i ,j));
                j++;
            }
            else
              printf(" ");
        }
        printf("|");
        printf("\n");
        //--------------------
//Baris 3
        for (k = 1; k<= NKolEff(M)*6;k++)
        {
            if(k % 6 == 1)
            printf("|");
            else
              printf("_");
        }
        printf("|");
        printf("\n");
        //--------------------

    }
}
/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return NBrsEff(M)*NKolEff(M);
}
