#include <stdio.h>

int main(){
    FILE * fit;
    FILE * save;
    float temp1, celsius;
    int contDefectuos = 0;
    fit = fopen("temp1.txt","r");
    save = fopen("save.txt", "w");
    if(fit == NULL || save == NULL){
        printf("No s'ha pogut obrir el fitxer");
    }else{
        if(fscanf(fit, "%f", &temp1)){
            while(!feof(fit)){
                if(("%.1f",temp1) == -999.90f){
                    printf("\n-999.9ºF");
                    contDefectuos++;
                }else{
                    celsius = ((("%f",temp1)-32.00) *  0.5556);
                    printf("\n%.2f ºF => %.2f ºC", temp1, celsius);
                    /*Guardar a un arxiu el resultat anterior*/
                    fprintf(save, "%.2f\t", celsius);
                }
                fscanf(fit, "%f", &temp1);
            }
        fclose(fit);
        fclose(save);
        }
        printf("\n\nSensors defectuosos: %d\n", contDefectuos);
    }
    return 0;
}