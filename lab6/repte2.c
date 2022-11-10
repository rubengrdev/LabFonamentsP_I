#include <stdio.h>
#define sensors 99;

int main(){
    FILE * fit;
    int sen = sensors;
    float temp1, mitjana, suma, max, min, taula_temps[sen];
    int n_fil, cont_temp, menor_avg, major_avg;

    menor_avg = 0;
    major_avg = 0;
    max = 0;
    min = 0;
    n_fil = 0;
    suma = 0;
    cont_temp = 0;
    fit = fopen("temp2.txt","r");
    if(fit == NULL){
        printf("No s'ha pogut obrir el fitxer");
    }else{
        if(fscanf(fit, "%f", &temp1)){
            while(!feof(fit)){
                if(("%.1f",temp1) != -999.90f){
                    /*En aquest punt els sensors son valids, podem calcular la mitjana*/
                    suma += temp1;
                    cont_temp++;
                    /*Insertem a la posició de la taula el valor en farenheit*/
                    taula_temps[n_fil] =  ("%.2f",temp1);
                    n_fil++;
                }
                fscanf(fit, "%f", &temp1);
            }
            mitjana = suma / cont_temp;
            fclose(fit);
            /*Asignaré uns valors minims i maxim amb el primer valor de la colecció, després amb les comparacións aniré modificant*/
                min = taula_temps[0];
                max = taula_temps[0];
            /*Iterar sobre la taula per obtenir les dades de volta*/
            for(int i = 0; i < n_fil; i++){
                if(taula_temps[i] < mitjana){
                    if(taula_temps[i] < min){
                        min = taula_temps[i];
                    }
                    /*printf("\n%.2f > %.2f", mitjana, taula_temps[i]);*/
                    menor_avg++;
                }else{
                    if(taula_temps[i] > max){
                        max = taula_temps[i];
                    }
                    /*printf("\n%.2f < %.2f", mitjana, taula_temps[i]);*/
                    major_avg++;
                }
            }
            printf("\nMitjana: %.2f", mitjana);
            printf("\nTemperatura menor a la mitjana: %d", menor_avg);
            printf("\nTemperatura major a la mitjana: %d\n", major_avg);
            printf("\nMinim: %.1f", min);
            printf("\nMaxim: %.1f\n", max);
        }
    }
    return 0;
}