#include <stdio.h>

/* funzione che crea un intero e ne restituisce l'indirizzo */
int *generaIntero()  {
	int x = 3;
	printf("L'indirizzo di x vale %d\n", &x);
	return &x;
//	int* y = &x;
//  return y;
}

int main() {
	int *dangling=generaIntero();		// ottieni l'indirizzo della variabile generata
	printf("La variabile puntata ha indirizzo %d\n", dangling);
//	printf("La variabile puntata vale %d ed ha indirizzo %d\n", *dangling, dangling);
}
