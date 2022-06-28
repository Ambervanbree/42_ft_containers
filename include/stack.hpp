/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:05:50 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/28 11:30:07 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <vector>
# include <memory>
# include <cstddef>

namespace ft {
	template <class T, class Container = std::vector<T> >
	class stack {

	public:
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef Container container_type;

		friend bool operator==(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y){
			return x.c == y.c;
		}
	
		friend bool operator<(const stack<T, Container>& x, const stack<T, Container>& y){
			return x.c < y.c;
		}
		
		friend bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y){
			return x.c != y.c;
		}
		
		friend bool operator>(const stack<T, Container>& x, const stack<T, Container>& y){
			return x.c > y.c;
		}
		
		friend bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y){
			return x.c >= y.c;
		}
		
		friend bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y){
			return x.c <= y.c;
		}

	protected:
		Container c;

	public:
		explicit stack(const Container& = Container()) {}
		
		bool empty() const { return c.empty(); }

		size_type size() const { return c.size(); }
		
		value_type& top() { return c.back(); }

		const value_type& top() const { return c.back(); }
		
		void push(const value_type& x) { c.push_back(x); }
	
		void pop() { c.pop_back(); }
		
		
	};
	
}

#endif