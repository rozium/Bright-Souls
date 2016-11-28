// NIM / Nama       : 13515026 / Achmad Fahrurrozi Maskur
// Nama File        : queuelist.c
// Tanggal          : 1 November 2016

#include "queuelist.h"
#include <stdlib.h>
#include <stdio.h>

void AlokasiQ (addressQ * P, infotypeQ X) {
	(*P) = (addressQ) malloc (sizeof (ElmtQueue));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void DealokasiQ (addressQ P) {
	free(P);
}

boolean IsEmptyQ (Queue Q) {
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

int NbElmtQ (Queue Q) {
	addressQ P;
	int N;
	P = Head(Q);
	N = 0;
	while (P != Nil) {
		N = N + 1;
		P = Next(P);
	}
	return N;
}

void CreateEmptyQ (Queue * Q) {
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

void AddQ (Queue * Q, infotypeQ X) {
	addressQ P;
	AlokasiQ(&P,X);
	if (P != Nil) {
		if (IsEmptyQ(*Q)) {
			Head(*Q) = P;
			Tail(*Q) = P;
		} else {
			Next(Tail(*Q)) = P;
			Tail(*Q) = P;
		}
	}
}

void DelQ (Queue * Q, infotypeQ * X) {
	addressQ P;
	(*X) = InfoHead(*Q);
	P = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q) == Nil) {
		Tail(*Q) = Nil;
	}
	DealokasiQ(P);
}

void DelQBATTLE (Queue * Q, infotypeQ * X) {
	addressQ P,T;
	(*X) = InfoTail(*Q);
	P = Tail(*Q);
	T = Head(*Q);
	if (Head(*Q) == Tail(*Q)) {
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	} else {
		while (Next(T) != Tail(*Q)) {
			T = Next(T);
		}
		Tail(*Q) = T;
	}
	DealokasiQ(P);
}

void PrintQueueQ (Queue Q){
	addressQ P;

	P = Head(Q);
	while (P != Nil) {
		printf("%c ",Info(P));
		P = Next(P);
	}
	printf("\n");
}

void PrintQueueE (Queue Q, int tutup1, int tutup2){
	addressQ P;
	int i = 1;

	P = Head(Q);
	while (P != Nil) {
		if (i == tutup1 || i == tutup2)
			printf("# ");
		else
			printf("%c ",Info(P));
		P = Next(P);
		i++;
	}
	printf("                    │");
}

void InsertFirstQ (Queue *Q, addressQ P){
	Next(P) = Head(*Q);
	Head(*Q) = P;
}

void InsertAfterQ (Queue *Q, addressQ P, addressQ Prec){
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLastQ (Queue *Q, addressQ P){
	addressQ Last;
	Last = Head(*Q);
	if (Head(*Q) == Nil) {
		InsertFirstQ(Q,P);
	} else {
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		InsertAfterQ(Q,P,Last);
	}
}

void DelAllQ (Queue *Q){
	addressQ P;
	P = Head(*Q);
	while (P != Nil) {
		Head(*Q) = Next(Head(*Q));
		Next(P) = Nil;
		DealokasiQ(P);
		P = Head(*Q);
	}
}

Queue CopyQ (Queue Q){
	addressQ P,Pi;
	Queue Qc;
	boolean gagal = false;
	CreateEmptyQ(&Qc);
	P = Head(Q);
	while ( P != Nil && !gagal) {
		AlokasiQ(&Pi,Info(P));
		if (Pi != Nil) {
			InsertLastQ(&Qc,Pi);
			P = Next(P);
		} else {
			DelAllQ(&Qc);
			gagal = true;
		}
	}
	return Qc;
}
