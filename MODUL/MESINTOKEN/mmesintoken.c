#include "mesintoken.h"
#include <stdio.h>

int main(){
	printf("input status karakter : 1. mahasiswa, 2. begal, 3. satpam, 4.kuli\n");
	int N;
	scanf("%d",&N);
	STARTGAMETOKEN(N);
	while (!EndToken){
		if (CToken.val != -1){			
			printf("%d ",CToken.val);
		}else{
			printf("%c ",CToken.tkn);
		}
		ADVTOKEN();
	}
	return 0;
}