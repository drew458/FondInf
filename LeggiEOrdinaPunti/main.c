/* Realizzare un programma che legge le cooordinate di un insieme di punti, memorizzando tali punti in un array,
 * quindi ordina tale array per distanza crescente dei punti dall'origine ed infine stampa la lista ordinata dei punti */

#include <stdio.h>
#include <math.h>

/* Definizione del tipo di punto */
typedef struct Punto {
	float x;		//variabile x
	float y;		//variabile y
} PUNTO;

/* Funzione che scambia la posizione di due elementi in un array */ 
void scambia(PUNTO *array, int i, int j){
	PUNTO temp = array[i];
	array[i]=array[j];
	array[j]=temp;
}

/* Per calcolare la distanza di un punto dall'origine */
float distanza(PUNTO p){
	return sqrt(p.x*p.x + p.y*p.y);
}

/* Per stampare una lista di punti, con relativa distanza dall'origine */
void stampaLista(PUNTO insieme[], int n){
	printf("Ecco la lista di punti\n");
	for(int i=0; i<n; i++){
		printf("(%.2f, %.2f) con distanza dall'origine %.2f\n", insieme[i].x, insieme[i].y, distanza(insieme[i]));
	}
}

/* Per ordinare una lista di punti: implementa selection sort */
void ordinaLista(PUNTO array[], int n){
	PUNTO minimo;		//punto con la minima distanza dall'origine
	int indice;			//indice del minimo
	/* Per tutti gli indici fino al penultimo */
	for(int i=0; i<=n-2; i++){
		/* Trova l'elemento minimo fra quelli con indice compreso fra i e n-1 */ 
		indice = i;
		minimo = array[i];
		for(int j=i+1; j<=n-1; j++){
			if(distanza(array[j])<distanza(minimo)){
				minimo=array[j];
				indice=j;
			}
		}
		/* Hai trovato l'elemento minimo, mettilo nella sua posizione definitiva */
		scambia(array, i, indice);
	}
}

/* Funzione principale */
int main(){
	int n;		//numero punti
	printf("Quanti punti vuoi introdurre?\n");
	scanf("%d", &n);
	PUNTO insieme[n];
	for(int i=0; i<n; i++){
		printf("Introduci la coordinata X del punto p%d: ", i+1);
		scanf("%f", &insieme[i].x);
		printf("Introduci la coordinata Y del punto p%d: ", i+1);
		scanf("%f", &insieme[i].y);
	}
	
	/* Ordina la lista */
	ordinaLista(insieme, n);
	
	/* Output */
	stampaLista(insieme, n);
}
