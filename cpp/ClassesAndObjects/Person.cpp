#include <iostream>
#include "Person.h"

Person::Person() 
{
	std::cout << "Constructing: " << getName() << std::endl;
}

Person::Person(std::string first, std::string last, int arbitrary) :
	firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
	std::cout << "Constructing: " << getName() << std::endl;
}

Person::~Person()
{
	std::cout << "Destructing: " << getName() << std::endl;
}

std::string Person::getName() 
{
	return firstname + " " + lastname;
}
