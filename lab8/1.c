#include <stdio.h>

int factorial(int num){
    int i, factorial = 1;
    for(i = 1; i <= num; i++){
        factorial = factorial*i;
    }
    return factorial;
}

int main(){
    int input;
    while(input < 1 || input > 19){
        printf("\nCalcula el factorial de el numero següent (entre 1 i 19): ");
        scanf("%d", &input);
        printf("\nFactorial de %d és: %d\n",input, factorial(input));
    }
    return 0;
}