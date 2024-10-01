


#include <iostream>
#include <string>
#include <cstring>

// C-style pass by value using char arrays
void renamePet(char name[], const char newName[]) {
    strcpy(name, newName);
    std::cout << "Inside function: " << name << std::endl;
}

// C++-style pass by reference using std::string
void renamePet(std::string& name, const std::string& newName) {
    name = newName;
    std::cout << "Inside function: " << name << std::endl;
}

void changeAge(int old, int newAge) {
    old = newAge;
    std::cout << "Inside function: " << old << std::endl;
}

int main() {
    char dogName[20] = "Buddy";
    std::string catName = "Whiskers";
    int petAge = 5;

    std::cout << "Original pet names:" << std::endl;
    std::cout << "Dog: " << dogName << std::endl;
    std::cout << "Cat: " << catName << std::endl;
    std::cout << "Age: " << petAge << std::endl;

    std::cout << "\nAttempting to rename dog (C-style, pass by value):" << std::endl;
    renamePet(dogName, "Max");
    std::cout << "After function call: " << dogName << std::endl;

    std::cout << "\nAttempting to rename cat (C++-style, pass by reference):" << std::endl;
    renamePet(catName, "Mittens");
    std::cout << "After function call: " << catName << std::endl;

    std::cout << "\nAttempting to change age (C-style, pass by vale):" << std::endl;
    changeAge(petAge, 20);
    std::cout << "After function call: " << petAge << std::endl;


    return 0;
}