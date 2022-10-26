#include <stdio.h>
#define MAX 100

int main(){
    FILE * fit;
    float temp1, temp2, temp3, temp4, celsius, suma, mitja;
    int cont, contDefectuos = 0, sensorsDefectuosos[MAX];
    suma = 0.00;
    cont = 0;
    fit = fopen("temp3.txt","r");
    if(fit == NULL){
        printf("No s'ha pogut obrir el fitxer");
    }else{
        if(fscanf(fit, "%f", &temp1)){
            while(!feof(fit)){
                if(("%.1f",temp1) == -999.90f){
                    printf("\n-999.9ºF");
                    sensorsDefectuosos[contDefectuos] = cont;
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
        for(int i = 0; i < contDefectuos; i++){
            printf("\nSensors defectuos a la posició: %d\n", sensorsDefectuosos[i]);
        }
    }
    return 0;
}