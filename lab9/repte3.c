#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100


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
    char input[MAX];
    bool status;
    printf("\nInserta un numero de telèfon");
    //fgets per llegir cadena de text amb espais (string)
    fgets(input, MAX, stdin);
    printf("\n%s", input);
    status = check_phone(input);
    if(status){
        printf("\nEl numero de telèfon és correcte");
    }else{
        printf("\nEl numero de telèfon NO és correcte");
    }
    return 0;
}