#include <iostream>

constexpr int Fibonacci(int n)
{
	switch(n)
	{
		case 0: return 0;
		case 1: return 1;
		default: return Fibonacci(n-1) + Fibonacci(n-2);
				 break;
	}
} 

int main()
{
	static_assert(Fibonacci(10) == 55, "Unexpected fibonacci number");
	return 0;
}