/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:39:15 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/11 16:28:27 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <algorithm>
# include <new>
# include <iterator>
# include "reverse_iterators.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// types:
			typedef typename Allocator::reference 					reference;
			typedef typename Allocator::const_reference 			const_reference;
			typedef typename Allocator::pointer 					pointer;
			typedef typename Allocator::const_pointer 				const_pointer;
			typedef pointer											iterator;
			typedef const_pointer									const_iterator;
			typedef size_t											size_type;
			typedef size_t											difference_type;
			typedef T 												value_type;
			typedef Allocator										allocator_type;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			// construct/copy/destroy:
			explicit vector(const allocator_type& alloc= allocator_type()) : 
			_array(0), _size(0), _capacity(0), _alloc(alloc) { }

			explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc= allocator_type()) :
			_size(n), _capacity(n), _alloc(alloc) {
				_array = _alloc.allocate(_capacity);
				construct_copy(value);
			}
			
			template <class SomeIterator> 
			vector(typename ft::enable_if<!ft::is_integral<SomeIterator>::value, SomeIterator>::type first, SomeIterator last, const Allocator& alloc = Allocator()) :
			_size(std::distance(first, last)), _capacity(_size), _alloc(alloc) {
				typedef typename std::iterator_traits<SomeIterator>::iterator_category 	category;

				_array = _alloc.allocate(_capacity);
				iterator_construct(first, last, category());
			}

			vector(const vector<T,Allocator>& x) :
			_array(0), _size(0), _capacity(0), _alloc(x.get_allocator()) {
				*this = x;
			}

			~vector(){
				clear();
				if (_capacity)
					_alloc.deallocate(_array, _capacity);
			}

			vector<T,Allocator>& operator=(const vector<T,Allocator>& x) {
				if (*this != x){
					if (x.size() > _capacity){
						if (size())
							clear();
						if (_capacity)
							_alloc.deallocate(_array, _capacity);
						_capacity = x.size();
						_array = _alloc.allocate(_capacity);
					}
					_size = x.size();
					construct_copy(_array, x._array, _size);
				}
				return *this;			
			}

			template <class SomeIterator> 
			void assign(typename ft::enable_if<!ft::is_integral<SomeIterator>::value, SomeIterator>::type first, SomeIterator last){
				size_type	new_size = std::distance(first, last);
				typedef typename std::iterator_traits<SomeIterator>::iterator_category 	category;
				
				clear();
				if (new_size > _capacity)
					reserve(new_size);
				iterator_construct(first, last, category());
				_size = new_size;
			}

			void assign(size_type n, const value_type& value){
				clear();
				if (n > _capacity)
					reserve(n);
				_size = n;
				construct_copy(value);		
			}

			allocator_type get_allocator() const {return _alloc; }

			// iterators:
			iterator begin() {return iterator(_array); }
			const_iterator begin() const {return const_iterator(_array); }
			iterator end() {return iterator(_array + _size); }
			const_iterator end() const {return const_iterator(_array + _size); }
			reverse_iterator rbegin() {return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const {return const_reverse_iterator(end()); }
			reverse_iterator rend() {return reverse_iterator(begin()); }
			const_reverse_iterator rend() const {return const_reverse_iterator(begin()); }

			// capacity:
			size_type size() const {return _size; }
			size_type max_size() const {return _alloc.max_size(); }

			void resize(size_type sz, T c = T()){
				if (sz < size())
					erase(begin() + sz, end());
				else if (sz > size()){
					if (sz > capacity())
						reallocate(sz - size());
					insert(end(), sz - size(), c);
				}
				else
				;
			}
				
			size_type capacity() const {return _capacity; }
			bool empty() const { return _size < 1 ? 1 : 0; }
			
			void reserve (size_type n){
				value_type	*temp;
				size_type	new_size = size();

				if (n <= _capacity)
					return ;
				if (n > max_size())
					throw std::length_error("vector::reserve");
				temp = get_allocator().allocate(n);
				if (_size){
					construct_copy(temp, _array, new_size);
					clear();
					_size = new_size;
				}
				if (_capacity)
					_alloc.deallocate(_array, _capacity);
				_array = temp;
				_capacity = n;
			}

			// element access:
			reference operator[](size_type n) {return _array[n]; }
			const_reference operator[](size_type n) const {return _array[n]; }
			
			const_reference at(size_type n) const {
				if (n >= _size)
					throw std::out_of_range("out of range");
				return _array[n]; 
			}
			
			reference at(size_type n) {
				if (n >= _size)
					throw std::out_of_range("out of range");
				return _array[n];	
			}
			
			reference front() {return _array[0]; }
			const_reference front() const {return _array[0]; } 
			reference back() {return _array[_size - 1]; }
			const_reference back() const {return _array[_size - 1]; }

			// modifiers:
			void push_back(const T& x) {
				if (_size + 1 > _capacity)
					reallocate(1);
				_alloc.construct(&_array[_size], x);
				_size++;
			}
			
			void pop_back() { 
				value_type		*p	= &(_array[_size - 1]);

				_alloc.destroy(p);
				_size--;
			}

			iterator insert(iterator position, const T& x){
				size_type	offset =	position - begin();

				if (_size + 1 > _capacity)
					reallocate(1);
				construct_copy_backward(offset, 1);
				_alloc.construct(&*(begin() + offset), x);
				_size++;
				return begin() + offset;
			}

			void insert(iterator position, size_type n, const T& value){
				size_type	offset = position - begin();

				if (n == 0)
					return ;				
				if (_size + n > _capacity)
					reallocate(n);
				construct_copy_backward(offset, n);
				position = begin() + offset;
				construct_copy(position, n, value);
				_size += n;
			}

			template <class SomeIterator>
			void insert(iterator position, typename ft::enable_if<!ft::is_integral<SomeIterator>::value, SomeIterator>::type first, SomeIterator last){
				size_type	offset = position - begin();
				size_type	n = std::distance(first, last);
				typedef typename std::iterator_traits<SomeIterator>::iterator_category 	category;

				if (n == 0)
					return ;
				if (_size + n > _capacity)
					reallocate(n);
				construct_copy_backward(offset, n);
				insert_copy(first, last, offset, category());
				_size += n;	
			}

			iterator erase(iterator position){
				size_type	offset 	= position - begin();
				iterator	first	= begin() + offset + 1;
				iterator	last	= end();

				_alloc.destroy(&*position);
				for (size_type i = 0; first != last; first++, i++){
					_alloc.construct(&*(position + i), *first);
					_alloc.destroy(&*first);
				}
				_size--;
				return begin() + offset;
			}

			iterator erase(iterator first, iterator last){
				size_type	offset 	= first - begin();
				size_type	range	= last - first;
				size_type	i = 0;

				for (; i < range; i++)
					_alloc.destroy(&*(first + i));
				if (first + i != end()){
					for (i = 0; i < _size - offset - range; i++){
						_alloc.construct(&*(first + i), *(first + range + i));
						_alloc.destroy(&*(first + range + i));
					}
				}
				_size -= range;
				return begin() + offset;
			}

			void clear(){
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_array[i]));
				_size = 0;
			}

			void swap(ft::vector<T,Allocator>& x){
				std::swap(_array, x._array);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x._alloc);
			}

