#include <stdio.h>
#include <stdbool.h>

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
   int input, input1, input2, opcio;
    do{
        printf("\n1.- Calcular el factorial");
        printf("\n2.- Calcular les variacions (sense repetició)");
        printf("\n3.- Sortir del programa");
        printf("\n\nQuina opció vols?:");
        scanf("%d", &opcio);
    }while(opcio < 1 || opcio > 3);

    switch (opcio)
    {
    case 1:
        printf("\nCalcula el factorial de el numero següent (entre 1 i 16): ");
        scanf("%d", &input);
         if(input > 1 || input < 16){
            printf("\nFactorial de %d és: %d\n",input, factorial(input));
         }else{
            printf("\nNo es pot calcular factorial, només valors entre 1 i 16");
         }
        break;
    case 2:
            printf("\nInserta el primer valor (m)");
            scanf("%d", &input1);
            printf("\nInserta el segón valor (n)");
            scanf("%d", &input2);
            if(input1 > 1 || input1 < 16){
                printf("\nVariacions sense repetició de %d i %d és: %d\n",input1, input2, variacions_sense_repeticio(input1, input2));
            }else{
                printf("\nNo es pot calcular ja que m és molt gran (només s'acceptan valors entre 1 i 16 per a M");
            }
        break;
    case 3:
         printf("\nSortint del programa...\n");
        break;
    default:
        break;
    }
    
    return opcio;
}

int main(){
     /*Definició de variables generals per a tots els casos*/
    bool output = false;
    do{
        if(mostra_opcions() == 3){
            output = true;
        }
    }while(!output);
    
    
    return 0;
}