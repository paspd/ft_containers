#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator_traits.hpp"
#include <memory>
#include <iterator>
#include <vector>

namespace ft {
    template <typename Iterator> class VectorIterator
{
	public:
		typedef Iterator                                                           iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type         value_type;
        typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
        typedef typename iterator_traits<iterator_type>::pointer            pointer;
        typedef typename iterator_traits<iterator_type>::reference          reference;

	protected:
		pointer	array;

	public:
			VectorIterator(void) : array(NULL) { }
			VectorIterator(pointer &array) : array(array) { }
			VectorIterator(pointer const &array) : array(array) { }
			VectorIterator(VectorIterator const &other) : array(other.array) { }
			virtual ~VectorIterator() { }

	public:
		reference operator=(VectorIterator const & rhs) { array = rhs.array; return (*this); }
		
		bool operator==(VectorIterator const & rhs) { return (*this == rhs); }
		bool operator!=(VectorIterator const & rhs) { return (*this != rhs); }
		bool operator<(VectorIterator const & rhs) { return (*this < rhs); }
		bool operator<=(VectorIterator const & rhs) { return (*this <= rhs); }
		bool operator>(VectorIterator const & rhs) { return (*this > rhs); }
		bool operator>=(VectorIterator const & rhs) { return (*this >= rhs); }

		iterator_type operator++(int) { return (array++); }


        
		pointer operator*() { return (*array); }
};

    template< class T, class Allocator = std::allocator<T> > class vector {
        private:
            size_t _size;
            size_t _size_max;
            T* _array;
            Allocator _alloc;
        public:
            typedef T											value_type;
            typedef Allocator									allocator_type;
            typedef typename allocator_type::reference			reference;
            typedef typename allocator_type::const_reference	const_reference;
            typedef typename allocator_type::size_type			size_type;
            typedef typename allocator_type::difference_type	difference_type;
            typedef typename allocator_type::pointer			pointer;
            typedef typename allocator_type::const_pointer		const_pointer;
            typedef VectorIterator<pointer>					    iterator;
            typedef VectorIterator<pointer>					    const_iterator;
            typedef std::reverse_iterator<iterator>				reverse_iterator;
            typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
    };
}

#endif