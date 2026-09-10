#include "palindromo.h"
#include <stdio.h>

int esPalindromo(char *vecCorr, int med){
    int i = 0, j = med - 1;
    int mitad = med / 2;
    int palindromo = 1;

    while(palindromo && i < mitad){
        if(*(vecCorr+i) != *(vecCorr+j)){
            palindromo = 0;
        }else{
            i++;
            j--;
        }
    }

    return palindromo;
}
