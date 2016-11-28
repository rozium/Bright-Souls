#include "mesinkar.h"
#include <stdio.h>

extern char CC,CC2;
extern boolean EOP,EOP2;

int main(){
	// START() dianggap sudah mewakili START... yang lain
	START();
	while (CC != '.'){
		printf("%c",CC);
		ADV();
	}
	return 0;
}

