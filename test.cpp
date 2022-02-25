#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	std::vector<int> test(5);
	for (size_t i = 0; i < test.size(); i++)
		test[i] = i;

	std::vector<int>::reverse_iterator it = test.rbegin();	

 	std::cout << *(it + 1) << " " << std::endl;		
	return 0;
}
