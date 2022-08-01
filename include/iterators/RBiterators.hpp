/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBiterators.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:51:10 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/01 17:19:27 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBITERATORS_HPP
# define RBITERATORS_HPP

# include <iostream>
# include "iterator_traits.hpp"
# include <iterator>

namespace ft{
	template <class T>
	class RBiterator {

		public:
		
			/* ******************************************************************** */
			/* types and definitions												*/
			/* ******************************************************************** */

			typedef 	std::bidirectional_iterator_tag 	iterator_category;
			typedef  	std::ptrdiff_t						difference_type;
			typedef		typename T::value_type				value_type;
			typedef		typename T::value_type *			value_ptr;
			typedef		typename T::value_type &			value_ref;
			typedef		T									node_type;
			typedef  	T *									node_ptr;
			typedef		T &									node_ref;			

			/* ******************************************************************** */
			/* variables															*/
			/* ******************************************************************** */
		protected:
		
			node_ptr	_current;

		public:

			/* ******************************************************************** */
			/* constructors															*/
			/* ******************************************************************** */

						RBiterator() : _current() {}
			explicit	RBiterator(const node_ptr &x) : _current(x) {}

			/* ******************************************************************** */
			/* getters																*/
			/* ******************************************************************** */

			RBiterator 	base() const {return _current; }		

			/* ******************************************************************** */
			/* member operator overload												*/
			/* ******************************************************************** */		
			
			// node_ref	operator*(void) const {return _current->_content; }
			value_type	operator*(void)	{return _current->_content; }
			value_ptr	operator->(void) {return &(_current->_content); }
			
			// reverse_iterator&	operator++(void) {--current; return *this; }
			// reverse_iterator	operator++(int) {reverse_iterator tmp(*this); --current; return tmp; }
			// reverse_iterator&	operator--(void) {++current; return *this; }
			// reverse_iterator	operator--(int) {reverse_iterator tmp(*this); ++current; return tmp; }
			
			// reverse_iterator 	operator+ (difference_type n) const {return reverse_iterator(current - n); }
			// reverse_iterator& 	operator+=(difference_type n) {current -= n; return *this; }
			// reverse_iterator 	operator- (difference_type n) const {return reverse_iterator(current + n); }
			// reverse_iterator& 	operator-=(difference_type n) {current += n; return *this; }
			// reference 			operator[](difference_type n) const {return current[- n - 1]; }
			
	};
}

#endif