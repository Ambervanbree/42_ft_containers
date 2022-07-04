/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:07:41 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/04 17:49:01 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class vector_test{
		private:
			T*			_array;
			size_t		_size;
			size_t		_capacity;
			Allocator	_alloc;

			void reallocate(){
				Allocator	temp;
				
				this->_capacity *= 2;
				this->_array = temp.allocate(this->_capacity);
				this->_alloc.deallocate(0, this->_size);
				this->_alloc = temp;
			}

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
			explicit vector_test(const allocator_type& alloc= allocator_type()) : 
			_size(0), _capacity(0), _alloc(alloc) {
				this->_array = this->_alloc.allocate(this->_capacity);
			}

			explicit vector_test(size_type n, const T& value = T(), const allocator_type& alloc= allocator_type()) :
			_size(n), _capacity(n), _alloc(alloc) {
				this->_array = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < n; i++){
					_array[i] = value;
				}
			}

			~vector_test(){
				this->_alloc.deallocate(this->_array, this->_capacity);
			}

			// capacity:
			size_type size() const {return this->_size; }
			size_type capacity() const {return this->_capacity; }

			// element access:
			reference operator[](size_type n) {return this->_array[n]; }
			const_reference operator[](size_type n) const {return this->_array[n]; }

			// modifiers:
			void push_back(const T& x){
				if (this->_capacity == this->_size){
					this->reallocate();
				}
				this->_array[this->_size] = x;
				this->_size++;
			}

			// non-member operators:
			friend bool operator==(const ft::vector_test<T, Allocator>& x, const ft::vector_test<T, Allocator>& y){
				return x._array == y._array ;
			}

			friend bool operator!=(const ft::vector_test<T, Allocator>& x, const ft::vector_test<T, Allocator>& y){
				return x._array != y._array ;
			}

			friend bool operator<(const ft::vector_test<T, Allocator>& x, const ft::vector_test<T, Allocator>& y){
				return x._array < y._array ;
			}

			friend bool operator>(const ft::vector_test<T, Allocator>& x, const ft::vector_test<T, Allocator>& y){
				return x._array > y._array ;
			}

			friend bool operator<=(const ft::vector_test<T, Allocator>& x, const ft::vector_test<T, Allocator>& y){
				return x._array <= y._array ;
			}

			friend bool operator>=(const ft::vector_test<T, Allocator>& x, const ft::vector_test<T, Allocator>& y){
				return x._array >= y._array ;
			}
	};
}

#endif
