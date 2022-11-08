#include <stdio.h>
#define sensors 99;

int main(){
    FILE * fit;
    int sen = sensors;
    float temp1, mitjana, suma, taula_temps[sen];
    int n_fil, cont_temp, menor_avg, major_avg;

    menor_avg = 0;
    major_avg = 0;
    n_fil = 0;
    suma = 0;
    cont_temp = 0;
    fit = fopen("temp1.txt","r");
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
            /*Iterar sobre la taula per obtenir les dades de volta*/
            for(int i = 0; i < n_fil; i++){
                if(taula_temps[i] < mitjana){
                    /*printf("\n%.2f > %.2f", mitjana, taula_temps[i]);*/
                    menor_avg++;
                }else{
                    /*printf("\n%.2f < %.2f", mitjana, taula_temps[i]);*/
                    major_avg++;
                }
            }
            printf("\nMitjana: %1.f", mitjana);
            printf("\nTemperatura menor a la mitjana: %d", menor_avg);
            printf("\nTemperatura major a la mitjana: %d\n", major_avg);
        }
    }
    return 0;
}