#include <stdio.h>
#include <stdbool.h>

int main() {
    int i, j, k = 0, z = 0;
    bool trigger = false;
    char message[] = "CONTINUEM PLA2";
    char encryptedMessage[] = "NFRFRIMIOFRIMFNARXAFRROTNXAA";

    char matrix[7][7] = {
        {' ', 'X', 'I', 'F', 'R', 'A', 'T'},
        {'N', 'A', 'B', 'C', 'D', 'E', 'F'},
        {'O', 'G', 'H', 'I', 'J', 'K', 'L'},
        {'R', 'M', 'N', 'O', 'P', 'Q', 'R'},
        {'M', 'S', 'T', 'U', 'V', 'W', 'X'},
        {'A', 'Y', 'Z', ' ', '1', '2', '3'},
        {'L', '4', '5', '6', '7', '8', '9'}
    };

    while(k < sizeof(message)){  
        for(i = 0; i < 7; i++){
            for(j = 0; j < 7; j++){
                //la primera i fila [0] que referencia "i" i "j" és una base, no ha de se part de la clau de xifrat
                if(i >= 1 && j >= 1){
                    if(message[k] == matrix[i][j]){
                        //printf("\n%c", matrix[i][j]);
                        printf("%c%c", matrix[i][0], matrix[0][j]);
                    }
                }
            }
        }
        k++;
    }

    printf("\n");
    
    while (z < sizeof(message)*2){
        int n, m;
        bool triggerRow = false, triggerColumn = false;
        n = 0;
        m = 0;
        /*obtenció de la posició n x m a l'array/taula de el caracter original*/
        do{
            if(encryptedMessage[z] == matrix[n][0]){
                //l'objectiu es guardar el contador de "n" ja que té la posició n x m de la matriu
                triggerRow = true;
                z++;
            }else{
                n++;
            }
        }while(!triggerRow);
        
        do{
            if(encryptedMessage[z] == matrix[0][m]){
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
   
    return 0;
}