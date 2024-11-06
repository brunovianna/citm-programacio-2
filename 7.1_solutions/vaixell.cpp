#include <iostream>

using namespace std;

class Boat {
    private:
        int speed;
        static const int maxRowers = 4;
        static const int maxWeight = 250;
        
        string rowers[maxRowers];
        int totalWeight;
        int numRowers;

    public:
        Boat() {
            speed = 0;
            totalWeight = 0;
            numRowers = 0;
        }
        Boat(string names[4]) {
            copy (names, names+4, rowers);
            for (int i=0; i<4; i++) rowers[i] = names[i];
            speed = 0;
            totalWeight = 0;
            numRowers = 0;
        }
        bool addRower (string name, int weight) {
            if (numRowers<maxRowers) {
                totalWeight += weight;
                if (totalWeight > 250) {
                    return false;
                } else {
                    rowers[numRowers] = name;
                    numRowers++;
                }
            }  
            return true;
        }

        int getNumRowers() {
            return numRowers;
        }

        void accelerate () {
            speed += 10;
        }
        void slow () {
            speed -= 10;
        }

};


int main () {
    Boat myBoat;
    bool loading = true;
    string name;
    int weight;
    char movement;
    string names[4];

    Boat newBoat(names);
    cout << "amount of rowers: " << newBoat.getNumRowers() << endl;

    while (loading) {
        cout << "enter rower name" << endl;
        cin >> name;
        cout << "enter rower weight" << endl;
        cin >> weight;
        
        if (myBoat.addRower(name, weight)) {
            if (myBoat.getNumRowers()==4) {
                cout << "loading done" << endl;
                loading = false;
            }
        } else {
            cout << "oh no the boat sank! Start again" << endl;
            exit(1);
        }
    }

    while (true) {
        cout << "enter + or - , or q to quit" << endl;
        cin >> movement;
        if (movement == '+') {
            myBoat.accelerate();
        } else if (movement == '-') {
            myBoat.slow();
        } else if (movement == 'q') {
            break;
        }
    }

}
