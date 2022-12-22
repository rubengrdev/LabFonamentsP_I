#include <stdio.h>

/* Exemple per veure el comportament de scanf */
int main()
{
    int n1, n2, n3, n4, n5, n6;
    char c1, c2, c3, cars1[2], cars2[2], cars3[2];

	printf("Introdueix un nombre:");
	scanf("%d", &n1);
	printf("\nIntrodueix el segon nombre:");
	scanf("%d", &n2);
	printf("\nIntrodueix el tercer nombre:");
	scanf("%d", &n3);

	printf("\nNombres introduits %d %d %d", n1, n2, n3);

	printf("\nIntrodueix tres nombres amb un espai entre mig, acaba amb intro:");
	scanf("%d", &n4); scanf("%d", &n5); scanf("%d", &n6);

	printf("\nNombres introduits %d %d %d", n4, n5, n6);

	printf("\nIntrodueix un caracter:");
	/* fflush(stdin); */
	scanf("%c", &c1);

	printf("\nIntrodueix el segon caracter:");
    /* fflush(stdin); */
	scanf("%c", &c2);

	printf("\nIntrodueix el tercer caracter:");
	/* fflush(stdin); */
	scanf("%c", &c3);

	printf("\nCaracters introduits %c %c %c", c1, c2, c3);

	printf("\nIntrodueix tres caracters amb un espai entre mig, acaba amb intro:");
	/*fflush(stdin); */
	scanf("%c", &c1); scanf("%c", &c2); scanf("%c", &c3);

	printf("\nCaracters introduits %c %c %c", c1, c2, c3);


	/*printf("\nIntrodueix un caracter:");
	scanf("%s", cars1);

	printf("\nIntrodueix el segon caracter:");
	scanf("%s", cars2);

	printf("\nIntrodueix el tercer caracter:");
	scanf("%s", cars3);
stdin
	printf("\nCaracters introduits %s %s %s", cars1, cars2, cars3); */


    return 0;
}
