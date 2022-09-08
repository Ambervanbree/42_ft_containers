/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBiterators.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:51:10 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/08 11:15:42 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBITERATORS_HPP
# define RBITERATORS_HPP

# include <iostream>
# include "iterator_traits.hpp"
# include "RBtree.hpp"
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
		typedef		typename T::value_type *			pointer;
		typedef		typename T::value_type &			reference;
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
		
		reference operator*(void)	const {return _current->_content; }
		pointer	operator->(void) const {return &(_current->_content); }
		
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

// template <class T>
// 	class RBreverse_iterator {

// 	public:
	
// 		/* ******************************************************************** */
// 		/* types and definitions												*/
// 		/* ******************************************************************** */

// 		typedef 	std::bidirectional_iterator_tag 	iterator_category;
// 		typedef  	std::ptrdiff_t						difference_type;
// 		typedef		typename T::value_type				value_type;
// 		typedef		typename T::value_type *			value_ptr;
// 		typedef		typename T::value_type &			value_ref;
// 		typedef		T									node_type;
// 		typedef  	T *									node_ptr;
// 		typedef		T &									node_ref;		
// 		typedef		RBiterator<T>						iterator;	

// 	protected:

// 		/* ******************************************************************** */
// 		/* variables															*/
// 		/* ******************************************************************** */
	
// 		iterator	_current;

// 	public:

// 		/* ******************************************************************** */
// 		/* constructors															*/
// 		/* ******************************************************************** */

// 					RBreverse_iterator() : _current() {}
// 		explicit	RBreverse_iterator(const node_ptr &x) : _current(x) {}
// 		explicit	RBreverse_iterator(iterator x) : _current(x.base()) {}

// 		/* ******************************************************************** */
// 		/* getters																*/
// 		/* ******************************************************************** */

// 		iterator 	base() const {return _current; }		

// 		/* ******************************************************************** */
// 		/* member operator overload												*/
// 		/* ******************************************************************** */		

// 		value_ref	operator*(void) const {return _current->_content; }
// 		value_ptr	operator->(void) const {return &(_current->_content); }
		
// 		RBreverse_iterator&	operator++(void) {
// 			_current = _current->predecessor(); 
// 			return *this;
// 		}
		
// 		RBreverse_iterator	operator++(int) {
// 			RBreverse_iterator temp(_current); 
// 			_current = _current->predecessor(); 
// 			return temp; 
// 		}
		
// 		RBreverse_iterator&	operator--(void) {
// 			_current = _current->successor(); 
// 			return *this; 
// 		}
		
// 		RBreverse_iterator	operator--(int) {
// 			RBreverse_iterator temp(_current); 
// 			_current = _current->successor(); 
// 			return temp; 
// 		}	
// 	};

template <class T>
	class const_RBiterator {

	public:
	
		/* ******************************************************************** */
		/* types and definitions												*/
		/* ******************************************************************** */

		typedef 	std::bidirectional_iterator_tag 	iterator_category;
		typedef  	std::ptrdiff_t						difference_type;
		typedef		typename T::value_type				value_type;
		typedef		typename T::value_type *			pointer;
		typedef		typename T::value_type &			reference;
		// typedef		typename T::value_type				value_type;
		// typedef		const value_type *					value_ptr;
		// typedef		const value_type &					value_ref;
		typedef		T									node_type;
		typedef  	T *									node_ptr;
		typedef		T &									node_ref;			
		typedef		const node_ptr						const_node_ptr;

	protected:

		/* ******************************************************************** */
		/* variables															*/
		/* ******************************************************************** */
	
		node_ptr	_current;

	public:

		/* ******************************************************************** */
		/* constructors															*/
		/* ******************************************************************** */

		const_RBiterator() : _current() {}
		const_RBiterator(const_node_ptr &x) : _current(x) {}
		const_RBiterator(const ft::RBiterator<T> x) : _current(x.base()) {}
		const_RBiterator(ft::const_RBiterator<T> const &x) : _current(x.base()) {}

		/* ******************************************************************** */
		/* getters																*/
		/* ******************************************************************** */

		const_node_ptr 	base() const {return _current; }		

		/* ******************************************************************** */
		/* member operator overload												*/
		/* ******************************************************************** */		
		
		reference	operator*(void)	const {return _current->_content; }
		pointer	operator->(void) const {return &(_current->_content); }
		
		const_RBiterator&	operator++ (void) {
			_current = _current->successor(); 
			return *this; 
		}
		
		const_RBiterator	operator++(int) {
			const_RBiterator temp(_current);
			_current = _current->successor();
			return temp;
		}
		
		const_RBiterator&	operator--(void) {
			_current = _current->predecessor(); 
			return *this; 
		}
		
		const_RBiterator	operator--(int) {
			const_RBiterator temp(_current);
			_current = _current->predecessor();
			return temp;
		}		
	};

