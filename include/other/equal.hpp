/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:03:16 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/16 10:01:15 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft{	
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2){
		for (; first1 != last1; ++first1, ++first2){
			if (!(*first1 == *first2)){
				return false;
			}
		}
		return true;	
	}

	template<class InputIt1, class InputIt2, class BinPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinPredicate pred){
		for (; first1 != last1; ++first1, ++first2) {
			if (!pred(*first1, *first2)) {
				return false;
			}
		}
		return true;	
	}
};

#endif

// Returns: true if for every iterator i in the range [first1, last1) 
// the following corresponding conditions hold: 
// *i == *(first2 + (i - first1)), pred(*i, *(first2 + (i - first1))) != false. 
// Otherwise, returns false.