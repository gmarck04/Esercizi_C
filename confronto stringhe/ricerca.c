#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *read;
	FILE *write;
	char stringa[100][100];
	int conta1 = 0;
	int numero_parole = 0;

	if((read = fopen(argv[1],"r")) == NULL)
	{
		printf("Il file di lettura non esiste");
		exit(1);
	}

	if((write = fopen(argv[2],"w")) == NULL)
	{
		printf("Il file di scrittura non esiste");
		exit(2);
	}

	do
	{
		fscanf(read, "%s/t", stringa[conta1]);
		conta1++;
	}while(!feof(read));

	fclose(read);

	for(int i = 0; i<conta1; i++)
	{
		if(strcmp(stringa[i],argv[3]) == 0)
		{
			numero_parole++;
		}
	}

	printf("il numero di parole uguali e' %d", numero_parole);
	fprintf(write, "il numero di parole uguali e' %d",numero_parole);
	fclose(write); 
	return 0;
}
