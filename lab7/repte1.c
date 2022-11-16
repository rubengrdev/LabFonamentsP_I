#include <stdio.h>
#define MAX 100

int main(){
    char frase[MAX], copyFrase[MAX];
    char vocals[5] = {'a', 'e', 'i', 'o', 'u'};
    int counter = 0, vocal = 0;

    printf("Introdueix una frase acabada amb punt.\n");
    fgets(frase, MAX, stdin);
    /*Conocemos tamaño de la frase*/
    while(frase[counter] != '.'){
        /*Backup de la frase*/
        copyFrase[counter] =frase[counter];
        counter++;
    }
    while(vocal < 5){
        for(int i = 0; i < counter; i++){
            for(int j = 0; j < 5; j++){
                if(frase[i] == vocals[j]){
                    frase[i] = vocals[vocal];
                }
            }
        }
        vocal++;
        printf("\n%s", copyFrase);
        printf("\n%s\n", frase); 
    }
    return 0;
}