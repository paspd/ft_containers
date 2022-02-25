#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
template <typename Iterator> class VectorIterator {
public:

	typedef Iterator                                                    iterator_type;
	typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;
	typedef typename iterator_traits<iterator_type>::value_type         value_type;
	typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
	typedef typename iterator_traits<iterator_type>::pointer            pointer;
	typedef typename iterator_traits<iterator_type>::reference          reference;

protected:
	iterator_type	array;

public:
	VectorIterator(): array(NULL) {}
	VectorIterator(iterator_type new_array): array(new_array) {}
	template <class U>
	VectorIterator(VectorIterator<U> const & src): array(src.base()) {}
	~VectorIterator() {}

	VectorIterator & operator=(const VectorIterator & src) {
		array = src.base();
		return *this;
	}

	iterator_type base() const {
		return array;
	}

	reference operator*(){
		return *array;
	}

	reference operator[](const int & index) {
		return *(array + index);
	}

	iterator_type operator->() const {
		return array;
	}

	VectorIterator & operator++() {
		array++;
		return *this;
	}
	VectorIterator operator++(int) {
		VectorIterator tmp(*this);
		operator++();
		return tmp;
	}

	VectorIterator operator+(const int & rhs) const {
		VectorIterator ret(*this);
		ret += rhs;
		return ret;
	}

	template < class T >
	friend VectorIterator<T> operator+(const int & lhs, const VectorIterator<T> & rhs);
    
	VectorIterator & operator--() {
		array--;
		return *this;
	}
	VectorIterator operator--(int) {
		VectorIterator tmp(*this);
		operator--();
		return tmp;
	}

	VectorIterator operator-(const int & subbed) const {
		VectorIterator ret(*this);
		ret.array -= subbed;
		return ret;
	}

	VectorIterator & operator+=(const int & added) {
		array += added;
		return *this;
	}

	VectorIterator & operator-=(const int & subbed) {
		array -= subbed;
		return *this;
	}            

};

	template <class Iter1, class Iter2>
	bool operator==(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y) {
		return x.base() == y.base();
	}

	template <class Iter1, class Iter2>
	bool operator<(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y) {
		return x.base() < y.base();
	}

	template <class Iter1, class Iter2>
	bool operator!=(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y) {
		return !(x == y);
	}

	template <class Iter1, class Iter2>
	bool operator>(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y) {
		return y < x;
	}

	template <class Iter1, class Iter2>
	bool operator>=(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y) {
		return !(x < y);
	}

	template <class Iter1, class Iter2>
	bool operator<=(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y) {
		return !(y < x);
	}

	template <class Iter1>
	bool operator!=(const VectorIterator<Iter1>& x, const VectorIterator<Iter1>& y) {
		return !(x == y);
	}

	template <class Iter1>
	bool operator>(const VectorIterator<Iter1>& x, const VectorIterator<Iter1>& y) {
		return y < x;
	}

	template <class Iter1>
	bool operator>=(const VectorIterator<Iter1>& x, const VectorIterator<Iter1>& y) {
		return !(x < y);
	}

	template <class Iter1>
	bool operator<=(const VectorIterator<Iter1>& x, const VectorIterator<Iter1>& y) {
		return !(y < x);
	}

	template <class Iter1, class Iter2>
	typename VectorIterator<Iter1>::difference_type operator-(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y) {
		return x.base() - y.base();
	}

	template < class T >
	VectorIterator<T> operator+(const int & lhs, const VectorIterator<T> & rhs) {
		VectorIterator<T> ret(rhs);
		ret += lhs;
		return ret;
	}


}

#endif