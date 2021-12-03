#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define numero 9

int main(int argc, char *argv[])
{
	int pid1 = fork();

	if(pid1 == 0)
	{
		printf("io sono il figlio");
		exit (0);
	}
	else
	{
		//pid1 = wait(0);
		wait(&pid1);
		printf("\nio sono il padre");
		printf("\n%d",numero);
	}
	return 0;
}
