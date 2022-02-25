#include "fixed_test.hpp"

int		main(void)
{
	int nb_test = 1;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;

	std::cout << std::endl << "Test n°" << nb_test++ << std::endl << std::endl;
	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	printSize(vct);
	printSize(vct_two);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << std::endl << "Test n°" << nb_test++ << std::endl << std::endl;
	std::cout << "\t### After assign(): ###" << std::endl;

	printSize(vct);
	printSize(vct_two);
	printSize(vct_three);
	printSize(vct_four);

	std::cout << std::endl << "Test n°" << nb_test++ << std::endl << std::endl;
	vct_four.assign(6, 84);
	printSize(vct_four);

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	std::cout << std::endl << "Test n°" << nb_test++ << std::endl << std::endl;
	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	std::cout << std::endl << "Test n°" << nb_test++ << std::endl << std::endl;
	printSize(vct);
	printSize(vct_two);

	return (0);
}
