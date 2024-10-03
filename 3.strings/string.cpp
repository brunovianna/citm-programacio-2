

include <iostream>

int main () {

    std::string mystr;

    std::cout << "enter line\n";
    std::getline (std::cin, mystr);

    int counter = 0;

    for (int i=0;i<(int)mystr.length();i++) {
        if (std::isdigit(mystr[(u_long)i])) {
            counter++;
        }

    }

    std::cout << "I counted "<<counter<< " digits";

}
