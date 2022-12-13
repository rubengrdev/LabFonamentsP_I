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

void maxim_minim_sensor(int taula[], int size){
	int k, min, max;
	min = taula[0];
	max = taula[0];
	for(k = 0; k < size; k++){
		if(taula[k]  > max){
			max = taula[k];
		}
		if(taula[k] < min){
			min = taula[k];
		}
	}
	printf("\nEl minim és %d", min);
	printf("\nEl maxim és %d\n", max);
}

void humitat_30_70_sensor(int taula[], int size){
	int k, counter = 0;
	for(k = 0; k < size; k++){
		if(taula[k]  > 30 && taula[k] < 70){
			counter++;
		}
	}
	printf("\nL'Humitat s'ha trobat entre el 30 i 70 percent en %d casos", counter);
}

int read_int_dimension(int num){
	int i = 1;
	if(num <= 10){
		i = 100;
	}else if(num <= 100){
		i = 100;
	}else if(num <= 1000){
		i = 1000;
	}else if(num <= 10000){
		i= 10000;
	}else if(num <= 100000){
		i=100000;
	}
	printf("\nValor de i: %d", i);
	return i;
}

void llum_percentatge(bool taula[], int size){
	float percent = 0.00;
	int k, counter = 0, div;
	for(k = 0; k < size; k++){
		if(taula[k] == true){
			counter++;
		}
	}
	printf("\nNumero de llums: %d", counter);
	percent = ((counter*read_int_dimension(size))/size);
	printf("\nPercentatge de llums: %.2f per cent", percent);
}


int main ()
{
	int i = 0, l = 0, n_lec;
    dades_t coleccio[2];
	ini_sensor(coleccio);
	
	do{
		printf("\nIntrodueix el numero de elements que vols: ");
		scanf("%d", &n_lec);
	}while(n_lec < 1);

	int temperatura[n_lec];
	int humitat[n_lec];
	bool llum[n_lec];

	while(i < n_lec){
		llegir_sensor(coleccio);
		temperatura[i] = coleccio->temp;
		humitat[i] = coleccio->hum;
		llum[i] = coleccio->llum;
		mostrar_dades_sensor(coleccio);
		i++;
	}

	maxim_minim_sensor(temperatura, n_lec);
	humitat_30_70_sensor(humitat, n_lec);
	llum_percentatge(llum, n_lec);
	return 0;
}
