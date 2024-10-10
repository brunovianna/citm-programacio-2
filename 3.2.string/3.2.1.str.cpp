#include <iostream>
#include <cstring>  // For C-style string functions
#include <string>   // For C++ string class
#include <cctype>   // For C-style character classification functions

int main() {
    // C-style strings
    const char* c_str1 = "Hello, World!";
    const char* c_str2 = "Hello, C++!";
    
    // C++ strings
    std::string cpp_str1 = "Hello, World!";
    std::string cpp_str2 = "Hello, C++!";

    // 1. Finding string length
    std::cout << "1. String Length:\n";
    std::cout << "C-style:   " << strlen(c_str1) << std::endl;
    std::cout << "C++-style: " << cpp_str1.length() << std::endl;

    // 2. Comparing strings
    std::cout << "\n2. String Comparison:\n";
    std::cout << "C-style:   " << strcmp(c_str1, c_str2) << std::endl;
    std::cout << "C++-style: " << (cpp_str1 == cpp_str2 ? "0" : (cpp_str1 < cpp_str2 ? "-1" : "1")) << std::endl;

    // 3. Checking if characters are digits or letters
    std::cout << "\n3. Character Classification:\n";
    
    const char* c_test_str = "Test123";
    std::string cpp_test_str = "Test123";

    std::cout << "C-style:\n";
    for (int i = 0; c_test_str[i] != '\0'; ++i) {
        std::cout << c_test_str[i] << " is ";
        if (isdigit(c_test_str[i])) std::cout << "a digit";
        else if (isalpha(c_test_str[i])) std::cout << "a letter";
        else std::cout << "neither a digit nor a letter";
        std::cout << std::endl;
    }

    std::cout << "\nC++-style:\n";
    for (char c : cpp_test_str) {
        std::cout << c << " is ";
        if (std::isdigit(c)) std::cout << "a digit";
        else if (std::isalpha(c)) std::cout << "a letter";
        else std::cout << "neither a digit nor a letter";
        std::cout << std::endl;
    }

    std::cout << "array access " << std::isdigit(cpp_test_str[2]);


    return 0;
}