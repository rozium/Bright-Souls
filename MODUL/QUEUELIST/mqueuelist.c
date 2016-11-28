// NIM / Nama       : 13515026 / Achmad Fahrurrozi Maskur
// Nama File        : mqueuelist.c

// DRIVER queuelist dan queuelistl

#include "queuelist.h"
#include <stdio.h>

int main(){
	Queue Q,Qcopy;
	infotypeQ X;

	printf("Buat Queue kosong\n");
	CreateEmptyQ(&Q);
	printf("Queue Berhasil dibuat!\n\n");

	printf("Check apakah queue kosong:\n");
	if (IsEmptyQ(Q)) {
		printf("    Queue Kosong\n\n");
	}
	printf("Penambahan Elemen '3' ke dalam Queue\n\n");
	X = '3';
	AddQ(&Q,X);

	printf("Penambahan Elemen '1' ke dalam Queue\n\n");
	X = '1';
	AddQ(&Q,X);

	printf("Print isi Queue\n");
	printf("Isi Queue = "); PrintQueueQ(Q);

	printf("Test input elemen ke Queue: ");scanf("%c",&X);
	AddQ(&Q,X);

	printf("Isi Queue = "); PrintQueueQ(Q);

	printf("Print NBElmt Queue\n");
	printf("NbElmt = %d\n",NbElmtQ(Q));

	printf("TEST Del Queue\n");
	DelQ(&Q,&X);
	printf("Isi Queue = "); PrintQueueQ(Q);

	printf("Nilai X = '%c'\n",X);

	printf("TEST COPY Q ke Qcopy\n");
	CreateEmptyQ(&Qcopy);
	Qcopy = CopyQ(Q);
	printf("Isi Qcopy = "); PrintQueueQ(Qcopy);

	return 0;
}