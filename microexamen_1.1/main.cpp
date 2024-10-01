#include "string.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main () {

    char firstpass [50];
    char secondpass [50];
    int alpha, digit = 0;
    
    scanf ("%s",firstpass);

    for (int i=0;i<(int)strlen(firstpass);++i) {
        if (isalpha(firstpass[i])) alpha = 1;
        if (isdigit(firstpass[i])) digit = 1;

    }

    cout << alpha << " " << digit << std::endl;

    return 0;
}