#include <stdio.h>
int main()
{
    short int a, b;
    a = 1000; b = 2000;

    /* sizeof indica quants bytes ocupa una variable */
    /* Fem Cas
    ting a la sortida de sizeof(a) per obtenir un resultat de tipus unsigned long int*/
    printf ("a te el valor %d i ocupa %lu bytes\n", a, (unsigned long int)sizeof(a));
    printf ("b te el valor %d i ocupa %lu bytes\n", b, (unsigned long int)sizeof(b));

    b = a + b;
    printf("b ara te el valor %d\n", b);

    b = b * 5;
    printf("b ara te el valor %d\n", b);

    /**Desbordament de la variable 'b'**/
    b = b * 10;
    printf("b ara te el valor %d\n", b);

    b = b * 100;
    printf("b ara te el valor %d\n", b);

    b = b + 200;
    printf("b ara te el valor %d\n", b);


    return 0;
}