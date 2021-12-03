#include <stdio.h>

int main(int argc, char *argv[])
{
	char stringa[100][100];
	int conta;
	FILE *fp;
	FILE *scrivi;
	scrivi = fopen("output.txt", "w");
	fp = fopen("ciao.txt", "r");
	do
	{
		fscanf(fp, "%s/t", stringa[conta]);
		printf(stringa[conta]);
		fprintf(scrivi, "%s ", stringa[conta]);
		conta++;
	}while(!feof(fp));



	fclose(fp);
	return 0;
}
