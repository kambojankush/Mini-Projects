#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> p = std::make_unique<int>(64);
	auto lambda = [ptr = std::move(p)](){ std::cout << "Inside Lambda, value = " << *ptr << std::endl; };

	lambda();
	std::cout << "Outside Lambda, value = " << (p==nullptr) << std::endl;

	return 0;
}