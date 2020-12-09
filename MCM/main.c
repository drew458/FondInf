#include <stdio.h>
#include "header.h"

int main()
{
	int n1=0;
	int n2=0;
	int n3=0;
	int n4=0;
	int r=0;
	int mcd=0;
	int mcm=0;
	printf("Inserire il primo numero\n");
	scanf("%d", &n1);
	printf("Inserire il secondo numero\n");
	scanf("%d", &n2);
	controlloNumeri(n1,n2,n3,n4,r);
	printf("MCD = %d\nMCM = %d\n", MCD(n1,n2,n3,n4,r), MCM(n1,n2,n3,n4,r,mcd));
	return 0;
}
