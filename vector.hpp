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

	public:// Constructor - Destructor

			VectorIterator(void) : array(NULL) { }
			VectorIterator(pointer &array) : array(array) { }
			VectorIterator(pointer const &array) : array(array) { }
			VectorIterator(VectorIterator const &other) : array(other.array) { }
			virtual ~VectorIterator() { }

	public:// Operator overload

		reference operator=(VectorIterator const & rhs) { array = rhs.array; return (*this); }

        reference operator*() const {
            return *array;
        }
        pointer operator->() const {
            return (pointer)std::addressof(*array);
        }

        VectorIterator & operator++() {
            ++array;
            return *this;
        }
        VectorIterator & operator++(int) {
            VectorIterator tmp(*this);
            array++;
            return tmp;
        }

        VectorIterator & operator--() {
            --array;
            return *this; 
        }
        VectorIterator & operator--(int) {
            VectorIterator tmp(*this);
            array--; return tmp;
        }

        VectorIterator & operator+(difference_type _n) const {
            VectorIterator result(*this);
            result.array += _n;
            return result;
        }
        VectorIterator & operator-(difference_type _n) const {
            VectorIterator result(*this);
            result.array -= _n;
            return result;
        }

        VectorIterator & operator+=(difference_type _n) {
            array += _n;
            return *this;
        }
        VectorIterator & operator-=(difference_type _n) {
            array -= _n;
            return *this;
        }

        reference operator[](difference_type _i) const {
            return array[_i];
        }

		bool operator==(VectorIterator const & rhs) {
            return (*this == rhs);
        }
		bool operator!=(VectorIterator const & rhs) {
            return (*this != rhs);
        }

		bool operator<(VectorIterator const & rhs) {
            return (*this < rhs);
        }
		bool operator<=(VectorIterator const & rhs) {
            return (*this <= rhs);
        }
		bool operator>(VectorIterator const & rhs) {
            return (*this > rhs);
        }
		bool operator>=(VectorIterator const & rhs) {
            return (*this >= rhs);
        }

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
        
        public: // Constructor - Destructor

            explicit vector (): _size(0), _size_max(0), _array(NULL), _alloc(NULL) {} // Default
            explicit vector( const Allocator & alloc ): _size(0), _size_max(0), _array(NULL), _alloc(alloc) {}
            explicit vector (size_type count, const value_type & value = value_type(), const allocator_type & alloc = allocator_type()): _size(0), _size_max(count), _alloc(alloc) { // Size + value
                _array = _alloc.allocate(_size_max);
                for (size_t i = _size; i < _size_max; i++, _size++)
                    _alloc.construct(_array + _size, value);
            } 
            // template <class InputIt> explicit vector (InputIt first, InputIt last, const allocator_type& alloc = allocator_type()): _size(0), _size_max(0), _alloc(alloc) { for (InputIterator tmp(first); tmp != last; tmp++) _size_max++; _array = _alloc.allocate(_size_max); while (first != last) { _alloc.construct(_array + _size, *first); first++; _size++; } }
            explicit vector (const ft::vector<value_type> & other): _size(0), _size_max(other._size_max), _alloc(other._alloc) { // Copy
                _array = _alloc.allocate(_size_max);
                for (size_t i = 0; i < _size_max; i++, _size++)
                    _alloc.construct(_array + _size, *(other._array + _size));
                }
            
            virtual ~vector () { // Destructor
                for (size_t i = 0; i < _size_max; i++)
                    _alloc.destroy(_array + i);
                _alloc.deallocate(_array, _size_max);
            }

            vector & operator=(const vector & other) {
                for (size_t i = 0; i < _size_max; i++)
                    _alloc.destroy(_array + i);
                _alloc.deallocate(_array, _size_max);
                _size_max = other._size_max;
                _size = 0; _alloc = other._alloc;
                _array = _alloc.allocate(_size_max);
                for (size_t i = 0; i < _size_max; i++, _size++)
                    _alloc.construct(_array + i, *(other._array + i));
                return *this;
            }

        public: // Operator overloading

            reference operator[] (size_type n) {
                return _array[n];
            }
            const_reference operator[] (size_type n) const {
                return _array[n];
            }

        public: // Capacity member function
            bool empty() const {
                return !size() ? true : false ;
            }
            size_t size() const {
                return _size;
            }
            size_type max_size() const{
                return _size_max;
            }
    };
}

#endif