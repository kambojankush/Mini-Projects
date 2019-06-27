#include "Tweeter.h"
#include <iostream>

Tweeter::Tweeter()
{
	std::cout << "Constructing: " << twitterhandle << std::endl;
}

Tweeter::Tweeter(std::string first, std::string last, int arbitrary, std::string handle) :
	Person(first, last, arbitrary), twitterhandle(handle)
{
	std::cout << "Constructing: " << twitterhandle << std::endl;
}

Tweeter::~Tweeter()
{
	std::cout << "Destructing: " << twitterhandle << std::endl;
}
