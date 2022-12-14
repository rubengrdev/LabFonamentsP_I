#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>        /* necessaria per tenir el tipus bool (boolepa) */
#include <time.h>


/**
 * El procediment inicialitza el generador d'aleatoris amb la data/hora actuals.
 * No te parametres
*/
void ini_llavor (void)
{

	srand(time(NULL));
}

/**
 * El procediment genera un enter aleatori entre 'min' i 'max'.
 * @param min (Valor (E): enter). El valor minim.
 * @param max (Valor (E): enter). El valor maxim.
 * @return enter, el valor aleatori.
*/
int aleatori_entre (int min, int max)
{
	return (min + (rand()%(max-min+1)));
}


int main ()
{
    /**Inicialitzem les variables y constants**/
	bool fi;
    int num_aleat, cont, intent_edad;
    const int max_intents = 5;
    /**Inicialitzem els seeds**/
    ini_llavor();
    num_aleat = aleatori_entre(10,50);
    fi =  false;
    cont = 1;
	printf("Quants anys tinc? endevina l'edat de l'ordinador\n");
    printf("\nRecorda que la meva edad és de 10 a 50 anys!\n");
    printf("Indica una edad:\n");
    scanf("%d", &intent_edad);

    while(intent_edad < 10 | intent_edad > 50){
          printf("Error, recorda que tens que ficar una edad entre 10 i 50 anys\n");
          printf("Indica una edad:\n");
          scanf("%d", &intent_edad);
    }

  while( fi != true && cont < max_intents){
        if(intent_edad == num_aleat){
            fi = true;
            printf("\nHas encertat!");
        }
        if(fi != true){
            if(intent_edad > num_aleat){
                printf("\nL'edad de l'ordinador és inferior!");
                printf("\nIndica una edad:\n");
                scanf("%d", &intent_edad);
            }else if(intent_edad < num_aleat){
                printf("\nL'edad de l'ordinador és superior!");
                printf("\nIndica una edad:\n");
                scanf("%d", &intent_edad);
            }
        }
        cont++;
    }
    if(fi != true){
        printf("Se t'han acabat els intents, bona sort la pròxima vegada!");
    }
	return 0;
}
