// @file Somma.c
// @brief file esempio somma
// @date file creato il 04/11/2021

/**
* @fn int somma(int a, int b)
* @brief funzione che somma i parametri
* @param int a: primo valore da sommare
* @param int b: secondo valore da sommare
* @return int: la funzione ritorna la somma di 5 e 6
* @date 04/11/2021
* @author Giovanni Marchetto
* @file Somma.c
*/
#include <stdio.h>

int somma(int a, int b){
return a+b;
}

int main(){
int sommanumero = somma(5,6);
printf("%d",sommanumero);
return 0;
}
