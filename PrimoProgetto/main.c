/*
#include <stdio.h>
int main()
{
	int x,y,z;
	int massimo;
	printf("Inserire tre numeri di cui si vuole calcolare il Massimo\n");
	scanf("%d\n", &x);
	scanf("%d\n", &y);
	scanf("%d", &z);
	massimo=x;
	if(y>massimo){
		massimo=y;
	}
	if (z>massimo){
		massimo=z;
	}
	printf("il massimo e' %d\n", massimo);
	return 0;
}
*/

#include <stdio.h>
int main()
{
	int x,y,z;
	int massimo;
	printf("Inserire tre numeri di cui si vuole calcolare il Massimo\n");
	scanf("%d\n", &x);
	scanf("%d\n", &y);
	scanf("%d", &z);
	if(x>y){
		massimo=x;
	}
	else massimo=y;
	if(z>massimo){
		massimo=z;
	}
	printf("il massimo e' %d\n", massimo);
	return 0;
}