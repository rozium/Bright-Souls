#include "mesinkata.h"
#include <stdio.h>

int main(){
	// START mewakili START... yang lain
	STARTKATA();
	while (!EndKata){
		int i;
		for (i = 1;i<= CKata.Length;i++){
			printf("%c",CKata.TabKata[i]);			
		}
		printf(" \n");
		ADVKATA();
	}
	return 0;
}