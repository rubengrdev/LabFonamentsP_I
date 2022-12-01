#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXSTR 100
#define MAX 10

bool comprova_string(char dada[]){
    int i, asciicode;
    bool trigger = false, check = true;
    /*No es una cadena vuida*/
        while(dada[i] != '\0'){
            /*Comprvació letres en majuscula i minuscula i espai en blanc*/
            if(dada[i] >= 65 && dada[i] <= 90 || dada[i] >= 97 && dada[i] <= 122 || dada[i] == 32){
                //dada correcta
                trigger = true;
            }else{
                trigger = false;
            }
            //s'ha trobat un item incorrecte
            if(!trigger){
                check = false;
            }
            i++;
        }  
    return check;
}

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

bool check_phone(char dada[]){
    int i;
    bool check = false;
    //utilitzo una funció de C per poder agilitzar el procés strlen()
    for(i = 1; i < (int)strlen(dada); i++){
        if(i == 9){
            check = true;
        }else{
            check = false;
        }
    }
    //retorna si es valid o no
    return check;
}


int main (){
    char input[MAXSTR];
    char inputphone[MAX];
    bool statusphone;
    int mods;
    printf("\nInserta el teu nom, només pots utilitzar caràcters del tipus [a-z]-[A-Z]");
    
    do{
        //fgets per llegir cadena de text amb espais (string)
        fgets(input, MAXSTR, stdin);
    }while(!comprova_string(input));
    
    mods = replace_string(input);
    if(mods > 0){
        printf("\nLa cadena s'ha de modificar %d vegades", mods);
    }else{
        printf("\nLa cadena NO s'ha de modificar");
    }
    return 0;
}