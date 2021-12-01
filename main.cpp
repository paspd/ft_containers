#include <vector>
#include <iostream>
#include "vector.hpp"
#include "iterator_traits.hpp"

int main(){
    ft::vector<char> ft_vector;
    std::vector<char> vector;

    ft::vector<char>::iterator its = test.end();

    for (ft::vector<char>::iterator it = test.begin(); it != its; it++)
        std::cout << *it << std::endl;
}