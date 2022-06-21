/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:13:34 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/21 11:44:54 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft.hpp"
# include <iostream>
# include <memory>

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector {
		private:
			std::string _name;
		
		public:

		//* memmber functions *//
			vector() : _name("veccie") {};
			~vector() {};
			void printVector(void) {std::cout << "Printing name: " << this->_name << std::endl;};
			// ft::vector & 	operator =(const ft::vector &inst);
			// void		assign( size_type count, const T& value );
			// template <class InputIt>
			// void 		assign( InputIt first, InputIt last );
			// void 		assign( std::initializer_list<T> ilist );
			// get_allocator();

		//* element acces*//
	};

// template <typename T>
// class ft::vector {
// 	public:

// 	//* memmber functions *//
// 		// ft::vector() {};
// 		// ft::~vector() {};
// 		// ft::vector & 	operator =(const ft::vector &inst);
// 		// void		assign( size_type count, const T& value );
// 		// template <class InputIt>
// 		// void 		assign( InputIt first, InputIt last );
// 		// void 		assign( std::initializer_list<T> ilist );
// 		get_allocator();

// 	//* element acces*//
// };
}

#endif