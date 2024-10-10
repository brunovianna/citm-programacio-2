// ConsoleApplication6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int main()
{
    string even = "even";
    string odd = "odd";

    bool* myArray = new bool[10];   // bool (boleano) quiere decir que el numero solo puede tomar dos valores: true o false. El 10 expecifica los 'espacios' que debe dejar para almacenar en la memoria.

    for (int i = 0; i < 10; i++)    // for es un bucle. int es un numero entero.
                                    // i=0 quiere decir que empezara desde el 0. i<10 quiere decir que hará el bucle hasta que i sea menor que 10.
                                    // i++ es para que cada vez que pase por el bucle sume 1 al i.
    {
        myArray[i] = (i % 2 == 0);  // divide el numero dado i entre dos para que devuelva el resto de la division i entre 2.
    }
    // Una vez se haya puesto la condición, el siguiente bucle es para que diga si es true o false.


    while(true)    // while (true) crea un bucle infinito que seguirá ejecutándose hasta que se encuentre un break dentro de él.
    {
        int number;  //declara variable number
        cout << "Introduce un numero del 0 al 9: "; //Imprime en la consola el mensaje
        cin >> number; //cuando el usuario introduzca un numero, este se guardará en el almacenamiento 'number'.

        if (number == -1) {//si el numero que introduce el usuario es -1 para el bucle.
        break; //detiene el bucle, asi que while dejara de preguntar numeros.
        }

    if(number >= 0 && number <= 9) // Verifica si el número está dentro del rango (0 a 9).
    {
        if (myArray[number]) // comprueba que myArray sea true
        {
            cout << "El numero " << number << " es " << even << " ." << endl; //si el numero es par (true) imprimira por pantalla que es par.
        }  
        else 
        {
        cout << "El número " << number << " es " << odd << "." << endl;
        }
    }

 else {
 cout << "Número fuera de rango. Por favor, introduce un número entre 0 y 9." << endl;
        }

    }
}