// template <class T>
// 	class const_RBreverse_iterator {

// 	public:
	
// 		/* ******************************************************************** */
// 		/* types and definitions												*/
// 		/* ******************************************************************** */

// 		typedef 	std::bidirectional_iterator_tag 	iterator_category;
// 		typedef  	std::ptrdiff_t						difference_type;
// 		typedef		typename T::value_type				value_type;
// 		typedef		const value_type *					value_ptr;
// 		typedef		const value_type &					value_ref;
// 		typedef		const T *							const_node_ptr;
// 		typedef		T									node_type;
// 		typedef  	T *									node_ptr;
// 		typedef		T &									node_ref;
// 		typedef		ft::RBiterator<T>					iterator;
// 		typedef		ft::RBreverse_iterator<T>			reverse_iterator;
// 		typedef		ft::const_RBiterator<T>				const_iterator;

// 	protected:

// 		/* ******************************************************************** */
// 		/* variables															*/
// 		/* ******************************************************************** */
	
// 		const_node_ptr	_current;

// 	public:

// 		/* ******************************************************************** */
// 		/* constructors															*/
// 		/* ******************************************************************** */

// 		const_RBreverse_iterator() : _current() {}
// 		const_RBreverse_iterator(const_node_ptr &x) : _current(x) {}
// 		const_RBreverse_iterator(const node_ptr &x) : _current(x) {}
// 		const_RBreverse_iterator(iterator x) : _current(x.base()) {}
// 		const_RBreverse_iterator(reverse_iterator x) : _current(x.base()) {}
// 		const_RBreverse_iterator(const_iterator x) : _current(x.base()) {}

// 		/* ******************************************************************** */
// 		/* getters																*/
// 		/* ******************************************************************** */

// 		const_node_ptr 	base() const {return _current; }		

// 		/* ******************************************************************** */
// 		/* member operator overload												*/
// 		/* ******************************************************************** */		

// 		value_ref	operator*(void) const {return _current->_content; }
// 		value_ptr	operator->(void) const {return &(_current->_content); }
		
// 		const_RBreverse_iterator&	operator++(void) {
// 			_current = _current->predecessor(); 
// 			return *this;
// 		}
		
// 		const_RBreverse_iterator	operator++(int) {
// 			const_RBreverse_iterator temp(_current); 
// 			_current = _current->predecessor(); 
// 			return temp; 
// 		}
		
// 		const_RBreverse_iterator&	operator--(void) {
// 			_current = _current->successor(); 
// 			return *this; 
// 		}
		
