#include <stdio.h>

int main(int argc, char **argv) {
	
	int *puntaX;		// puntatore ad un intero
	int x = 13;
	
	puntaX = &x;		// memorizza un indirizzo dentro al puntatore 
	printf("La variabile puntaX ha valore %d\n", puntaX);

	/* stampa corretta */
	printf("La variabile puntaX ha valore %p\n", (void *) puntaX);
	
	/* accesso al valore puntato */
	printf("Ecco il valore di x: %d\n", x);
	printf("che posso ottenere anche come: %d\n", *puntaX);
	
	/* accesso in lettura */
	int y = *puntaX +5;
	printf("La variabile y ha valore %d\n", y);

	/* accesso in scrittura */
	*puntaX = 27;
	printf("Adesso l'area di memoria puntata memorizza il valore %d\n", *puntaX);
	printf("e se non ci credi guarda il valore di x %d\n", x);

	printf("Valore x: %d\n", x);
	printf("Valore &x: %d\n",&x);
	printf("Valore *puntaX: %d\n", *puntaX);
	printf("Valore puntaX: %d\n", puntaX);
	printf("Valore &puntaX: %d\n", &puntaX);

	}
