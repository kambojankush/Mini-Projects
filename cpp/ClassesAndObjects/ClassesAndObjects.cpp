#include <iostream>
#include "Person.h"
#include "Tweeter.h"
#include "status.h"

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

	FileError fe = FileError::notfound;
	fe = FileError::ok;

	NetworkError ne = NetworkError::disconnected;
	ne = NetworkError::ok;

	std::cin.get();

	return 0;
}