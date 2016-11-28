#include <stdlib.h>
#include <stdio.h>
#include "stacklist.h"

int main(){

	Stack S;
	CreateEmptyS(&S);
	if(IsEmptyS(S))
	{
		printf("Stack Kosong\n");
	}
	Kata K1;
	K1.Length = 3;
	K1.TabKata[1] = 'H';
	K1.TabKata[2] = 'A';
	K1.TabKata[3] = 'I';
	
	Kata K2;
	K2.Length = 3;
	K2.TabKata[1] = 'M';
	K2.TabKata[2] = 'A';
	K2.TabKata[3] = 'U';

	Kata K3;

	PushS(&S, K1);
	PushS(&S, K2);
	PopS(&S, &K3);
	PrintKata(K3);
	printf("\n");
	PrintStack(S);
	return 0;
}