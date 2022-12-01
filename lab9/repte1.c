#include <stdio.h>
#include <stdbool.h>

#define MAX 100

/*Métode per comprovar si la cadena de text es correcta (només paraules sense 'chars' estranys)*/
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
int main (){
    char input[MAX];
    bool status;
    printf("\nInserta una cadena de text, només pots utilitzar caràcters del tipus: [a-z] - [A-Z]");
    scanf("%s", input);
    /*Resultat de la funció anterior*/
    status = comprova_string(input);
    if(status){
        printf("\nLa cadena és valida");
    }else{
        printf("\nLa cadena NO és valida");
    }
    return 0;
}