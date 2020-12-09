#include <stdio.h>

int main(){
	/* array e puntatori, corrispondenza base */ 
	int num[3] = {1,3,7};
	int *puntatore = num;
	printf("Ecco il valore puntato: %d\n", *puntatore);
	*puntatore = 2;
	printf("Ecco il primo elemento di num: %d\n", num[0]);
	
	/* array e puntatori potrebbero sembrare la stessa cosa .... */ 
	char stringa1[] = "ciao";
	char* stringa2 = "cari";
	printf("%s %s\n", stringa1, stringa2);
	
	/* ... ma non lo sono! */ 
	/* memorizzazione in un array */
	char stringaLeggi[50];
	printf("Introduci una stringa: ");
	fgets(stringaLeggi, 50, stdin);
	printf("Hai introdotto: %s", stringaLeggi);

	/* memorizzazione in un puntatore */
	char* stringaPunta;
	printf("Introduci una stringa: ");
	fgets(stringaPunta, 50, stdin);
	printf("Hai introdotto: %s", stringaPunta);
}
