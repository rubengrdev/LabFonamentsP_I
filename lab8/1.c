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
    printf("\nCalcula el factorial de el numero següent: ");
    scanf("%d", &input);
    printf("\nFactorial de %d és: %d\n",input, factorial(input));
    return 0;
}