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

    int n = 0, m = 0, triggerRow = false, triggerColumn = false;
    while (z < sizeof(message)*2){

        do{
            printf("\n%c found at Column: %d\n", matrix[n][0], n);
            if(encryptedMessage[z] == matrix[n][0]){
                triggerColumn = true;
                //z++;
                //avisar de la posición en la que se encuentra aqui
                
                n = 0;
            }    
           n++; 
        }while(!triggerColumn);
    
        /*
         for(i = 0; i < 7; i++){
            for(j = 0; j < 7; j++){
                //la primera i fila [0] que referencia "i" i "j" és una base, no ha de se part de la clau de xifrat
                if(encryptedMessage[z] == matrix[0][j]){
                    printf("\nword %d %d", i, j);
                }
                if(encryptedMessage[z] == matrix[i][0]){
                    printf("\nword %d %d", j, i);
                }
            }
        }
        */
        z++;
    }
   
    return 0;
}