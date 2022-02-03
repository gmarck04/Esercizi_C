#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    int status;
    int fd[2];
    pipe(fd);
    int pid1 = fork();
    if (pid1 == 0) //Processo figlio 1
    {
        close(1);
        dup(fd[1]);
        close(fd[1]);
        close(fd[0]);
        execl("/bin/cat", "cat", "file.txt", NULL);
        exit(1);
    }
    else
    {
        int pid2 = fork();
        if (pid2 == 0) //Processo figlio 2
        {
            close(0);
            dup(fd[0]);
            close(fd[0]);
            close(fd[1]);
            char cmd[] = "wc -l";
            execl("/bin/wc", cmd, NULL);
            exit(2);
        }
        else
        {
            wait(&status);
            close(fd[0]);
            close(fd[1]);
            printf("I processi figli hanno terminato\n");
        }
    }
}
