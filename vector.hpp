#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator_traits.hpp"
#include <memory>
#include <iterator>
#include <vector>
#include <stdexcept>
#include <iostream>

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

			VectorIterator(void) {};
			 VectorIterator(const VectorIterator &other) { *this = other; };
			 VectorIterator(pointer ptr): array(ptr) {};
			 ~VectorIterator(void) {};
    public:
			VectorIterator &operator=(const VectorIterator &other) {
				array = other.array;
				return (*this);
			};

			VectorIterator &operator++(void) {
				array++;
				return (*this);
			};
			VectorIterator &operator--(void) {
				array--;
				return (*this);
			};
			
            VectorIterator operator++(int) {
				VectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			VectorIterator operator--(int) {
				VectorIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator==(const VectorIterator &other) const {
				return (array == other.array);
			};
			bool operator!=(const VectorIterator &other) const {
				return (array != other.array);
			};
			bool operator>(const VectorIterator &other) const {
				return (array > other.array);
			};
            bool operator>=(const VectorIterator &other) const {
				return (array >= other.array);
			};
			bool operator<(const VectorIterator &other) const {
				return (array < other.array);
			};
			bool operator<=(const VectorIterator &other) const {
				return (array <= other.array);
			};

			value_type &operator*(void) {
				return (*array);
			};
			value_type *operator->(void) {
				return (array);
			};

			VectorIterator operator+(int n) const {
				VectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			VectorIterator operator-(int n) const {
				VectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
            difference_type operator-(VectorIterator it) const {
				int i = 0;
                while (array + i != it.array)
                    i++;
                return (i);
			};

			VectorIterator &operator+=(int n) {
				while (n < 0)
				{
					(*this)--;
					n++;
				}
				while (n > 0)
				{
					(*this)++;
					n--;
				}
				return (*this);
			};
			VectorIterator &operator-=(int n) {
				return (*this += -n);
			};
            
			value_type &operator[](int n) const {
				return (*(*this + n));
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

            explicit vector( const Allocator & alloc = allocator_type()): _size(0), _size_max(0), _array(NULL), _alloc(alloc) {}
            explicit vector (size_type count, const value_type & value = value_type(), const allocator_type & alloc = allocator_type()): _size(0), _size_max(count), _alloc(alloc) { // Size + value
                _array = _alloc.allocate(_size_max);
                for (size_t i = 0; i < _size_max; i++, _size++)
                    _alloc.construct(_array + _size, value);
            } 
            // template <class InputIt> explicit vector (InputIt first, InputIt last, const allocator_type& alloc = allocator_type()): _size(0), _size_max(0), _alloc(alloc) {
            //     if (first == last)
            //         return ;
            //     insert(begin(), first, last);
            // }
            explicit vector (const ft::vector<value_type> & other): _size(0), _size_max(other._size_max), _alloc(other._alloc) { // Copy
                _array = _alloc.allocate(_size_max);
                for (size_t i = 0; i < other._size; i++, _size++)
                    _alloc.construct(_array + _size, *(other._array + _size));
                }
            
            virtual ~vector () { // Destructor
                for (size_t i = 0; i < _size; i++)
                    _alloc.destroy(_array + i);
                _alloc.deallocate(_array, _size_max);
            }

            vector & operator=(const vector & other) {
                for (size_t i = 0; i < _size; i++)
                    _alloc.destroy(_array + i);
                _alloc.deallocate(_array, _size_max);
                _size_max = other._size_max;
                _size = 0;
                _alloc = other._alloc;
                _array = _alloc.allocate(_size_max);
                for (size_t i = 0; i < other._size; i++, _size++)
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

        public: // Iterator
        
            iterator begin() {
                return _array;
            }
            const_iterator begin() const {
                return _array;
            }

            iterator end() {
                return _array + _size;
            }
            const_iterator end() const {
                return _array + _size;
            }


        public: // Capacity member function

            bool empty() const {
                return !size() ? true : false ;
            }

            size_t size() const {
                return _size;
            }

            size_type max_size() const {
                if (this->_alloc.max_size() > 9223372036854775807)
                    return 9223372036854775807;
                return this->_alloc.max_size();
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
                    value_type* tmp = _alloc.allocate(new_cap);
                    for (size_t i = 0; i < _size; i++) {
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
                for (size_t i = 0; i < _size; i++)
                    _alloc.destroy(_array + i);
                _size = 0;                 
            }

            iterator insert( iterator pos, const T& value ) {
                size_type pos_len = &(*pos) - begin();
                if (_size + 1 > capacity()) {
                    value_type* tmp;
                    if (!capacity())
                        tmp = _alloc.allocate(1);
                    else
                        tmp = _alloc.allocate(capacity() * 2);
                    int tmp_i = 0;
                    int array_i = 0;
                    for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                        _alloc.construct(tmp + tmp_i, *it);
                        _alloc.destroy(_array + array_i);
                    }
                    _alloc.construct(tmp + tmp_i++, value);
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
                    value_type* tmp = _alloc.allocate(capacity());
                    int tmp_i = 0;
                    int array_i = 0;
                    for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                        _alloc.construct(tmp + tmp_i, *it);
                        _alloc.destroy(_array + array_i);
                    }
                    _alloc.construct(tmp + tmp_i++, value);
                    for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
                        _alloc.construct(tmp + tmp_i, *pos);
                        _alloc.destroy(_array + array_i);
                    }
                    _alloc.deallocate(_array, capacity());
                    _size++;
                    _array = tmp;
                }
                return begin() + pos_len;
            }
            void insert( iterator pos, size_type count, const T& value ) {
                if (size() + count > capacity()) {
                    size_type tmp_size = size() + count;
                    value_type* tmp = _alloc.allocate(tmp_size);
                    size_type tmp_i = 0;
                    size_type array_i = 0;
                    for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                        _alloc.construct(tmp + tmp_i, *it);
                        _alloc.destroy(_array + array_i);
                    }
                    for (size_t i = 0; i < count; i++) _alloc.construct(tmp + tmp_i++, value);
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
                    value_type* tmp = _alloc.allocate(capacity());
                    size_type tmp_i = 0;
                    size_type array_i = 0;
                    for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                        _alloc.construct(tmp + tmp_i, *it);
                        _alloc.destroy(_array + array_i);
                    }
                    for (size_t i = 0; i < count; i++) _alloc.construct(tmp + tmp_i++, value);
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
            // template < typename InputIt > void insert( iterator pos, InputIt first, InputIt last ) {
            //     if (_size + (last - first) > _size_max) {
            //         value_type* tmp;
            //         if (!capacity())
            //             tmp = _alloc.allocate(last - first);
            //         else
            //             tmp = _alloc.allocate(capacity() * 2);
            //         int tmp_i = 0;
            //         int array_i = 0;
            //         for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
            //             _alloc.construct(tmp + tmp_i, *it);
            //             _alloc.destroy(_array + array_i);
            //         }
            //         while (first != last)
            //             _alloc.construct(tmp + tmp_i++, *first++);
            //         for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
            //             _alloc.construct(tmp + tmp_i, *pos);
            //             _alloc.destroy(_array + array_i);
            //         }
            //         _alloc.deallocate(_array, capacity());
            //         _size_max = capacity() * 2;
            //         _size++;
            //         _array = tmp;
            //     }
            //     else {
            //         value_type* tmp = _alloc.allocate(capacity());
            //         int tmp_i = 0;
            //         int array_i = 0;
            //         for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
            //             _alloc.construct(tmp + tmp_i, *it);
            //             _alloc.destroy(_array + array_i);
            //         }
            //         while (first != last)
            //             _alloc.construct(tmp + tmp_i++, *first++);
            //         for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
            //             _alloc.construct(tmp + tmp_i, *pos);
            //             _alloc.destroy(_array + array_i);
            //         }
            //         _alloc.deallocate(_array, capacity());
            //         _size++;
            //         _array = tmp;
            //     }
            //}
    
            iterator erase( iterator pos ) {
                value_type* tmp = _alloc.allocate(capacity());
                int tmp_i = 0;
                int array_i = 0;
                for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
                    _alloc.construct(tmp + tmp_i, *it);
                    _alloc.destroy(_array + array_i);
                }
                pos++;
                _alloc.destroy(_array + array_i++);
                for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
                    _alloc.construct(tmp + tmp_i, *pos);
                    _alloc.destroy(_array + array_i);
                }
                _alloc.deallocate(_array, capacity());
                _size--;
                _array = tmp;
                return begin();
            }
            iterator erase( iterator first, iterator last ) {
                value_type* tmp = _alloc.allocate(capacity());
                int tmp_i = 0;
                int array_i = 0;
                for (iterator it = begin(); it != first; it++, tmp_i++, array_i++) {
                    _alloc.construct(tmp + tmp_i, *it);
                    _alloc.destroy(_array + array_i);
                }
                while (first != last) {
                    _alloc.destroy(_array + array_i++);
                    first++;
                }
                for (iterator its = end(); last != its; last++, tmp_i++, array_i++) {
                    _alloc.construct(tmp + tmp_i, *last);
                    _alloc.destroy(_array + array_i);
                }
                _alloc.destroy(_array + array_i);
                _size = tmp_i;
                _array = tmp;
                return begin();
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

                void resize( size_type count, T value = T() ) {
                    if (count > _size) {
                        while (count > _size)
                            push_back(value);
                    }
                    else
                        while (count < _size)
                            pop_back();
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
}

#endif