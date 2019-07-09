#include <iostream>

[[Deprecated("DoSomething() is inefficient; Use DoSomethingBetter")]]
void DoSomething()
{
	std::cout << "Doing something ..." << std::endl;
}

void DoSomethingBetter()
{
	std::cout << "Doing something better ..." << std::endl;
}

int main ()
{
	DoSomething();
	return 0;
}