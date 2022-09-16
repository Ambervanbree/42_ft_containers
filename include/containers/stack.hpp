/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:05:50 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/16 09:58:58 by amber            ###   ########.fr       */
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
			
			//	The operator overloads are based on protected and/or private variablesof the 
			//	class, which they can't use, because they are not member functions. Adding
			//	the friend declaration to the class will grant these specific functions 
			//	access to the private and protected variables of the class it is associated 
			//	with.
			
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
