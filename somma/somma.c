#include <stdio.h>

int somma(char *argv[])
{
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        int c = a+b;
        return c;
}

int main(int argc, char *argv[])
{
        int valore = somma(argv);
	FILE *scrivi;
	scrivi = fopen("output.txt", "w+");

	fprintf(scrivi,"il numero e' %d", valore);
        printf("il numero e' %d", valore);

	fclose(scrivi);
        return 0;
}
