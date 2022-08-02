/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:24:39 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/02 17:53:58 by avan-bre         ###   ########.fr       */
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
				// first = T1(other.first);
				second = other.second;
			}
			return *this;
		}
// TODO --------------->> this is not good
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