// Logic constness and bitwise constness
#include <iostream>
#include <vector>

class BigArray {
    std::vector<int> v;
    mutable int accessCounter; // can be changed within a const function

    int* v2;

public:
    int getItem(int index) const {
        accessCounter++;
        return v[index];
    }

    // even though the function changes the value logically, it is bitwise const (does not directly changes any member variable).
    // i.e it will successfully compile even though is declared const
    void setV2Item(int index, int value) const {
        *(v2+index) = value;
    }
};

int main() {
    BigArray b;
    return 0;
}