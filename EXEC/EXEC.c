#include stdio.h
#include stdlib.h
#include unistd.h
#include syswait.h

void main()
{
    int status;
    int fd[2];
    pipe(fd);
    int p1 = fork();
    if (p1 == 0) Processo figlio 1
    {
        close(1);
        dup(fd[1]);
        close(fd[1]);
        close(fd[0]);
        execl(bincat, cat, file.txt, NULL);
        exit(1);
    }
    else
    {
        int p2 = fork();
        if (p2 == 0) Processo figlio 2
        {
            close(0);
            dup(fd[0]);
            close(fd[0]);
            close(fd[1]);
            char cmd[] = wc -l;
            execl(binwc, cmd, NULL);
            exit(2);
        }
        else
        {
            wait(&status);
            close(fd[0]);
            close(fd[1]);
            printf(I figli hanno terminaton);
        }
    }
}