
#include <stdlib.h>
#include <stdio.h>
#include "data.h"
//Include ADT lain yang diperlukan

ENEMY TabEnemy[14];
char CC;

//FORMAT SAVE:
//SAVEFILE disimpan dalam file bernama <username>
// [nama]  [waktusave dalam detik]  [durasi bermain] [MaxHP] [HP] [STR] [DEF] [Exp] [Level] [Job] [mapindex] [pos i] [pos j] | [skill] | [maps] | [enemy] | 

void Load(Kata *nama, TabMat *maps, PLAYER *player, PLAYERPOS *playerpos, int *dur, BinTree *skill, int *waktu)
{
	// loadfiles
	//dapetin variabel nama dari

	//Buka files

	STARTFILE(KataToChar(*nama));

	ADVKATA2(); // nama
	ADVKATA2(); // waktu
	*waktu = CKata2.Val;
	ADVKATA2(); // dur
	*dur = CKata2.Val;
	ADVKATA2(); // MaxHP
	MaxHP(*player) = CKata2.Val;
	ADVKATA2(); // HP
	HP(*player) = CKata2.Val;
	ADVKATA2(); // STR
	STR(*player) = CKata2.Val;
	ADVKATA2(); // DEF
	DEF(*player) = CKata2.Val;
	ADVKATA2(); // Exp
	Exp(*player) = CKata2.Val;
	ADVKATA2(); // Level
	Level(*player) = CKata2.Val;
	ADVKATA2(); // Job
	Job(*player) = CKata2.Val;
	ADVKATA2(); // MapIndex
	Map(*playerpos) = CKata2.Val;
	ADVKATA2(); // Pos i
	Absis(Pos(*playerpos)) = CKata2.Val;
	ADVKATA2(); // Pos i
	Ordinat(Pos(*playerpos)) = CKata2.Val;
	ADVKATA2(); // Guard

	int i = 1;

	//read Skill
	//18 = jumlah skill
	for(; i<= 18; i++)
	{	
		int has;

		ADVKATA2();
		has = CKata2.Val;
		if(has == 1)
		{
			HasSkill(Akar(SearchTreeIndex(*skill, i))) = true;
		}
		else
		{
			HasSkill(Akar(SearchTreeIndex(*skill, i))) = false;
		}
	}

	ADVKATA2(); // Guard

	//read Maps
	int k = 1;
	
	int j;
	for(; k <= MaxArea*2-1; k++)
	{	i = 1;
		j = 1;
		for(; i <= BrsArea; i++)
		{	
			j = 1;
			for(;j <= KolArea; j++)
			{
				ADVKATA2();
				Elmt(Area(*maps,k),i,j) = CKata2.TabKata[1];
				if(Elmt(Area(*maps, k), i,j) == 'x')
				{
					Elmt(Area(*maps, k), i,j) = ' ';
				}
			}
		}
		NKolEff( Area(*maps, k)) = KolArea;
		NBrsEff( Area(*maps, k)) = BrsArea;
		BranchCount(*maps) = MaxArea -1;
	}
	ADVKATA2(); //Guard

	//load Enemy Pos
	i = 1;
	//1 to maxenemy
	for(; i <= MaxEnemy; i++)
	{
		ADVKATA2();
		Absis(EnemyPos(TabEnemy[i])) = CKata2.Val;
		ADVKATA2();
		Ordinat(EnemyPos(TabEnemy[i])) = CKata2.Val;
	}
	ADVKATA2(); //Guard

	//load Skill Pos
	//1 to 4 skill on map
	for(i = 1; i <= 4; i++) {
		ADVKATA2();
		Absis(SkillPos(TabSkill[i])) = CKata2.Val;
		ADVKATA2();
		Ordinat(SkillPos(TabSkill[i])) = CKata2.Val;
	}
	ADVKATA2(); // Guard
}

// format save files
// [no] [nama]  | ....

