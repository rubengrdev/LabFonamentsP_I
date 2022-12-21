#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int obtindreMida(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        i++;
    }
    return i;
}

void construir_matriu_xifrat(char newMatrix[][7]){
    int a, b;
    //caracters que s'utilitzen per poder crear l'encriptat (fila de dalt)
    char xifratX[6] =  {'X', 'I', 'F', 'R', 'A', 'T'};
    //caracters que s'utilitzen per poder crear l'encriptat (columna esquerra)
    char xifratY[6] =  {'N', 'O', 'R', 'M', 'A', 'L'};
    char matrixBase[6][6] = {
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X'},
        {'Y', 'Z', ' ', '1', '2', '3'},
        {'4', '5', '6', '7', '8', '9'}
    };
    /*
    Amb aquesta definició de variables tan especifica el que busquem es obtindre una matriu com la següent quan es tractada per el bucle.
    Tenir separada d'aquesta forma la primera columna i la primera fila ens permet utilitzar altres caracters de xifrat.

        {{' ', 'X', 'I', 'F', 'R', 'A', 'T'},
        {'N', 'A', 'B', 'C', 'D', 'E', 'F'},
        {'O', 'G', 'H', 'I', 'J', 'K', 'L'},
        {'R', 'M', 'N', 'O', 'P', 'Q', 'R'},
        {'M', 'S', 'T', 'U', 'V', 'W', 'X'},
        {'A', 'Y', 'Z', ' ', '1', '2', '3'},
        {'L', '4', '5', '6', '7', '8', '9'}};
    
    */
    for(a = 0; a < 7; a++){
        printf("\n");
        for(b = 0; b < 7; b++){
            if(a == 0 && b == 0){
                newMatrix[a][b] = ' ';
            }else if(a == 0 && b > 0){
                newMatrix[a][b] = xifratX[b-1];
            }else{
                if(newMatrix[a][0] == '\0'){
                    newMatrix[a][0] = xifratY[a-1];
                }else{
                    newMatrix[a][b] = matrixBase[a-1][b-1];
                }
            }
            
            
            printf("%c", newMatrix[a][b]);
        }
    }   
    
}


void xifrar_frase(char text[], char matrix[][7], char frase_xifrada[]){
    int i, j, k = 0, l = 0, o = 0;
    bool firtsValue = false;
    while(k < (obtindreMida(text))){  
        for(i = 0; i < 7; i++){
            for(j = 0; j < 7; j++){
                //la primera i fila [0] que referencia "i" i "j" és una base, no ha de se part de la clau de xifrat
                if(i >= 1 && j >= 1){
                    if(text[k] == matrix[i][j]){
                        //printf("\n%c", matrix[i][j]);
                        //printf("%c%c", matrix[i][0], matrix[0][j]);
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
    //finalització de la cadena de text
    frase_xifrada[o] = '\0';

}

void desxifrar_frase(char textXifrat[], char matrix[][7], char frase_desxifrada[]){
    int n, m, z = 0, u = 1, j = 0, lenghtOfDecript = 0;
    bool triggerRow, triggerColumn, secondValue = false;
    while (z < obtindreMida(textXifrat)){
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
        //printf("\n%c", matrix[n][m]);

        do{
            //esperaré a la segona comprovació ja que no he de fer tantes repeticions
            if(u == 0){
                secondValue = true;
                u++;
            }else{
                frase_desxifrada[j] = matrix[n][m];
                secondValue = false;
                u = 0;
                j++;
            } 
        }while(!secondValue && u == 0);
    }
    frase_desxifrada[j] = '\0';
}



int main() {
    char message[] = "CONTINUEM PLA2";
    char matrix[7][7] = {};
    //un text encriptat d'aquesta forma equival a el doble de la seva mida, ja que per cada lletra crea 2 caracters
    char frase_xifrada[(obtindreMida(message)*2)];
    char frase_desxifrada[(obtindreMida(message))];

    construir_matriu_xifrat(matrix);
    xifrar_frase(message, matrix, frase_xifrada);
    printf("\n%s", frase_xifrada);
    desxifrar_frase(frase_xifrada, matrix, frase_desxifrada);
    printf("\n%s", frase_desxifrada);
   

    return 0;
}