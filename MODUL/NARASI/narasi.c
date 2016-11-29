
#define slpt 25000
#include <stdio.h>
#include "narasi.h"

void ibumahasiswa(){
    printf(COLOR_GREEN);
    ibu(8,5);
    printf(COLOR_RESET);
    mahasiswa1(10,93);
}

void mahasiswaibu(){
    printf(COLOR_RESET);
    ibu(8,5);
    printf(COLOR_BLUE);
    mahasiswa1(10,93);    
}

void clear(){
    gotoXY(1,1);
    setWin(32,120);
    gotoXY(1,1);
    CetakBingkai(32,120);    
}

void mahasiswaProlog()
/* Menceritakan kehidupan awal mahasiswa */
{
    clear();
    int x,y = 4;
    HIDEKURSOR;
    printf(COLOR_WHITE);
    gotoXY(7,y);SlowPrint("Setiap hari, telefon si mahasiswa selalu berdering.",slpt);
    gotoXY(9,y);SlowPrint("Seperti biasa, orang tuanya selalu berusaha menghubunginya.",slpt);
    gotoXY(11,y);SlowPrint("Pada awalnya, si mahasiswa selalu menjawab setiap telefon dari orang tuanya.",slpt);
    gotoXY(13,y);SlowPrint("Lambat laun, seiring berjalannya waktu, si mahasiswa mulai bosan dan malas menjawab telefon orang tuanya.",slpt);
    gotoXY(15,y);SlowPrint("Pesan singkat dari orang tuanya juga tidak pernah ia baca hingga selesai.",slpt);
    gotoXY(17,y);SlowPrint("Percakapannya dengan orang tuanya hanya sekedar.... ",slpt);
    printf(COLOR_RESET);
    

    pressENTER();
    
    gotoXY(7,y);printf("                                                                                                               ");
    gotoXY(9,y);printf("                                                                                                               ");
    gotoXY(11,y);printf("                                                                                                               ");
    gotoXY(13,y);printf("                                                                                                               ");
    gotoXY(15,y);printf("                                                                                                               ");
    gotoXY(17,y);printf("                                                                                                               ");

    dialog();
    gotoXY(3,2);printf("+--------------------------------------------------------------------------------------------------------------------+");

    ibumahasiswa();
    gotoXY(23,6);
    printf(COLOR_GREEN" Halo nak.                                     ");
    pressENTER();
    
    mahasiswaibu();
    gotoXY(23,6);
    printf(COLOR_BLUE" Halo bu.                                        ");
    pressENTER();
    
    ibumahasiswa();
    gotoXY(23,6);
    printf(COLOR_GREEN" Gimana kabarnya nak?                             ");
    pressENTER();
    
    mahasiswaibu();
    gotoXY(23,6);
    printf(COLOR_BLUE" Alhamdulillah baik-baik saja bu.                   ");
    pressENTER();
    
    ibumahasiswa();
    gotoXY(23,6);
    printf(COLOR_GREEN" Kuliahnya lancar-lancar sajakan?                      ");
    pressENTER();
    
    mahasiswaibu();
    gotoXY(23,6);
    printf(COLOR_BLUE" Iya. Sudah ya bu, aku mau lagi mau rapat nih.");
    pressENTER();
    
    clear();

    x = 4;
    printf(COLOR_WHITE);
    gotoXY(x++,y);SlowPrint("Semenjak menjadi malas dan bosan, percakapan si mahasiswa dengan orang tuanya hanya sebatas menanyakan kabar",slpt);
    gotoXY(x++,y);SlowPrint("dan kemudian si mahasiswa mengakhirinya di tengah-tengah dengan berbagai alasan seperti sibuk, ",slpt);
    gotoXY(x++,y);SlowPrint("sedang di jalan, sedang bersama teman, dan lain-lain.",slpt);
    x++;
    pressENTER();
    
    gotoXY(x++,y);SlowPrint("Si mahasiswa mulai terlena dengan lengkapnya fasilitas yang tersedia di kota tempatnya merantau.",slpt);
    gotoXY(x++,y);SlowPrint("Ia juga mulai terobsesi untuk mendapatkan indeks prestasi yang sempurna hingga benar-benar malas ",slpt);
    gotoXY(x++,y);SlowPrint("dan tidak mau mengangkat telefon dari kedua orang tuanya.",slpt);
    pressENTER();
    x++;
    
    gotoXY(x++,y);SlowPrint("Saat masa akhir perkuliahan, indeks prestasinya pun telah keluar. Ia sangat bahagia ketika mengetahui ",slpt);
    gotoXY(x++,y);SlowPrint("IP nya bulat sempurna 4.00.",slpt);
    pressENTER();
    x++;
    
    gotoXY(x++,y);SlowPrint("Ia kemudian mencoba menghubungi kedua orang tuanya untuk memberitahu mereka hasil jerih payahnya selama ini, ",slpt);
    gotoXY(x++,y);SlowPrint("namun kedua orang tuanya tidak ada yang menjawab.",slpt);
    gotoXY(x++,y);SlowPrint("Pada hari itu, ia mencoba menghubungi orang tuanya lebih dari tiga kali, semua dengan hasil yang nihil.",slpt);
    gotoXY(x++,y);SlowPrint("Hari esoknya, si mahasiswa mencoba menghubungi orang tuanya lagi tapi tetap tidak diangkat. ",slpt);
    gotoXY(x++,y);SlowPrint("Hal ini berlangsung lebih dari seminggu lamanya.",slpt);
    pressENTER();
    x++;
    
    gotoXY(x++,y);SlowPrint("Si mahasiswa kemudian memutuskan untuk segera pulang karena ia khawatir dengan keluarganya.",slpt);
    gotoXY(x++,y);SlowPrint("Saat tiba di kampung halamannya, ia terkejut mendapati keluarganya sudah tidak menempati rumah dulunya.",slpt);
    gotoXY(x++,y);SlowPrint("Ia kemudian membuka dan membaca semua pesan singkat yang masuk dari orang tuanya dengan seksama.",slpt);
    pressENTER();
    x++;
    gotoXY(x++,y);SlowPrint("Setelah selesai, si mahasiswa baru mengetahui bahwa keluarganya telah pindah ke luar kota karena ayahnya dimutasi.",slpt);
    gotoXY(x++,y);SlowPrint("Ia kemudian menimbang-nimbang apakah ia akan pergi ke tempat keluarganya sekarang atau kembali ke perantauan.",slpt);
    gotoXY(x++,y);SlowPrint("Karena masih banyak kegiatan di perantauan, si mahasiswa memilih untuk kembali ke perantauan.",slpt);
    pressENTER();
    x++;
    gotoXY(x++,y);SlowPrint("Dalam perjalanan, bis yang ditumpanginya mengalami kecelakaan dan masuk ke jurang.",slpt);
    gotoXY(x++,y);SlowPrint("Saat tersadar, ia berada pada sebuah gua yang gelap dan sunyi.",slpt);
    printf(COLOR_RESET);
    pressENTER();

    clear();    

    dialog();
    gotoXY(3,2);printf("+--------------------------------------------------------------------------------------------------------------------+");

    mahasiswa(6,3);
    gotoXY(23,6);printf(COLOR_RESET" Dimana ini? Kenapa aku bisa di sini?             ");
    pressENTER();
    
    gotoXY(23,6);printf(" Perasaan aku sedang duduk di bis.              ");
    pressENTER();
    
    clear();

    printf(COLOR_WHITE);
    gotoXY(10,6);SlowPrint("Tiba-tiba muncul seekor naga besar di hadapan si mahasiswa.             ",slpt);
    gotoXY(28,80);SlowPrint("Si mahasiswa terkejut bukan main.    ",slpt);
    printf(COLOR_RESET);
    pressENTER();

    clear();

    dialog();
    gotoXY(3,2);printf("+--------------------------------------------------------------------------------------------------------------------+");

    mahasiswa(6,3);
    dragon(5,80);
    gotoXY(23,6);printf(COLOR_RESET" Mahkluk apa ini? Dimana sebenarnya aku?                                 ");
    pressENTER();
    
    gotoXY(23,6);printf(RED" Kamu berada pada alam setengah hidup setengah mati dan aku adalah penjaga alam tersebut.");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Mengapa aku bisa disini?                                                                     ");
    pressENTER(); 
    
    gotoXY(23,6);printf(RED" Bis yang kamu tumpangi untuk kembali ke perantauan mengalami kecelekaan dan masuk ke jurang.");
    gotoXY(24,6);printf(" Di dunia nyata, tubuhmu sedang dalam kondisi sekarat.");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Lalu kenapa aku tidak mati?                                                                      ");
    gotoXY(24,6);printf("                                                                           ");
    pressENTER();
    
    gotoXY(23,6);printf(RED" Seseorang yang masuk ke duniaku berarti ia telah diberi kesempatan untuk hidup kembali.");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Lalu bagaimana caranya agar aku dapat kembali ke duniaku?                               ");
    pressENTER();
    
    gotoXY(23,6);printf(RED" Kalahkan aku dan kau akan kembali dengan selamat ke duniamu.");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Kalau aku gagal mengalahkanmu?                                       ");
    pressENTER();
    
    gotoXY(23,6);printf(RED" Maka kau akan terperangkap selamanya di dunia ini.");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Sepertinya lebih enak hidup di dunia ini. Aku tidak harus susah-susah kuliah, ");
    gotoXY(24,6);printf(" hidup sendiri di perantauan, dan memikirkan harus hidup seperti apa.");
    pressENTER();
    
    gotoXY(23,6);printf(RED" Bukankah kau sendiri yang dulu berniat untuk kuliah dengan serius dan membahagiakan orang tuamu?");
    gotoXY(24,6);printf(RED"                                                                           ");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Hah dulu aku naif. Dulu mereka setiap hari menghubungiku hanya untuk menanyakan hal-hal yang tidak penting.");
    gotoXY(24,6);printf(" Giliran sekarang aku dapat IP 4.00 mereka tidak pernah menjawab telefonku.");
    pressENTER();
    
    gotoXY(23,6);printf(RED" Bukankah itu kesalahanmu sendiri? Selama ini siapa yang sebenarnya sulit untuk dihubungi?                  ");
    gotoXY(24,6);printf(RED" Mereka selalu bersedia meluangkan waktu di sela kesibukan mereka hanya untuk menanyaimu “hal-hal ga penting”.");
    gotoXY(25,6);printf(RED" Mereka berusaha mengabarimu kejadian yang terjadi pada keluargamu hingga mereka lelah dan bosan karena tidak ");
    gotoXY(26,6);printf(RED" pernah kau tanggapi dengan serius.");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Salahku katamu? Merekalah yang tidak mengerti keadaanku. Hidup di perantauan susah.        ");
    gotoXY(24,6);printf(" Kuliah susah. Ngatur keuangan susah. Belum lagi kalo barangku ada yang hilang. Semua ini salahku katamu!!?   ");
    gotoXY(25,6);printf("                                                                                                              ");
    gotoXY(26,6);printf("                                                                                                              ");    
    pressENTER();
    
    gotoXY(23,6);printf(RED" Iya, semua itu salahmu. Tidakkah kau bayangkan betapa sulit mereka merawat dan membesarkanmu ");
    gotoXY(24,6);printf(RED" dari bayi hingga besar? Tidakkah kau pikirkan betapa sulit mereka mencari uang untuk memberimu makan       ");
    gotoXY(25,6);printf(RED" dan membiayai kuliahmu!!? Kapan terakhir kau ingat melihat muka kedua orang tuamu???");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Cukup!!! Kembalikan aku ke duniaku sekarang juga. Masih banyak yang harus kerjakan dan selesaikan.");
    gotoXY(24,6);printf("                                                                                                         ");
    gotoXY(25,6);printf("                                                                                                         ");
    pressENTER();
    
    gotoXY(23,6);printf(RED" Yang mereka inginkan darimu bukanlah IP sempurnamu. Bukan hartamu ketika kau sukses nanti.        ");
    gotoXY(24,6);printf(RED" Mereka hanya ingin sebagian kecil dari waktumu.");
    pressENTER();
    
    gotoXY(23,6);printf(COLOR_RESET" Diam!!! Tahu apa yang kamu tentang aku? Jangan harap aku akan mendengarkan semua perkataanmu.");
    gotoXY(24,6);printf(COLOR_RESET"                                                       ");
    pressENTER();
    
    gotoXY(23,6);printf(RED" Dasar keras kepala!!!                                                                             ");
    pressENTER();
    
    clear();

    x = 23;

    printf(COLOR_WHITE);
    gotoXY(x++,y);SlowPrint(" Dengan amarah, sang naga mengayunkan ekornya mengenai si mahasiswa hingga ia terlempar jauh membentur dinding.",slpt);
    
    x = 30;
    gotoXY(x++,y);SlowPrint(" Sang naga kemudian pergi dan meninggalkan si mahasiswa malang yang merintih kesakitan.",slpt);
    pressENTER();
    
    clear();

    dialog();
    gotoXY(3,2);printf("+--------------------------------------------------------------------------------------------------------------------+");

    mahasiswa(6,3);
    x = 23;
    gotoXY(x++,y);SlowPrint(COLOR_RESET" Apa salahku? Kenapa semua jadi begini!!??",slpt);
    pressENTER();
    
    gotoXY(x++,y);SlowPrint(" Masih banyak kegiatan yang harus kulakukan. Aku masih harus melakukan persiapan untuk semester baru.",slpt);
    pressENTER();
    
    clear();

    x = 4;
    printf(COLOR_WHITE);
    gotoXY(x++,y);SlowPrint(" Sekesal apapun si mahasiswa, tidak ada satupun orang yang mendengarnya.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint(" Sekeras apapun ia berteriak tidak ada tanggapan yang di terimanya. ",slpt);
    x++;
    gotoXY(x++,y);SlowPrint(" Ia kemudian mulai memikirkan perasaan kedua orang tuanya.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint(" Mungkin selama ini, hal inilah yang mereka rasakan. Mereka berbicara dengan anak mereka sendiri ",slpt);
    x++;
    gotoXY(x++,y);SlowPrint(" seolah sedang berbicara dengan sebuah batu, Tak ada jawaban dan tanggapan.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint(" Saat terpikirkan hal tersebut, si mahasiswa tak kuasa menahan air matanya.",slpt);
    pressENTER();
    
    x += 4;
    printf(COLOR_BLUE);
    gotoXY(x++,y);SlowPrint(" Maafkan aku pah, mah. Aku selalu pelit untuk meluangkan waktu bagi kalian.",slpt);
    pressENTER();
    
    gotoXY(x++,y);SlowPrint(" Aku janji akan selalu mengakat telephone kalian dan mendengar setiap perkataan kalian.",slpt);
    pressENTER();
    
    x += 4;
    printf(COLOR_WHITE);
    gotoXY(x++,y);SlowPrint(" Setelah menenangkan diri, si mahasiswa mulai dapat berpikir rasional.",slpt);
    gotoXY(x++,y);SlowPrint(" Ia kemudian menyimpulkan bahwa satu-satunya cara agar ia dapat keluar ",slpt);
    gotoXY(x++,y);SlowPrint(" dari tempat ini adalah dengan mengalahan sang naga.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint(" Ia kemudian membulatkan tekad untuk melalui segala rintangan dan ",slpt);
    gotoXY(x++,y);SlowPrint(" mengalahkan sang naga agar ia dapat kembali bertemu dengan kedua orang tuanya.",slpt);
    printf(COLOR_RESET);
    pressENTER();
    
}
void mahasiswaGameOver()
/* Menceritakan epilog jika mahasiswa kalah */
{
    clear();
    dialog();
    gotoXY(3,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    mahasiswa(6,3);
    printf(COLOR_BLUE);
    gotoXY(23,4);SlowPrint(" Sepertinya aku tidak akan bisa bertemu dengan orang tuaku lagi.... ... .. .",slpt*1.5);
    printf(COLOR_RESET);
    pressENTER();
}
void mahasiswaVictory()
/* Menceritakan epilog jika mahasiswa kalah */
{
    clear();
    int x,y = 4;
    HIDEKURSOR;
    x = 4;

    printf(COLOR_WHITE);
    gotoXY(x++,y);SlowPrint("Saat terbangun, si mahasiwa merasa familiar dengan kondisi ruangan tempatnya tersadar.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint("Ia kemudian berusaha mengumpulkan semua nyawanya secara utuh.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint("Ia sedang terbaring pada kasur tempat ia biasa tidur sebelum merantau.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint("Ia berada pada kamar yang biasa ia tempati saat masih kecil hingga tumbuh dewasa.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint("Ia kemudian membuka pintu kamarnya.",slpt);
    x = 30;
    gotoXY(x++,y);SlowPrint("Semua orang yang hadir di ruang keluarga terkejut ketika melihat si mahasiswa keluar dari kamarnya.",slpt);
    pressENTER();
    
    clear();
    dialog();
    gotoXY(3,2);printf("+--------------------------------------------------------------------------------------------------------------------+");

    printf(COLOR_GREEN);
    ibu(8,5);
    printf(COLOR_RESET);
    ayah(11,25);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_GREEN" Nak, nak kamu masih ingat sama ibu kan?"COLOR_RESET);
    pressENTER();
    
    printf(COLOR_RESET);
    ibu(8,5);
    mahasiswa1(10,80);    
    printf(COLOR_YELLOW);
    ayah(11,25);
    gotoXY(23,4);printf(COLOR_YELLOW" Kamu masih ingat dengan semua yang di sini kan?"COLOR_RESET);
    pressENTER();
    
    printf(COLOR_RESET);
    ibu(8,5);
    ayah(11,25);
    printf(COLOR_BLUE);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_BLUE" Ibu, Ayah.                                                 ");
    pressENTER();

    clear();    

    x = 8;
    printf(COLOR_WHITE);
    gotoXY(x++,y);SlowPrint("Tanpa basa-basi, si mahasiswa memeluk erat kedua orang tuanya.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint("Ia kemudian meminta maaf kepada mereka karena tidak pernah menjawab telephone dari mereka.",slpt);
    x++;
    gotoXY(x++,y);SlowPrint("Ia juga meminta maaf karena tidak pernah berusaha meluangkan waktu untuk mereka.",slpt);
    pressENTER();
    
    clear();
    dialog();
    gotoXY(3,2);printf("+--------------------------------------------------------------------------------------------------------------------+");

    printf(COLOR_RESET);
    ibu(8,5);
    ayah(11,25);
    printf(COLOR_BLUE);
    mahasiswa1(10,80);
    gotoXY(23,4);printf(COLOR_BLUE"     Apa yang sebenarnya terjadi? Mengapa aku bisa disini?");
    pressENTER();
    
    printf(COLOR_RESET);
    ibu(8,5);
    printf(COLOR_YELLOW);
    ayah(11,25);
    printf(COLOR_RESET);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_YELLOW" Kamu mengalami kecelakaan saat sedang dalam perjalanan menuju tempat perantauanmu.");
    gotoXY(24,4);printf(COLOR_YELLOW" Bis yang kamu tumpangi masuk ke jurang.");
    gotoXY(25,4);printf(COLOR_YELLOW" Setelah berhasil dievakuasi, kamu dinyatakan dalam kondisi koma oleh dokter.");
    pressENTER();
    
    printf(COLOR_RESET);
    ibu(8,5);
    ayah(11,25);
    printf(COLOR_BLUE);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_BLUE" Koma?? Sudah berapa lama aku koma yah?                                               ");
    gotoXY(24,4);printf(COLOR_BLUE"                                                                                      ");
    gotoXY(25,4);printf(COLOR_BLUE"                                                                                      ");
    pressENTER();
    
    printf(COLOR_GREEN);
    ibu(8,5);
    printf(COLOR_RESET);
    ayah(11,25);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_GREEN" Hampir 2 bulan                                  ");
    pressENTER();
    
    printf(COLOR_RESET);
    ibu(8,5);
    ayah(11,25);
    printf(COLOR_BLUE);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_BLUE" Astaga. Banyak hal terlewatkan olehku.");
    pressENTER();
    
    printf(COLOR_RESET);
    ibu(8,5);
    printf(COLOR_YELLOW);
    ayah(11,25);
    printf(COLOR_RESET);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_YELLOW" Ayah sudah mengajukan surat izin cuti semester ini untukmu.");
    gotoXY(24,4);printf(" Ayah khawatir kamu tidak dapat mengikuti kuliah karena koma yang kau alami.");
    pressENTER();
    
    printf(COLOR_RESET);
    ibu(8,5);
    ayah(11,25);
    printf(COLOR_BLUE);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_BLUE" Terimakasih ibu, ayah sudah mau repot-repot mengurus izinku.");
    gotoXY(24,4);printf(COLOR_BLUE"                                                                            ");
    pressENTER();
    
    
    printf(COLOR_GREEN);
    ibu(8,5);
    printf(COLOR_RESET);
    ayah(11,25);
    mahasiswa1(10,80);    
    gotoXY(23,4);printf(COLOR_GREEN" Iya nak.                                                             ");
    pressENTER();
    
    clear();

    x = 6;
    printf(COLOR_WHITE);
    gotoXY(x++,y);SlowPrint(" Sejak saat itu, ",slpt);
    x++;x++;
    gotoXY(x++,y);SlowPrint(" si mahasiswa selalu berusaha menjawab setiap telfon",slpt);
    x++;
    gotoXY(x++,y);SlowPrint(" dari kedua orangtuanya dan menjaga komunikasi yang baik dengan keluarganya.",slpt);
    printf(COLOR_RESET);
    pressENTER();
    
}

