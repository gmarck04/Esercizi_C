#include <stdio.h>
#include <stdlib.h>

void confronto(char stringa[100][100], int lunghezza, char *carattere_sorgente, char *carattere_sostituito ,int * num)
{
    for(int j = 0; j < num ; j++)
    {
        for(int i = 0; i < strlen(stringa[j]) ; i++){
            if(stringa[j][i] == carattere_sorgente)
                carattere_sorgente = carattere_sostituito;
        }
    }
}

void scriviOutput(char * argv[],int num){
    FILE* stream;

    if((stream = fopen(argv[2], "w")) == NULL){
        printf("errore nell'apertura del file output");
        exit(4);
    }

    fprintf(stream,"%s", argv[4][0]);

    fclose(stream);
}

int main(int argc, char * argv[]){ 
    FILE* stream; 
    char  stringa[100][100];  
    int numParole = 0; 
    char str[100]; 
    int num = 0; 
 
    if (argc != 5){ 
        printf("Argomenti errati"); 
        exit(1);     
    } 
     
    if(argv[3][1] != 'c' && argv[3][1] != 'p'){ 
        printf("Metodo errato"); 
        exit(2); 
    } 
     
    //apro stream input 
         
    if((stream = fopen(argv[1], "r")) == NULL){ 
        printf("errore nell'apertura del file input"); 
        exit(3); 
    }     
         
    //prelevo stringa da  stream input 
         
    for(numParole; !feof(stream); numParole++) 
     
        fscanf(stream, "%s\t", stringa[numParole]);         
    }

    fclose(stream);

            confronto(stringa, numParole, &argv[4][0], &argv[5][0] ,&num);
            scriviOutput(argv, num); 
 
    return 0; 
}
