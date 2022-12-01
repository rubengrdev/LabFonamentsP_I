#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100


bool replace_string(char dada[]){
    int i, j = 0, k = 0;
    char newstring[MAX];
    bool trigger = false, check = true;
    /*No es una cadena vuida*/
        printf("%s", dada);
        for(i=0; i < (int)strlen(dada);i++){
            if((int)dada[i] == 32){
                j = i + 1;
                if(dada[j] >= 65 && dada[j] <= 90){
                   dada[j] = (int)dada[j] - 32;
                   trigger = true;
                   k++;
                }else if((int)dada[j] >= 97 && (int)dada[j] <= 122){
                    dada[j] = (int)dada[j] + 32;
                    trigger = true;
                    k++;
                }
            }
            newstring[i] = dada[j];
            j++;
        }
        //en el cas de que 
        if(!trigger){
            check = false;
        }
        printf("\n%d",k);
    return check;
}
int main (){
    char input[MAX];
    bool status;
    printf("\nInserta una cadena de text");
    //fgets per llegir cadena de text amb espais (string)
    fgets(input, MAX, stdin);
    status = replace_string(input);
    if(status){
        printf("\nLa cadena s'ha de modificar");
    }else{
        printf("\nLa cadena NO s'ha de modificar");
    }
    return 0;
}