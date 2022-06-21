/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:13:19 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/20 18:42:06 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
# define FT_HPP

# define RESET   "\033[0m"
# define GREEN	 "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define CYAN    "\033[36m"
# define RED     "\033[31m"
# define MAGENTA "\033[35m"
# define LINE    "\033[4m"
# define BOLD    "\e[1m"

# include "vector.hpp"
# include <iostream>
# include <memory>

namespace ft {
	template <class T1, class T2>		struct pair;
	template <class T1, class T2>		ft::pair<T1, T2> 	make_pair(const T1& x, const T2& y);
	template < class T, class Alloc >	class vector;
}

#endif