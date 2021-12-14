#include <iostream>
#include <vector>

int main()
{
	std::vector<int> test(3, 1);

	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;

	std::vector<int>::iterator it = test.insert(test.begin(), 2);
	
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;
	
	it = test.insert(it, 3);
	it = test.insert(it, 4);
	
	std::cout << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++) std::cout << test[i]; std::cout << std::endl;
	return 0;
}
