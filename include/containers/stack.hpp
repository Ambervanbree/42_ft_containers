/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:05:50 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/16 15:07:33 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <memory>
# include <cstddef>
# include "vector.hpp"
// # include <deque> // << Uncomment to test with std::deque<T> in stead of ft::vector<T>

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		public:

			/* **************************************************************************** */
			/* types and definitions														*/
			/* **************************************************************************** */

			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type 	size_type;
			typedef Container 						container_type;
			
		protected:
		
			/* **************************************************************************** */
			/* variables																	*/
			/* **************************************************************************** */		
		
			container_type c;

		public:
		
			/* **************************************************************************** */
			/* member functions																*/
			/* **************************************************************************** */	
		
			explicit stack(const container_type& cont = container_type()) : c(cont) {}

			~stack(void){}
			
			stack& operator=(const stack& x) { c = x.c; return *this; }
			
			bool empty() const { return c.empty(); }
			
			size_type size() const { return c.size(); }

			value_type& top() { return c.back(); }

			const value_type& top() const { return c.back(); }

			void push(const value_type& x) { c.push_back(x); }
			
			void pop() { c.pop_back(); }
			
			/* **************************************************************************** */
			/* Non-member operators															*/
			/* **************************************************************************** */	
			
			// Operator overload functions are a binary equation of 2 elements. To compare
			// two elements of any container we need acces to the private variables, which
			// only member functions have. But operator overloads can't be member functions
			// (that would add *this as a variable and it wouldn't be binary). To solve this
			// issue we add the friend declaration. If a function is declared friend it has
			// acces to the private and protected variables of its associated class. 
			
			friend bool operator==(const ft::stack<T, container_type>& x, 
				const ft::stack<T, container_type>& y){
				return x.c == y.c;
			}
		
			friend bool operator<(const stack<T, container_type>& x, 
				const stack<T, container_type>& y){
				return x.c < y.c;
			}
			
			friend bool operator!=(const stack<T, container_type>& x, 
				const stack<T, container_type>& y){
				return x.c != y.c;
			}
			
			friend bool operator>(const stack<T, container_type>& x, 
				const stack<T, container_type>& y){
				return x.c > y.c;
			}
			
			friend bool operator>=(const stack<T, container_type>& x, 
				const stack<T, container_type>& y){
				return x.c >= y.c;
			}
			
			friend bool operator<=(const stack<T, container_type>& x, 
				const stack<T, container_type>& y){
				return x.c <= y.c;
			}
	};	
}

#endif
