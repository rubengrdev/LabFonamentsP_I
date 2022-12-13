#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
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

void mostrar_dades_sensor(dades_t *dades){
	if(dades->hum != '\0'){
		printf("\nHum: %d", dades->hum);
	}
	if(dades->temp != '\0'){
		printf("\nTemperatura: %d", dades->temp);
	}
	if(dades->llum){
		printf("\nLlum: Si\n");
	}else{
		printf("\nLlum: No\n");
	}
}

int main ()
{
	int i = 0, j,  n_lec;
	dades_t * array[MAX];
    dades_t * coleccio;
	ini_sensor(coleccio);

		printf("\nIntrodueix el numero de elements que vols: ");
		scanf("%d", &n_lec);

	while(i < n_lec){
		llegir_sensor(coleccio);
		array[i] = coleccio;
		printf("\nS'han llegit dades del sensor");
		mostrar_dades_sensor(coleccio);
		i++;
	}
	
	for(j = 0; j < n_lec; j++){
		mostrar_dades_sensor(array[j]);
	}



	return 0;
}
