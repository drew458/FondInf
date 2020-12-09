#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b;
	int minore;
	printf("Inserire due numeri\n");
	scanf("%d\n", &a);
	scanf("%d", &b);
	if(a<b){
		minore=a;
	}
	else{ 
		minore=b;
	}
	while (a%minore!=0 || b%minore!=0){
		minore=minore-1;
	}
	printf("il Massimo Comun Divisore fra %d e %d %c %d\n", a, b, 138, minore);
	return 0;
}
