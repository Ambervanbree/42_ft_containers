/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:46:13 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/16 10:01:06 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft{
	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> { typedef T type; };	
}

// The function takes a bool and a template, if the first condition
// is true, the type will be set. If the first condition is false,
// however (for example: enable_if<is_integral::iterator::type, iterator::type>),
// the type will not be set, so the function will fail, but because of
// SFINAE the compiler will not give an error, but it will look for the 
// next possible function to use. 

#endif