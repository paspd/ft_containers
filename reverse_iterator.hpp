#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
template <typename Iterator> class reverse_iterator {
public:
	typedef Iterator                                                    iterator_type;
	typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;
	typedef typename iterator_traits<iterator_type>::value_type         value_type;
	typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
	typedef typename iterator_traits<iterator_type>::pointer            pointer;
	typedef typename iterator_traits<iterator_type>::reference          reference;

protected:
	iterator_type	array;
	iterator_type	current;

public:
	reverse_iterator(): array(), current() {}
	reverse_iterator(iterator_type new_array): array(new_array), current(new_array) {}
	template <class U>
	reverse_iterator(reverse_iterator<U> const & src): array(src.base()), current(src.base()) {}
	~reverse_iterator() {}

	reverse_iterator & operator=(const reverse_iterator & src) {
		array = current = src.base();
		return *this;
	}

	iterator_type base() const {
		return current;
	}

	reference			operator*(void) const {
		Iterator tmp = current;
		return *--tmp;
	};
	pointer				operator->(void) const {
		return &operator*();
	}

	reverse_iterator & operator++() {
		--current;
		return *this;
	}
	reverse_iterator operator++(int) {
		reverse_iterator tmp(*this);
		--current;
		return tmp;
	}

	reverse_iterator & operator--() {
		current++;
		return *this;
	}
	reverse_iterator operator--(int) {
		reverse_iterator tmp(*this);
		++current;
		return tmp;
	}

	reverse_iterator operator+(const int & n) const {
		return reverse_iterator(current - n);
	}
	reverse_iterator & operator+=(const int & n) {
		current -= n;
		return *this;
	}

	reverse_iterator operator-(const int & n) const {
		return reverse_iterator(current + n);
	}
	reverse_iterator & operator-=(const int & n) {
		current += n;
		return *this;
	}

	reference operator[](const int & index) {
		return *(*this + index);
	}

	template < class T >
	friend reverse_iterator<T> operator+(const int & lhs, const reverse_iterator<T> & rhs);

};

	template <class _Iter1, class _Iter2>
	bool operator==(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y) {
		return __x.base() == __y.base();
	}

	template <class _Iter1, class _Iter2>
	bool operator<(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y) {
		return __x.base() > __y.base();
	}

	template <class _Iter1, class _Iter2>
	bool operator!=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y) {
		return __x.base() != __y.base();
	}

	template <class _Iter1, class _Iter2>
	bool operator>(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y) {
		return __x.base() < __y.base();
	}

	template <class _Iter1, class _Iter2>
	bool operator>=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y) {
		return __x.base() <= __y.base();
	}

	template <class _Iter1, class _Iter2>
	bool operator<=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y) {
		return __x.base() >= __y.base();
	}

	template <class _Iter1, class _Iter2>
	typename reverse_iterator<_Iter1>::difference_type operator-(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y) {
		return __y.base() - __x.base();
	}

	template <class _Iter>
	reverse_iterator<_Iter> operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter>& __x) {
    	return reverse_iterator<_Iter>(__x.base() - __n);
	}

	template < class T >
	reverse_iterator<T> operator+(const int & lhs, const reverse_iterator<T> & rhs) {
		reverse_iterator<T> ret(rhs);
		ret += lhs;
		return ret;
	}

	template < class T >
	reverse_iterator<T> operator-(const int & lhs, const reverse_iterator<T> & rhs) {
		return operator+(-lhs, rhs);
	}



}

#endif
