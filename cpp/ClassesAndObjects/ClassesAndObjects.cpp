#include <iostream>
#include "Person.h"

int main() 
{
	Person p1("Ankush", "Kamboj", 32);
	Person p2;

	std::string name = p1.getName();
	std::cout << "name: " << name << std::endl;
	std::cin.get();
}