// 		const_RBreverse_iterator	operator--(int) {
// 			const_RBreverse_iterator temp(_current); 
// 			_current = _current->successor(); 
// 			return temp; 
// 		}	
// 	};
	

	/* ******************************************************************** */
	/* non member operator overload											*/
	/* ******************************************************************** */	

	template <typename T, typename U>
	bool operator==(const RBiterator<T>& x, const RBiterator<U>& y){
		return x.base() == y.base();
	}

	template <typename T, typename U>
	bool operator==(const RBiterator<T>& x, const const_RBiterator<U>& y){
		return x.base() == y.base();
	}

	template <typename T, typename U>
	bool operator==(const const_RBiterator<T>& x, const RBiterator<U>& y){
		return x.base() == y.base();
	}

	template <typename T, typename U>
	bool operator==(const const_RBiterator<T>& x, const const_RBiterator<U>& y){
		return x.base() == y.base();
	}

	template <typename T, typename U>
	bool operator!=(const RBiterator<T>& x, const RBiterator<U>& y){
		return !(x == y);
	}

	template <typename T, typename U>
	bool operator!=(const const_RBiterator<T>& x, const const_RBiterator<U>& y){
		return !(x == y);
	}

	template <typename T, typename U>
	bool operator!=(const RBiterator<T>& x, const const_RBiterator<U>& y){
		return !(x == y);
	}

	template <typename T, typename U>
	bool operator!=(const const_RBiterator<T>& x, const RBiterator<U>& y){
		return !(x == y);
	}

	// // /* ******************************************************************** */
	// // /* non member operator overload reverse iterators						*/
	// // /* ******************************************************************** */	

	// template <typename LeftIterator, typename RightIterator>
	// bool operator==(const RBreverse_iterator<LeftIterator>& x, 
	// 	const RBreverse_iterator<RightIterator>& y){
	// 	return x.base() == y.base();
	// }

	// template <typename LeftIterator, typename RightIterator>
	// bool operator==(const RBreverse_iterator<LeftIterator>& x, 
	// 	const const_RBreverse_iterator<RightIterator>& y){
	// 	return x.base() == y.base();
	// }

	// template <typename LeftIterator, typename RightIterator>
	// bool operator==(const const_RBreverse_iterator<LeftIterator>& x, 
	// 	const RBreverse_iterator<RightIterator>& y){
	// 	return x.base() == y.base();
	// }

	// template <typename LeftIterator, typename RightIterator>
	// bool operator==(const const_RBreverse_iterator<LeftIterator>& x, 
	// 	const const_RBreverse_iterator<RightIterator>& y){
	// 	return x.base() == y.base();
	// }

	// template <typename LeftIterator, typename RightIterator>
	// bool operator!=(const RBreverse_iterator<LeftIterator>& x, 
	// 	const RBreverse_iterator<RightIterator>& y){
	// 	return !(x == y);
	// }

	// template <typename LeftIterator, typename RightIterator>
	// bool operator!=(const const_RBreverse_iterator<LeftIterator>& x, 
	// 	const const_RBreverse_iterator<RightIterator>& y){
	// 	return !(x == y);
	// }

	// template <typename LeftIterator, typename RightIterator>
	// bool operator!=(const RBreverse_iterator<LeftIterator>& x, 
	// 	const const_RBreverse_iterator<RightIterator>& y){
	// 	return !(x == y);
	// }

	// template <typename LeftIterator, typename RightIterator>
	// bool operator!=(const const_RBreverse_iterator<LeftIterator>& x, 
	// 	const RBreverse_iterator<RightIterator>& y){
	// 	return !(x == y);
	// }

	// // template <typename LeftIterator, typename RightIterator>
	// // bool operator==(const RBreverse_iterator<LeftIterator>& x, 
	// // 	const RBreverse_iterator<RightIterator>& y){
	// // 	return x.base() == y.base();
	// // }

	// // template <typename LeftIterator, typename RightIterator>
	// // bool operator!=(const RBreverse_iterator<LeftIterator>& x, 
	// // 	const RBreverse_iterator<RightIterator>& y){
	// // 	return !(x == y);
	// // }

	// // template <typename LeftIterator, typename RightIterator>
	// // bool operator==(const const_RBreverse_iterator<LeftIterator>& x, 
	// // 	const const_RBreverse_iterator<RightIterator>& y){
	// // 	return x.base() == y.base();
	// // }

	// // template <typename LeftIterator, typename RightIterator>
	// // bool operator!=(const const_RBreverse_iterator<LeftIterator>& x, 
	// // 	const const_RBreverse_iterator<RightIterator>& y){
	// // 	return !(x == y);
	// // }
	
}


#endif