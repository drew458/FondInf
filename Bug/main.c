#include <stdio.h>

int main(int argc, char **argv)
{
	int a=1;
	int i=0;
	while(a>0){
		a++;
		i++;
		printf("\t\tIl valore con un incremento lineare di %d e pari a %d \n", i, a);
	}
	return 0;
}
