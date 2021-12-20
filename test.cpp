#include <iostream>
#include <vector>

int main()
{
	std::vector<int> test(3, 1);

	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;

	test.erase(test.begin() + 1);

	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;
	
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;
	return 0;
}
