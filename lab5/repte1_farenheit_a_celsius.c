#include <stdio.h>

int main(){
    FILE * fit;
    float temp1, celsius;
    int contDefectuos = 0;
    fit = fopen("temp1.txt","r");
    if(fit == NULL){
        printf("No s'ha pogut obrir el fitxer");
    }else{
        if(fscanf(fit, "%f", &temp1)){
            while(!feof(fit)){
                if(("%.1f",temp1) == -999.90f){
                    printf("\n-999.9 ºF");
                    contDefectuos++;
                }else{
                    celsius = ((("%f",temp1)-32.00) *  0.5556);
                    printf("\n%.2f ºF => %.2f ºC", temp1, celsius);
                }
                fscanf(fit, "%f", &temp1);
            }   
        fclose(fit);
        }
        printf("\n\nSensors defectuosos: %d\n", contDefectuos);
    }
    return 0;
}