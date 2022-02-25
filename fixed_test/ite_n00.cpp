#include "fixed_test.hpp"

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

	std::cout << vct.size() << std::endl;
	
	for (int i = 0; i < size; ++i)
		it[i] = i;

	ite[1] = 42; // < -- error

	return (0);
}
