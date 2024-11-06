#include <iostream>

using namespace std;

void encrypt (string &word, int shift) {

    for (int i=0;i<word.length();i++) {
        word[i] = word[i] + shift;
        if (word [i] > (char)122) {
            word[i] -= (char)26;
        }
    }

}

string decrypt (string word, int shift) {

    for (int i=0;i<word.length();i++) {
        word[i] = word[i] - shift;
        if (word [i] < (char)97) {
            word[i] += (char)26;
        }
    }

    return word;

}

int main () {

    char choice;
    int shift;
    string input, result;
    bool loop = true;

    while (loop) {
        cout << "Type d to decrypt, e to encrypt, anything else to quit" << endl;
        cin >> choice;
        switch (choice) {
            case 'd':
            case 'e':
                cout << "Type the word" << endl;
                cin >> input;
                cout << "Type the shift" << endl;
                cin >> shift;
                if (choice=='e') {
                    encrypt(input, shift);
                    cout << "Result: " << input << endl << endl;
                } else {
                    result = decrypt (input, shift);
                    cout << "Result: " << result << endl << endl;

                }
                break;
            default:
                loop= false;
                break;

        }
    }
    return (0);

}
