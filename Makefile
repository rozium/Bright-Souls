CC = gcc
CFLAGS = -c -Wall

all: BrightSouls

BrightSouls: main.o display.o player.o queuelist.o mesintoken.o mesinkar.o enemy.o mesinkata.o point.o battle.o stacklist.o graf.o map.o matriks.o navigation.o queuelistl.o skill.o data.o jam.o bintree.o narasi.o
	$(CC) main.o display.o player.o queuelist.o mesintoken.o mesinkar.o enemy.o mesinkata.o point.o battle.o stacklist.o graf.o map.o matriks.o navigation.o queuelistl.o skill.o data.o jam.o bintree.o narasi.o -lm -o BrightSouls

gdb: main.o display.o player.o queuelist.o mesintoken.o mesinkar.o enemy.o mesinkata.o point.o battle.o stacklist.o graf.o map.o matriks.o navigation.o queuelistl.o skill.o data.o jam.o bintree.o narasi.o
	$(CC) main.o display.o player.o queuelist.o mesintoken.o mesinkar.o enemy.o mesinkata.o point.o battle.o stacklist.o graf.o map.o matriks.o navigation.o queuelistl.o skill.o data.o jam.o bintree.o narasi.o -lm -g

main.o: main.c
	$(CC) $(CFLAGS) main.c

display.o: MODUL/DISPLAY/display.c
	$(CC) $(CFLAGS) MODUL/DISPLAY/display.c

player.o: MODUL/PLAYER/player.c
	$(CC) $(CFLAGS) MODUL/PLAYER/player.c

queuelist.o: MODUL/QUEUELIST/queuelist.c
	$(CC) $(CFLAGS) MODUL/QUEUELIST/queuelist.c

mesintoken.o: MODUL/MESINTOKEN/mesintoken.c
	$(CC) $(CFLAGS) MODUL/MESINTOKEN/mesintoken.c

mesinkar.o: MODUL/DATA/mesinkar.c
	$(CC) $(CFLAGS) MODUL/DATA/mesinkar.c

enemy.o: MODUL/ENEMY/enemy.c
	$(CC) $(CFLAGS) MODUL/ENEMY/enemy.c

mesinkata.o: MODUL/DATA/mesinkata.c
	$(CC) $(CFLAGS) MODUL/DATA/mesinkata.c

point.o: MODUL/POINT/point.c
	$(CC) $(CFLAGS) MODUL/POINT/point.c

battle.o: MODUL/BATTLE/battle.c
	$(CC) $(CFLAGS) MODUL/BATTLE/battle.c

stacklist.o: MODUL/STACKLIST/stacklist.c
	$(CC) $(CFLAGS) MODUL/STACKLIST/stacklist.c

graf.o: MODUL/GRAPH/graf.c
	$(CC) $(CFLAGS) MODUL/GRAPH/graf.c

map.o: MODUL/MAP/map.c
	$(CC) $(CFLAGS) MODUL/MAP/map.c

matriks.o: MODUL/MATRIKS/matriks.c
	$(CC) $(CFLAGS) MODUL/MATRIKS/matriks.c

navigation.o: MODUL/NAVIGATION/navigation.c
	$(CC) $(CFLAGS) MODUL/NAVIGATION/navigation.c

queuelistl.o: MODUL/QUEUELIST/queuelistl.c
	$(CC) $(CFLAGS) MODUL/QUEUELIST/queuelistl.c

skill.o: MODUL/SKILL/skill.c
	$(CC) $(CFLAGS) MODUL/SKILL/skill.c

data.o: MODUL/DATA/data.c
	$(CC) $(CFLAGS) MODUL/DATA/data.c

jam.o: MODUL/JAM/jam.c
	$(CC) $(CFLAGS) MODUL/JAM/jam.c

bintree.o: MODUL/BINTREE/bintree.c
	$(CC) $(CFLAGS) MODUL/BINTREE/bintree.c		

narasi.o: MODUL/NARASI/narasi.c
	$(CC) $(CFLAGS) MODUL/NARASI/narasi.c

clean:
	rm -rf *o BrightSouls a.out
