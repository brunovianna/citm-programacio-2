//Programeu una calculadora que pren dues entrades numèriques i fa una operació de sumar, multiplicar, dividir o restar.
//Les dues primeres entrades són nombres, i la tercera és l'operació. L'usuari pot triar l’operació amb nombres, per exemple :
//  1 - Multiplicar
//  2 - Sumar
//  3 - Dividir
//  4 - Restar
//També es pot utilitzar, per triar, els símbols de les operacions com : +, -, *, /
//Feu atenció al cas en què hi hagi resultats decimals.

#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int main() 
{
    float num1;
    float num2;
    int desition;

    printf("Please insert the first number:");
    scanf_s("%f", &num1);

    printf("Please insert the second number:");
    scanf_s("%f", &num2);

    printf("\nNow, choose what do u want to do:\n1.Multiplicar\n2.Sumar\n3.Dividir\n4.Restar\n\nAnswer:");
    scanf_s("%d", &desition);

    if(desition==1)
    {
        printf("\nThe result is %.2f", num1*num2);
    }
    else if (desition == 2)
    {
        printf("\nThe result is %.2f", num1+num2);
    }
    else if (desition == 3)
    {
        printf("\nThe result is %.2f", num1/num2);
    }
    else if (desition == 4)
    {
        printf("\nThe result is %.2f", num1-num2);
    }
}