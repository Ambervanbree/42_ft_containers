/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:30:28 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/16 10:00:41 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATORS_HPP
#define REVERSE_ITERATORS_HPP

#include "iterator_traits.hpp"

namespace ft {
	template <class iterator>
	class reverse_iterator {

		public:

			/* **************************************************************************** */
			/* types and definitions														*/
			/* **************************************************************************** */
			
			typedef typename	ft::iterator_traits<iterator>::difference_type 	difference_type;
			typedef typename	ft::iterator_traits<iterator>::reference		reference;
			typedef typename	ft::iterator_traits<iterator>::pointer			pointer;
			
		protected:
		
			/* **************************************************************************** */
			/* variables																	*/
			/* **************************************************************************** */
		
			iterator _current;
			
		public:

			/* **************************************************************************** */
			/* constructors																	*/
			/* **************************************************************************** */

								reverse_iterator() : _current() {}

			explicit 			reverse_iterator(const iterator & x) : _current(x) {}
			
			template <class U> 	reverse_iterator(const reverse_iterator<U>& u)
									: _current(u.base()) {}

			/* **************************************************************************** */
			/* element access																*/
			/* **************************************************************************** */

			iterator 			base() const {return _current; }									// explicit
	
			/* **************************************************************************** */
			/* member operator overload														*/
			/* **************************************************************************** */		
			
			reference 			operator*(void) const {
								iterator tmp = _current; return *--tmp; 
			}
			
			pointer				operator->(void) const {return &(operator* ()); }
			
			reverse_iterator&	operator++(void) {--_current; return *this; }
			
			reverse_iterator	operator++(int) {
								reverse_iterator tmp(*this); --_current; return tmp; 
			}

			reverse_iterator&	operator--(void) {++_current; return *this; }
			
			reverse_iterator	operator--(int) {
								reverse_iterator tmp(*this); ++_current; return tmp; 
			}
			
			reverse_iterator 	operator+ (difference_type n) const {
								return reverse_iterator(_current - n); 
			}

			reverse_iterator& 	operator+=(difference_type n) {_current -= n; return *this; }

			reverse_iterator 	operator- (difference_type n) const {
								return reverse_iterator(_current + n); 
			}

			reverse_iterator& 	operator-=(difference_type n) {_current += n; return *this; }

			reference 			operator[](difference_type n) const {
								return _current[- n - 1]; 
			}
			
	};

	/* **************************************************************************** */
	/* member operator overload														*/
	/* **************************************************************************** */

	// Because it should be possible to have a const iterator as lhs and a non const
	// iterator as rhs or vice versa, I used a template with two iterator classes.

	template <typename LeftIterator, typename RightIterator>
	bool operator==(const reverse_iterator<LeftIterator>& x, 
		const reverse_iterator<RightIterator>& y){
		return x.base() == y.base();
	}

	template <typename LeftIterator, typename RightIterator>
	bool operator<(const reverse_iterator<LeftIterator>& x, 
		const reverse_iterator<RightIterator>& y){
		return x.base() > y.base();
	}

	template <typename LeftIterator, typename RightIterator>
	bool operator!=(const reverse_iterator<LeftIterator>& x, 
		const reverse_iterator<RightIterator>& y){
		return x.base() != y.base();
	}

	template <typename LeftIterator, typename RightIterator>
	bool operator>( const reverse_iterator<LeftIterator>& x, 
		const reverse_iterator<RightIterator>& y){
		return x.base() < y.base();
	}

	template <typename LeftIterator, typename RightIterator>
	bool operator>=(const reverse_iterator<LeftIterator>& x, 
		const reverse_iterator<RightIterator>& y){
		return x.base() <= y.base();
	}

	template <typename LeftIterator, typename RightIterator>
	bool operator<=(const reverse_iterator<LeftIterator>& x, 
		const reverse_iterator<RightIterator>& y){
		return x.base() >= y.base();
	}

	template <typename LeftIterator, typename RightIterator>
	typename reverse_iterator<LeftIterator>::difference_type 
		operator-(const reverse_iterator<LeftIterator>& x, 
		const reverse_iterator<RightIterator>& y){
		return y.base() - x.base();
	}

	template <typename Iterator>
	reverse_iterator<Iterator> 
		operator+(typename reverse_iterator<Iterator>::difference_type n, 
		const reverse_iterator<Iterator>& x){
		return reverse_iterator<Iterator>(x.base() - n);
	}
	
}

#endif