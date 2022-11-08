#include <stdio.h>
#define sensors 99;
#define columnes 1;

int main(){
    FILE * fit;
    int sen = sensors;
    int col = columnes
    float temp1, mitjana, suma, taula_temps[sen][col];
    int n_fil1, n_fil2, cont_temp;
    n_fil1 = 0;
    n_fil2 = 0;
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
                }
                fscanf(fit, "%f", &temp1);
            }
            mitjana = suma / cont_temp;
            fclose(fit);
            /*Com ja he comprovat anteriorment si podia accedit a l'arxiu no tornaré a preguntar*/
            fit = fopen("temp1.txt","r");
            fscanf(fit, "%f", &temp1);
            printf("%1.f", mitjana);
            while(!feof(fit)){
                 if(("%.1f",temp1) != -999.90f){
                    if(("%.1f",temp1) < ("%.1f",mitjana)){
                        taula_temps[n_fil1][0] =  ("%.1f",temp1);
                        n_fil1++;
                        printf("\nMitjana < %1.f", temp1);
                    }else{
                        taula_temps[n_fil2][1] =  ("%.1f",temp1);
                        n_fil1++;
                        printf("\nMitjana > %1.f", temp1);
                    }
                }
                fscanf(fit, "%f", &temp1);
            }  
        fclose(fit);
        }
    }
    return 0;
}