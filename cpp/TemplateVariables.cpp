#include <iostream>

template<class T>
constexpr T maxVal = T(1000);

template<>
constexpr double maxVal<double> = 2000;

template<>
constexpr char maxVal<char> = 'Z';

int main()
{
	std::cout << "maxVal<int>    = " << maxVal<int>    << std::endl;
	std::cout << "maxVal<double> = " << maxVal<double> << std::endl;
	std::cout << "maxVal<char>   = " << maxVal<char>   << std::endl;

	return 0; 
}