
#include <stdio.h>
#include <unistd.h>
#include "player.h"



QueueL StrPlayer;
QueueL DefPlayer;
QueueL HpPlayer;
QueueL NextExpPlayer;

void username(PLAYER *player, Kata uname){
	Name(*player) = CopyKata(uname);
}
// nama player telah terdefinisi
// I.S = player telah terdefinisi
// F.S = nama player telah terdefinisi

void PrintStatus(PLAYER player, PLAYERPOS pos){

	int i,x = 2,y = 2;
	Kata Nama20;
	Nama20 = CopyKata(Name(player));
	i = Nama20.Length;
	for (i = Nama20.Length + 1 ; i <= 20 ; i++)
		Nama20.TabKata[i] = ' ';
	Nama20.Length = 20;
	int poss;
	if(Map(pos) > MaxArea)
	{
		poss = Map(pos)%MaxArea +1;
	}
	else
	{
		poss = Map(pos);
	}
	if (Level(player) != MaxLevel) {
		gotoXY(x++,y);printf(COLOR_RESET"┌─────────────────────┬────────┬─────────┐");
		gotoXY(x++,y);printf("│ "COLOR_WHITE);PrintKata(Nama20);printf(""COLOR_RESET"│ "COLOR_YELLOW"LVL: %d "COLOR_RESET"│ "COLOR_MAGENTA" MAP: %d "COLOR_RESET"│",Level(player),poss);
		gotoXY(x++,y);printf("├─────────┬─────────┬─┴───────┬┴─────────┤	");
		gotoXY(x++,y);printf(""COLOR_RESET"│ "COLOR_GREEN"HP: %3d "COLOR_RESET"│ "COLOR_RED"STR: %2d "COLOR_RESET"│ "COLOR_BLUE"DEF: %2d "COLOR_RESET"│ "COLOR_CYAN"EXP: %3d "COLOR_RESET"│",HP(player),STR(player),DEF(player),(NextExp(player)-Exp(player)));
		gotoXY(x++,y);printf("└─────────┴─────────┴─────────┴──────────┘"COLOR_RESET);
	} else {
		gotoXY(x++,y);printf(COLOR_RESET"┌─────────────────────┬─────────┬────────┐");
		gotoXY(x++,y);printf("│ "COLOR_WHITE);PrintKata(Nama20);printf(""COLOR_RESET"│ "COLOR_YELLOW"LV: MAX "COLOR_RESET"│ "COLOR_MAGENTA"MAP: %d "COLOR_RESET"│",poss);
		gotoXY(x++,y);printf("├─────────┬─────────┬─┴───────┬─┴────────┤	");
		gotoXY(x++,y);printf(""COLOR_RESET"│ "COLOR_GREEN"HP: %3d "COLOR_RESET"│ "COLOR_RED"STR: %2d "COLOR_RESET"│ "COLOR_BLUE"DEF: %2d "COLOR_RESET"│ "COLOR_CYAN"EXP: 000 "COLOR_RESET"│",HP(player),STR(player),DEF(player));
		gotoXY(x++,y);printf("└─────────┴─────────┴─────────┴──────────┘"COLOR_RESET);
	}
}
// menampilkan status karakter.
// I.S = karakter telah terdefinisi
// F.S = status karakter telah teretak ke layar

void Lvl1Player(PLAYER *player){
	MaxHP(*player) = 0;
	HP(*player) = 0;
	STR(*player) = 0;
	DEF(*player) = 0;
	Exp(*player) = 0;
	Level(*player) = 0;
	LevelUp(player,Nil);
}
// menciptakan karakter level 1
// I.S = job player telah terdefinisi
// F.S = karakter player menjadi level 1

boolean IsDead(PLAYER player){
	return (HP(player) <= 0);
}
// prekondisi = karakter player telah terdefinisi
// menghasilkan boolean berdasarkan kondisi karakter sudah mati atau belum.

void IncreaseHP(PLAYER * player, int X){
	if ((HP(*player) + X) > MaxHP(*player)){
		HP(*player) = MaxHP(*player);
	}
	else{
		HP(*player) += X;
	}
}
// menambah current HP dari player sebanyak X
// current hp tidak lebih dari max hp.
// I.S = current hp dan max hp sudah terdefinisi
// F.S = current hp telah berhasil tertambah

