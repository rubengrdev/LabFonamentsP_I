#include <stdio.h>
#include <stdbool.h>

#define MAX 100


bool replace_string(char dada[]){
    int i, j;
    char newstring[MAX];
    bool trigger = false, check = true;
    /*No es una cadena vuida*/
        while(dada[i] != '\0'){
            printf("\n%c",dada[i]);
            //todo
            i++;
        }
    return check;
}
int main (){
    char input[MAX];
    bool status;
    printf("\nInserta una cadena de text");
    scanf("%s", input);
    status = replace_string(input);
    if(status){
        printf("\nLa cadena s'ha de modificar");
    }else{
        printf("\nLa cadena NO s'ha de modificar");
    }
    return 0;
}