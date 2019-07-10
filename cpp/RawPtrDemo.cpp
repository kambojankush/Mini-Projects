#include <iostream>

class X 
{
private:
	int m1{};
	double m2{3.14};

public:
	X() { std::cout << "Constructing X" << std::endl; }
	
	void SayHi() { std::cout << "X is saying Hi!!" << std::endl; }

	~X() { std::cout << "Destructing X" << std::endl; }
};

int main() 
{
	X * XPtr = new X;
	XPtr->SayHi();
	// Memory leak; no destructor will be called

	return 0;
}