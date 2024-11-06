// scrambler.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int main()
{

	srand(std::time(nullptr));
	string cartes[10] = { "zero", "one", "two", "tree", "four", "five", "six", "seven", "eight", "nine" };


	cout << "\n before\n";

	for (int i = 0; i < 10; i++) {
		cout << *(cartes + i) << " ";
	}

	

	for (int i = 0; i < 10; i++) {
		int r = std::rand() % 10;
		string temp = *(cartes + r);
		*(cartes + r) = *(cartes + i);
		*(cartes + i) = temp;
	}

	cout << "\n after\n";

	for (int i = 0; i < 10; i++) {
		cout << *(cartes + i) << " ";
	}


	return (0);

}
