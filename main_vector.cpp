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
        ft::vector<int> too_short(-1000, 3);
    }
    catch(const std::exception& e) {
        // std::cerr << e.what() << '\n';
    }
    

    std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Constructor by copy" << std::endl << std::endl; {
        ft::vector<char> tmp1(10, 'O');
        
        std::cout << "ft::vector<char> tmp1(10, 'O');" << std::endl << std::endl;
        for (size_t i = 0; i < tmp1.size(); i++)
            std::cout << tmp1[i];
        std::cout << std::endl << std::endl;

        ft::vector<char> tmp2(tmp1);
        
        std::cout << "ft::vector<char> tmp2(tmp1);" << std::endl << std::endl;
        for (size_t i = 0; i < 10; i++)
            std::cout << tmp2[i];
        std::cout << std::endl << std::endl;
    } std::cout << "====================================================================" << std::endl << std::endl;
    
    std::cout << "Test " << nb_test++ << ": ft::vector<char> tmp(10, 'a');" << std::endl << std::endl; {
   
    ft::vector<char> tmp(10, 'a');
    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i];
    std::cout << std::endl << std::endl;
   
    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": ft::vector<int> tmp(1000000, 42);" << std::endl << std::endl; {

    if (ac > 1) {
    ft::vector<int> tmp(1000000, 42);
    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;
    }

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": ft::vector<char> tmp(10, 'a');" << std::endl << std::endl; {
   
    ft::vector<char> tmp(10, 'a');
    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i];
    std::cout << std::endl << std::endl;
    
    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Operator \"=\" overload" << std::endl << std::endl; {
    
    ft::vector<char> tmp1(20, 'R');

    ft::vector<char> tmp2(2000, '2');

    for (size_t i = 0; i < tmp1.size(); i++)
        std::cout << tmp1[i];
    std::cout << std::endl << std::endl;

    tmp2 = tmp1;

    for (size_t i = 0; i < tmp2.size(); i++)
        std::cout << tmp2[i];
    std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;
    // std::cout << "Test " << nb_test++ << ": Construtor with iterrators of real vector" << std::endl << std::endl;

    // std::vector<char> real_vector_char(10, 'K');
    // ft::vector<char> iter_vector(real_vector_char.begin(), real_vector_char.end());
    // for (size_t i = 0; i < 10; i++)
        // std::cout << iter_vector[i];
    // std::cout << std::endl << std::endl;
 
    // std::cout << "====================================================================" << std::endl << std::endl;

    // std::cout << "Test " << nb_test++ << ": Assign function" << std::endl << std::endl; {
//    
    // ft::vector<char> tmp(20, 'a');
    // for (size_t i = 0; i < tmp.size(); i++)
        // std::cout << tmp[i];
    // std::cout << std::endl << std::endl;
    // 
    // tmp.assign(8, 'b');
    // for (size_t i = 0; i < tmp.size(); i++)
        // std::cout << tmp[i];
    // std::cout << std::endl << std::endl;
// 
    // tmp.assign(4, 'c');
    // for (size_t i = 0; i < tmp.size(); i++)
        // std::cout << tmp[i];
    // std::cout << std::endl << std::endl;
    // 
    // tmp.assign(100, 'd');
    // for (size_t i = 0; i < tmp.size(); i++)
        // std::cout << tmp[i];
    // std::cout << std::endl << std::endl;
    // 
    // } std::cout << "====================================================================" << std::endl << std::endl;

 
    std::cout << "Test " << nb_test++ << ": Size member function" << std::endl << std::endl; {

    ft::vector<int> size_42(42, 21);

    std::cout << "ft::vector<int> size_42(42, 42); | size_42.size() : " << size_42.size() << std::endl << std::endl;

    if (ac > 1) {
        ft::vector<char*> size_int_max(INT_MAX, (char *)"Hello!");

        std::cout << "ft::vector<char*> size_int_max(INT_MAX, (char *)\"Hello!\"); | size_int_max.size() : " << size_int_max.size() << std::endl << std::endl;
    }

    } std::cout << "====================================================================" << std::endl << std::endl;
    
    std::cout << "Test " << nb_test++ << ": Reserve member function" << std::endl << std::endl; {

    ft::vector<char> tmp(10, 'P');
    
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i];
    std::cout << std::endl << std::endl;

    tmp.reserve(20);

    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i];
    std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;
    
    std::cout << "Test " << nb_test++ << ": Clear membre function" << std::endl << std::endl; {

    ft::vector<int> tmp(20, 1807);
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    {ft::vector<int>::iterator its = tmp.end();

    for (ft::vector<int>::iterator it = tmp.begin(); it != its; it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;}

    tmp.clear();

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    {ft::vector<int>::iterator its = tmp.end();

    for (ft::vector<int>::iterator it = tmp.begin(); it != its; it++) 
        std::cout << *it;
    std::cout << std::endl << std::endl;}

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Insert membre function" << std::endl << std::endl; {

    ft::vector<int> tmp(2, 1);
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;
    
    tmp.insert(tmp.begin(), 2);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;

    tmp.insert(tmp.begin() + 2, 3);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;
}