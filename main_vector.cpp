#include <vector>
#include <iostream>
#include "vector.hpp"
#include "iterator_traits.hpp"

int main(int ac, char **av){
    (void)av;
    int nb_test(1);

    std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Constructor error" << std::endl << std::endl;

    try {
        ft::vector<int> too_high(SIZE_T_MAX + 1, 3);
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    try {
        ft::vector<int> too_high(SIZE_T_MAX + 1, 3);
        ft::vector<int> too_short(-1000, 3);
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    

    std::cout << "====================================================================" << std::endl << std::endl;
   
    std::cout << "Test " << nb_test++ << ": Constructor by copy" << std::endl << std::endl;

    ft::vector<char> for_copy(10, 'O');
    
    std::cout << "ft::vector<char> for_copy(10, 'O');" << std::endl << std::endl;
    for (size_t i = 0; i < 10; i++)
        std::cout << for_copy[i];
    std::cout << std::endl << std::endl;

    ft::vector<char> copy_construct(for_copy);
    
    std::cout << "ft::vector<char> copy_construct(for_copy);" << std::endl << std::endl;
    for (size_t i = 0; i < 10; i++)
        std::cout << copy_construct[i];
    std::cout << std::endl << std::endl;

    std::cout << "====================================================================" << std::endl << std::endl;
    
    std::cout << "Test " << nb_test++ << ": ft::vector<char> a(10, 'a');" << std::endl << std::endl;
   
    ft::vector<char> a(10, 'a');
    for (size_t i = 0; i < 10; i++)
        std::cout << a[i];
    std::cout << std::endl << std::endl;
   
    if (ac > 1) {
    std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": ft::vector<int> long_list(1000000, 42);" << std::endl << std::endl;

    ft::vector<int> long_list(1000000, 42);
    for (size_t i = 0; i < 1000000; i++)
        std::cout << long_list[i] << " ";
    std::cout << std::endl << std::endl;
   
    }
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

    // std::cout << "Test " << nb_test++ << ": Construtor with iterrators of real vector" << std::endl << std::endl;

    // std::vector<char> real_vector_char(10, 'K');
    // ft::vector<char> iter_vector(real_vector_char.begin(), real_vector_char.end());
    // for (size_t i = 0; i < 10; i++)
        // std::cout << iter_vector[i];
    // std::cout << std::endl << std::endl;
 
    // std::cout << "====================================================================" << std::endl << std::endl;
 
    std::cout << "Test " << nb_test++ << ": Size member function" << std::endl << std::endl;

    ft::vector<int> size_42(42, 21);
    std::cout << "ft::vector<int> size_42(42, 42); | size_42.size() : " << size_42.size() << std::endl << std::endl;

    if (ac > 1) {
        ft::vector<char*> size_int_max(INT_MAX, (char *)"Hello!");
        std::cout << "ft::vector<char*> size_int_max(INT_MAX, (char *)\"Hello!\"); | size_int_max.size() : " << size_int_max.size() << std::endl << std::endl;
    }

}