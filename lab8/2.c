#include <stdio.h>

int factorial(int num){
    int factorial = 1;
    for(int i = 1; i <= num; i++){
        factorial = factorial*i;
    }
    return factorial;
}

int variacions_sense_repeticio(int m, int n){
    int calcul = 0;
    if(m > n){
        calcul = (factorial(m)) / (factorial((m-n)));
    }
    return calcul;
}
int main(){
    int input1, input2;
    printf("\nInserta el primer valor (m)");
    scanf("%d", &input1);
    printf("\nInserta el segón valor (n)");
    scanf("%d", &input2);
    printf("\nVariacions sense repetició de %d i %d és: %d\n",input1, input2, variacions_sense_repeticio(input1, input2));
    return 0;
}