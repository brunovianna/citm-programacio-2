#include <iostream>
using namespace std;

void printBoard (char board[], bool found[]) {
    for (int i=0;i<10;i++) {
        //if ((found[i])) {

        if (*(found+i)) {
            cout << *(board+i);
        } else {
            cout << ".";
        }
    }

    cout << endl;
}

void printBoard (int pos, char board[], bool found[]) {

    for (int i=0;i<10;i++) {
        if (*(found+i)||(i==pos)) {
            cout << *(board+i);
        } else {
            cout << ".";
        }
    }

    cout << endl;

}

void printBoard (int pos1, int pos2, char board[], bool found[]) {

    for (int i=0;i<10;i++) {
        if (*(found+i)||(i==pos1)||(i==pos2)) {
            cout << *(board+i);
        } else {
            cout << ".";
        }
    }

    cout << endl;

}

int main () {
    char memoryBoard[10] {'A','B','E','E','C','A','D','B','C','D'};
    bool found[10] {false};
    int totalFound = 0;
    int pos1, pos2;

    while (totalFound!=5) {
        printBoard(memoryBoard,found);
        cout << "Enter the first position (0-9)" << endl;
        cin >> pos1;

        printBoard(pos1,memoryBoard,found);

        cout << "Enter the second position (0-9)" << endl;
        cin >> pos2;

        printBoard(pos1,pos2,memoryBoard,found);

        if (*(memoryBoard+pos1)==*(memoryBoard+pos2)) {
            cout << "You found a pair\n";
            totalFound++;
            *(found+pos1)=*(found+pos2)=true;
        } else {
            cout << "Sorry, they don't match\n";

        }


    }

    cout << "Congratulations, you found all!\n";


}