#include <iostream>
#include "Person.h"
#include "Tweeter.h"

int main() 
{
	Person p1("Ankush", "Kamboj", 32);
	{
		Tweeter t1("Someone", "Else", 27, "@whosomeone");
		std::cout << "Tweeter name: " << t1.getName() << std::endl;
	}
	std::cout << "Outside Block" << std::endl;
	std::string name = p1.getName();
	std::cout << "Person name: " << name << std::endl;
	std::cin.get();

	return 0;
}