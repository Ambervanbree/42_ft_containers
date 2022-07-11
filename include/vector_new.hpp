/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:39:15 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/11 12:48:36 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_NEW_HPP
# define VECTOR_NEW_HPP

# include <memory>
# include <iostream>
# include <algorithm>
# include <new>
# include "enable_if.hpp"
# include "is_integral.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector_new{
		public:
			// types:
			typedef typename Allocator::reference 			reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef typename std::vector<T>::iterator		iterator;
			typedef typename std::vector<T>::const_iterator	const_iterator;
			typedef size_t									size_type;
			typedef size_t									difference_type;
			typedef T 										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer;
			typedef typename std::vector<T>::reverse_iterator 		reverse_iterator;
			typedef typename std::vector<T>::const_reverse_iterator	const_reverse_iterator;

			// construct/copy/destroy:
			explicit vector_new(const allocator_type& alloc= allocator_type()) : 
			_array(0), _size(0), _capacity(0), _alloc(alloc) {}

			explicit vector_new(size_type n, const value_type& value = value_type(), const allocator_type& alloc= allocator_type()) :
			_size(n), _capacity(n), _alloc(alloc) {
				_array = _alloc.allocate(_capacity);
				fill(begin(), end(), value);
			}

			template <class InputIterator, class = typename ft::enable_if<ft::is_integral<InputIterator>::value == false>::type> 
			vector_new(InputIterator first, InputIterator last, const Allocator& alloc = Allocator()) :
			_size(last - first), _capacity(last - first), _alloc(alloc) {
				_array = _alloc.allocate(_capacity);
				copy(first, last, begin());
			}

			vector_new(const vector_new<T,Allocator>& x) :
			_array(0), _size(0), _capacity(0), _alloc(x.get_allocator()) {
				*this = x;
			}

			~vector_new(){
				if (_capacity)
					_alloc.deallocate(_array, _capacity);
			}

			vector_new<T,Allocator>& operator=(const vector_new<T,Allocator>& x) {
				if (x.size() > _capacity){
					if (_capacity)
						_alloc.deallocate(_array, _capacity);
					_capacity = x.size();
					_array = _alloc.allocate(_capacity);
				}
				_size = x.size();
				copy(x.begin(), x.end(), begin());
				return *this;
			}

			allocator_type get_allocator() const {return _alloc; }

			// iterators:
			iterator begin() {return iterator(_array); }
			const_iterator begin() const {return const_iterator(_array); }
			iterator end() {return iterator(_array + _size); }
			const_iterator end() const {return const_iterator(_array + _size); }
			reverse_iterator rbegin() {return reverse_iterator(_array); }
			const_reverse_iterator rbegin() const {return const_reverse_iterator(_array); }
			reverse_iterator rend() {return reverse_iterator(_array + _size); }
			const_reverse_iterator rend() const {return const_reverse_iterator(_array + _size); }

			// capacity:
			size_type size() const {return _size; }
			size_type capacity() const {return _capacity; }
			bool empty() const { return _size < 1 ? 1 : 0; }
			
			void reserve (size_type n){
				value_type	*temp;
				size_type	new_capacity = n;

				temp = get_allocator().allocate(new_capacity);
				copy(begin(), end(), temp);
				_alloc.deallocate(_array, _capacity);
				_array = temp;
				_capacity = new_capacity;
			}

			// element access:
			reference operator[](size_type n) {return _array[n]; }
			const_reference operator[](size_type n) const {return _array[n]; }


			// modifiers:
			void push_back(const T& x) {
				if (_size + 1 > _capacity)
					reallocate(1);
				*end() = x;
				_size++;
			}
			
			void pop_back() { 
				value_type		*p	= &(_array[_size - 1]);

				_alloc.destroy(p);
				_size--;
			}
			
			// returns: Iterator following the last removed element.
			// If pos refers to the last element, then the end() iterator is returned.
			// If last==end() prior to removal, then the updated end() iterator is returned.
			// If [first, last) is an empty range, then last is returned.

			iterator erase(iterator position){
				size_type	offset 	= position - begin();
				value_type	*p 		= &(_array[offset]);

				_alloc.destroy(p);
				copy(begin() + offset + 1, end(), begin() + offset);
				_size--;
				return begin() + offset;
			}

			iterator erase(iterator first, iterator last){
				size_type	offset 	= first - begin();
				size_type	range	= last - first;

				for (size_type i = 0; i < range; i++){
					_alloc.destroy(&(_array[offset + i]));
					std::cout << "destroyed: " << *&(_array[offset + i]) << std::endl;
				}
				copy(begin() + offset + range, end(), begin() + offset);
				_size -= range;
				return begin() + offset;
			}

			
			iterator insert(iterator position, const T& x){
				size_type	offset = position - begin();
				
				if (_size + 1 > _capacity)
					reallocate(1);
				copy_backward(begin() + offset, end(), end() + 1);
				*(begin() + offset) = x;
				_size++;
				return begin() + offset;
			}

			void insert(iterator position, size_type n, const T& x){
				size_type	offset = position - begin();
				
				if (_size + n > _capacity)
					reallocate(n);
				copy_backward(begin() + offset, end(), end() + n);
				fill(begin() + offset, begin() + offset + n, x);
				_size += n;
			}
// TODO --------->> capacity reallocation is not right yet for the last 2 inserts

			template <class InputIterator, class = typename ft::enable_if<ft::is_integral<InputIterator>::value == false>::type>
			void insert(iterator position, InputIterator first, InputIterator last){
				size_type	offset = position - begin();
				size_type	n = last - first;

				if (_size + n > _capacity)
					reallocate(n);
				copy_backward(begin() + offset, end(), end() + n);
				copy(first, last, begin() + offset);
				_size += n;	
			}

// TODO --------->> delete!!!
			void print_veccie(std::string name){
				std::cout << "Veccie " << name << " (size " 
				<< _size << ", capacity " << _capacity << ") contains: " << std::endl;
				for (size_type i = 0; i < _size; i++)
					std::cout << _array[i] << " ";
				std::cout << std::endl;
			}
			
		private:
			value_type*		_array;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;

			void	reallocate(size_type n){
				size_type	new_capacity = 0;
				
				if (_size > n)
					new_capacity = _size * 2;
				else
					new_capacity = _size + n;
				reserve(new_capacity);
			}
	};
}

#endif