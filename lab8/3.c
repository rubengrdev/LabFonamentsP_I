#include <stdio.h>

int factorial(int num){
    int i, factorial = 1;
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

int mostra_opcions(){
    /*Definició de variables generals per a tots els casos*/
    int input, input1, input2;
    int opcio = 0;
    while(opcio < 1 || opcio > 3){
        printf("\n1.- Calcular el factorial");
        printf("\n2.- Calcular les variacions (sense repetició)");
        printf("\n3.- Sortir del programa");
        printf("\n\nQuina opció vols?:");
        scanf("%d", &opcio);
    }
    if(opcio == 1){
        printf("\nCalcula el factorial de el numero següent: ");
        scanf("%d", &input);
        printf("\nFactorial de %d és: %d\n",input, factorial(input));
    }else if(opcio == 2){
            printf("\nInserta el primer valor (m)");
            scanf("%d", &input1);
            printf("\nInserta el segón valor (n)");
            scanf("%d", &input2);
            printf("\nVariacions sense repetició de %d i %d és: %d\n",input1, input2, variacions_sense_repeticio(input1, input2));
    }else if(opcio == 3){
        printf("\nSortint del programa...\n");
    }
    return opcio;
}
int main(){
    mostra_opcions();
    return 0;
}