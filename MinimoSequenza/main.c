#include <stdio.h>

int main()
{
	int numeri[20];
	int minimo;
	printf("inserire 20 numeri\n");
	for(int i=0; i<20; i++){
		scanf("%d", &numeri[i]);
	}
	minimo=numeri[0];
	for(int i=1; i<20; i++){
		if(numeri[i]<minimo){
			minimo=numeri[i];
			
		}
	printf("il minimo nel ciclo numero %d %c %d\n", i, 138, minimo);
	}
	printf("il minimo tra i numeri inseriti %c %d\n", 138, minimo);
	return 0;
}