//Menload semua data dari file eksternal
void Save(TabMat maps, PLAYER player, PLAYERPOS playerpos, int waktumulai, BinTree skill)
{	
	//Inisialisasi
	Kata nama;

	//Pindahin variable
	nama = CopyKata(Name(player));

		JAM WaktuJam;
		//Tulis jam main
		GetCurrentJAM(&WaktuJam);
		
		int Waktu = JAMToDetik(WaktuJam);
		//tulis Durasi main
		int durplay =  Waktu - waktumulai;
		
		//End
	//cek nama udah ada apa belum
	if(CheckExistence(nama))
	{
		//Sudah ada save an dengan nama tersebut
		WriteSaves(nama,maps,player,playerpos,durplay,skill, Waktu);
	}
	else
	{

		//tulis baru
		int i;
		
		int k = 0;
		

		FILE * savefiles;
		//Menghitung ini save ke berapa
		STARTSAVEFILES();
		EndKata = false;
		while(!EndKata)
		{
			if (CKata.TabKata[1] == '|') k++;
			ADVKATA();
		}
		Kata savee[k+1][2];
		STARTSAVEFILES();
		EndKata = false;
		i = 0;
		while(i != k)
		{
			ADVKATA(); // no
			ADVKATA(); // uname
			savee[i][0] = CopyKata(CKata);
			ADVKATA(); // job
			savee[i][1] = CopyKata(CKata);
			ADVKATA(); // Guard
			i++;
		}
	
		//Mulai menulis save
		savefiles = fopen("SAVES/savefiles.txt","w");
		while (i-k+1 != k)
		{
			fprintf(savefiles, "%d ",i-k+1);
			for (int j = 1; j <= savee[i-k][0].Length; j++){
				fprintf(savefiles, "%c", savee[i-k][0].TabKata[j]);
			}
			fprintf(savefiles, "%c", ' ' );
			for (int j = 1; j <= savee[i-k][1].Length; j++){
				fprintf(savefiles, "%c", savee[i-k][1].TabKata[j]);
			}
			fprintf(savefiles, "%c", ' ' );
			i++;
			fprintf(savefiles, "%s", "| " );
		}
		//Tulis indeks savean
		fprintf(savefiles, "%d ", k);

		//Tulis Nama player
		for (i = 1; i <= Name(player).Length; i++){
			fprintf(savefiles, "%c", Name(player).TabKata[i]);
		}
		fprintf(savefiles, "%c", ' ' );
		//Tulis Job player
		int job = Job(player);
		switch(job)
		{
			case 1:
				fprintf(savefiles, "%s ","Mahasiswa");
				break;
			case 2:
				fprintf(savefiles, "%s ","Begal");
				break;
			case 3:
				fprintf(savefiles, "%s ","Satpam");
				break;
			case 4:
				fprintf(savefiles, "%s ","Kuli");
				break;
		}
		fprintf(savefiles, "%s", "| ." );
	
		fclose(savefiles);

		FILE * pita2;

  int iu=6,ju;
  char s1[] = "SAVES/";

  	char * filee;
  	filee = KataToChar(nama);
    for(ju = 0; filee[ju] != '\0'; ++ju, ++iu)
    {
        s1[iu] = filee[ju];
    }

    s1[iu] = '\0'; 

		pita2 = fopen(s1,"ab+");
		fprintf(pita2, "%c", '.');
		fclose(pita2);
		//TulisSave
		WriteSaves(nama,maps,player,playerpos,durplay,skill, Waktu);
	}
	
}
//Mensave semua datafile eksternal


// format data save player

// [nama]  [waktusave dalam detik]  [durasi bermain] [MaxHP] [HP] [STR] [DEF] [Exp] [Level] [Job] [mapindex] [pos i] [pos j] | [skill] | [maps] | [enemy] | [skillpos]
void WriteSaves(Kata name,TabMat maps, PLAYER player, PLAYERPOS playerpos, int dur, BinTree skill, int waktu){

	FILE * pita;
	char * filename;
	filename = KataToChar(name);
	int durbef;

  int i = 6,j;
  char s1[100];
  s1[0] = 'S';
  s1[1] = 'A';
  s1[2] = 'V';
  s1[3] = 'E';
  s1[4] = 'S';
  s1[5] = '/';
    for(j = 0; filename[j] != '\0'; ++j, ++i)
    {
        s1[i] = filename[j];
    }
    s1[i] = '\0';
	//Mengambil durasi playtime
	if (CheckExistence(name)) {
		EndKata = false;
		STARTFILEW(filename);
		if (EndKata) {
		} else {
			ADVKATA2(); // nama
			ADVKATA2(); // waktu
			ADVKATA2(); // durbef
			durbef = CKata2.Val;
		}
		pita = fopen(s1,"w");
	} else {
		durbef = 0;
		pita = fopen(s1,"ab+");
	}

	//Save data dan posisi player
	fprintf(pita, "%s %d %d %d %d %d %d %d %d %d %d %d %d", filename, waktu, (dur+durbef), MaxHP(player), HP(player), STR(player), DEF(player), Exp(player), Level(player), Job(player), Map(playerpos), Absis(Pos(playerpos)), Ordinat(Pos(playerpos)));
	fprintf(pita, " | ");
	i = 1;

	//Save Skill
	//18 = jumlah skill
	for(; i<= 18; i++)
	{	
		int has;
		if(HasTreeIndex(skill, i))
		{
			has = 1;
		}
		else
		{
			has = 0;
		}
		fprintf(pita, " %d ", has);
	}
	fprintf(pita, " | ");

	//Save Maps
	int k = 1;
	
	for(; k <= MaxArea*2-1; k++)
	{	i = 1;
		j = 1;
		for(; i <= BrsArea; i++)
		{	
			j = 1;
			for(;j <= KolArea; j++)
			{

				if(Elmt(Area(maps, k), i,j) == ' ')
				{
					fprintf(pita, " x ");
				}
				else
				{

				fprintf(pita, " %c ", Elmt(Area(maps, k), i,j));
				}
			}
			

		}


	}
	fprintf(pita, " | ");

	//Save Enemy Pos
	i = 1;
	//1 to maxenemy
	for(; i <= MaxEnemy; i++)
	{
		fprintf(pita, " %d %d ", Absis(EnemyPos(TabEnemy[i])), Ordinat(EnemyPos(TabEnemy[i]))) ;
	}

	fprintf(pita, " | ");

	//Save Skill Pos
	//1 to 4 skill on map
	for(i = 1; i <= 4; i++) {
		fprintf(pita, " %d %d ",Absis(SkillPos(TabSkill[i])),Ordinat(SkillPos(TabSkill[i])));
	}

	fprintf(pita, " | .");
	fclose(pita);

}

int CheckExistence(Kata username)
//mengecek apakah save file dengan nama player sudah ada, jika ada return index, jika tidak return 0
{
	int idx = 0;
	Kata name;
	STARTSAVEFILES();
	boolean found = false;
	EndKata = false;
	while (!found && !EndKata && CC != '\0'){
		ADVKATA();
		idx = CKata.Val;
		ADVKATA();
		name = CopyKata(CKata);
		ADVKATA(); //job
		ADVKATA(); //guard
		if (IsKataSama(name,username)){
			found = true;
		}
	}
	if (!found)
		return 0;
	else
		return idx;
}	