#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void construir_matriu_xifrat(char matrix[][7]){
    int a, b;
    char matrix2[7][7] = {
        {' ', 'X', 'I', 'F', 'R', 'A', 'T'},
        {'N', 'A', 'B', 'C', 'D', 'E', 'F'},
        {'O', 'G', 'H', 'I', 'J', 'K', 'L'},
        {'R', 'M', 'N', 'O', 'P', 'Q', 'R'},
        {'M', 'S', 'T', 'U', 'V', 'W', 'X'},
        {'A', 'Y', 'Z', ' ', '1', '2', '3'},
        {'L', '4', '5', '6', '7', '8', '9'}
    };
    for(a = 0; a < 7; a++){
        for(b = 0; b < 7; b++){
            matrix[a][b] = matrix2[a][b];
        }
    }   
}


void xifrar_frase(char text[], char matrix[][7], char frase_xifrada[]){
    int i, j, k = 0, l = 0, o = 0;
    bool firtsValue = false;
    while(k < strlen(text)){  
        for(i = 0; i < 7; i++){
            for(j = 0; j < 7; j++){
                //la primera i fila [0] que referencia "i" i "j" és una base, no ha de se part de la clau de xifrat
                if(i >= 1 && j >= 1){
                    if(text[k] == matrix[i][j]){
                        //printf("\n%c", matrix[i][j]);
                        //printf("\nprintf: %c%c", matrix[i][0], matrix[0][j]);
                        do{
                            if(l == 0){
                                frase_xifrada[(o+l)] = matrix[i][0];
                                l++;
                            }else{
                                frase_xifrada[(o+l)] = matrix[0][j];
                                firtsValue = false; //reset variable
                                l = 0;
                            }
                            
                        }while(!firtsValue && l > 0);
                        o = o + 2;
                    }
                }
            }
        }
        k++;
    }
}

void desxifrar_frase(char textXifrat[], char matrix[][7]){
    int n, m, z = 0;
    bool triggerRow, triggerColumn;
    while (z < strlen(textXifrat)){
        triggerRow = false;
        triggerColumn = false;
        n = 0;
        m = 0;
        /*obtenció de la posició n x m a l'array/taula de el caracter original*/
        do{
            if(textXifrat[z] == matrix[n][0]){
                //l'objectiu es guardar el contador de "n" ja que té la posició n x m de la matriu
                triggerRow = true;
                z++;
            }else{
                n++;
            }
        }while(!triggerRow);
        
        do{
            if(textXifrat[z] == matrix[0][m]){
                //l'objectiu es guardar el contador de "m" ja que té la posició n x m de la matriu
                triggerColumn = true;
                z++;
            }else{
                m++;
            }
        }while(!triggerColumn);

        //demo decript
        printf("%c", matrix[n][m]);
    }
}



int main() {
    char message[] = "CONTINUEM PLA2";
    char encryptedMessage[] = "NFRFRIMIOFRIMFNARXAFRROTNXAA";
    char matrix[7][7] = {};
    char frase_xifrada[100] = '\0';

    construir_matriu_xifrat(matrix);
    xifrar_frase(message, matrix, frase_xifrada);
    printf("\n%s", encryptedMessage);
    printf("\n%s", frase_xifrada);
    //printf("\ndesxifrada: ");
    //desxifrar_frase("NFRFRIMIOFRIMFNARXAFRROTNXAA", matrix);
    
   

    return 0;
}