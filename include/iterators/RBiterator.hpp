/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBiterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:51:10 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/29 10:58:50 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBITERATOR_HPP
# define RBITERATOR_HPP

#include <iostream>

namespace ft{
	template <class T>
	class RBiterator{

		/* ******************************************************************** */
		/* variables															*/
		/* ******************************************************************** */

		protected:
			iteratory_type	current;

		/* ******************************************************************** */
		/* types and definitions												*/
		/* ******************************************************************** */

		public:
			typedef			 RBiterator									iterator_type;
			typedef typename ft::iterator_traits<T*>::value_type		value_type;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
		
		explicit
			
	}
}

#endif