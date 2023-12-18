#include <iostream>

int myFunction() {
    return 23;
}

#ifndef UNIT_TEST

int main() {
    myFunction();
    return 0;
}

#endif

