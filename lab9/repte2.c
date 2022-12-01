#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100


int replace_string(char dada[]){
    int i, j = 0, k = 0;
    char newstring[MAX];
    //utilitzo una funció de C per poder agilitzar el procés strlen()
        for(i=0; i < (int)strlen(dada);i++){
            if((int)dada[i] == 32){
                j = i + 1;
                if(dada[j] >= 65 && dada[j] <= 90){
                   dada[j] = (int)dada[j] - 32;
                   k++;
                }else if((int)dada[j] >= 97 && (int)dada[j] <= 122){
                    dada[j] = (int)dada[j] + 32;
                    k++;
                }
            }
            newstring[i] = dada[j];
            j++;
        }
        //retorna el numero de modifiacions que necessita
        return k;
}
int main (){
    char input[MAX];
    int mods;
    printf("\nInserta una cadena de text");
    //fgets per llegir cadena de text amb espais (string)
    fgets(input, MAX, stdin);
    mods = replace_string(input);
    if(mods > 0){
        printf("\nLa cadena s'ha de modificar %d vegades", mods);
    }else{
        printf("\nLa cadena NO s'ha de modificar");
    }
    return 0;
}