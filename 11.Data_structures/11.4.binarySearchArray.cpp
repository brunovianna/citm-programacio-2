// binarySearch.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;


bool binarySearch(int *arr, int low, int high, int target) {



}

int main() {
    int orderedData [10]{ 1, 2, 3, 4, 8, 9, 11, 15,20,25 };

    // Element to be searched
    int target = 20;

    // recursive function
    if (binarySearch(orderedData, 0, 9, target)) {
        cout << target << ": ordered- found in " << counter << " steps.\n";
    }
    else {
        cout << target << ": ordered-  NOT found." << counter << " steps.\n";
    }
    return 0;
}
