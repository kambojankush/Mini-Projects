#include <iostream>

class Dog {
    int age;
    std::string name;

public:
    Dog() {
        age = 3;
        name = "Tommy";
    }
    
    void set_age(const int& a) {
        std::cout << "const" << std::endl;
        age = a;
    }

    void set_age(int& a) {
        std::cout << "non-const" << std::endl;
        age = a;
    }

    const std::string& get_name() {
        return name;
    }

    // const funtion can only call other const functions
    void print_name() const {
        std::cout << name << "const" << std::endl;
    }

    void print_name() {
        std::cout << name << "non-const" << std::endl;
    }
};

int main() {
    Dog d;
    int x = 3;
    // d.set_age(x);
    // d.print_name();
    std::cout << s << std::endl;
    d.print_name();
}