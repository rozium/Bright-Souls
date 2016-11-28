#include "matriks.h"
#include <stdio.h>


int main(){
	MATRIKS M,Mtemp;
	MakeMATRIKS(5,5,&M);
	BacaMATRIKS(&M,3,3);
	CopyMATRIKS(M,&Mtemp);
	TulisMATRIKS(M);
	TulisMATRIKS(Mtemp);
	printf("apakah index (1,1) valid?\n");
	if (IsIdxValid(1,1)){
		printf("true\n");
	}else{
		printf("false\n");
	}
	printf("first index brs => %d\n",GetFirstIdxBrs(M));
	printf("First index kol => %d\n",GetFirstIdxKol(M));
	printf("last index brs = > %d\n",GetLastIdxBrs(M));
	printf("last index kol = > %d\n",GetLastIdxKol(M));
	printf("apakah index (1,1) efektif?\n");
	if (IsIdxValid(1,1)){
		printf("true\n");
	}else{
		printf("false\n");
	}
	printf("berapakah jumlah NBElmt = %d\n",NBElmt(M));


	return 0;
}
