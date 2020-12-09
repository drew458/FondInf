/* Scrivere un programma che prende in input una stringa non vuota di caratteri e 
 * che restituisce true se la stringa è composta da almeno un carattere alfabetico minuscolo, false altrimenti. 
 * Tale verifica deve essere realizzata attraverso una funzione ricorsiva. */

#include <stdio.h>
#include <string.h>

int minuscola(char stringa[]){
	int risultato;
	if(strlen(stringa)==0){
		risultato=0;
	}
	else{
		risultato = (stringa[strlen(stringa)-1]>'a' && stringa[strlen(stringa)-1]<'z') || minuscola(stringa-1);
	}
	
	return risultato;
}

int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa "); 
	printf("e determina se contiene almeno un carattere alfabetico minuscolo.\n"); 
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	if(minuscola(stringa))
		printf("La stringa contiene nessun carattere alfabetico minuscolo\n\n");
	else
		printf("La stringa non contiene nessun carattere alfabetico minuscolo\n\n");
}