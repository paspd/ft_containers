#include <vector>
#include <iostream>
#include "vector.hpp"
#include "iterator_traits.hpp"

int main(){
    int nb_test(1);

    std::cout << "====================================================================" << std::endl << std::endl;
   
    std::cout << "Test " << nb_test++ << ": ft::vector<char> a(10, 'a');" << std::endl << std::endl;
   
    ft::vector<char> a(10, 'a');
    for (size_t i = 0; i < 10; i++)
        std::cout << a[i];
    std::cout << std::endl << std::endl;
   
    std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": ft::vector<int> long_list(1000000, 42);" << std::endl << std::endl;

    std::vector<int> long_list(1000000, 42);
    for (size_t i = 0; i < 1000000; i++)
        std::cout << long_list[i] << " ";
    std::cout << std::endl << std::endl;
   
    std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": ft::vector<char> const_a(10, 'a');" << std::endl << std::endl;
   
    ft::vector<char> const_a(10, 'a');
    for (size_t i = 0; i < 10; i++)
        std::cout << const_a[i];
    std::cout << std::endl << std::endl;
    
    std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": ft::vector< ft::vector<char> > list_a(10, a);" << std::endl << std::endl;

    ft::vector< ft::vector<char> > list_a(10, a);
    for (size_t i = 0; i < 10; i++) {
       for (size_t j = 0; j < 10; j++)
            std::cout << list_a[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": ft::vector<ft::vector<ft::vector<char> > > list_list_a(10, list_a);" << std::endl << std::endl;

    ft::vector<ft::vector<ft::vector<char> > > list_list_a(10, list_a);
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            for (size_t k = 0; k  < 10; k++)
            std::cout << list_list_a[i][j][k];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "====================================================================" << std::endl << std::endl;
}