void DecreaseHP(PLAYER * player, int X){
	if ((HP(*player) - X) < 0){
		HP(*player) = 0;
	}
	else{
		HP(*player) -= X;
	}
}
// Kurang current HP dari player sebanyak X
// Mungkin jadi  kosong tidak mungkin kurang dari 0
// I.S = current hp telah terdefinisi
// F.S = current hp telah berkurang

void AddExp(PLAYER * player, int X, BinTree *Skill){
	if (Exp(*player)!=MaxExp){
		if ((Exp(*player) + X) >= NextExp(*player))
		{
			X = ((Exp(*player) + X) - NextExp(*player));
			LevelUp(player,Skill);
			if (Level(*player) != MaxLevel){
				Exp(*player) = 0;
				AddExp(player,X,Skill);
			}else{
				Exp(*player) = MaxExp;
			}
		}
		else{
			Exp(*player) += X;
		}
	}
}
// Nambah EXP sebanyak X
// jika EXP bertambah lebih dari next exp, karakter akan level up, dan exp akan mulai dari 0 lagi
// dimungkinkan naik exp lebih dari 1 kali
// I.S = exp karakter telah bertambah sebanyak x
// F.S = exp karakter telah bertambah sebnayak x

void GetSkill(PLAYERPOS pos, boolean *del, BinTree *skill)
{
	IsiTabSkillPos(*skill);

	int i = 1;
	boolean found = false;
	while(!found && i<= 4)
	{
		if(SkillIdxMap(TabSkill[i]) == Map(pos) && EQ(SkillPos(TabSkill[i]), Pos(pos)))
		{
			found = true;
		}
		else
		{
			i++;
		}
	}

		printf(COLOR_YELLOW);
	    gotoXY(10,45);printf("┌─vVv───────────────────────vVv─┐");
	    gotoXY(11,45);printf("│         Dapet Skill!          │");
	    gotoXY(12,45);printf("├───────────────────────────────┤");
	    gotoXY(13,45);printf("│                               │");
	    gotoXY(14,45);printf("│                               │");
	    gotoXY(15,45);printf("│                               │");
	    gotoXY(16,45);printf("│                               │");
	    gotoXY(17,45);printf("│                               │");
	    gotoXY(18,45);printf("│                               │");
	    gotoXY(19,45);printf("│                               │");
	    gotoXY(20,45);printf("│                               │");
	    gotoXY(21,45);printf("│                               │");
	    gotoXY(22,45);printf("│                               │");
	    gotoXY(23,45);printf("├───────────────────────────────┤");
	    gotoXY(24,45);printf("│                               │");
	    gotoXY(25,45);printf("├───────────────────────────────┤");
	    gotoXY(26,45);printf("│    "COLOR_WHITE"Press ENTER to continue."COLOR_YELLOW"   │");
	    gotoXY(27,45);printf("└───────────────────────────────┘");

	if(IsKataSamaString(SkillName(TabSkill[i]), "BoxingPunch"))
	{

		gotoXY(14,45);printf("│       "COLOR_RED"       ________     "COLOR_YELLOW"    │");
		gotoXY(15,45);printf("│       "COLOR_RED" __.--\"        \"\\"COLOR_WHITE"'.  "COLOR_YELLOW"   │");
		gotoXY(16,45);printf("│   "COLOR_WHITE"----"COLOR_RED"f\"             / \\"COLOR_WHITE"\\\\ "COLOR_YELLOW"   │");
		gotoXY(17,45);printf("│   "COLOR_WHITE"    "COLOR_RED"|                 |"COLOR_WHITE"||"COLOR_YELLOW"   │");
		gotoXY(18,45);printf("│   "COLOR_WHITE"    "COLOR_RED"|                 |"COLOR_WHITE"||"COLOR_YELLOW"   │");
		gotoXY(19,45);printf("│   "COLOR_WHITE"  --"COLOR_RED"L_-XX-.           |"COLOR_WHITE"|'"COLOR_YELLOW"   │");
		gotoXY(20,45);printf("│       "COLOR_RED"       \"\\   -<___/"COLOR_WHITE"// "COLOR_YELLOW"   │");
		gotoXY(21,45);printf("│       "COLOR_RED"         \\___)   "COLOR_WHITE"-\"  "COLOR_YELLOW"   │");
		gotoXY(24,45);printf("│         "COLOR_RED"Boxing Punch"COLOR_YELLOW"          │");
		HasSkill(Akar(SearchTreeString (*skill, "BoxingPunch"))) = true;
		*del = true;
	}
	else if(IsKataSamaString(SkillName(TabSkill[i]), "GatlingGun"))
	{
		if(HasSkill(Akar(SearchTreeString (*skill, "BoxingPunch"))))
		{

			gotoXY(16-2,45);printf("│   "COLOR_WHITE"     _  __________=__       "COLOR_YELLOW"│");
			gotoXY(17-2,45);printf("│   "COLOR_WHITE"      \\\\@([____]_____()     "COLOR_YELLOW"│");
			gotoXY(18-2,45);printf("│   "COLOR_WHITE"     _/\\|-[____]            "COLOR_YELLOW"│");
			gotoXY(19-2,45);printf("│   "COLOR_WHITE"    /     /"COLOR_YELLOW"(("COLOR_WHITE" )"COLOR_YELLOW"             │");
			gotoXY(20-2,45);printf("│   "COLOR_WHITE"   /____|'----'             "COLOR_YELLOW"│");
			gotoXY(21-2,45);printf("│   "COLOR_WHITE"   \\____/                   "COLOR_YELLOW"│");
			gotoXY(24,45);printf("│         "COLOR_WHITE"Gatling Gun"COLOR_YELLOW"           "COLOR_YELLOW"│");
			HasSkill(Akar(SearchTreeString (*skill, "GatlingGun"))) = true;
			*del = true;
		}
		else{
			gotoXY(11,45);printf("│         Skill Locked!         │");
			gotoXY(14,45);printf("│         .??????.              │");
			gotoXY(15,45);printf("│         ??????????.           │");
			gotoXY(16,45);printf("│         `???? ?????           │");
			gotoXY(17,45);printf("│               ?????           │");
			gotoXY(18,45);printf("│            .???????           │");
			gotoXY(19,45);printf("│            ??????:'           │");
			gotoXY(20,45);printf("│            .???.              │");
			gotoXY(21,45);printf("│            ?%%%%%%?              │");
			gotoXY(22,45);printf("│            `:;:'              │");
			gotoXY(24,45);printf("│          ??????? ???          │");
		}
	}
	else if(IsKataSamaString(SkillName(TabSkill[i]), "Exorcist"))

	{
		if(HasSkill(Akar(SearchTreeString (*skill, "BoxingPunch"))))
		{
			gotoXY(14,45);printf("│              "COLOR_WHITE"/\\"COLOR_YELLOW"               │");
			gotoXY(15,45);printf("│             "COLOR_RED"\\"COLOR_WHITE"II"COLOR_RED"/"COLOR_YELLOW"              │");
			gotoXY(16,45);printf("│           (88II88)            │"); 
			gotoXY(17,45);printf("│             "COLOR_RED"/"COLOR_CYAN"II"COLOR_RED"\\"COLOR_YELLOW"              │"); 
			gotoXY(18,45);printf("│              "COLOR_CYAN"II "COLOR_YELLOW"              │");  
			gotoXY(19,45);printf("│              "COLOR_CYAN"II "COLOR_YELLOW"              │");  
			gotoXY(20,45);printf("│              "COLOR_CYAN"II "COLOR_YELLOW"              │");  
			gotoXY(21,45);printf("│              "COLOR_CYAN"\\/"COLOR_YELLOW"               │"); 
			gotoXY(24,45);printf("│           Exorcist            │");
			HasSkill(Akar(SearchTreeString (*skill, "Exorcist"))) = true;
			*del = true;
		}
		else{
	    	gotoXY(11,45);printf("│         Skill Locked!         │");
	    	gotoXY(14,45);printf("│         .??????.              │");
			gotoXY(15,45);printf("│         ??????????.           │");
			gotoXY(16,45);printf("│         `???? ?????           │");
			gotoXY(17,45);printf("│               ?????           │");
			gotoXY(18,45);printf("│            .???????           │");
			gotoXY(19,45);printf("│            ??????:'           │");
			gotoXY(20,45);printf("│            .???.              │");
			gotoXY(21,45);printf("│            ?%%%%%%?              │");
			gotoXY(22,45);printf("│            `:;:'              │");
			gotoXY(24,45);printf("│           ????????            │");
		}
	}
	else if(IsKataSamaString(SkillName(TabSkill[i]), "Giant"))
	{
		if(HasSkill(Akar(SearchTreeString (*skill, "GatlingGun"))))
		{

			gotoXY(14,45);printf("│     "COLOR_RED"      .-.         "COLOR_YELLOW"        │");
			gotoXY(15,45);printf("│     "COLOR_RED"     /  _)        "COLOR_YELLOW"        │");
			gotoXY(16,45);printf("│     "COLOR_RED"    /  /          "COLOR_YELLOW"        │");
			gotoXY(17,45);printf("│     "COLOR_RED"   /  /   _       "COLOR_YELLOW"        │");
			gotoXY(18,45);printf("│     "COLOR_RED"  /  /_./` `\\_   "COLOR_YELLOW"         │");
			gotoXY(19,45);printf("│     "COLOR_RED"  |               "COLOR_YELLOW"        │");
			gotoXY(20,45);printf("│     "COLOR_RED"  `\\_________/_  "COLOR_YELLOW"         │");
			gotoXY(24,45);printf("│     "COLOR_RED"       Giant      "COLOR_YELLOW"        │");
			HasSkill(Akar(SearchTreeString (*skill, "Giant"))) = true;
			*del = true;
		}
		else{
	    	gotoXY(11,45);printf("│         Skill Locked!         │");
	    	gotoXY(14,45);printf("│         .??????.              │");
			gotoXY(15,45);printf("│         ??????????.           │");
			gotoXY(16,45);printf("│         `???? ?????           │");
			gotoXY(17,45);printf("│               ?????           │");
			gotoXY(18,45);printf("│            .???????           │");
			gotoXY(19,45);printf("│            ??????:'           │");
			gotoXY(20,45);printf("│            .???.              │");
			gotoXY(21,45);printf("│            ?%%%%%%?              │");
			gotoXY(22,45);printf("│            `:;:'              │");
			gotoXY(24,45);printf("│             ?????             │");
		}
	}
	printf(COLOR_RESET);
}
// mendapatkan skill untuk player
// I.S = skill telah diinisialisasi
// F.S = skill telah terbuat

