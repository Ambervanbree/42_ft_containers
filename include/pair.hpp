/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:24:39 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/20 18:50:58 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include "ft.hpp"

template <class T1, class T2>
struct ft::pair {
	typedef T1	first_type;
	typedef T2	second_type;
	
	T1	first;
	T2	second;
	
	pair() : first(0), second(0) {};
	
	pair(const T1& x, const T2& y) : first(x), second(y) {};
	
	template<class U, class V> 
	pair(const pair<U, V> &p) : first(p.first), second(p.second) {};
	
	pair& operator=(const pair& other) {
		this->first = other.first;
		this->second = other.second;
		return *this;
	};
};

template <class T1, class T2>
bool 	operator==(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y){
	return x.first == y.first && x.second == y.second;
}

template< class T1, class T2 >
bool 	operator!=(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y){
	return !(x.first == y.first && x.second == y.second);
};

template <class T1, class T2>
bool	operator<(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y){
	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
};

template <class T1, class T2>
bool	operator>(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y){
	return x.first > y.first || (!(y.first > x.first) && x.second > y.second);
};

template <class T1, class T2>
bool	operator<=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y){
	return x.first <= y.first || (!(y.first <= x.first) && x.second <= y.second);
};

template <class T1, class T2>
bool	operator>=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y){
	return x.first >= y.first || (!(y.first >= x.first) && x.second >= y.second);
};

template <class T1, class T2>
ft::pair<T1, T2> 	ft::make_pair(const T1& x, const T2& y){
	return ft::pair<T1, T2> (x, y);
};

#endif