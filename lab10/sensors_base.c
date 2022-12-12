#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int temp;   /* temperatura en graus Celsius */
	int hum;    /* percentatge d’humitat   */
	bool llum;  /* indica si ha detectat llum o no */

} dades_t;

/* El procediment "inicialitza el sensor" */
void ini_sensor (dades_t *dades)
{
	srand(time(NULL));
	dades->temp = (-30 + rand()%(80+1));	/* Valor inicial de temperatura */
	dades->hum = 40 + rand()%(60+1);	/* Valor inicial de humitat */

}

/**
 * Obte, ficticiament, les dades d'un sensor. La lectura triga un temps aleatori.
 * @param dades (Valor (E): registre de t_dades). Les dades que s'obtenen del sensor.
 */

void llegir_sensor (dades_t *dades)
{
	int al, espera, i, j;

	espera = rand()%300 * 100;

	/* Literalment, perdem el temps */
	for (i = 0; i < espera; i++)
	{
		for (j = 0; j < espera; j++)
		{
			/* Pentino el gat */
		}
	}

	/* La temperatura serà la inicial mes/menys un aleatori */
	dades->temp = dades->temp + (rand()%10);

	/* La humitat serà la inicial mes/menys un aleatori */
	dades->hum = dades->hum + (rand()%50)/10.0;

	/* La llum també serà aleatoria */
	al = rand()%100;

	if ((al%3 == 0) || (al%7 == 0))
	{
		dades->llum = true;
	}
	else
	{
		dades->llum = false;
	}

}


int main ()
{
	int i = 0;
	dades_t exdada;
    dades_t array[100];

	exdada.hum = 30;
	exdada.llum = false;
	exdada.temp = 22;

	//prova per agafar informació de la estructura de dades (obj)
	printf("La informació de el objecte creat és: %d, %d, %d", exdada.hum, exdada.temp, exdada.llum);
	array[0] = exdada;


	exdada.hum = 15;
	exdada.llum = true;
	exdada.temp = 12;

	//prova per agafar informació de la estructura de dades (obj)
	printf("La informació de el objecte creat és: %d, %d, %d", exdada.hum, exdada.temp, exdada.llum);
	array[1] = exdada;

	//prova provisional
	for(i = 0; i < 10; i++){
		printf("\nLa informació de el objecte %d és: %d, %d, %d", i, array[i].hum, array[i].temp, array[i].llum);
	
		
		
	}
	return 0;
}
