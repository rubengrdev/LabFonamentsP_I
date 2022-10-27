#include <stdio.h>

int main(){
    FILE * fit;
    float temp1, temp2, temp3, temp4, celsius, suma, mitja;
    int cont, contDefectuos = 0;
    suma = 0.00;
    cont = 0;
    fit = fopen("temp4.txt","r");
    if(fit == NULL){
        printf("No s'ha pogut obrir el fitxer");
    }else{
        if(fscanf(fit, "%f", &temp1)){
            while(!feof(fit)){
                if(("%.1f",temp1) == -999.90f){
                    /*El contador comença amb 0, estic contemplant que la primera posició es 0 i no 1, podría fer cont+1 per començar amb la 1*/
                    printf("\nSensors defectuos a la posició: %d\n", cont);
                    contDefectuos++;
                }else{
                    celsius = ((("%f",temp1)-32.00) *  0.5556);
                    printf("\n%.2f ºF => %.2f ºC", temp1, celsius);
                    suma = suma + ("%.2f", celsius);
                }
                fscanf(fit, "%f", &temp1);
                cont++;
            }
        fclose(fit);
        }
        printf("\n\nSensors defectuosos: %d\n", contDefectuos);
        if(cont >= 0){
            mitja = suma / cont;
            printf("\nLa Mitja de temperatures Celsius és: %.2f ºC\n", mitja);
        }
    }
    return 0;
}