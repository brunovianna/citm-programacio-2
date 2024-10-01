
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

