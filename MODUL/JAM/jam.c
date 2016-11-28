// NIM : 13515026
// Nama : Achmad Fahrurrozi Maskur

#include <stdio.h>
#include "jam.h"
#include <math.h> 
#include <time.h>
#include <unistd.h>


void GetCurrentJAM(JAM *Jam){
   time_t rawtime;
   time (&rawtime);
   timeinfo = localtime (&rawtime);
   Hour(*Jam) = jam;
   Minute(*Jam) = menit;
   Second(*Jam) = detik;
}

boolean IsJAMValid (int H, int M, int S)
{
   return (H<24 && H>=0 && M>=0 && M<60 && S>=0 && S<60);
}
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

JAM MakeJAM (int HH, int MM, int SS)
{
   JAM J;  
   Hour(J) = HH;
   Minute(J) = MM;
   Second(J) = SS;
   return J;
}
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
   
void TulisJAM (JAM J)
{
   printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

long JAMToDetik (JAM J)
{
   return (3600*Hour(J) + 60*Minute(J) + Second(J));
}
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

JAM DetikToJAM (long N)
{
   JAM J;
   N = N % 86400;
   Hour(J) = N/3600;
   N = N % 3600;
   Minute(J) = N/60;
   Second(J) = N%60;
   return J;
} 
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

boolean JLT (JAM J1, JAM J2)
{
   return (JAMToDetik(J1)<JAMToDetik(J2));
}
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2)
{
   return (JAMToDetik(J1)>JAMToDetik(J2));
}
/* Mengirimkan true jika J1>J2, false jika tidak */
long Durasi (JAM JAw, JAM JAkh)
{
   long detikAw,detikAkh;
   detikAw = JAMToDetik(JAw);
   detikAkh = JAMToDetik(JAkh);
   if (detikAw > detikAkh) {
      detikAkh += 86400;
   } 
   return (detikAkh - detikAw);
}
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
