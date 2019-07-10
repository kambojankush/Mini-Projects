#include <iostream>
#include <vector>
#include <algorithm>

void PrintMessage(std::string const& message, std::vector<std::string> const& names)
{
	std::cout << message << std::endl;
	for (std::string name : names)
		std::cout << name << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> names{"k9", "Kohli", "Dhoni", "Ankush", "Jadeja"};
	PrintMessage("Before", names);

	if (auto it = std::find(std::begin(names), std::end(names), "k9");
		it != std::end(names))
	{
		*it = "**";
	}

	if (auto it = std::find(names.begin(), names.end(), "Ankush");
		it != names.end())
	{
		*it = "******";
	}

	PrintMessage("After", names);

	return 0;
}