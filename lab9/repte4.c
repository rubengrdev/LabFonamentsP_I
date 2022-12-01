#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXSTR 100
#define MAX 10

bool comprova_string(char dada[]){
    int i, asciicode;
    bool trigger = false, check = true;
    /*No es una cadena vuida*/
        for(i = 0; i < strlen(dada); i++){
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
    char newstring[MAXSTR];
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
    printf("\nInserta el teu nom complet, només pots utilitzar caràcters del tipus [a-z]-[A-Z]");
    do{
        //fgets per llegir cadena de text amb espais (string)
        fgets(input, MAXSTR, stdin);
         if(comprova_string(input)){
            printf("\nLa cadena és valida");
        }else{
            printf("\nLa cadena NO és valida");
            printf("\nInserta el teu nom complet, només pots utilitzar caràcters del tipus [a-z]-[A-Z]");
        }
    }while(!comprova_string(input));
    printf("\nS'han fet %d conversions de lletres", replace_string(input));
    printf("\nInserta el teu telèfon:");
    do{
        fgets(inputphone, MAX, stdin);
        if(check_phone(inputphone)){
            printf("\nEl telefon es correcte");
        }else{
            printf("\nEl telefon es incorrecte\n");
        }
    }while(!check_phone(inputphone));
    return 0;
}