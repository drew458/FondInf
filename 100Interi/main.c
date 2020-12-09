#include <stdio.h>

int main() {
	/* scrivi i primi 100 interi dentro ad un file */
	FILE *fp = fopen("100interi", "wb");
	for(int i=0; i<100; i++)
		fwrite(&i, sizeof(int), 1, fp);
	fclose(fp);

	/* leggi i primi 100 interi da un file e memorizzali in un array */
	FILE *fp2 = fopen("100interi", "rb");
	int interi[100];
	fread(interi, sizeof(int), 100, fp2);
	fclose(fp2);
	
	/* stampa i 100 interi da array */
	for(int i=0; i<100; i++)
		printf("%d ", interi[i]);
}
