#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b;
	int maggiore,minore;
	printf("Inserire due numeri\n");
	scanf("%d\n", &a);
	scanf("%d", &b);
	if(a>b){
		maggiore=a;
		minore=b;
	}
	else 
		maggiore=b;
		minore=a;
	printf("Il numero maggiore %c %d\n", 138, maggiore);
	printf("Il numero minore %c %d\n", 138, minore);
	return 0;
}
