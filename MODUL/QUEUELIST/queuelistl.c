// NIM / Nama	: 13515026 / Achmad Fahrurrozi Maskur
// Nama File		: queuelist.c		
// Tanggal			: 1 November 2016

#include "queuelistl.h"
#include <stdlib.h>
#include <stdio.h>


void AlokasiQL (addressQL * P, infotypeQL X) {
	(*P) = (addressQL) malloc (sizeof (ElmtQueueL));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void DealokasiQL (addressQL P) { 
	free(P);
}

boolean IsEmptyQL (QueueL Q) {
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

int NbElmtQL (QueueL Q) {
	addressQL P;
	int N;
	P = Head(Q);
	N = 0;
	while (P != Nil) {
		N = N + 1;
		P = Next(P);
	}
	return N;
}

void CreateEmptyQL (QueueL * Q) {
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

void AddQL (QueueL * Q, infotypeQL X) {
	addressQL P;
	AlokasiQL(&P,X);
	if (P != Nil) {
		if (IsEmptyQL(*Q)) {
			Head(*Q) = P;
			Tail(*Q) = P;
		} else {
			Next(Tail(*Q)) = P;
			Tail(*Q) = P;
		}
	}
}

void DelQL (QueueL * Q, infotypeQL * X) {
	addressQL P;
	(*X) = InfoHead(*Q);
	P = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q) == Nil) {
		Tail(*Q) = Nil;
	}
	DealokasiQL(P);
}

void PrintQueueQL (QueueL Q){
	addressQL P;

	P = Head(Q);
	while (P != Nil) {
		printf("%d ",Info(P));
		P = Next(P);
	}
	printf("\n");
}

void PrintQueueEL (QueueL Q, int tutup1, int tutup2){
	addressQL P;
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
	printf("\n");
}

void InsertFirstQL (QueueL *Q, addressQL P){
	Next(P) = Head(*Q);
	Head(*Q) = P;
}

void InsertAfterQL (QueueL *Q, addressQL P, addressQL Prec){
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLastQL (QueueL *Q, addressQL P){
	addressQL Last;
	Last = Head(*Q);
	if (Head(*Q) == Nil) {
		InsertFirstQL(Q,P);
	} else {
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		InsertAfterQL(Q,P,Last);
	}
}

void DelAllQL (QueueL *Q){
	addressQL P;
	P = Head(*Q);
	while (P != Nil) {
		Head(*Q) = Next(Head(*Q));
		Next(P) = Nil;
		DealokasiQL(P);
		P = Head(*Q);
	}
}

QueueL CopyQL (QueueL Q){
	addressQL P,Pi;
	QueueL Qc;
	boolean gagal = false;
	CreateEmptyQL(&Qc);
	P = Head(Q);
	while ( P != Nil && !gagal) {
		AlokasiQL(&Pi,Info(P));
		if (Pi != Nil) {
			InsertLastQL(&Qc,Pi);
			P = Next(P);
		} else {
			DelAllQL(&Qc);
			gagal = true;
		}
	}
	return Qc;
}