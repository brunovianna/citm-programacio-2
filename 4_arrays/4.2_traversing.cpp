// 4.2-TreasureMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 20;


struct treasureMap_struct {
    char charMap[ARRAY_SIZE];
    int treasure;
    int player;
};

void printMap(treasureMap_struct map) {
    for (char* i = map.charMap; i < map.charMap + ARRAY_SIZE; i++) {
        cout << *i;
    }
    cout << std::endl;
}

int main() {
    srand(std::time(nullptr));

    treasureMap_struct treasureMap;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        *(treasureMap.charMap + i) = '.';
    }

    printMap(treasureMap);

    // Place the treasure
    treasureMap.treasure = std::rand() % ARRAY_SIZE;
    *(treasureMap.charMap + treasureMap.treasure) = 'T';
    *(treasureMap.charMap) = '@';


    treasureMap.player = 0;


    cout << "Find the treasure (T)." << endl;
    cout << "Commands: 'a' to move left, 'd' to move right, 'q' to quit." << endl << endl;

    while (true) {
        printMap(treasureMap);

        if (treasureMap.player == treasureMap.treasure) {
            std::cout << "Congratulations! You found the treasure!" << endl;
            break;
        }

        char move;
        cout << "Enter your move: ";
        cin >> move;

        switch (move) {
        case 'a':
            if (treasureMap.player > 0) {
                *(treasureMap.charMap + treasureMap.player) = '.';
                treasureMap.player--;
                *(treasureMap.charMap + treasureMap.player) = '@';
                cout << "Moved left by 1 (pointer arithmetic: playerPtr--)." <<  endl;
            }
            else {
                 cout << "Can't move left. You're at the start of the array." <<  endl;
            }
            break;
        case 'd':
            if (treasureMap.player < ARRAY_SIZE - 1) {
                *(treasureMap.charMap + treasureMap.player) = '.';
                treasureMap.player++;
                *(treasureMap.charMap + treasureMap.player) = '@';
                cout << "Moved right by 1 (pointer arithmetic: playerPtr++)." << endl;
            }
            else {
                cout << "Can't move right. You're at the end of the array." <<  endl;
            }
            break;
        case 'q':
             cout << "Thanks for playing!" <<  endl;
            return 0;
        default:
            cout << "Invalid move. Use 'a' for left, 'd' for right, or 'q' to quit." <<  endl;
        }


         cout << "Current position in array: " << treasureMap.player <<  endl;
    }

    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

