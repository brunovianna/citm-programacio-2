//L’examen només cobreix temes de C.Tanmateix, podeu utilitzar recursos de C++ a les respostes, com bé cout i cin.
//Un cop acabat, heu de fer un arxiu zip de la carpeta de la “solució” i penjar - ho a la tasca d’Atenea.
//Podeu consultar tots arxius disponibles a Atenea.Els enllaços no haurien de funcionar, però la descàrrega
//d'arxiu sí, per exemple les coses a la carpeta Downloadable Resources, com aquesta referència de C++.
//Només es pot utilitzar el browser Edge
//Telefons sobre el desktop
//
//2. Programeu un verificador de contrasenyes.L’usuari ha d’entrar amb una contrasenya qualsevol i després digitar la mateixa d’abans.
//
//El programa ha de verificar si són iguals.En cas que no siguin, s’ha de demanar les dues un altre cop amb un missatge d’error.
//Es pot utilitzar una funció de string.h o std::string per fer la comparació.
//
//S’ha d’escriure una funció per verificar si la contrasenya conté almenys 1 lletra i un número.La mida no importa, per exemple, la contrasenya “8i” és vàlida)

#include <iostream>
#include <string>

// He creado una funcion booleana que devuelve un valor en true o false para verificar que la contraseña contiene al menos un caracter y un digito
bool verifyPassword(std::string password, int passwordlength) {

	// Declaro las variables que usare para las comprobaciones
	int isDigit = 0, isChar = 0;
	bool isCorrect = false;

	for (int i = 0; i < passwordlength; i++)
	{
		// Con la funcion isdigit() verifico si hay un digito y subo uno a la variable isDigit
		if (isdigit(password[i])) {
			isDigit += 1;
		}
		// si no es un digito significa que es un caracter y por lo tanto tambien subo +1
		else {
			isChar += 1;
		}
	}

	// Mientras los valores en isDigit y isChar sean iguales o mayores de 1, la contraseña será correcta y se devolverá un true al main()
	if (isDigit >= 1 && isChar >= 1) {
		isCorrect = true;
	}

	return isCorrect;

}

int main() {

	// Declaro dos variables de tipo string para guardar las dos contraseñas
	std::string firstpassword, secondpassword;

	// Como tambien dos variables de tipo int para poder tener el tamaño de estas
	int firstlength,secondlength;

	// Estas dos variables booleanas son para salir de los bucles while
	bool exit = true, exit2 = true;

	while (exit)
	{
		std::cout << "First password:" << std::endl;
		std::getline(std::cin, firstpassword);


		firstlength = firstpassword.length();

		// Primero compruebo que la contraseña sea valida, tan solo lo hago en la primera puesto que la segunda ha de ser identica
		if (verifyPassword(firstpassword, firstlength) == false) {
			
			std::cout << "The password must have at least 1 digit and 1 character. Try again!" << std::endl;
			exit = true;
		}
		else {
			exit = false;
		}

	}

	while (exit2)
	{
		std::cout << "Repeat password:" << std::endl;
		std::getline(std::cin, secondpassword);

		int correctI = 0;

		secondlength = secondpassword.length();

		// La primera comprovacion será del tamaño de cada string
		if (secondlength == firstlength) {
			for (int i = 0; i < firstlength; i++) {

				if (firstpassword[i] == secondpassword[i]) {
					// Por cada caracter de la contraseña que sea correcto, se sumará 1
					correctI += 1;
				}
				else {
					std::cout << "The password doesn't match. Try again!" << std::endl;
					// Si no son iguales, se saldrá de este bucle for y se pedira al usuario que la vuelva a escribir
					break;
				}

			}
		}

		// Si el tamaño de los strings no es igual, se tendra que volver a escribir la segunda variable
		else {
			std::cout << "The password doesn't match. Try again!" << std::endl;
		}

		// Si el valor de la variable creada para verificar, es igual que el de la largaria del string
		// (da igual si es el primero o el segundo porque ya se ha comprovado eso anteriormente)
		// Se mostrará un mensaje y se cerrará el programa
		if (correctI == secondlength) {
			std::cout << "The passwords match!" << std::endl;
			exit2 = false;
		}

	}


}