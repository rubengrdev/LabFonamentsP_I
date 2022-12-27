#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int obtindreMida(char string[]){
    int i = 0;
    while(string[i] != '\0' || string[i] == '\n'){
        i++;
    }
    return i;
}
char minuscula_a_majuscula(char message[]){
    int size = obtindreMida(message);
    int a = 0;
    while(a < size){
        if(("%d",message[a]) >= 97 && ("%d",message[a]) <= 122 ){
              message[a] = message[a] - 32;
        }
        a++;
    }
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
        }
    }   
    
}

void xifrar_frase(char text[], char matrix[][7], char frase_xifrada[]){
    int i, j, k = 0, l = 0, o = 0;
    bool firtsValue = false;
    //comprovació si totes les lletres son en majuscula per poder fer la transformació, en el cas de ser minuscula la transforma a majuscula
    minuscula_a_majuscula(text);
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

void llegir_arxiu(FILE * fit, char encriptedMessage[]){
            int fileStringCounter, fileCounter = 0;
            char fileString[80];
            while(fgets(fileString, 80, fit)){
                printf("\n%d--", obtindreMida(fileString));
                //fileString té cada linea de text que hi ha a l'arxiu
                if(obtindreMida(fileString) > 0 || obtindreMida(fileString) <= 80){
                fileStringCounter = 0;
                do{
                    encriptedMessage[fileCounter] = fileString[fileStringCounter];
                    fileStringCounter++;    //contador que s'utilitza internament per cada posició de la linea obtenida de l'arxiu a xifrar
                    fileCounter++;  //contador que  obté la posició a la nova cadena que estem omplint (encriptedMessage)
                }while(fileStringCounter < obtindreMida(fileString));
                }
            }
            encriptedMessage[(obtindreMida(encriptedMessage))] = '\0';
}

void lliurar_buffer(){
        while ((getchar()) != '\n');
}
bool llegir_linea(FILE * fit){
    bool overflow = false;
    char content[80];
    if(obtindreMida(fgets(content, 80, fit)) > 80){
        overflow = true;
    }else{
        overflow = false;
    }
}
bool comprovar_arxiu(FILE * fit){
    bool status;
    if(fit != NULL){
        status = true;
    }else{
        status = false;
    }
    return status;
}


int main() {
    FILE * fit, * fitW;
    int opcio, fileStringCounter, fileCounter = 0;
    char message[80];
    char encriptedMessage[160];
    char fileString[80];
    char matrix[7][7] = {};
    //un text encriptat d'aquesta forma equival a el doble de la seva mida, ja que per cada lletra crea 2 caracters
    char frase_xifrada[160];
    char frase_desxifrada[80];
    //boleà per comprovar que l'arxiu s'ha trobat
    bool fileExists = false;
    //comprovació de l'arxiu
    fit = fopen("Text_a_xifrar.txt", "r");
    if(comprovar_arxiu(fit)){
        fileExists = true;
    }
    fclose(fit);
    construir_matriu_xifrat(matrix);

   printf("\n\n---Pràctica de Xifrat---\n");
   while(opcio != 5){
   do{
        printf("\nTria una opció insertant el seu numero: \n");
        //opcions
        printf("\n1.- Encriptar un text introduit per teclat");
        printf("\n2.- Desencriptar un text introduit per teclat");
        printf("\n3.- Encriptar un text inclòs en un arxiu de text");
        printf("\n4.- Desencriptar un text inclòs en un arxiu de text");
        printf("\n5.- Sortir\n\n");
        printf("\nSeleccionar opció: ");
        scanf("%d", &opcio);
   }while(opcio < 1 || opcio > 5);

   switch (opcio)
   {
   case 1:
        //encriptar un text introduit per teclat
        printf("\nHas seleccionat la opció (1) - Encriptar un text introduit per teclat");
        printf("\nIntrodueix un text a encriptar: ");
        //utilitzo expressions regulars per poder obtindre totes les dades de forma correcta (strings amb espais, o salts de linea.)
        //funció creada per lliurar el buffer de la entrada de dades (fflush no funciona correctament en tots el casos).
        lliurar_buffer();
        scanf("%[^\t\n]",message);
        //llegir_variable_espais(message);
        printf("\nHas introduit el text: '%s'", message);
        xifrar_frase(message, matrix, frase_xifrada);
        printf("\nText xifrat: '%s'", frase_xifrada);
    break;
   case 2:
    //desencriptar un text introduit per teclat
        printf("\nIntrodueix un text per desencriptar: ");
        scanf("%s",encriptedMessage);
        printf("\nHas introduit el següent text encriptat: '%s'", encriptedMessage);
        desxifrar_frase(encriptedMessage, matrix, frase_desxifrada);
        printf("\nText desencriptat: %s", frase_desxifrada);
    break;
   case 3:
    //encriptar un text inclòs en un arxiu de text
    if(fileExists){
        fit = fopen("Text_a_xifrar.txt", "r");
        if(!llegir_linea(fit)){
        llegir_arxiu(fit, message);
        xifrar_frase(message, matrix, frase_xifrada);
        fitW = fopen("Text_a_xifrar.txt", "w");
        fprintf(fitW,"%s",frase_xifrada);
        fclose(fit);
        fclose(fitW);
        printf("\nText xifrat: '%s'", frase_xifrada);
        }else{
            printf("\nNo s'ha pogut llegir l'arxiu, comprova que el contingut és correcte i que les linies no tenen més de 80 caracters");
        }
    }
    break;  
   case 4:
    //desencriptar un text inclòs en un arxiu de text
     if(fileExists){
        fit = fopen("Text_a_xifrar.txt", "r");
         if(!llegir_linea(fit)){
        llegir_arxiu(fit, encriptedMessage);
        fclose(fit);
        desxifrar_frase(encriptedMessage, matrix, frase_desxifrada);
        fitW = fopen("Text_a_xifrar.txt", "w");
        fprintf(fitW,"%s",frase_desxifrada);
        fclose(fitW);
        printf("\nText desencriptat: %s", frase_desxifrada);
    }else{
        printf("\nS'ha tancat l'arxiu");
    }
    }else{
            printf("\nNo s'ha pogut llegir l'arxiu, comprova que el contingut és correcte i que les linies no tenen més de 80 caracters");
        }
    break;
   default:
    break;
   }
   }

    return 0;
}