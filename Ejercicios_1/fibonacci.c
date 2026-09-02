#include "fibonacci.h"

int fibonacci(int num){
    int num1 = 1, num2 = 1, prev;
    int existe = 0;

    while(num2 <= num && existe == 0){
        if(num2 == num){
            existe = 1;
        }
        else{
            prev = num2;
            num2 += num1;
            num1 = prev;
        }
    }

    return existe;
}
