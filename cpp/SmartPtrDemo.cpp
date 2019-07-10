#include <iostream>
#include <memory>

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
	std::unique_ptr<X> XPtr = std::make_unique<X>();
	XPtr->SayHi();

	return 0;
}