// #include <iostream>
// #include <string>

// // C-style pass by value
// void doubleIngredient(int amount) {
//     amount *= 2;
//     std::cout << "Inside function: " << amount << std::endl;
// }

// // C++-style pass by reference
// void tripleIngredient(int& amount) {
//     amount *= 3;
//     std::cout << "Inside function: " << amount << std::endl;
// }

// int main() {
//     int flour = 2; // cups
//     int sugar = 1; // cups

//     std::cout << "Original recipe:" << std::endl;
//     std::cout << "Flour: " << flour << " cups" << std::endl;
//     std::cout << "Sugar: " << sugar << " cup" << std::endl;

//     std::cout << "\nAttempting to double flour (pass by value):" << std::endl;
//     doubleIngredient(flour);
//     std::cout << "After function call: " << flour << " cups" << std::endl;

//     std::cout << "\nAttempting to triple sugar (pass by reference):" << std::endl;
//     tripleIngredient(sugar);
//     std::cout << "After function call: " << sugar << " cups" << std::endl;

//     return 0;
// }


#include <iostream>
#include <string>

struct Outfit {
    std::string top;
    std::string bottom;
    std::string shoes;
};

// C-style pass by value
void swapShoes(Outfit *outfit, std::string newShoes) {
    outfit->shoes = newShoes;
    std::cout << "Inside function: " << outfit->top << ", " << outfit->bottom << ", " << outfit->shoes << std::endl;
}

// C++-style pass by reference
void swapTop(Outfit& outfit, std::string newTop) {
    outfit.top = newTop;
    std::cout << "Inside function: " << outfit.top << ", " << outfit.bottom << ", " << outfit.shoes << std::endl;
}


int main() {
    Outfit myOutfit = {"T-shirt", "Jeans", "Sneakers"};


    std::cout << "Original outfit: " << myOutfit.top << ", " << myOutfit.bottom << ", " << myOutfit.shoes << std::endl;

    std::cout << "\nTrying to swap shoes (pass by value):" << std::endl;
    swapShoes(&myOutfit, "Boots");
    std::cout << "After function call: " << myOutfit.top << ", " << myOutfit.bottom << ", " << myOutfit.shoes << std::endl;

    std::cout << "\nTrying to swap top (pass by reference):" << std::endl;
    swapTop(myOutfit, "Sweater");
    std::cout << "After function call: " << myOutfit.top << ", " << myOutfit.bottom << ", " << myOutfit.shoes << std::endl;

    return 0;
}



// #include <iostream>
// #include <string>
// #include <cstring>

// // C-style pass by value using char arrays
// void renamePet(char name[], const char newName[]) {
//     strcpy(name, newName);
//     std::cout << "Inside function: " << name << std::endl;
// }

// void changeAge(int old, int newAge) {
//     old = newAge;
//     std::cout << "Inside function: " << old << std::endl;
// }

// // C++-style pass by reference using std::string
// void renamePet(std::string& name, const std::string& newName) {
//     name = newName;
//     std::cout << "Inside function: " << name << std::endl;
// }

// int main() {
//     char dogName[20] = "Buddy";
//     std::string catName = "Whiskers";
//     int petAge = 5;

//     std::cout << "Original pet names:" << std::endl;
//     std::cout << "Dog: " << dogName << std::endl;
//     std::cout << "Cat: " << catName << std::endl;
//     std::cout << "Age: " << petAge << std::endl;

//     std::cout << "\nAttempting to rename dog (C-style, pass by value):" << std::endl;
//     renamePet(dogName, "Max");
//     std::cout << "After function call: " << dogName << std::endl;

//     std::cout << "\nAttempting to rename cat (C++-style, pass by reference):" << std::endl;
//     renamePet(catName, "Mittens");
//     std::cout << "After function call: " << catName << std::endl;

//     std::cout << "\nAttempting to change age (C-style, pass by vale):" << std::endl;
//     changeAge(petAge, 20);
//     std::cout << "After function call: " << petAge << std::endl;


//     return 0;
// }