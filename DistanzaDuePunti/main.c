#include <stdio.h>
#include <math.h>

struct Punto {
	float x;			// la coordinata x
	float y;			// la coordinata y
};

/* calcola la distanza fra due punti */
float distanza(struct Punto p1, struct Punto p2) {
	float d;
	d=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	return d;
}

/* legge due punti e ne stampa la distanza */
int main() {
	struct Punto p1, p2;				// due punti
	
	/* INPUT */
	printf("Introduci la coordinata x del primo punto: ");
	scanf("%f", &p1.x);
	printf("Introduci la coordinata y del primo punto: ");
	scanf("%f", &p1.y);

	printf("Introduci la coordinata x del secondo punto: ");
	scanf("%f", &p2.x);
	printf("Introduci la coordinata y del secondo punto: ");
	scanf("%f", &p2.y);

	/* CALCOLA DISTANZA E STAMPA OUTPUT */
	printf("La distanza fra i due punti vale %.2f", distanza(p1,p2) );
}

