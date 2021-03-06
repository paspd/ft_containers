#include <vector>
#include <iostream>
#include "vector.hpp"
#include "iterator_traits.hpp"

int main(int ac, char **av){
    (void)av;
    int nb_test(1);

    std::cout << "Test " << nb_test++ << ": Constructor by copy" << std::endl << std::endl; {
        TESTED_NAMESPACE::vector<char> tmp1(10, 'O');
        
        std::cout << "TESTED_NAMESPACE::vector<char> tmp1(10, 'O');" << std::endl << std::endl;
        for (size_t i = 0; i < tmp1.size(); i++)
            std::cout << tmp1[i];
        std::cout << std::endl << std::endl;

        TESTED_NAMESPACE::vector<char> tmp2(tmp1);
        
        std::cout << "TESTED_NAMESPACE::vector<char> tmp2(tmp1);" << std::endl << std::endl;
        for (size_t i = 0; i < 10; i++)
            std::cout << tmp2[i];
        std::cout << std::endl << std::endl;
    } std::cout << "====================================================================" << std::endl << std::endl;
    
    std::cout << "Test " << nb_test++ << ": TESTED_NAMESPACE::vector<char> tmp(10, 'a');" << std::endl << std::endl; {
   
    TESTED_NAMESPACE::vector<char> tmp(10, 'a');
    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i];
    std::cout << std::endl << std::endl;
   
    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": TESTED_NAMESPACE::vector<int> tmp(1000000, 42);" << std::endl << std::endl; {

    if (ac > 1) {
    TESTED_NAMESPACE::vector<int> tmp(1000000, 42);
    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;
    }

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": TESTED_NAMESPACE::vector<char> tmp(10, 'a');" << std::endl << std::endl; {
   
    TESTED_NAMESPACE::vector<char> tmp(10, 'a');
    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i];
    std::cout << std::endl << std::endl;
    
    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Operator \"=\" overload" << std::endl << std::endl; {
    
    TESTED_NAMESPACE::vector<char> tmp1(20, 'R');

    TESTED_NAMESPACE::vector<char> tmp2(2000, '2');

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
    // TESTED_NAMESPACE::vector<char> iter_vector(real_vector_char.begin(), real_vector_char.end());
    // for (size_t i = 0; i < 10; i++)
        // std::cout << iter_vector[i];
    // std::cout << std::endl << std::endl;
 
    // std::cout << "====================================================================" << std::endl << std::endl;

    // std::cout << "Test " << nb_test++ << ": Assign function" << std::endl << std::endl; {
//    
    // TESTED_NAMESPACE::vector<char> tmp(20, 'a');
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

    TESTED_NAMESPACE::vector<int> size_42(42, 21);

    std::cout << "TESTED_NAMESPACE::vector<int> size_42(42, 42); | size_42.size() : " << size_42.size() << std::endl << std::endl;

    if (ac > 1) {
        TESTED_NAMESPACE::vector<char*> size_int_max(INT_MAX, (char *)"Hello!");

        std::cout << "TESTED_NAMESPACE::vector<char*> size_int_max(INT_MAX, (char *)\"Hello!\"); | size_int_max.size() : " << size_int_max.size() << std::endl << std::endl;
    }

    } std::cout << "====================================================================" << std::endl << std::endl;
    
    std::cout << "Test " << nb_test++ << ": Reserve member function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<char> tmp(10, 'P');
    
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

    TESTED_NAMESPACE::vector<int> tmp(20, 1807);
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    {TESTED_NAMESPACE::vector<int>::iterator its = tmp.end();

    for (TESTED_NAMESPACE::vector<int>::iterator it = tmp.begin(); it != its; it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;}

    tmp.clear();

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    {TESTED_NAMESPACE::vector<int>::iterator its = tmp.end();

    for (TESTED_NAMESPACE::vector<int>::iterator it = tmp.begin(); it != its; it++) 
        std::cout << *it;
    std::cout << std::endl << std::endl;}

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Insert membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<int> tmp(2, 1);
    
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

    tmp.insert(tmp.end(), 4);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    
    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    tmp.insert(tmp.begin() + (tmp.size() / 2), 5);

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;
    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Insert membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<char> tmp(5, 'O');

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.reserve(30);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    tmp.insert(tmp.begin() + 2, 51, 'I');

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.insert(tmp.end(), 13, 'G');
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;
    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Insert membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<char> tmp;

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;

    tmp.insert(tmp.begin(), 'A');
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl << std::endl;
    } std::cout << "====================================================================" << std::endl << std::endl;
    
    std::cout << "Test " << nb_test++ << ": Insert membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<char> tmp(1, 'A');

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.reserve(100);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    tmp.insert(tmp.begin(), 50, 'B');
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    } std::cout << "====================================================================" << std::endl << std::endl;
    
    std::cout << "Test " << nb_test++ << ": Insert membre function" << std::endl << std::endl; {

    std::vector<int> tmp(3, 1);
	std::vector<int> tmp1(10, 2);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

	tmp.reserve(10);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
	
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

	tmp.insert(tmp.begin(), tmp1.begin(), tmp1.end() - 1);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;

    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Erase membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<int> tmp(1, 1);

    tmp.insert(tmp.end(), 2);
    tmp.insert(tmp.end(), 3);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.erase(tmp.begin() + 1);
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.erase(tmp.begin() + 1);
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.erase(tmp.begin());
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    } std::cout << "====================================================================" << std::endl << std::endl;

    // std::cout << "Test " << nb_test++ << ": Erase membre function" << std::endl << std::endl; {

    // TESTED_NAMESPACE::vector<int> tmp(1, 0);

    // std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    // std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    // for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    // for (size_t i = 1; i < 100; i++)
    //     tmp.insert(tmp.end(), i);    
    
    // std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    // std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    // for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    // tmp.erase(tmp.begin() + 50, tmp.end());
    // std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    // std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    // for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    // tmp.erase(tmp.begin(), tmp.end());
    // std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    // std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    // for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    // } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Push_back membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<int> tmp;

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    tmp.push_back(1);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    tmp.push_back(2);
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.push_back(3);
    tmp.push_back(4);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    tmp.push_back(5);
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Push_back membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<int> tmp(1, 0);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    for (size_t i = 1; i < 100; i++)
        tmp.push_back(i);
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Pop_back membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<int> tmp(1, 0);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    for (size_t i = 1; i < 100; i++)
        tmp.push_back(i);
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    for (size_t i = 0; i < 50; i++)
        tmp.pop_back();

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Resize membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<int> tmp(1, 0);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;
    
    for (size_t i = 1; i < 100; i++)
        tmp.push_back(i);
    
    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.resize(50);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.resize(75, 9);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Swap membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<int> tmp1;
    TESTED_NAMESPACE::vector<int> tmp2(20, 8);

    for (size_t i = 0; i < 100; i++)
        tmp1.push_back(i);

    std::cout << "tmp1.size() :" << tmp1.size() << std::endl << std::endl;
    std::cout << "tmp1.max_size() :" << tmp1.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp1.size(); i++) std::cout << tmp1[i] << " "; std::cout << std::endl << std::endl;

    std::cout << "tmp2.size() :" << tmp2.size() << std::endl << std::endl;
    std::cout << "tmp2.max_size() :" << tmp2.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp2.size(); i++) std::cout << tmp2[i] << " "; std::cout << std::endl << std::endl;

    tmp1.swap(tmp2);
    
    
    std::cout << "tmp1.size() :" << tmp1.size() << std::endl << std::endl;
    std::cout << "tmp1.max_size() :" << tmp1.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp1.size(); i++) std::cout << tmp1[i] << " "; std::cout << std::endl << std::endl;

    std::cout << "tmp2.size() :" << tmp2.size() << std::endl << std::endl;
    std::cout << "tmp2.max_size() :" << tmp2.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp2.size(); i++) std::cout << tmp2[i] << " "; std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;

    std::cout << "Test " << nb_test++ << ": Assign membre function" << std::endl << std::endl; {

    TESTED_NAMESPACE::vector<int> tmp;

    for (size_t i = 0; i < 10; i++)
        tmp.push_back(i);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    tmp.assign(20, 42);

    std::cout << "tmp.size() :" << tmp.size() << std::endl << std::endl;
    std::cout << "tmp.max_size() :" << tmp.capacity() << std::endl << std::endl;
    
    for (size_t i = 0; i < tmp.size(); i++) std::cout << tmp[i] << " "; std::cout << std::endl << std::endl;

    } std::cout << "====================================================================" << std::endl << std::endl;
}