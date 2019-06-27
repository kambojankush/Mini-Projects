#pragma once
#include <string>

class Person
{
private:
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;

public:
	Person() = default;
	Person(std::string first, std::string last, int arbitrary);
	std::string getName();
};

