#include <math.h>
#include <stdio.h>

int main(){
    int a,b,c;
    float traspas,resultat1,resultat2;

    printf("\nUna equacio de segon grau te la forma ax^2 + bx + c = 0");
    printf("\nEspecifica l'equacio introduint els valors de a, b i c");
    printf("\nQuant val a?");
    scanf("%d", &a);
    printf("\nQuant val b?");
    scanf("%d", &b);
    printf("\nQuant val c?");
    scanf("%d", &c);

    if(a==0){
        printf("\nL'equació no és de segón grau");
    }else{
        if(((pow(b,2))-4*a*c) < 0){
            printf("\nL'equació no té solució");
        }else{
            traspas = (pow(b,2)-4*a*c);
            resultat1 = (-(b)+sqrt(traspas))/(2*a);
            resultat2 = (-(b)-sqrt(traspas))/(2*a);
            printf("\nResultat en el cas positiu %.2f", resultat1);
            printf("\nResultat en el cas negatiu %.2f\n", resultat2);
    }
    }
    return 0;
}
