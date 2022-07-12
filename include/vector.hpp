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
# include <vector>
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
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
			explicit vector(const allocator_type& alloc= allocator_type()) : 
			_array(0), _size(0), _capacity(0), _alloc(alloc) { }

			explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc= allocator_type()) :
			_size(n), _capacity(n), _alloc(alloc) {
				_array = _alloc.allocate(_capacity);
				std::fill(begin(), end(), value);
			}

			template <class InputIterator> 
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const Allocator& alloc = Allocator()) :
			_size(last - first), _capacity(last - first), _alloc(alloc) {
				_array = _alloc.allocate(_capacity);
				std::copy(first, last, begin());
			}

			vector(const vector<T,Allocator>& x) :
			_array(0), _size(0), _capacity(0), _alloc(x.get_allocator()) {
				*this = x;
			}

			~vector(){
				clear();
				_alloc.deallocate(_array, _capacity);
			}

			vector<T,Allocator>& operator=(const vector<T,Allocator>& x) {
				if (x.size() > _capacity){
					if (_capacity)
						_alloc.deallocate(_array, _capacity);
					if (size())
						clear();
					_capacity = x.size();
					_array = _alloc.allocate(_capacity);
				}
				_size = x.size();
				copy(x.begin(), x.end(), begin());
				return *this;
			}
			
			template <class InputIterator> 
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last){
				size_type	new_size = last - first;
				
				clear();
				if (new_size > _capacity)
					reserve(new_size);
				std::copy(first, last, begin());
				_size = new_size;
			}

			void assign(size_type n, const value_type& u){
				clear();
				if (n > _capacity)
					reserve(n);
				for (size_type i = 0; i < n; i++)
					_array[i] = u;
				// std::fill(begin(), begin() + n, u);
				_size = n;
			}

// TODO --------> if vector is 0, begin() and end(). 

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

				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (!(n > _capacity))
					return ;
				temp = get_allocator().allocate(n);
				if (_size){
					copy(begin(), end(), temp);
					clear();
					_size = new_size;
				}
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
			const_reference back() const {return (end() - 1); }

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

			template <class InputIterator>
			void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last){
				size_type	offset = position - begin();
				size_type	n = last - first;

				if (_size + n > _capacity)
					reallocate(n);
				copy_backward(begin() + offset, end(), end() + n);
				copy(first, last, begin() + offset);
				_size += n;	
			}

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

				for (size_type i = 0; i < range; i++)
					_alloc.destroy(&(_array[offset + i]));
				copy(begin() + offset + range, end(), begin() + offset);
				_size -= range;
				return begin() + offset;
			}

			void clear(){
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_array[i]));
				_size = 0;
			}

			void swap(ft::vector<T,Allocator>& x){
				ft::vector<value_type>	temp;

				temp = *this;
				temp._capacity = _capacity;
				*this = x;
				_capacity = x._capacity;
				x = temp;
				x._capacity = temp._capacity;
			}

// TODO --------->> delete!!!
			void print_veccie(std::string name){
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
	};
}

#endif