void LoadPlayer(PLAYER *player, BinTree *Skill){
	infotypeQL X;
	for (int i = 1 ; i <= Level(*player) ; i++){
		DelQL(&HpPlayer,&X);
		HP(*player) = X;
		MaxHP(*player) = X;
		DelQL(&StrPlayer,&X);
		STR(*player) = X;
		DelQL(&DefPlayer,&X);
		DEF(*player) = X;
	}
	if (Level(*player) != 1){
		if (HasSkill(Akar(SearchTreeString (*Skill, "GiantArms"))))
		{
			STR(*player) = STR(*player)+4;

		}
		if (HasSkill(Akar(SearchTreeString (*Skill, "IronBody"))))
		{
			DEF(*player) = DEF(*player)+6;

		}
		if (HasSkill(Akar(SearchTreeString (*Skill, "FitBody"))))
		{
			MaxHP(*player) = MaxHP(*player)+40;
			HP(*player) = MaxHP(*player);
		}
	}	
}
// meload status player dari file eksternal
// I.S = sembarang
// F.S = Player posisi dan status berhasil di load 

void LevelUp(PLAYER * player, BinTree *Skill){
	if (Level(*player) != 0 && Level(*player) < MaxLevel){
		PrintLvlUp(Skill);
	}
	infotypeQL X;
	if (Level(*player) < MaxLevel){
		Level(*player)++;
		DelQL(&HpPlayer,&X);
		HP(*player) = X;
		MaxHP(*player) = X;
		DelQL(&StrPlayer,&X);
		STR(*player) = X;
		DelQL(&DefPlayer,&X);
		DEF(*player) = X;


		if (Level(*player) != 1){
			if (HasSkill(Akar(SearchTreeString (*Skill, "GiantArms"))))
			{
				STR(*player) = STR(*player)+4;

			}
			if (HasSkill(Akar(SearchTreeString (*Skill, "IronBody"))))
			{
				DEF(*player) = DEF(*player)+6;

			}
			if (HasSkill(Akar(SearchTreeString (*Skill, "FitBody"))))
			{
				MaxHP(*player) = MaxHP(*player)+40;
				HP(*player) = MaxHP(*player);
			}
		}
	}
}

