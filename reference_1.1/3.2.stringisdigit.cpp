#include "stdio.h"
#include <iostream>

int main () {
    std::string s ="alo1";
    std::getline (std::cin, s);
    std::cout << "aqui: " << s;
   // printf ("%d",std::isdigit (s[2]));
    return 0;
}