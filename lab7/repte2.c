#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int main(){
    char frase[MAX], copyFrase[MAX];
    char vocals[5] = {'a', 'e', 'i', 'o', 'u'};
    int vocal = 0, pos = 0;
    bool dot = false;

    printf("Introdueix una frase acabada amb punt.\n");
    fgets(frase, MAX, stdin);
    while(frase[pos]){
         /*Backup de la frase*/
        copyFrase[pos] =frase[pos];
        if(frase[pos] == '.'){
            dot = true;
        }
        pos++;
    }
    if(dot){
        while(vocal < 5){
            for(int i = 0; i < pos; i++){
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
    }else{
        printf("Error! La frase no acaba amb punt");
    }
    return 0;
}