// TODO --------->> delete!!!
			void print_veccie(std::string name) const{
				std::cout << "Veccie " << name << " (size " 
				<< _size << ", capacity " << _capacity << ") contains: " << std::endl;
				for (size_type i = 0; i < _size; i++)
					std::cout << _array[i] << " ";
				std::cout << std::endl;
			}

			// non-member operators:
			friend bool operator==(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				if (x.size() != y.size())
					return false;
				else
					for (size_type i = 0; i < x.size(); i++)
						if (x._array[i] != y._array[i])
							return false;
				return true;
			}

			friend bool operator!=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return !(x == y);
			}

			friend bool operator<(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()) ;
			}

			friend bool operator>(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return !ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()) && (x != y);
			}

			friend bool operator<=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()) || x == y ;
			}

			friend bool operator>=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return !ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
			}

			friend void swap(vector<T,Allocator>& x, vector<T,Allocator>& y) {y.swap(x);}
			
		private:
			value_type*		_array;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;

			void	reallocate(size_type n){			
				if (_size > n)
					reserve(_size * 2);
				else
					reserve(_size + n);
			}

			template<typename RandomAccessIterator>
			void iterator_construct(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag){
				construct_copy(first, last, begin());
			}

			template<typename input_iterator>
			void iterator_construct(input_iterator first, input_iterator last, std::input_iterator_tag){
				for (size_type i = 0; first != last; i++, first++)
					_alloc.construct(&_array[i], *first);
			}

			template <class InputIterator> 
			void	insert_copy(InputIterator first, InputIterator last, size_type offset, std::input_iterator_tag){
				iterator	it = begin();

				for (size_type i = 0; i < offset; i++)
					it++;
				for (size_type i = 0; first != last; first++, i++)
					_alloc.construct(&*(it + i), *first);
			}

			template <class InputIterator> 
			void	insert_copy(InputIterator first, InputIterator last, size_type offset, std::random_access_iterator_tag){
				construct_copy(first, last, begin() + offset);
			}

			template <class InputIterator> 
			void	construct_copy(InputIterator first, InputIterator last, iterator position){
				for (size_type i = 0; first != last; first++, i++)
					_alloc.construct(&*(position + i), *first);
			}

			void	construct_copy(iterator position, size_type n, value_type value){
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&*(position + i), value);
			}

			void	construct_copy(value_type *destination, value_type *source, size_type n){
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&destination[i], source[i]);
			}

			void	construct_copy(value_type value){
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], value);
			}

			void	construct_copy_backward(size_type offset, size_type n){
				for (size_type i = _size; i > offset; i--){
					_alloc.construct(&_array[i + n - 1], _array[i - 1]);
					_alloc.destroy(&_array[i - 1]);
				}
			}		
	};
}

#endif