void begalProlog()
/* Menceritakan kehidupan awal begal */
{
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    int x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Di sebuah tempat kumuh di pinggiran kota di pagi hari.");
     pressENTER();
     clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);

    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_GREEN"Ibu Begal : Nak kamu dari mana? Kok jam 5 subut baru pulang?");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Ahh berisik aku capek mau tidur.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_GREEN"Ibu Begal : Ibu ga masalah kamu pulang sepagi ini asalkan rezeki yang kamu hasilkan halal.");
    pressENTER();
    x++;
    clear();
dialog();
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Ahh yang penting aku bisa makan enak.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_GREEN"Ibu Begal : Ini ibu sudah siapkan sarapan buat kamu, dimakan ya.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Kok lauknya cuma sayur asem?Kan udah sering aku kasih duit buat belanja.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_GREEN"Ibu Begal : Makanlah nak.Kamu butuh energi untuk kembali bekerja lagi nanti malam.");
    pressENTER();
    x++;
      clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);

    printf(COLOR_RED"Begal     : Ahhh ga mau!!!Aku capek mau tidur aja.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_GREEN"Ibu Begal : Sini ibu suapin kalau kamu capek.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal     : Berisik!!!Aku udah gede.Pokoknya nanti siang waktu aku bangun aku mau makan daging sapi(Sambil membanting pintu kamar).");
    pressENTER();
    x++;
      clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);

    printf(COLOR_WHITE"Sambil bersedih, sang ibu meletakkan kembali sepiring nasi yang ia sodorkan ke anaknya.\nKemudian ia mencari tempat tabungan uangnya, dan kemudian memecahkannya.\nIa dengan hati-hatinya menghitung uang yang telah ia tabung tersebut sambil bergumam.");
     pressENTER();
     clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);

    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_GREEN"Ibu Begal : Alhamdulillah sepertinya cukup buat beli daging 1/4 kilo.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_WHITE"Ibu Begal itu kemudian segera bergegas ke pasar.\nDi pasar, ia membeli berbagai macam bahan yang dibutuhkan untuk membuat gepuk daging sapi.");
     pressENTER();
     clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);printf("Setelah selesai, wanita tua itu kemudian pulang sambil tersenyum puas.");
    pressENTER();
    x++;
      clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);

    printf(COLOR_GREEN"Ibu Begal : Anakku pasti senang akhirnya bisa makan daging.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_WHITE"Saat dalam perjalanan, tiba-tiba sebuah motor mendekati wanita tua itu dari belakang dengan cepat.\nIa mengayunkan sebuah golok ke arah tubuh wanita malang itu.\nDalam sekejap, wanita tua itu tergeletak bersimbah darah.\nOrang di sekililingnya sontak panik dengan kejadian tersebut.");
     pressENTER();
     clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);printf(COLOR_WHITE"Salah satu tetangga yang melihat kejadian itu dengan cepat berlari ke rumah si begal.\nTetangga tersebut memberitahu bahwa ibu dari si begal telah di begal.\nSi begal yang diberitahu kabar tersebut dengan cepat berlari menuju lokasi kejadian.\nSaat menyebrang jalan, karena dalam kondisi panik, ia tidak memperhatikan kodisi jalanan.\nDari arah samping, ia di tabrak oleh sebuah mobil yang sedang melaju dangan kencang.\nDari kejauhan, ia mendengar suara ambulan mendekat.");
  pressENTER();
     clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    clear();
    begal1(7,3);
    ibu(7,80);
    x=23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Saat tersadar, si begal berada pada tempat yang tidak ia kenali.\nTempat tersebut sangat gelap dan dingin.\nTiba-tiba muncul seekor naga besar di hadapannya.");
    pressENTER();
    x++;
      clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    dragon(5,80);
    x=23;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Gila kenapa ada naga disini?");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_BLUE"Naga  : Kamu berada pada alam setengah hidup setengah mati dan aku adalah penjaganya.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Kenapa aku bisa ada disini?");
    pressENTER();
    x++;
      clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    dragon(5,80);
    x=23;
    gotoXY(x,6);

    printf(COLOR_BLUE"Naga  : Kamu sedang dalam kondisi sekarat di duniamu setelah tertabrak mobil.Jika kamu bisa mengalahkanku, kamu bisa hidup kembali.");
    pressENTER();
    x++;x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Enakan juga mati.Ga usah susah-susah mikirin macem-macem.");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_BLUE"Naga  : Apakah kamu tidak ingat dengan ibumu?");
    pressENTER();
    x++;
      clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    dragon(5,80);
    x=23;
    gotoXY(x,6);

    printf(COLOR_WHITE"Naga : Ia rela menggunakan uang tabungannya demi kamu bisa makan daging, dan sekarang ia sedang dalam kondisi sekarat setelah di begal oleh salah satu temanmu.");
    pressENTER();
    x++;x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Ah masa bodo!!!");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_WHITE"Mendengar perkataan si begal, Naga tersebut murka.\nIa kemudian mengibaskan ekornya yang besar mengenai si begal hingga si begal terpental jauh.\nNaga tersebut pergi kemudian meninggalkan si begal yang terluka parah dan merintih kesakitan.\nSekujur tubuhnya bersimbah darah yang biasa ia lihat ketika sedang membegal tagetnya.\nTak ada perkataan yang data terucap dari mulutnya.Dalam rintihan, ia menangis dan memanggil nama ibunya.");
     pressENTER();
     clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    dragon(5,80);
    x=23;
    gotoXY(x,6);

    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Ibu, ibu sini bu.Badanku sakit semua.Aku ga bisa gerak.");
    pressENTER();
    x++;
      clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    dragon(5,80);
    x=23;
    gotoXY(x,6);

    printf(COLOR_WHITE"Namun ia tersadar, ibunya tak ada di sampingnya.\nIa kemudian mengingat kejadian tadi pagi saat ia menolak masakan sayur asem ibunya.\nDalam benaknya, terngiang kenikmatan rasa sayur asem buatan ibunya.\nIa teringat masa kecilnya saat ibunya sering membawakan bekal sekolah sayur asem yang enak.");
     pressENTER();
     clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    dragon(5,80);
    x=23;
    gotoXY(x,6);

    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Ahhh ini semua salahku.Ibuku sekarat aku pun sekarat.Sekarang apa yang harus aku lakukan?");
    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_WHITE"Dalam hening, ia merenung dan berusaha mengumpulkan tekadnya.\nSetelah bulat tekadnya, dengan tubuh penuh luka ia bangkit dan berhenti merenungi apa yang terjadi kepadanya.");
     pressENTER();
     clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    dragon(5,80);
    x=23;
    gotoXY(x,6);

    pressENTER();
    x++;
    gotoXY(x,6);

    printf(COLOR_RED"Begal : Aku akan mengalahkanmu wahai naga dan aku akan kembali bertemu dengan ibuku dengan selamat!!!"COLOR_RESET);
    pressENTER();
    x++;
    gotoXY(x,6);

}
void begalGameOver()
/* Menceritakan epilog jika begal kalah */
{
      clear();
    dialog();
        gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
      gotoXY(23,6);
    printf(COLOR_RED"Begal : Tidak, aku masih ingin hidup dan bertemu dengan ibuku lagi."COLOR_RESET);
    pressENTER();
    
}
void begalVictory()
/* Menceritakan epilog jika begal menang */
{
    clear();
    dialog();
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    int x = 23;
    gotoXY(x,6);
    printf(COLOR_RED"Begal : Akhirnya aku bisa mengalahkanmu.Aku dapat kembali bertemu dengan ibuku.");
    pressENTER();
        clear();
    dialog();
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x = 23;
     gotoXY(x,6);
    printf(COLOR_WHITE"Setelah melewati pintu gua, ia kemudian tersadar.Ia sedang terbaring pada sebuah ranjang rumah sakit.\nTanpa pikir panjang, ia melepas semua infus dan selang yang menempel padanya dan bergegas mencari ibunya.\nSaat membuka pintu kamar perawatannya, ia mendapati ibunya sedang duduk pada sebuah kursi roda yang di dorong oleh seorang perawat.\nIa kemudian menghampiri ibunya dan memeluk ibunya sambil menangis tersedu-sedu.");
    pressENTER();
        clear();
    dialog();
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x = 23;
    x++;
     gotoXY(x,6);
    printf(COLOR_RED"Begal : Ibu maafkan aku.Selama ini aku telah berbuat keji kepada orang lain untuk bersenang-senang dan mendapatkan banyak uang.");
    pressENTER();
    x++;
    x++;
     gotoXY(x,6);
    printf(COLOR_GREEN"Ibu Begal : Ibu tahu nak.Tak apa, Ibu sudah memaafkanmu.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    begal1(7,3);
    ibu(7,80);
    x = 23;

    gotoXY(x,6);
    printf(COLOR_RED"Begal : Aku janji setelah ini akan mencari pekerjaan yang halal.");
    pressENTER();
    x++;
     gotoXY(x,6);
    printf(COLOR_WHITE"Setelah kejadian pembegalan ibunya, si begal berhenti menjadi begal dan mendapatkan pekerjaan sebagai cleaning service di kantor dekat rumahnya.\nIa bersyukur dapat mencari nafkah yang halal dan membahagiakan ibunya."COLOR_RESET);
    pressENTER();
    
}

void satpamProlog()
/* Menceritakan kehidupan awal satpam */
{   clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    int x = 23;
    gotoXY(x,6);
    
    printf(COLOR_WHITE"Seorang satpam sedang melamun dengan tatapan kosong.\nIa tidak tahu lagi harus berbuat apa.\nIstri yang dicintainya hanya bisa terbaring di kasur setelah dokter mendiagnosa istrinya mengidap lupus.\nDi tambahkan oleh dokter, istrinya hanya meiliki sisa waktu hidup 2 bulan.\nMereka baru menikah selama 2 tahun dan belum dikaruniai keturunan.\nMerasa tertekan dengan kondisi kehidupannya, si satpam mulai terjerumus ke narkoba dan tidak lagi memperdulikan istrinya.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf("Suatu sehari sepulang si satpam dari tempat kerjanya, ");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_GREEN"Istri Satpam : Mas sudah makan belum? (tanya istri satpam yang terbaring di kasur)");
    pressENTER();
    x++;
      gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Sudah.(Menjawab dengan dingin tanpa menatap langsung muka istrinya)");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_GREEN"Istri Satpam : Mas makasih ya...");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Tanpa sempat menyelesaikan ucapannya, si satpam keluar dari kamarnya.\nIa kemudian membuka sebuah pelastik berisi heroin dan menaburkannya ke tangannya\n.Ia terlihat sangat menikmati menghirup serbuk-serbuk itu dari tangannya.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_GREEN"Istri Satpam : Mas, mungkin saya masih bisa memahami jika mas tidak bisa menerima kondisi saya yang seperti ini, tapi tolong mas jangan gunakan narkoba sebagai pelarian");   x++;
    pressENTER();
      x++;
        gotoXY(x,6);
    printf("Istri Satpam : Mas boleh cari istri lagi kok mas, saya ikhlas dimadu.Asalkan mas berhenti mengkonsumsi barang haram itu.");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Barang haram katamu?(Melempar bungkusan heroinnya ke si istri).Barang haram inilah yang justru menolongku dari segala penderitaanku.Jadi istri cuma nyusahin orang doang.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Dengan seluruh kekutannya, si istri berdiri dan menampar suaminya.\nSi satpam yang tidak terima, membalas tamparan itu dengan pukulan  ke muka istrinya.\nWanita malang itu tidak punya cukup tenaga untuk menopang dirinya dan terpental ke kasurnya.\nKehabisan kata-kata, si istri hanya bisa menangis tersedu dengan muka lebam.\nIa membuang jauh-jauh kokain suaminya yang ada di kasur.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Jadi istri tidak tahu di untung.Sudah mandul, sebentar lagi mati, sekarang berani sama suami sendiri.");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_GREEN"Istri Satpam : Mas, jika mas sangat terbebani dengan kondisi saya, saya bahkan ikhlas jika mas menceraikan saya asalkan mas berhenti menggunakan barang haram itu.");   x++;
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Diam.Jika saya menceraikanmu, orang tua saya akan sedih.Saya tidak mau melibatkan mereka.Mereka sudah cukup kesusahan memelihara saya dari kecil.");   x++;
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_GREEN"Istri Satpam : Baik.Kalau begitu, Saya yang akan pergi dari sini!!");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Tanpa memperdulikan omongan istrinya, ia mengambil bungkusan heroin yang tadi ia lempar dan kembali menghirupnya.\nSi istri sibuk menata barangnya ke dalam koper.\nSetelah selesai, si istri kemudian keluar dari rumah tersebut dan pulang ke rumah orang tuanya.\nSelang seminggu setelah istrinya kabur, Si satpam semakin sering menggunakan narkoba.\nHingga suatu saat, ia mengalami overdosis.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Hak, hak, hak, hak, kenapa ini? apa yang terjadi kepadaku?");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Si satpam mengalami overdosis narkoba.\nIa kemudian dilarikan oleh tetangganya ke rumah sakit terdekat.\nSaat tersadar, ia berada dalam sebuah gua yang gelap dan sunyi.");   x++;
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Dimana ini?Apakah saya sudah mati?");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    ibu(7,85);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Tiba-tiba muncul seekor naga di hadapan si satpam.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Astaga mahkluk apa ini?Apakah saya sedang berhalusinasi karena narkoba?");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Kamu berada dalam dunia setengah hidu setengah mati.Orang yang telah memasuki dunia ini hanya memiliki 2 pilihan, hidup kembali setelah berhasil mengalahkanku atau terjebak di sini selamanya.");   x++;
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Mengapa saya bisa ada di sini?");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Kamu sedang dalam kondisi sekarat akibat overdosis narkoba di duniamu.");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Satpam :Ah bodoamat saya hidup atau mati yang penting saya punya heroin.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Sambil meraba-raba kantong celananya, ia berusaha mencari bungkusan heroinnya.Namun segigih apapun ia mencari, barang tersebut tidak ada di celananya.");   x++;
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_RED"Naga : Jadi kamu punya apa?Apakah yang kamu maksud herinmu?");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Kembalikan!!!Saya mengeluarkan banyak uang hanya untuk membeli sebungkus kecil kokain itu.");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Jangan bodoh.Tentu saja saya tidak aka mengizinkan benda haram seperti itu ada di dunia saya.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Si satpam yang mulai sakau mencari benda tajam untuk melukai dirinya.Ia ingin menjilat darahnya.Ia tidak lagi  menghiraukan perkataan sang naga.");   x++;
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_RED"Naga : Dengarkan perkataanku!!!.Apakah kamu lupa terhadap istrimu?Apakah kamu tidak merasa khawatir dengan kondisinya sekarang?");   x++;
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Peduli setan.Dia bisa mati kapanpun dia mau.Yang aku butuhkan hanya heroin untuk bertahan hidup.");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Tak ingatkah kau saat pertama kali jatuh cinta dengannya? Bagaimana perasaanmu saat itu?");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Saat-saat kami saling jatuh cinta sudah berlalu lama.Sekarang istriku hanya menyusahkan hidupku dan sebentar lagi ia akan mati.");   x++;
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_RED"Naga : Ia adalah orang yang selau ada untukmu setiap saat bahkan sebelum kalian menikah.");
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Itu semua hanya masa lalu.Sekarang yang dia bisa hanya membebaniku.Sekarang tolong kembalikan heroinku!!!");   x++;
    pressENTER();
      x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Dasar keras kepala!!!");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Dengan marah, sang naga pergi meninggalkan si satpam.\nSi satpam menyadari ia benar-benar sendiri dalam kegelapan.");
   
pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);    printf("Ia kemudian menggigit ibu jarinya hingga berdarah dan menghirup darahnya sendiri untuk meredakannya sakaunya yang kambuh.\nDarah yang keluar dari ibu jarinya mengundang banyak monster mendekatinya.");
   pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf("Tanpa ia sadari, sekumpulan monster telah mengepungnya.\nSegerombolan monster itu menyerangnya secara membabi buta.\nBeruntung ia masih mengenakan pakaian satpamnya yang memiliki tingkat ketahanan tinggi.\nDengan susah payah ia keluar dari kerumunan monster itu sambil menutupi semua lukanya yang mengeluarkan darah agar tak tercium lagi oleh monster lain.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Satpam : Sepertinya monster-monster ini tertarik dengan bau kokain dalam darahku.Jika aku menghirup darahku, aku akan terus jadi incaran mereka.");   x++;
    pressENTER();
      x++;
        gotoXY(x,6);
    printf("Satpam : Aku harus mencari cara untuk menghilangkan bau kokain dalam darahku agar monster-monster ini tidak terus mengejarku.");   x++;
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Sekeras apapun si satpam berpikir, ia tidak dapat mencari cara untuk menghilangkan bau narkoba di darahnya.\nJala satu-satunya yang terpikirkan adalah untuk segera keluar dari tempat itu secepat-cepatnya dan berhenti melukai dirinya sendiri agar tidak semakin menarik perhatian para monster.\nSi satpam kemudian membulatkan tekadnya untuk megalahkan si naga secepatnya agar ia dapat segera kembali ke dunia nyata dan dengan bebas mengkonsumsi narkoba."COLOR_RESET);
    pressENTER();
    
}
void satpamGameOver()
/* Menceritakan epilog jika satpam kalah */
{
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
   int x = 23;
    gotoXY(x,6);
    printf(")Satpam : Tidak, aku tidak ingin mati ditempat seperti  ini."COLOR_RESET);
    pressENTER();
    
}
void satpamVictory()
/* Menceritakan epilog jika satpam menang */
{   clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    int x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Setelah berhasil mengalahkan sang naga, Sang naga akhirnya menjelaskan bahwa monster-monster yang ada di guanya sangat sensitif dengan bau narkoba."); 
clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf("Dengan menahan diri tidak mengirup heroin selama berada di gua, ketergantungan si satpam terhadap narkoba dapat berkurang.\nSI satpam tahu jika ia tetap menghirup kokain, makin banyak monster yang aka menyerangnya.");
  
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(" Sang naga juga berpesan, dengan sembuhnya si satpam dari kecanduan narkobanya, ia dapat memperbaiki hubungannya dengan istrinya dan meluangkan lebih banyak waktu dengan istrinya sebelum si istri meningg.Setelah kembali kedunia nyata, ia tersadar."); 
   
clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);    printf("Ia berada pada pusat rehabilitasi intensif narkoba.\nSetelah membuktikan bahwa ia telah sepenuhnya sembuh, ia diizinkan keluar oleh pihak rehabilitasi.\nIa kemudian pergi mencari istrinya di rumah mertuanya.\nSetelah meminta maaf ke mertuanya, ia membawa istrinya kembali ke rumah mereka.\nIa menghabiskan waktunya dengan istri tercintanya dan membuat banyak memori indah hingga ajal menjemput sang istri sebulan kemudian.\n.Sebelum meninggal, istri satpam mengucapkan kata-kata terakhirnya, ");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_GREEN"Istri Satpam : Terimakasih ya mas sudah mau menjadi suamiku.Terimakasih sudah memberikan kenangan terindah dalam hidupku.Sudah mau menemaniku hingga saat terakhirku.Maafkan aku yang tak bisa memberimu keturunan dan selalu merepotkanmu.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    satpam1(9,3);
    dragon(5,80);
    x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Dengan tenang dan damai, si satpam melepas kepergian istrinya.Si satpam bersyukur dapat berhenti dari kecanduan narkoba dan membahagiakan istrinya hingga saat terakhir."COLOR_RESET);
    pressENTER();
    
}
void kuliProlog()
/* Menceritakan kehidupan awal kuli */
{
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   int x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Di kota bandung, hidup seorang pengusaha sukses yang telah memiliki sebuah perusahaan besar.\nPengusaha sukses ini telah memiliki seorang istri dan seorang anak selayaknya keluarga bahagia.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
    x = 23;
    gotoXY(x,6);
    printf("Pada suatu pagi di hari jumat, ");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_YELLOW"Anak Kuli : Pah besok minggu kita ke Trans Studio pah, kata temanku ada mainan baru disana.");
    pressENTER();
    x++;
        gotoXY(x,6);
    printf(COLOR_GREEN"Istri Kuli: Iya pah, mumpung masih musim libur.Papah kan juga butuh refreshing sekali-kali masa kerja terus.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Bukannya papa tidak mau, tapi papa udah ada janji sama mitra perusahaan papa.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_YELLOW"Anak Kuli : Yah pah, adik sebentar lagi liburannya selesai.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_GREEN"Istri Kuli : Ayolah pah, sekali-sekali rekreasi satu keluarga.Anak kita juga baru sekali ke trans studio.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Lain kali saja ya, soalnya pertemuan besok minggu penting sekali.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_YELLOW"Anak Kuli : Pah please please.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Lain kali ya, papa janji kok.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_YELLOW"Anak Kuli : Janji ya.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Di hari minggu, si pengusaha menepati janjinya untuk bertemu dengan direktur dari perusahaan X.\nMereka sepakat untuk meneken MOU.\nSi pengusaha dengan santainya menandatangi perjanjian dengan perusahaan lain tanpa membaca dengan detail isi dari perjanjian tersebut.\nTanpa disadari, si pengusaha telah masuk ke jaring laba-laba orang-orang licik yang haus kekayaan.");
        clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
      gotoXY(x,6);
    printf("Keesokan harinya, beredar kabar bahwa perusahaan si pengusaha dinyatakan pailit dan diakuisisi secara sepihak oleh perusahaan X.\nSontak si pengusaha berusaha menghubungi semua orang kepercayaannya namun tak ada satupun yang menjawab.\nDi sekeliling  rumahnya telah di kepung oleh ratusan debt collector.\nDengan panik pengusaha tersebut keluar dari rumahnya dan menemui para debt collector.");
    pressENTER();
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Ada apa ini? Kenapa rumah saya di kepung seperti ini?");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_WHITE"Rentenir : Rumah bapak akan disita untuk menutupi seluruh hutang bapak ke perusahaan X.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Apa? Saya tidak merasa berhutang apa-apa ke perusahaan X.");
    pressENTER();
    
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Rentenir : Jangan pura-pura lupa.Sudah, sebaiknya anda segera mengosongkan rumah ini atau rasakan sendiri akibatnya.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Ini perbuatan melawan hukum.Saya laporkan kalian semua ke polisi.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_WHITE"Setelah kalimat tersebut terucap, para rentenir naik pitam dan menghakimi si pengusaha.Pengusaha malang itu harus terima badannya babak belur akibat ulah para rentenir.");x++;
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Ampun! Ampun! Maafkan saya.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_WHITE"Rentenir : Udah kapokk??Tahu rasa berani macem-macem sama perusahaan X.");
    pressENTER();
    
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Ampun!!, Sudah, kalian bisa ambil rumah saya dan perusahaan saya tapi biarkan anak istri saya keluar dari rumah tersebut dengan selamat dan kembali ke rumah ibu mertua saya.");x++;
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_WHITE"Rentenir : Cepat keluar kalian kalau tidak ingin terluka.");
    pressENTER();
        x++;
        gotoXY(x,6);

    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Anak dan istri si pengusaha keluar dengan ketakutan.\nMereka melewati si pengusaha yang tersungkur di tanah tanpa mengucap sepatah katapun.\nDengan pandangan kabur, si pengusaha melihat anak istrinya telah pergi meninggalkannya.\nDalam sekejap rumah dan harta yang di perolehnya selama ini hilang begitu saja.\nSetelah ditendang dari rumahnya dan tidak memiliki sepeser uangpun, Janji yang telah ia buat dengan anaknya seakan terasa sangat jauh.\nSi pengusaha kemudian memutuskan untuk mencari pekerjaan seadanya.\nIa bertemu dengan seorang mandor yang menawarinya pekerjaan menjadi kuli bangunan.\nSetelah 2 tahun menjadi kuli, ");
    pressENTER();
        x++;
        gotoXY(x,6);

    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BROWN"Mandor : Pak, Bapak yakin tetap mau jadi kuli bangunan seperti ini?");
    pressENTER();
    
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Iya pak, saya tidak tahu mau kerja apa lagi selain ini.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BROWN"Mandor : Banyak pekerjaan di luar sana yang lebih layak untuk orang dengan kualitas seperti bapak.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Ah tidak pak, saya sudah nyaman jadi kuli.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BROWN"Mandor : Saya dengar bapak dulunya seorang pengusaha ya?");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Tahu aja bapak ini, itu udah dulu pak udah lama.");
    pressENTER();
    
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BROWN"Mandor : Bapak punya anak istri kan? Bapak yakin tidak mau bertemu mereka lagi?");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Mana mau mereka ketemu sama saya sekarang pak.Saya sekarang sudah miskin, dekil, kerjanya cuma jadi kuli lagi.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BROWN"Mandor : Mungkin itu hanya anggapan bapak saja.Kan bapak belum pernah mencoba menemui mereka.");
    printf(COLOR_BLUE"Kuli : Sudah ya pak.Tolong jangan bahas masalah ini lagi.");
    
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);

    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Dengan berat hati, mandor itu menydahi pembicaraan mereka.\nDi sore hari, hujan deras turun melanda.\nSebuah tiang pancang rubuh karena tidak kuat menahan kencangnya terpaan angin.\nSi kuli yang tidak sadar akan rubuhnya tiang itu tidak berusaha menyeamatkan diri hingga tiang itu menimpanya.\nSaat tersadar, si kuli berada pada sebuah gua yang dingin dan gelap.");
    pressENTER();
        x++;
        gotoXY(x,6);

    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Dimana ini?Apa yang terjadi dengan saya?");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_WHITE"Tiba-tiba muncul seekor naga di hadapan si kuli.");
    pressENTER();
        x++;
        gotoXY(x,6);
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Astaga! Mahkluk apa ini? ");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Aku adalah naga penjaga dunia setengah hidup setengah mati.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf("Naga : Orang yang telah memasuki dunia ini hanya memiliki 2 pilihan, hidup kembali setelah berhasil mengalahkanku atau terjebak di sini selamanya.");x++;
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Kenapa saya bisa berada di tempat ini?");
    pressENTER();
    
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_RED"Naga : Sebuah tiang pancang jatuh menimpamu.Sekarang tubuhmu di dunia nyata sedang dalam kondisi kritis.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Jadi ini saatnya saya dipanggil menghadap tuhan.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Apakah kamu lupa akan anak istrimu?tak kah kau merindukan mereka?");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Mereka sudah tidak mau menemui saya sekarang.Saya miskin, dekil, dan cuma seorang kuli bangunan.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Apakah kamu sudah mencoba menemui mereka?");
    pressENTER();
    
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Belum.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Lantas kenapa kamu bisa mengira mereka tidak mau menemuimu?");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Jangan bahas ini lagi.Jika ini saatnya saya mati, maka percepatlah proses kematian saya.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Dasar pengecut keras kepala!!.Jawaban atas semua pertanyaanku sudah ada di benakmu.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf("Naga : Kamu terlalu sibuk dengan dunia dan urusanmu sendiri.Yang di inginkan oleh anak dan istrimu bukan harta dan kekayaanmu.");x++;
    pressENTER();
        x++;
        gotoXY(x,6);
    printf("Naga : Yang mereka butuhkan hanya sedikit dari waktumu untuk mereka.");
    pressENTER();
        x++;
        gotoXY(x,6);
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Semua sudah terlambat untuk di perbaiki.");
    pressENTER();
        x++;
        gotoXY(x,6);
    printf(COLOR_RED"Naga : Sepertinya percuma berdebat denganmu!!!.");
   

    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Dengan emosi si naga terbang pergi meninggalkan si kuli.\nSi kuli yang kini sendiri berusaha menata pikirannya.\nIa teringat perkataan sang naga bahwa jika ia tidak mengalahkan sang naga, ia akan terjebak hidup selamanya di dunia ini.\nDalam kesendiriannya, ia terbayang masa-masa ketika ia sedang bersama keluarganya.");
    
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
   printf("     Air mata mengalir membasahi pipinya mengenang masa-masa kebersamaannya dulu.\nKerinduan yang selama ini di sembunyikan dan dipendam meluap tumpah di hatinya.\nDengan tersedu-sedu, ia memanggil nama anak dan istrinya.\nSetelah air mata berhenti mengalir, ia membulatkan tekadnya untuk bisa kembali kedunianya dan bertemu dangan keluarganya lagi.");
    pressENTER();
        x++;
        gotoXY(x,6);

    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Tunggu ayah ya.Ayah akan keluar dari tempat ini dan nanti kita ke trans studio bareng bunda."COLOR_RESET);
}
void kuliGameOver()
/* Menceritakan epilog jika kuli kalah */


