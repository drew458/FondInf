#include <stdio.h>
#include <string.h>

/* funzione che verifica se tutti caratteri della stringa parametro sono numerici: REALIZZAZIONE 3 */
int tutteCifre(char *stringa){
   int  cifre; 		// il risultato

	/* CASO BASE */
   if (strlen(stringa)==0) 
	   /* se non hai caratteri da verificare, è vero che sono tutti numerici */
        cifre=1;
   else 
	   /* altrimenti controlla il primo e ricorsivamente i successivi */
         cifre= (stringa[0]>='0' && stringa[0]<='9') && tutteCifre(stringa+1);

   return cifre;
}

       
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa "); 
	printf("e determina se %c composta da soli caratteri numerici.\n",138); 
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione tutteCifre e stampo il risultato */
	if(tutteCifre(stringa))
		printf("La stringa %c composta di soli caratteri numerici!\n\n", 138);
	else
		printf("La stringa non %c composta di soli caratteri numerici!\n\n", 138);
}



