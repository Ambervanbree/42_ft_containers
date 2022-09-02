/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:33:06 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/02 11:37:55 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft{
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, 
		InputIt2 first2, InputIt2 last2){
		for ( ; (first1 != last1) && (first2 != last2) ; ++first1, (void) ++first2 ){
			// std::cout << "first1 : " << first1->first << " => " << first1->second << std::endl;
			// std::cout << "first2 : " << first2->first << " => " << first2->second << std::endl;
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, 
		InputIt2 first2, InputIt2 last2, Compare comp){
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);		
	}
}

#endif


// Returns: true if the sequence of elements defined by the 
// range [first1, last1) is lexicographically less than the 
// sequence of elements defined by the range [first2, last2).