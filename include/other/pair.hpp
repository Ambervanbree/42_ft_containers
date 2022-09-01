/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:24:39 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/01 18:35:11 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft{
	template <class T1, class T2>
	struct pair {		
		T1	first;
		T2	second;
		
		pair() : first(T1()), second (T2()) {}
		
		pair(const T1& x, const T2& y) : first(x), second(y) {}
		
		template<class U, class V> 
		pair(const pair<U, V> &p) : first(p.first), second(p.second) {}
		
		pair& operator=(const pair& other) {
			if (*this != other){
				first = other.first;
				second = other.second;
			}
			return *this;
		}
	};

	template <class T1, class T2>
	bool 	operator==(const pair<T1, T2>& x, const pair<T1, T2>& y){
		return x.first == y.first && x.second == y.second;
	}

	template< class T1, class T2 >
	bool 	operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y){
		return !(x.first == y.first && x.second == y.second);
	}

	template <class T1, class T2>
	bool	operator<(const pair<T1, T2>& x, const pair<T1, T2>& y){
		std::cout << "blaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
		std::cout << "x.first < y.first " << (x.first < y.first) << std::endl;
		std::cout << "y.first < x.first " << (y.first < x.first) << std::endl;
		std::cout << "x.second < y.second " << (x.second < y.second) << std::endl;
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template <class T1, class T2>
	bool	operator>(const pair<T1, T2>& x, const pair<T1, T2>& y){
		return x.first > y.first || (!(y.first > x.first) && x.second > y.second);
	}

	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y){
		return x.first <= y.first || (!(y.first <= x.first) && x.second <= y.second);
	}

	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y){
		return x.first >= y.first || (!(y.first >= x.first) && x.second >= y.second);
	}

	template <class T1, class T2>
	pair<T1, T2> 	make_pair(const T1& x, const T2& y){
		return pair<T1, T2> (x, y);
	}
}

#endif