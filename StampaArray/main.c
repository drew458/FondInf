#include <stdio.h>

int main(int argc, char **argv)
{
	int num[] = {1,1,2,3,5,8,13,21,34,55,89};
	int *puntaFibo = num;
	printf("L'area di memoria puntata vale: %d\n", puntaFibo);
	
	printf("Ecco i numeri di Fibonacci: \n");
	for(int i=0; i<11; i++){
		printf("Valore %d ", *(puntaFibo));
		printf("Indirizzo %d \n", (puntaFibo));
		puntaFibo=puntaFibo+1;
	}
}
