#include <stdio.h>

struct Punto {
	float x;			// la coordinata x
	float y;			// la coordinata y
};

/* legge e stampa un punto */
int main() {
	struct Punto p;				// un punto
	printf("Introduci una coordinata x: ");
	scanf("%f", &p.x);
	printf("Introduci una coordinata y: ");
	scanf("%f", &p.y);

	printf("Ecco le coordinate del tuo punto: (%.2f,%.2f)\n", p.x, p.y);
}

