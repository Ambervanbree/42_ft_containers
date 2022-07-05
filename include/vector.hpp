/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:07:41 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/05 17:53:07 by avan-bre         ###   ########.fr       */
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
			// typedef implementation defined iterator; // See 23.1
			// typedef implementation defined const_iterator; // See 23.1
			typedef size_t									size_type;
			typedef size_t									difference_type;
			typedef T 										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer;
			// typedef std::reverse_iterator<iterator> 		reverse_iterator;
			// typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;
			
			// construct/copy/destroy:
			explicit vector(const allocator_type& alloc= allocator_type()) : 
			_size(0), _capacity(0), _alloc(alloc) {
				this->_array = this->_alloc.allocate(this->_capacity);
			}

			explicit vector(size_type n, const T& value = T(), const allocator_type& alloc= allocator_type()) :
			_size(n), _capacity(n), _alloc(alloc) {
				this->_array = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < n; i++){
					_array[i] = value;
				}
			}

// TODO --------->> Not sure if I understand well: 
// Copy constructors for all container types defined in this clause copy an allocator argument from their
// respective first parameters. All other constructors for these container types take an Allocator& argu-
// ment (20.1.5), an allocator whose value type is the same as the container’s value type. A copy of this argu-
// ment is used for any memory allocation performed, by these constructors and by all member functions, dur-
// ing the lifetime of each container object. In all container types defined in this clause, the member
// get_allocator() returns a copy of the Allocator object used to construct the container.

			vector(const vector<T,Allocator>& x) :
			_array(0), _size(0), _capacity(0){
// TODO --------->> maybe use get_allocator for this? 
				*this = x;
			}

			~vector(){
				this->_alloc.deallocate(this->_array, this->_capacity);
			}

			vector<T,Allocator>& operator=(const vector<T,Allocator>& x) {
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_size = x.size();
				if (x._size > this->_capacity)
					this->_capacity = x.size();
				this->_array = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_array[i] = x._array[i];
// TODO --------->> turn into copy
				return *this;
			}

			// capacity:
			size_type size() const {return this->_size; }
			size_type capacity() const {return this->_capacity; }
			void reserve(size_type n) { 
// TODO --------->> throw exception if n > this->max_size();
				if (this->_capacity < n) 
					{this->reallocate(n);} }
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
// TODO --------->> use insert for this funtcion // should throw an exception
			}

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

				if (this->_capacity == 0)
					this->_capacity = 1;
				else
					this->_capacity *= 2;
				temp_array = temp_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					temp_array[i] = this->_array[i];
// TODO --------->> turn into copy
				this->_alloc.deallocate(this->_array, this->_size);		
				this->_alloc = temp_alloc;
				this->_array = temp_array;
			}

			void reallocate(size_type n){
				value_type* 	temp_array;
				allocator_type	temp_alloc;

				this->_capacity = n;
				temp_array = temp_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					temp_array[i] = this->_array[i];
// TODO --------->> turn into copy
				this->_alloc.deallocate(this->_array, this->_size);		
				this->_alloc = temp_alloc;
				this->_array = temp_array;
			}
	};
}

#endif
