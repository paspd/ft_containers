#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator_traits.hpp"
#include "VectorIterator.hpp"
#include "reverse_iterator.hpp"
// #include "wazack/includes/Iterator.hpp"
#include "utils.hpp"
#include <memory>
#include <iterator>
#include <vector>
#include <stdexcept>
#include <iostream>

namespace ft {
template< class T, class Allocator = std::allocator<T> > class vector {
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
    typedef VectorIterator<const_pointer>			    const_iterator;
    typedef ft::reverse_iterator<iterator>				    reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>		    const_reverse_iterator;

private:

    size_type _size;
    size_type _size_max;
    pointer _array;
    allocator_type _alloc;

public:
    explicit vector( const Allocator & alloc = allocator_type()): _size(0), _size_max(0), _array(NULL), _alloc(alloc) {}
    explicit vector (size_type count, const value_type & value = value_type(), const allocator_type & alloc = allocator_type()): _size(0), _size_max(count), _alloc(alloc) { // Size + value
        _array = _alloc.allocate(_size_max);
        for (size_type i = 0; i < _size_max; i++, _size++)
            _alloc.construct(_array + _size, value);
    }
    template <class InputIterator> vector(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type()): _size(0), _size_max(ft::distance(first, last)), _alloc(alloc) {
        _array = _alloc.allocate(_size_max);
        for (size_type i = 0; i < _size_max; i++, _size++)
            _alloc.construct(_array + _size, *(first++));
    }
    explicit vector (const ft::vector<value_type> & other): _size(0), _size_max(other._size_max), _alloc(other._alloc) { // Copy
        _array = _alloc.allocate(_size_max);
        for (size_type i = 0; i < other._size; i++, _size++)
            _alloc.construct(_array + _size, *(other._array + _size));
        }
    virtual ~vector () { // Destructor
        for (size_type i = 0; i < _size; i++)
            _alloc.destroy(_array + i);
        _alloc.deallocate(_array, _size_max);
    }

    vector & operator=(const vector & other) {
        clear();
        if (other.size() > capacity())
            reserve(other.size());
        for (size_type i = 0; i < other.size(); i++)
            push_back(other[i]);
        return *this;
    }

    template < class InputIt >
    void assign (InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = InputIt()) {
        size_type size = ft::distance(first, last);
        if (size > capacity()) {
            pointer tmp = _alloc.allocate(size);
            for (size_type i = 0; i < size; i++, first++) {
                _alloc.construct(tmp + i, *first);
                _alloc.destroy(_array + i);
            }
            _alloc.deallocate(_array, _size_max);
            _array = tmp;
            _size_max = size;
            _size = size;
        }
        else {
            for (size_type i = 0; i < size; i++, first++) {
                _alloc.destroy(_array + i);
                _alloc.construct(_array + i, *first);
            }
            _size = size;
        }
    }
    void assign( size_type count, const T& value ) {
        if (count > capacity()) {
            pointer tmp = _alloc.allocate(count);
            for (size_type i = 0; i < count; i++) {
                _alloc.construct(tmp + i, value);
                _alloc.destroy(_array + i);
            }
            _alloc.deallocate(_array, _size_max);
            _array = tmp;
            _size_max = count;
            _size = count;
        }
        else {
            for (size_type i = 0; i < count; i++) {
                _alloc.construct(_array + i, value);
                _alloc.destroy(_array + i);
            }
            _size = count;
        }
    }
    

public: // Operator overloading
    reference at( size_type pos ) {
        if (pos >= size())
            throw std::out_of_range("out of range");
        return _array[pos];
    }

    const_reference at( size_type pos ) const {
        if (pos >= size())
            throw std::out_of_range("out of range");
        return _array[pos];
    }

    reference front() {
        return *_array;
    }

    const_reference front() const {
        return *_array;
    }

    reference back() {
        return _array[size() - 1];
    }

    const_reference back() const {
        return _array[size() - 1];
    }

    reference operator[] (size_type n) {
        return _array[n];
    }
    const_reference operator[] (size_type n) const {
        return _array[n];
    }

public: // Iterator
    iterator begin() {
        return _array;
    }
    const_iterator begin() const {
        return _array;
    }

    iterator end() {
        return iterator(_array + size());
    }
    const_iterator end() const {
        return const_iterator(_array + size());
    }

    reverse_iterator		rbegin () {
        return reverse_iterator(_array + size());
    }
    const_reverse_iterator	rbegin () const {
        return const_reverse_iterator(_array + size());
    }

    reverse_iterator		rend () {
        return reverse_iterator(_array);
    }
    const_reverse_iterator	rend () const {
        return const_reverse_iterator(_array);
    }

public: // Capacity member function
    bool empty() const {
        return !size() ? true : false ;
    }

    size_t size() const {
        return _size;
    }

    size_type max_size() const {
        if (_alloc.max_size() > 9223372036854775807)
            return 9223372036854775807;
        return _alloc.max_size();
    }

    void reserve( size_type new_cap ) {
        if (new_cap > max_size())
            throw std::length_error::exception();
        if (!capacity()) {
            _array = _alloc.allocate(new_cap);
            _size_max = new_cap;
            return ;
        }
        if (new_cap > _size_max) {
            pointer tmp = _alloc.allocate(new_cap);
            for (size_type i = 0; i < _size; i++) {
                _alloc.construct(tmp + i, *(_array + i));
                _alloc.destroy(_array + i);
            }
                _alloc.deallocate(_array, _size_max);
            _size_max = new_cap;
            _array = tmp;
        }
    }

    size_type capacity() const {
        return _size_max;
    }

public: // Modifiers
    void clear() {
        for (size_type i = 0; i < _size; i++)
            _alloc.destroy(_array + i);
        _size = 0;                 
    }

    iterator insert( iterator pos, const T& value ) {
        size_type ret_i = 0;
        if (_size + 1 > capacity()) {
            pointer tmp;
            int tmp_i = 0;
            int array_i = 0;
            if (capacity())
                tmp = _alloc.allocate(capacity() * 2);
            else
                tmp = _alloc.allocate(1);
            for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *it);
                _alloc.destroy(_array + array_i);
            }
            _alloc.construct(tmp + tmp_i++, value);
            ret_i = tmp_i - 1;
            for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *pos);
                _alloc.destroy(_array + array_i);
            }
            if (capacity()) {
                _alloc.deallocate(_array, capacity());
                _size_max = capacity() * 2;
            }
            else
                _size_max = 1;
            _size++;
            _array = tmp;
        }
        else {
            pointer tmp = _alloc.allocate(capacity());
            int tmp_i = 0;
            int array_i = 0;
            for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *it);
                _alloc.destroy(_array + array_i);
            }
            _alloc.construct(tmp + tmp_i++, value);
            ret_i = tmp_i - 1;
            for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *pos);
                _alloc.destroy(_array + array_i);
            }
            _alloc.deallocate(_array, capacity());
            _size++;
            _array = tmp;
        }
        return iterator(_array + ret_i);
    }
    void insert( iterator pos, size_type count, const T& value ) {
        if (size() + count > capacity()) {
            size_type tmp_size;
            if (size() + count < capacity() || size() + count > capacity() * 2)
                tmp_size = size() + count;
            else
                tmp_size = capacity() * 2;
            pointer tmp = _alloc.allocate(tmp_size);
            size_type tmp_i = 0;
            size_type array_i = 0;
            for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *it);
                _alloc.destroy(_array + array_i);
            } 
            for (size_type i = 0; i < count; i++) _alloc.construct(tmp + tmp_i++, value);
            for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *pos);
                _alloc.destroy(_array + array_i);
            }
            _alloc.deallocate(_array, capacity());
            _size_max = tmp_size;
            _size += count;
            _array = tmp;
        }
        else {
            pointer tmp = _alloc.allocate(capacity());
            size_type tmp_i = 0;
            size_type array_i = 0;
            for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *it);
                _alloc.destroy(_array + array_i);
            }
            for (size_type i = 0; i < count; i++) _alloc.construct(tmp + tmp_i++, value);
            for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *pos);
                _alloc.destroy(_array + array_i);
            }
            if (capacity())
                _alloc.deallocate(_array, capacity());
            _size += count;
            _array = tmp;
        }
    }
    template < typename InputIt >
    void insert( iterator pos, InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value, InputIt>::type = InputIt()) {
        if (size() + ft::distance(first, last) > capacity()) {
            pointer tmp;
            size_type tmp_size = 0;
            if (size() + ft::distance(first, last) < capacity() || size() + ft::distance(first, last) > capacity() * 2)
                tmp_size = size() + ft::distance(first, last);
            else
                tmp_size = capacity() * 2;
            tmp = _alloc.allocate(tmp_size);
            size_type tmp_i = 0;
            size_type array_i = 0;
            iterator it = begin();
            while (it != pos) {
                _alloc.construct(tmp + tmp_i, *it);
                _alloc.destroy(_array + array_i);
                it++;
                array_i++;
                tmp_i++;
            }
            for (InputIt ofirst = first; ofirst != last; ofirst++, tmp_i++)
                _alloc.construct(tmp + tmp_i, *ofirst);
            for (iterator its = end(); it != its; it++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *it);
                _alloc.destroy(_array + array_i);
            }
            _alloc.deallocate(_array, capacity());
            _size_max = tmp_size;
            _size += ft::distance(first, last);
            _array = tmp;
        }
        else {
            pointer tmp = _alloc.allocate(capacity());
            int tmp_i = 0;
            int array_i = 0;
            for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *it);
                _alloc.destroy(_array + array_i);
            }
            while (first != last) {
                _alloc.construct(tmp + tmp_i++, *first);
                first++;
            }
            for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
                _alloc.construct(tmp + tmp_i, *pos);
                _alloc.destroy(_array + array_i);
            }
            _alloc.deallocate(_array, capacity());
            _size++;
            _array = tmp;
        }
    }

    iterator erase( iterator pos ) {
        size_type index = ft::distance(begin(), pos);
        for (size_type i = index; i != _size; ++i) {
            _alloc.destroy(_array + i);
            if (i + 1 != _size)
                _alloc.construct(_array + i, *(_array + i + 1));
        }
        _size--;
        return begin() + index;
    }
    iterator erase( iterator first, iterator last ) {
        size_type posFirst = ft::distance(begin(), first);
        size_type posLast = ft::distance(begin(), last);
        size_type n = posLast - posFirst;
        for (size_type i = posFirst; i < posLast; ++i)
            _alloc.destroy(_array + i);
        for (size_type i = posLast; i < _size; ++i)
            _alloc.construct(_array + (i - n), *(_array + i));
        _size -= n;
        return first;
    }
    void push_back( const T& value ) {
        if (_size + 1 > capacity()) {
            if (!capacity())
                    reserve(1);
                else
                    reserve(capacity() * 2);
        }
        _alloc.construct(_array + _size, value);
        _size++;
    }

    void pop_back() {
        if (!size())
            return ;
        _alloc.destroy(_array + _size);
        _size--;
    }

    void resize( size_type n, T value = T() ) {
            if (n < _size)
        {
            for (size_type i = n; i < _size; ++i)
                _alloc.destroy(_array + i);
        }
        else if (n > size())
        {
            if (n > capacity())
            {
                if (capacity() * 2 < n)
                    reserve(n);
                else
                    reserve(capacity() * 2);
            }
            for (size_type i = _size; i < n; ++i)
                _alloc.construct(_array + i, value);
        }
        _size = n;  
    }

    void swap( vector& other ) {
        {value_type *tmp = other._array;
        other._array = _array;
        _array = tmp;}

        {size_type tmp = other._size;
        other._size = _size;
        _size = tmp;}

        {size_type tmp = other._size_max;
        other._size_max = _size_max;
        _size_max = tmp;}

        {allocator_type tmp = other._alloc;
        other._alloc = _alloc;
        _alloc = tmp;}
    }
};

template <class T, class Alloc>
bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool	operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool	operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return !(lhs < rhs);
}

template <class T, class Alloc>
void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y) { x.swap(y); }

}

#endif