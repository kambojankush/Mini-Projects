#include <iostream>
#include <chrono>
using namespace std::chrono_literals;

void PrintTime(std::chrono::milliseconds ms)
{
	std::cout << ms.count() << "ms" << std::endl;
}

int main()
{
	auto x = 2s;
	std::cout << "x = 2s : "; PrintTime(x);

	auto y = 150ms;
	std::cout << "y = 150ms : "; PrintTime(y);

	auto z = x + y;
	std::cout << "z = x + y : "; PrintTime(z);

	auto timeLimit = 3s;
	std::cout << "Time Limit is :"; PrintTime(timeLimit);

	if (z < timeLimit)
		std::cout << "All right! :)" << std::endl;
	else
		std::cout << "Time-Out! :(" << std::endl;

	return 0;
}