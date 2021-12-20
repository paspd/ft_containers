#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	std::vector<int> test;

	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;

	test.push_back(2);

	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;
	
	test.push_back(3);
	test.push_back(3);

	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;

	test.pop_back();
std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;
	test.pop_back();
std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;
	test.pop_back();
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;
	return 0;
}
