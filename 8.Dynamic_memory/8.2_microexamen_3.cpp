// splitArray.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

void splitArray(string* originalArray, int originalSize, int splitPoint,
    string* firstPart, string* secondPart) {
    // Copy elements to firstPart array (0 to splitPoint-1)
    for (int i = 0; i < splitPoint; i++) {
        firstPart[i] = originalArray[i];
    }

    // Copy elements to secondPart array (splitPoint to end)
    int secondArrayIndex = 0;
    for (int i = splitPoint; i < originalSize; i++) {
        secondPart[secondArrayIndex] = originalArray[i];
        secondArrayIndex++;
    }
}


void printArray(string* arr, int size, string arrayName) {
    cout << arrayName << ": {";
    for (int i = 0; i < size; i++) {
        cout << "\"" << arr[i] << "\"";
        if (i < size - 1) cout << ", ";
    }
    cout << "}" << endl;
}

int main() {
    const int SIZE = 10;
    int splitPoint;
    string* arr = new string[SIZE]{ "zero", "one", "two", "three", "four",
                                  "five", "six", "seven", "eight", "nine" };

    // Print original array
    cout << "Original ";
    printArray(arr, SIZE, "array");

    cout << "Enter the split point (0-" << SIZE << "): ";
    cin >> splitPoint;

    // Create new arrays for split parts
    string* firstPart = new string[splitPoint];
    string* secondPart = new string[SIZE - splitPoint];

    splitArray(arr, SIZE, splitPoint, firstPart, secondPart);

    printArray(firstPart, splitPoint, "First part");
    printArray(secondPart, SIZE - splitPoint, "Second part");

    // Free memory
    delete[] arr;
    delete[] firstPart;
    delete[] secondPart;

    return 0;
}

