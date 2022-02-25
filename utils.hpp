#ifndef UTILS_HPP
#define UTILS_HPP

#include "iterator_traits.hpp"

namespace ft {

template < bool B, class T = void >
struct enable_if {};

template < class T >
struct enable_if<true, T> { typedef T type; };

template < class Iter >
typename ft::iterator_traits<Iter>::difference_type	distance(Iter first, Iter last) {
	typename ft::iterator_traits<Iter>::difference_type ret = 0;
	while (first != last) {
		ret++;
		first++;
	}
	return ret;
}

template <bool B>
struct bool_wrapper {
	static const bool value = B;
};

template < class T >
struct is_integral : bool_wrapper<false> {};

template <>
struct is_integral<bool> : bool_wrapper<true> {};
template <>
struct is_integral<char> : bool_wrapper<true> {};
template <>
struct is_integral<char16_t> : bool_wrapper<true> {};
template <>
struct is_integral<char32_t> : bool_wrapper<true> {};
template <>
struct is_integral<wchar_t> : bool_wrapper<true> {};
template <>
struct is_integral<short> : bool_wrapper<true> {};
template <>
struct is_integral<int> : bool_wrapper<true> {};
template <>
struct is_integral<long> : bool_wrapper<true> {};
template <>
struct is_integral<long long> : bool_wrapper<true> {};

template < class InputIterator1, class InputIterator2 >
bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) { // equality
	while (first1 != last1) {
		if (*first1 != *first2)
			return false;
		first1++;
		first2++;
	}
	return true;
}
template < class InputIterator1, class InputIterator2, class BinaryPredicate >
bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) { // predicate
	while (first1 != last1) {
		if (!pred(*first1, *first2))
			return false;
		first1++;
		first2++;
	}
	return true;
}

template < class InputIterator1, class InputIterator2 >
bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) { // default
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		first1++;
		first2++;
	}
	return (first2 != last2);
}
template < class InputIterator1, class InputIterator2, class Compare >
bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) { // custom
	while (first1 != last1) {
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		else if (comp(*first1, *first2))
			return true;
		first1++;
		first2++;
	}
	return (first2 != last2);
}

}

#endif