// meload status player dari level ke level ke dalam sebuah queue
// I.S = file eksternal telah tersiapkan.
// F.S = status player telah terload dari file eksternal

void Heal(PLAYER * player){
	int selisih = MaxHP(*player) - HP(*player);
	PGMed();
	gotoXY(24,57);printf(COLOR_GREEN"(HP +%3d)",selisih);
	HP(*player) = MaxHP(*player);
}
// meningkatkan current hp player hingga max hp
// I.S karakter telah terdefinisi
// F.S current hp player = max hp player

void PilihJob(PLAYER * player){
	int N = 0;
	char cc, bef[4][23] = {"  Mahasiswa  ", "  Begal  ", "  Satpam  ", "  Kuli  "}, aft[5][30] = {"\u25B7 Mahasiswa ", "\u25B7 Begal ", "\u25B7 Satpam ","\u25B7 Kuli "};
    int pil = 0;
    while(N == 0)
    {
        pilihjob();
        printf(COLOR_RESET);
        mahasiswa(13,50);
        gotoXY(11,24);printf(COLOR_RED"Username: ");PrintKata(Name(*player));
        gotoXY(13+pil,22);
        printf("\e[1;37m%s"COLOR_RESET"\n", aft[pil]);
        while (1)
        {
            initTermios(); // use new terminal setting again to make kbhit() and getch() work
            cc = getch();
            resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
            if(cc == 27 )
            {
                initTermios();
                cc = getch();
                cc = getch();
                resetTermios();
                gotoXY(13+pil,22);
                printf("%s", bef[pil]);
								if (pil == 1 ) blank(10,50);
                else blank(13,50);
                switch(cc)
                {
                    case 'A' :
                    pil = (pil+3) % 4;
                    break;
                    case 'B' :
                    pil = (pil+1) % 4;
                    break;
                }
                gotoXY(13+pil,22);
                printf("\e[1;37m%s"COLOR_RESET, aft[pil]);
                if (pil == 0) {
					mahasiswa(13,50);
                } else if (pil == 1) {
					begal(10,50);
                } else if (pil == 2) {
					satpam(13,50);
                } else {
					kuli(13,50);
                }
            } else
            if(cc == 10)
            {
                N = pil + 1;
                break;
            }
        }
    }
    Job(*player) = N;
    printf(COLOR_RESET);
    SHOWKURSOR;
}
// Menampilkan menu pilih job ,dan mengupdate status player berdasarkan job yang dipilih
// I.S = player telah terdefinisi
// F.S = job player telah terdefinisi

