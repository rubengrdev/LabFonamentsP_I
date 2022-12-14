#include <stdio.h>
#include <stdbool.h>

int main(){
    /*Pràctica 0 - Alumne: Rubén Gómez Rodríguez*/
    const float importMaxim = 100000000.00;
    float fruitesVerduresCost, cerealsDerivatsCost, altresAlimentsCost, begudesSucreCost, begudesAlcoholCost, 
    aiguaCost, prodSanitarisCost, totalNoIva, totalIva, totalNoIvaReduit, totalIvaReduit, totalNoIvaSuperReduit, 
    totalIvaSuperReduit, noIvaSet1, ivaSet1, noIvaReduitSet1, ivaReduitSet1, noIvaSuperReduitSet1, ivaSuperReduitSet1, sumaSet1, costCompra;
    bool dadesCorrectes = false;
    printf("Per calcular el cost semanal introdueix les dades que es et demanaran a continuació\n");
    while (dadesCorrectes != true){
        /*Fins a que no es compleixi la condició no deixará de preguntar la mateixa pregunta*/
        do{
            printf("\nIntrodueix el consum en la primera setmana de fruites, verdures, horatalisses, llegums i tubercles\n");
            scanf("%f", &fruitesVerduresCost);
        }while(fruitesVerduresCost < 0.00 || fruitesVerduresCost > importMaxim);
        do{
            printf("Introdueix el consum en la primera setmana de cereals, ous, pa formatge i llet\n");
            scanf("%f", &cerealsDerivatsCost);
        }while(cerealsDerivatsCost < 0 || cerealsDerivatsCost > importMaxim);
        do{
            printf("Introdueix el consum en la primera setmana de altres aliments\n");
            scanf("%f", &altresAlimentsCost);
        }while(altresAlimentsCost < 0 || altresAlimentsCost > importMaxim);
        do{
            printf("Introdueix el consum en la primera setmana de begudes ensucrades\n");
            scanf("%f", &begudesSucreCost);
        }while(begudesSucreCost < 0 || begudesSucreCost > importMaxim);
        do{
            printf("Introdueix el consum en la primera setmana de begudes alcohòliques\n");
            scanf("%f", &begudesAlcoholCost);
        }while(begudesAlcoholCost < 0 || begudesAlcoholCost > importMaxim);
        do{
            printf("Introdueix el consum en la primera setmana d'aigua\n");
            scanf("%f", &aiguaCost);
        }while(aiguaCost < 0 || aiguaCost > importMaxim);
        do{
            printf("Introdueix el consum en la primera setmana de productes sanitaris\n");
            scanf("%f", &prodSanitarisCost);
        }while(prodSanitarisCost < 0 || prodSanitarisCost > importMaxim);
        /*faig una ultima suma per comprovar que les dades no son iguals a 0, ja que de ser així no te sentit comprovar les setmanes següents*/
        if((fruitesVerduresCost + cerealsDerivatsCost + altresAlimentsCost + begudesSucreCost + begudesAlcoholCost + aiguaCost + prodSanitarisCost) > 0){
           dadesCorrectes = true;
        }else{
            printf("\nNo es pot calcular el cost de les altres setmanes si a la setmana 1 el gast ha sigut de 0€\n");
        }
    }
    /*productes amb IVA del 21%*/
        /*calcul de el import dels productes comprats sense el IVA*/
        noIvaSet1 = (begudesSucreCost + begudesAlcoholCost);
	    ivaSet1 = noIvaSet1 * 0.21;
        /*productes amb IVA del 10%*/
	    /*calcul del import dels productes comprats sense IVA redüit*/
        noIvaReduitSet1 = (altresAlimentsCost + prodSanitarisCost + aiguaCost);
	    ivaReduitSet1 =  noIvaReduitSet1 * 0.10;
        /*productes amb IVA del 4%*/
        /*calcul del import dels productes comprats sense IVA redüit*/
        noIvaSuperReduitSet1 = (fruitesVerduresCost + cerealsDerivatsCost);
	    ivaSuperReduitSet1 =  noIvaSuperReduitSet1 * 0.04;

        totalNoIva = noIvaSet1 + (noIvaSet1 * 0.80) + (noIvaSet1 * 0.70) + (noIvaSet1 * 0.60);
	    totalIva = ivaSet1 + (ivaSet1 * 0.80) + (ivaSet1 * 0.70) + (ivaSet1 * 0.60);
	    totalNoIvaReduit = noIvaReduitSet1 + (noIvaReduitSet1 * 0.80) + (noIvaReduitSet1 * 0.70) + (noIvaReduitSet1 * 0.60);
	    totalIvaReduit = ivaReduitSet1 + (ivaReduitSet1 * 0.80) + (ivaReduitSet1 * 0.70) + (ivaReduitSet1 * 0.60);
	    totalNoIvaSuperReduit = noIvaSuperReduitSet1 + (noIvaSuperReduitSet1 * 0.80) + (noIvaSuperReduitSet1 * 0.70) + (noIvaSuperReduitSet1 * 0.60);
	    totalIvaSuperReduit =  ivaSuperReduitSet1 + (ivaSuperReduitSet1 * 0.80) + (ivaSuperReduitSet1 * 0.70) + (ivaSuperReduitSet1 * 0.60);
        /*suma final de tots els productes i el IVA*/
        costCompra = totalNoIva + totalIva + totalNoIvaReduit + totalIvaReduit + totalNoIvaSuperReduit + totalIvaSuperReduit;
        /*resultat del sumatori*/
        printf("\nproductes categoritzats amb el 21 per cent de IVA => fruites, verdures, horatalisses, llegums i tubercles...\n");
	    printf("subtotal (sense IVA): %.2f\n", totalNoIva);
	    printf("IVA: %.2f\n", totalIva);
	    printf("productes categoritzats amb el 10 per cent de IVA => productes sanitaris, cereals, ous, pa formatge, llet i altres aliments\n");
	    printf("subtotal (sense IVA): %.2f\n", totalNoIvaReduit);
	    printf("IVA: %.2f\n", totalIvaReduit);
	    printf("productes categoritzats amb el 4 per cent de IVA => begudes ensucrades i begudes alcohòliques\n");
	    printf("subtotal (sense IVA): %.2f\n", totalNoIvaSuperReduit);
	    printf("IVA: %.2f\n", totalIvaSuperReduit);
        printf("\nEl cost total de la compra puja a: %.2f €\n", costCompra);       
    return 0;
}