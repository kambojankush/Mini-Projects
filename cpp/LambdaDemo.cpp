#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream file("data.txt");

	std::vector<std::string> lines{};
	std::string line;

	while(std::getline(file, line))
	{
		lines.push_back(line);
	}

	sort(std::begin(lines), std::end(lines),
		[](auto const& a, auto const& b){
			return a.length() < b.length();
		});

	for (std::string l : lines)
	{
		std::cout << l << std::endl;
	}

	file.close();
	
	return 0;
}