int NextExp(PLAYER player){
	int i;
	if (Level(player) < MaxLevel){
		addressQL P = Head(NextExpPlayer);
		for (i = 1; i<=(Level(player)-1);i++)
		{
			P = Next(P);
		}
		return (Info(P));
	}else{
		return (MaxExp);
	}
}
// memasukan nilai next exp ke dalam queue next exp
// I.S = sembarang
// F.S = NextExp karakter telah dimasukan dalam queue list


void LoadStatusPlayer(PLAYER player){
	CreateEmptyQL(&StrPlayer);
	CreateEmptyQL(&DefPlayer);
	CreateEmptyQL(&HpPlayer);
	CreateEmptyQL(&NextExpPlayer);
	STARTGAMETOKEN(Job(player));
	int Mark2 = '|' - '0';
	while((!EndToken) && (CToken.val != Mark2))
	{
		AddQL(&HpPlayer,CToken.val);
		ADVTOKEN();
	}
	ADVTOKEN();
	while((!EndToken) && (CToken.val != Mark2))
	{
		AddQL(&StrPlayer,CToken.val);
		ADVTOKEN();
	}
	ADVTOKEN();
	while((!EndToken) && (CToken.val != Mark2))
	{
		AddQL(&DefPlayer,CToken.val);
		ADVTOKEN();
	}

	ADVTOKEN();
	while((!EndToken) && (CToken.val != Mark2))
	{
		AddQL(&NextExpPlayer,CToken.val);
		ADVTOKEN();
	}

}
// meload status player dari level ke level ke dalam sebuah queue
// I.S = file eksternal telah tersiapkan.
// F.S = status player telah terload dari file eksternal