#include <iostream>
#include <map>

int main()
{
	std::map<std::string, std::string> frenchEnglishDict {
		{"chat", "cat"},
		{"cheval", "horse"},
		{"homme", "man"}, 
		{"femme", "woman"},
		{"pizza", "pizza"},
		{"elle", "she"}
	};

	auto [position, success] = frenchEnglishDict.insert({"fille", "girl"});
	if (success)
		std::cout << "Insertion Successful !!" << std::endl;

	for (auto const& [french, english] : frenchEnglishDict)
	{
		std::cout << french << " : " << english << std::endl;
	}

	return 0;
}