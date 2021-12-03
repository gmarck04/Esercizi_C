#include <stdio.h>

int main(int argc, char *argv[])
{
	somma(argv[]);
	printf("il numero e' %d", somma());
	return 0;
}

int somma(char *argv[])
{
	int a = atoi(argv[0]);
	int b = atoi(argv[1]);
	int c = a+b;
	return c;
}

