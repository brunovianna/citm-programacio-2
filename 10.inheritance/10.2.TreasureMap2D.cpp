// 4.2-TreasureMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


const int ARRAY_SIZE = 20;

const int ARRAY_X = 20;
const int ARRAY_Y = 20;

class TreasureMapClass {
private:

    char charMap[ARRAY_SIZE]{};

public:
    int treasure_x;
    int player_x;
    TreasureMapClass() {

        for (int i = 0; i < ARRAY_SIZE; i++) {

            charMap[i] = '.';
        }

        // Place the treasure
        treasure_x = std::rand() % ARRAY_SIZE;
        charMap[treasure_x] = 'T';

        //place the player at the leftmost position
        player_x = 0;

        charMap[player_x] = '@';

    }
    void print() {
        for (char* i = charMap; i < charMap + ARRAY_SIZE; i++) {
            cout << *i;
        }
        cout << std::endl;
    }
        bool move(char m) {
        switch (m) {
        case 'a':
            if (player_x > 0) {
                charMap[player_x] = '.';

                player_x--;
                charMap[player_x] = '@';
                cout << "Moved left by 1" <<  endl;
            }
            else {
                cout << "Can't move left. You're at the start of the line." <<  endl;
            }
            break;
        case 'd':
            if (player_x < ARRAY_SIZE-1) {
                charMap[player_x] = '.';

                player_x++;
                charMap[player_x] = '@';
                cout << "Moved right by 1" << endl;
            }
            else {
                cout << "Can't right left. You're at the end of the line." << endl;
            }
            break;
        case 'q':
           cout << "Thanks for playing!" <<  endl;
           return false;
        }
        return true;
    }

    bool checkTreasure() {
        if ((player_x == treasure_x)) {
            return true;
        }
        else {
            return false;
        }
    }
};



class TreasureMapClass2D: public TreasureMapClass {
private:

    char charMap2D[ARRAY_X][ARRAY_Y];

public:
    int treasure_y;
    int player_y;
    TreasureMapClass2D() {

        for (int j=0;j< ARRAY_Y; j++) {

            for (int i = 0; i < ARRAY_X; i++) {

                charMap2D[i][j] = '.';
            }
        }

        // Place the treasure
        treasure_x = std::rand() % ARRAY_X;
        treasure_y = std::rand() % ARRAY_Y;
        charMap2D[treasure_x][treasure_y] = 'T';

        //place the player at the leftmost position
        player_x = 0;
        player_y = 0;
        charMap2D[player_x][player_y] = '@';

    }

    bool move(char m) {
        switch (m) {
        case 'a':
            if (player_x > 0) {
                charMap2D[player_x][player_y] = '.';

                player_x--;
                charMap2D[player_x][player_y] = '@';
                cout << "Moved left by 1" <<  endl;
            }
            else {
                cout << "Can't move left. You're at the start of the line." <<  endl;
            }
            break;
        case 'd':
            if (player_x < ARRAY_X-1) {
                charMap2D[player_x][player_y] = '.';

                player_x++;
                charMap2D[player_x][player_y] = '@';
                cout << "Moved right by 1" << endl;
            }
            else {
                cout << "Can't right left. You're at the end of the line." << endl;
            }
            break;
        case 'w':
            if (player_y > 0) {
                charMap2D[player_x][player_y] = '.';

                player_y--;
                charMap2D[player_x][player_y] = '@';
                cout << "Moved up by 1" << endl;
            }
            else {
                cout << "Can't move up. You're at the top of the board." << endl;
            }
            break;
        case 's':
            if (player_y < ARRAY_Y-1) {
                charMap2D[player_x][player_y] = '.';

                player_y++;
                charMap2D[player_x][player_y] = '@';
                cout << "Moved down by 1" << endl;
            }
            else {
                cout << "Can't move down. You're at the bottom of the board." << endl;
            }
            break;
        case 'q':
           cout << "Thanks for playing!" <<  endl;
           return false;
        }
        return true;
    }

    void print() {
        for (int j = 0; j < ARRAY_Y; j++) {

            for (int i = 0; i < ARRAY_X; i++) {

                cout << charMap2D[i][j];
            }
            cout << endl;
        }
    }


    bool checkTreasure() {
        if ((player_x == treasure_x) && (player_y == treasure_y)) {
            return true;
        }
        else {
            return false;
        }
    }
};


int main() {
    srand(std::time(nullptr));

    TreasureMapClass2D treasureMap;


    cout << "Find the treasure (T)." << endl;
    cout << "Commands: 'a','s','d','w' to move  'q' to quit." << endl << endl;

    while (true) {
        treasureMap.print();

        if (treasureMap.checkTreasure()) {
            std::cout << "Congratulations! You found the treasure!" << endl;
            break;
        }

        char move;
        cout << "Enter your move: ";
        cin >> move;

        if (!treasureMap.move(move)) {
            return (0);
        }


    }

    return 0;
}
