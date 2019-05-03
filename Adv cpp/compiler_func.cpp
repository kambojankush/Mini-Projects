#include <iostream>

/*
    Compiler silently writes 4 functions if they are not explicitly declared:
        1. Default constructor (only if there is no constructor declared)
        2. Copy constructor
        3. Copy assignment operator
        4. Default constructor (only if there is no constructor declared)

    Note:
        1. They are public and inline.
        2. They are generated only if they are needed.

    Example:
        class Dog{};

        is equivalent to:

        class Dog() {
        public:
            Dog(const Dog& rhs) {...}
            Dog& operator=(const Dog& rhs) {...}
            Dog() {...}  // 1. Call base class's default constructor.
                         // 2. Call data member's default constructor. 
            ~Dog() {...} // 1. Call base class's default desstructor.
                         // 2. Call data member's default desstructor.
        }
*/

// Example 1:
class Dog {
public:
    std::string name;

    Dog(std::string str = "Tommy") {
        name = str;
        std::cout << name << " is born." << std::endl;
    }

    ~Dog() {
        std::cout << name << " died." << std::endl;
    }
};

/*
int main() {
    Dog d1("Bobby");
    Dog d2;
    d2 = d1;
    return 0;
}
Output:
    Bobby is born.
    Tommy is born.
    Bobby died.
    Bobby died.

Compiler generated functions:
    1. Copy assignment operator.
*/

// Example 2:
class Collar {
public:
    Collar(std::string name) {
        std::cout << "Collar is generated";
    }
};

class Dog2 {
    Collar collar;
};

/*
int main() {
    Dog2 d;
    return 0;
}

Output:
    error: use of deleted function 'Dog2::Dog2()
*/

// Example 3:
class Collar2 {
public:
    Collar2() {
        std::cout << "Collar2 is generated" << std::endl;
    }
};

class Dog3 {
    Collar2 collar;
};

/*
int main() {
    Dog3 d;
}

Output:
    Collar2 is generated

Compiler generated functions:
    1. Default constructor (Dog)
*/

// Example 4:
// default: makes the compiler generate the default implementations for explicitly defaulted functions,
//          which are more efficient than manually programmed function implementations.
class A {
public:
    A() = default;
    A(int x) {
        std::cout << "This is a parameterized constructor" << std::endl;
    }
};

/*
int main() {
    A a;
    A b(3);
    return 0;
}

Output:
    This is a parameterized constructor
*/

//Exapmle 5:
// delete: To disable the usage of a member function.
class AB { 
public: 
	AB(int) {} 

	// Declare the conversion constructor as a 
	// deleted function. Without this step, 
	// even though A(double) isn't defined, 
	// the A(int) would accept any double value 
	// for it's argumentand convert it to an int 
	AB(double) = delete; 
}; 

int main() 
{ 
	AB A1(1); 
	
	// Error, conversion from 
	// double to class A is disabled. 
	// AB A2(100.1); 
	return 0; 
} 
