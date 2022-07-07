/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:55:35 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/07 18:00:59 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class vector{
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
			_size(0), _capacity(0), _alloc(alloc) {}

			explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc= allocator_type()) :
			_size(n), _capacity(n), _alloc(alloc) {
// TODO --------->> can maybe be , _alloc(alloc.allocate(n))
				this->_array = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < n; i++){
					this->_array[i] = value;
				}
			}

			template <class InputIterator> 
			vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator()) :
			_size(last - first), _capacity(last - first), _alloc(alloc) {
				_array = _alloc.allocate(_capacity);
				std::copy(first, last, this->begin());
			}

			vector(const vector<T,Allocator>& x) :
			_array(0), _size(0), _capacity(0), _alloc(x.get_allocator()){
				*this = x;
			}

			~vector(){
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_array, this->_capacity);
			}

			vector<T,Allocator>& operator=(const vector<T,Allocator>& x) {
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_size = x.size();
				if (x._size > this->_capacity)
					this->_capacity = x.size();
				this->_array = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < _size; i++)
					_array[i] = x._array[i];
				return *this;
			}

			allocator_type get_allocator() const {return this->_alloc; }

			// iterators:
			iterator begin() {return iterator(this->_array); }
			iterator end() {return iterator(this->_array + this->_size); }
			// reverse_iterator rbegin() {{return reverse_iterator(_array); }
			// reverse_iterator rend() {return reverse_iterator(_array + _size); }

			// capacity:
			size_type size() const {return this->_size; }
			size_type capacity() const {return this->_capacity; }
// 			void reserve(size_type n) { 
// // TODO --------->> throw exception if n > this->max_size();
// 				if (this->_capacity < n) 
// 					{this->reallocate(n);} }
			bool empty() const { return this->_size < 1 ? 1 : 0; }

			// element access:
			reference operator[](size_type n) {return this->_array[n]; }
			const_reference operator[](size_type n) const {return this->_array[n]; }

			// modifiers:
			void push_back(const T& x){
				if (this->_capacity == this->_size)
					this->reallocate();
				this->_array[this->_size] = x;
				this->_size++;
				// this->insert(this->end(), x);
// TODO --------->> use insert for this funtcion // should throw an exception
			}

			iterator insert(iterator position, const T& x){
				// inserts a copy of x before position
				// if (this->_size + 1 > this->max_size())
					//throw exception
				difference_type			offset = position - this->begin();
				ft::vector<value_type>	temp(begin(), begin() + offset);

				if (_size + 1 > _capacity){
					if (_capacity == 0)
						_capacity = 1;
					else
						_capacity *= 2;
				}
				temp.reallocate(_capacity);
				temp.print_veccie();
				std::cout << "capa temp 2: " << temp.capacity() << " and size " << temp.size() << std::endl;
				std::cout << "capa this 2: " << capacity() << " and size " << size() << std::endl;				
				// std::cout << *temp.end() << std::endl;
				*temp.end() = x;
				// std::cout << *temp.end() << std::endl;
				// temp.print_veccie();
				// std::copy(begin() + offset, end(), temp.end());
				// temp.print_veccie();
				// // *this = temp;
				return begin() + offset;
			}

			// void insert(iterator position, size_type n, const T& x)
			// inserts n copies of x before position
			// if (this->_size + 1 > this->max_size())
				//throw exception
			// 	if (this->_capacity == this->_size)
			// 		this->reallocate();
			// }
			
			// template <class InputIterator>
			// void insert(iterator position, InputIterator first, InputIterator last){
			// pre: first & last are not iterators into a
			// inserts copies of elements [first, last) before position
			// if (this->_size + 1 > this->max_size())
				//throw exception
			// 	if (this->_capacity == this->_size)
			// 		this->reallocate();
			// }
			
			// non-member operators:
			friend bool operator==(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return x._array == y._array ;
			}

			friend bool operator!=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return x._array != y._array ;
			}

			friend bool operator<(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return x._array < y._array ;
			}

			friend bool operator>(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return x._array > y._array ;
			}

			friend bool operator<=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return x._array <= y._array ;
			}

			friend bool operator>=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y){
				return x._array >= y._array ;
			}
		
		private:
			value_type*		_array;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;

			void reallocate(){
				value_type* 	temp_array;
				allocator_type	temp_alloc;

				if (this->_capacity == 0){
					this->_capacity = 1;
					this->_array = this->_alloc.allocate(this->_capacity);	
				}
				else{
					this->_capacity *= 2;
					temp_array = temp_alloc.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++)
						temp_array[i] = this->_array[i];
// TODO --------->> turn into copy
					this->_alloc.deallocate(this->_array, this->_size);	
					this->_alloc = temp_alloc;
					this->_array = temp_array;
				}
			}

			void reallocate(size_type n){
				ft::vector<int>	temp;
				
				temp._array = temp._alloc.allocate(n);
				// std::copy(begin(), end(), temp.begin());
				std::cout << "blaah" << std::endl;
				print_veccie();
				temp.print_veccie();
				temp._capacity = n;	
				*this = temp;
			}

			void print_veccie(void){
				std::cout << "Veccie contains: ";
				for (size_type i = 0; i < _size; i++)
					std::cout << this->_array[i] << " ";
				std::cout << std::endl;
			}

			void allocate(size_type n){
				_array = _alloc.allocate(n);
				_capacity = n;
			}
	};
}

#endif
