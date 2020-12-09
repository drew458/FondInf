#include <stdio.h>

/* Funzione che riceve come parametro una stringa e restituisce la massima differenza 
 * (in valore assoluto) fra due caratteri numerici che appartengono alla stringa e fra i 
 * quali non ci sono altri caratteri numerici, oppure -1 se la stringa non contiene 
 * due caratteri numerici. */
int differenzaNumerici(char *stringa){
	int differenza;						//Differenza tra i due caratteri numerici
	int differenzatrovata=0;			//Ho trovato due caratteri numerici per cui fare la differenza
	int i=0;							//Variabile contatore
	int j;								//Variabile contatore
	
	/* Scorre tutti gli elementi della stringa */
	while(stringa[i]!='\0' && !differenzatrovata && differenza!=-1){
		/* Controlla se l'elemento della stringa è un numero */
		if(stringa[i]>='0' && stringa[i]<='9' && !differenzatrovata){
			j=i+1;
			/* Se l'elemento successivo corrisponde alla fine della stringa, il ciclo di ferma */
			if(stringa[j]=='\0'){
				differenza=-1;
			}
			else{
				/* Scorre tutti gli elementi della stringa dell'elemento i-esimo fino alla fine */
				while(stringa[j]!='\0' && !differenzatrovata){
					/* Controlla se l'elemento della stringa è un numero */
					if(stringa[j]>='0' && stringa[j]<='9' && !differenzatrovata){
						/* Controlla quale è più grande tra i due caratteri numerici trovati, quindi fa la differenza */
						if(stringa[i]>=stringa[j]){
							differenza=stringa[i]-stringa[j];
							differenzatrovata=1;
						}
						else{
							differenza=stringa[j]-stringa[i];
							differenzatrovata=1;
						}
					}
					else{
						j++;
					}
				}
			}
		}
		else{
			i++;
		}
	}
	if(differenzatrovata==0){
		differenza=-1;
	}
	return differenza;
}

void testDifferenzaNumerici(){
	/* Stringa vuota */
	char stringa1[]="";
	printf("Test differenzaNumerici(\"\"): Atteso= -1 ; Calcolato= %d\n", differenzaNumerici(stringa1));
	
	/* Stringa con una sola lettera */
	char stringa2[]="a";
	printf("Test differenzaNumerici(\"a\"): Atteso= -1 ; Calcolato= %d\n", differenzaNumerici(stringa2));
	
	/* Stringa con un solo numero */
	char stringa3[]="2";
	printf("Test differenzaNumerici(\"2\"): Atteso= -1 ; Calcolato= %d\n", differenzaNumerici(stringa3));
	
	/* Stringa con una lettera ed un numero */
	char stringa4[]="a1";
	printf("Test differenzaNumerici(\"a1\"): Atteso= -1 ; Calcolato= %d\n", differenzaNumerici(stringa4));
	
	/* Stringa con una lettera e due numeri */
	char stringa5[]="a12";
	printf("Test differenzaNumerici(\"a12\"): Atteso= 1 ; Calcolato= %d\n", differenzaNumerici(stringa5));
	
	/* Stringa con due numeri separati da lettere */
	char stringa6[]="a5usus4d";
	printf("Test differenzaNumerici(\"a5usus4d\"): Atteso= 1 ; Calcolato= %d\n", differenzaNumerici(stringa6));
}

int main(){
	char stringa[50];
	printf("Inserisci una stringa\n");
	fgets(stringa,50,stdin);
	int differenza;
	differenza=differenzaNumerici(stringa);
	if(differenza<0){
		printf("Nella stringa non ci sono caratteri numerici\n\n");
	}
	else{
		printf("La differenza massima tra i due caratteri numerici nella stringa %c: %d\n\n", 138, differenza);
	}
	testDifferenzaNumerici();
}
