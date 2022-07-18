/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:30:28 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/16 17:09:13 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATORS_HPP
#define REVERSE_ITERATORS_HPP

#include "iterator_traits.hpp"

namespace ft {
	template <class Iterator>
	class reverse_iterator {

		protected:
			Iterator current;

		public:
			typedef 			Iterator										iterator_type;
			typedef typename	ft::iterator_traits<Iterator>::difference_type 	difference_type;
			typedef typename	ft::iterator_traits<Iterator>::reference		reference;
			typedef typename	ft::iterator_traits<Iterator>::pointer			pointer;

								reverse_iterator() : current() {}
			explicit 			reverse_iterator(Iterator x) : current(x) {}
			template <class U> 	reverse_iterator(const reverse_iterator<U>& u) : current(u.current) {}
			
			Iterator 			base() const {return current; }									// explicit
			reference 			operator*(void) const {iterator_type tmp = current; return *--tmp; }
			pointer				operator->(void) const {return &(operator* ()); }
			
			reverse_iterator&	operator++(void) {--current; return *this; }
			reverse_iterator	operator++(int) {reverse_iterator tmp(*this); --current; return tmp; }
			reverse_iterator&	operator--(void) {++current; return *this; }
			reverse_iterator	operator--(int) {reverse_iterator tmp(*this); ++current; return tmp; }
			
			reverse_iterator 	operator+ (difference_type n) const {return reverse_iterator(current - n); }
			reverse_iterator& 	operator+=(difference_type n) {current -= n; return *this; }
			reverse_iterator 	operator- (difference_type n) const {return reverse_iterator(current + n); }
			reverse_iterator& 	operator-=(difference_type n) {current += n; return *this; }
			reference 			operator[](difference_type n) const {return current[- n - 1]; }

			friend bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y){
				return x.current == y.current;
			}

			friend bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y){
				return x.current > y.current;
			}

			friend bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y){
				return x.current != y.current;
			}

			friend bool operator>( const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y){
				return x.current < y.current;
			}

			friend bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y){
				return x.current <= y.current;
			}

			friend bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y){
				return x.current >= y.current;
			}

			friend typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y){
				return y.current - x.current;
			}

			friend reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x){
				return reverse_iterator<Iterator>(x.current - n);
			}
};

}

#endif