{

    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    anak(7,90);
   char x = 23;
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
  x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Tidak aku masih ingin bertemu dengan anak istriku dan menepati janjiku."COLOR_RESET);
    pressENTER();
    
}
void kuliVictory()
/* Menceritakan epilog jika kuli menang */
{ 
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
int   x = 23;
    gotoXY(x,6);
    printf(COLOR_WHITE"Setelah berhasil mengalahkan sang naga, si kuli tersadar.\nIa sedang berada di sebuah ruang ICU.\nDi sebelah kanan dan kirinnya duduk istri dan anaknya.\nSaat mengetahui si kuli telah sadar, mereka kemudian memeluk erat si kuli.");
    pressENTER();
     
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
    gotoXY(x,6);
    printf(COLOR_YELLOW"Anak Kuli : Papah!!");
    pressENTER();
    
   x = 23;
    gotoXY(x,6);
    printf(COLOR_GREEN"Istri Kuli : Mas!!!");
    pressENTER();
    
  
    clear();
    dialog();
    gotoXY(2,2);
    gotoXY(2,2);printf("+--------------------------------------------------------------------------------------------------------------------+");
    kuli1(9,3);
    anak(10,60);
    ibu(7,90);
   x = 23;
   
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Maafin papah ya tidak segera mencari kalian setelah rumah kita diambil.Papah malah sibuk mencari pekerjaan baru hingga melupakan kalian.");
    pressENTER();
     
    clear();
    dialog();
   x = 23;
    gotoXY(x,6);
    printf(COLOR_YELLOW"Anak Kuli: Iya pah gapapa.");
    pressENTER();
     
    clear();
    dialog();
   x = 23;
    gotoXY(x,6);
    printf(COLOR_BLUE"Kuli : Nanti kalo papah ada uang, kita ke trans studio ya.");
    pressENTER();
     
    clear();
    dialog();
   x = 23;
    gotoXY(x,6);
    printf(COLOR_GREEN"Anak & Istri Kuli : Iya pah."COLOR_RESET);
    pressENTER();
    
}
    
