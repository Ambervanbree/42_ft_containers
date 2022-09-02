/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBiterators.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:51:10 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/02 14:12:31 by avan-bre         ###   ########.fr       */
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

	protected:

		/* ******************************************************************** */
		/* variables															*/
		/* ******************************************************************** */
	
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

		node_ptr 	base() const {return _current; }		

		/* ******************************************************************** */
		/* member operator overload												*/
		/* ******************************************************************** */		
		
		value_ref	operator*(void)	const {return _current->_content; }
		value_ptr	operator->(void) const {return &(_current->_content); }
		
		RBiterator&	operator++(void) {
			_current = _current->successor(); 
			return *this; 
		}
		
		RBiterator	operator++(int) {
			RBiterator temp(_current);
			_current = _current->successor();
			return temp;
		}
		
		RBiterator&	operator--(void) {
			_current = _current->predecessor(); 
			return *this; 
		}
		
		RBiterator	operator--(int) {
			RBiterator temp(_current);
			_current = _current->predecessor();
			return temp;
		}		
	};

	/* ******************************************************************** */
	/* non member operator overload											*/
	/* ******************************************************************** */	

	template <typename LeftIterator, typename RightIterator>
	bool operator==(const RBiterator<LeftIterator>& x, 
		const RBiterator<RightIterator>& y){
		return x.base() == y.base();
	}

	template <typename LeftIterator, typename RightIterator>
	bool operator!=(const RBiterator<LeftIterator>& x, 
		const RBiterator<RightIterator>& y){
		return !(x == y);
	}

template <class T>
	class RBreverse_iterator {

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

	protected:

		/* ******************************************************************** */
		/* variables															*/
		/* ******************************************************************** */
	
		node_ptr	_current;

	public:

		/* ******************************************************************** */
		/* constructors															*/
		/* ******************************************************************** */

					RBreverse_iterator() : _current() {}
		explicit	RBreverse_iterator(const node_ptr &x) : _current(x) {}

		/* ******************************************************************** */
		/* getters																*/
		/* ******************************************************************** */

		node_ptr 	base() const {return _current; }		

		/* ******************************************************************** */
		/* member operator overload												*/
		/* ******************************************************************** */		

		value_ref	operator*(void) const {return _current->_content; }
		value_ptr	operator->(void) const {return &(_current->_content); }
		
		RBreverse_iterator&	operator++(void) {
			_current = _current->predecessor(); 
			return *this;
		}
		
		RBreverse_iterator	operator++(int) {
			RBreverse_iterator temp(_current); 
			_current = _current->predecessor(); 
			return temp; 
		}
		
		RBreverse_iterator&	operator--(void) {
			_current = _current->successor(); 
			return *this; 
		}
		
		RBreverse_iterator	operator--(int) {
			RBreverse_iterator temp(_current); 
			_current = _current->successor(); 
			return temp; 
		}	
	};

	/* ******************************************************************** */
	/* non member operator overload											*/
	/* ******************************************************************** */	

	template <typename LeftIterator, typename RightIterator>
	bool operator==(const RBreverse_iterator<LeftIterator>& x, 
		const RBreverse_iterator<RightIterator>& y){
		return x.base() == y.base();
	}

	template <typename LeftIterator, typename RightIterator>
	bool operator!=(const RBreverse_iterator<LeftIterator>& x, 
		const RBreverse_iterator<RightIterator>& y){
		return !(x == y);
	}
}

#endif