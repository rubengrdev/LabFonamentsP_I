#include<stdio.h>
/**repte 1 laboratori 3 Rubén Gómez**/
int main(){

    int capacitat, num_persones, num_nits;
    float preu_nit, preu_total, import_iva, preu_sin_iva;

    capacitat = 12;
    preu_nit = 150;

    do{
        printf("\nPressupost Can Marbal");
        printf("\nQuantes persones sereu?");
        scanf("%d",&num_persones);
        printf("\nPer quantes nits?");
        scanf("%d", &num_nits);
        if(num_persones <= 0 || num_persones >=12){
            printf("\nNo es pot fer una reserva per aquesta quantitat de persones");
            num_persones = 0;
        }
        if(num_nits <= 0){
            printf("\nNo es pot fer una reserva per aquesta quantitat de dies");
            num_nits = 0;
        } 
    }while((int)num_persones <= 1 && (int)num_nits <= 1);

    /**calcul del preu total a la variable "preu_total"**/
    preu_sin_iva = preu_nit*num_nits;
    /**calcul iva**/
    import_iva = preu_sin_iva*0.21;
    printf("\n%f", preu_sin_iva);
    preu_total = preu_sin_iva+import_iva;
    printf("\nPreu allotjament %f euros", preu_total);
    printf("\nIVA %f\n", preu_total);
    return 0;
}