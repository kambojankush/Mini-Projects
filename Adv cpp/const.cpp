#include <iostream>

/*
    const : A compile time constraint that an object cannot be modified


    Why use const:
        1.) Guard against inadvertent write to variables.
        2.) Self documenting
        3.) Enable compiler to do more optimization, make code tightier
        4.) const means the variable can be put in ROM
*/

int main() {
    const int i = 9;

    const int* p1 = &i; // data is constant, pointer is not
    p1++;

    int x = 5;
    int* const p2 = &x; //pointer is constant, data is not

    // if const is to the left of *, data is constant
    // if const is to the right of *, pointer is constant

    // const_cast is used to cast away the constness of variables.
    const_cast<int&>(i) = 6;
    std::cout << i << std::endl;

    // simple cast with very strict type-checking. Only implicit conversions
    int j;
    // static_cast<const int&>(j) = 7; // gives error

    return 0;
}