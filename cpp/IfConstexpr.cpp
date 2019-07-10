#include <iostream>
#include <type_traits>

//won't compile w/o constexpr if
template <typename T>
auto GetLength(T const& t)
{
	if constexpr (std::is_integral<T>::value)
	{
		return t;
	}
	else 
	{
		return t.length();
	}
}

int main()
{
	int n{64};
	std::string s{"hydes"};

	std::cout << "n = " << n << "; length = " << GetLength(n) << std::endl;
	std::cout << "s = " << s << "; length = " << GetLength(s) << std::endl;

	return 0;
}