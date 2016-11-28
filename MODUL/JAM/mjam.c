#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "jam.h"


int main()
{
  JAM J1, J2;
    printf("Program ini untuk mengetes ADT JAM\n\n");
    printf("cek jam saat ini\n");
    GetCurrentJAM(&J1);
    TulisJAM(J1);
    int HH, MM, SS;
    printf("\nMasukkan HH MM SS\n");
    scanf("%d %d %d", &HH, &MM, &SS);
    if(IsJAMValid(HH,MM,SS))
    {
        printf("Jam valid\n");
        J2 = MakeJAM(HH,MM,SS);
    }
    else
    {
        printf("Jam tidak valid\n");
    }
    printf("\nJam 1: \n");
    TulisJAM(J1);
    printf("\nJam 2: \n");
    TulisJAM(J2);
    printf("\n\nJam 2 apabila diubah ke detik:\n");
    printf("%ld detik\n",JAMToDetik(J2));
    printf("\nApakah Jam 1 dan Jam 2 sama?\n");
        if(JLT(J1,J2))
        {
            printf("Lebih kecil Jam 1\n");
        }
        if(JGT(J1,J2))
        {
            printf("Lebih besar Jam 1\n");
        }
    printf("\nMasukkan detik: \n");
    long detikk;
    scanf("%ld", &detikk);
    JAM J3;
    printf("\nDetik apabila diubah ke jam:\n");
    J3 = DetikToJAM(detikk);
    TulisJAM(J3);
    printf("\n\nDurasi antara "); TulisJAM(J1);
    printf(" dan ");TulisJAM(J2);
    printf(" adalah \n");
    printf("%ld detik\n",Durasi(J1,J2));
    return 0;
}
