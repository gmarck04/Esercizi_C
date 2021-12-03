#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CHAR 10

typedef struct
{
	char nome[MAX_CHAR];
	char cognome[MAX_CHAR];
	char numero[MAX_CHAR];
} Persona_T;

void MostraRubrica(Persona_T persone[], int righe)
{
	for (int i = 0; i < righe; i++)
	{
		printf("%s\n", persone[i].nome);
		printf("%s\n",persone[i].cognome);
		printf("%s\n",persone[i].numero);
	}
}

void AggiungiContatto(Persona_T persone[], int righe, int argc, char *argv[])
{	
	FILE *Write;
	
	Persona_T nuovo;
	printf("Inserisci nome");
	scanf("%s", nuovo.nome);
	printf("Inserisci cognome");
	scanf("%s", nuovo.cognome);
	printf("Inserisci numero");
	scanf("%s", nuovo.numero);
	if (argc == 2)
	{
		if ((Write = fopen(argv[1], "w")) == NULL)
		{
			printf("impossibile aprire file");
			exit(5);
		}	
		
		for (int i = 0; i < righe; i++)
		{
			fprintf(Write, "%s %s %s\n", persone[i].nome, persone[i].cognome, persone[i].numero);
		}
		fprintf(Write, "%s %s %s", nuovo.nome,nuovo.cognome,nuovo.numero);
		fclose(Write);
	}
	else if (argc == 4)
	{
		if ((Write = fopen(argv[3], "w")) == NULL)
		{	
			printf("impossibile aprire file");
			exit(6);
		}
		for (int i = 0; i < righe; i++)
		{
			fprintf(Write, "%s %s %s\n", persone[i].nome, persone[i].cognome, persone[i].numero);
		}
		fprintf(Write, "%s %s %s", nuovo.nome,nuovo.cognome,nuovo.numero);
		fclose(Write);
	}
}

void RimuoviContatto(Persona_T persone[], int righe, int argc, char *argv[])
{
	FILE *Write;
	Persona_T rimuovi;
	int codice = -1;
	
	while(codice == -1)
	{
		printf("Inserisci nome");
		scanf("%s", rimuovi.nome);
		printf("Inserisci cognome");
		scanf("%s", rimuovi.cognome);
	
		for (int i = 0; i < righe; i++)
		{
			if ((persone[i].nome == rimuovi.nome) && (persone[i].cognome == rimuovi.cognome))
			{
				printf("Contatto trovato");
				codice = 0;
			}
		}
		if (codice == -1)
		{
			printf("Contatto non trovato");
		}
	}
	
	if (argc == 2)
	{
		if ((Write = fopen(argv[1], "w")) == NULL)
		{
			printf("impossibile aprire file");
			exit(5);
		}	
		
		for (int i = 0; i < righe; i++)
		{
			if (persone[i].nome != rimuovi.nome && persone[i].cognome != rimuovi.cognome)
			{
				fprintf(Write, "%s %s %s\n", persone[i].nome, persone[i].cognome, persone[i].numero);
			}
		}
		fclose(Write);
	}
	else if (argc == 4)
	{
		if ((Write = fopen(argv[3], "w")) == NULL)
		{	
			printf("impossibile aprire file");
			exit(6);
		}
		for (int i = 0; i < righe; i++)
		{
			if (persone[i].nome != rimuovi.nome && persone[i].cognome != rimuovi.cognome)
			{
				fprintf(Write, "%s %s %s\n", persone[i].nome, persone[i].cognome, persone[i].numero);
			}
		}
		fclose(Write);
	}
}

int main(int argc, char *argv[])
{	
	FILE *Read;
	int scelta, righe;
	Persona_T persone[100];
	
	if((argc != 2 && argc != 4) || (argc == 4 && strcmp(argv[2], "-f") != 0))
	{
		printf("Argomenti non validi");
		exit(3);
	}
		
	if ((Read = fopen(argv[1], "r")) == NULL)
	{
		printf("impossibile aprire file");
		exit(2);
	}
	
	do
	{
		fscanf(Read, "%s %s %s", persone[righe].nome, persone[righe].cognome, persone[righe].numero);
		righe++;
	}while (!feof(Read));
	
	fclose(Read);	
	do
	{
		printf("Menù:\n 1)Mostra Rubrica,\n 2)Aggiungi contatto,\n 3)Rimuovi contatto,\n 4)Chiudi programma.");
		scanf("%d", &scelta);
		
		switch(scelta)
		{
			case 1:
			{
				MostraRubrica(persone, righe);
			}
			break;
			case 2:
			{
				AggiungiContatto(persone, righe, argc, argv);
			}
			break;
			case 3:
			{
				RimuoviContatto(persone, righe, argc, argv);
			}
			break;
			case 4:
			{
				exit(1);
			}
			break;
			default:
			{
				printf("Scelta non valida");
			}
			break;
	}	
	}while (scelta != 1 || scelta != 2 || scelta != 3 || scelta != 4);
	return 0;
}
