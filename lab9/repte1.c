#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef struct
{
char cadena, cad[MAX];
} str;

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
    str cadena, cad[MAX];
    int j;
    printf("\nInserta una cadena de text, només pots utilitzar caràcters del tipus: [a-z] - [A-Z]");
    scanf("%c", &cad[MAX]);
    
    //comprova_string(cad);
    return 0;
}