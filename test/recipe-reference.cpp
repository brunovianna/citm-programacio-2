#include <iostream>
#include <string>



// C-style pass by value
void doubleIngredient(int amount) {
    amount *= 2;
    std::cout << "Inside function: " << amount << std::endl;
}

// C-style pass by reference
void halfIngredient(int* amount) {
	*amount /= 2;
	std::cout << "Inside function: " << * amount << std::endl;
}



// C++-style pass by reference
void tripleIngredient(int& amount) {
    amount *= 3;
    std::cout << "Inside function: " << amount << std::endl;
}

int main() {
    int flour = 2; // cups
    int sugar = 1; // cups
    int eggs = 6;

    std::cout << "Original recipe:" << std::endl;
    std::cout << "Flour: " << flour << " cups" << std::endl;
    std::cout << "Sugar: " << sugar << " cup" << std::endl;
    std::cout << eggs << " eggs" << std::endl;

    std::cout << "\nAttempting to double flour (pass by value):" << std::endl;
    doubleIngredient(flour);
    std::cout << "After function call: " << flour << " cups" << std::endl;

    std::cout << "\nAttempting to half eggs (pass by reference):" << std::endl;
    halfIngredient(&eggs);
    std::cout << "After function call: " << eggs << " eggs" << std::endl;


    std::cout << "\nAttempting to triple sugar (pass by reference):" << std::endl;
    tripleIngredient(sugar);
    std::cout << "After function call: " << sugar << " cups" << std::endl;

    return 0;
}