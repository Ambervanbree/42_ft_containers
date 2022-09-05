/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBnodes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:22:03 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/05 09:33:14 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP

# include <iostream>

namespace ft{
	template <class T>
	struct RBnode{

		/* ******************************************************************** */
		/* types and definitions												*/
		/* ******************************************************************** */
		
		typedef T									value_type;
		typedef ft::RBnode<T>						node_type;
		typedef ft::RBcontent<T>					data_ptr;
		typedef node_type *							node_ptr;
		typedef node_type &							node_ref;
		typedef size_t								size_type;
		typedef const node_type &					const_node_ref;
		
		/* ******************************************************************** */
		/* variables															*/
		/* ******************************************************************** */

		node_ptr		_parent;
		node_ptr		_child[2];
		color_t			_color;
		data_ptr		_data;
		bool			_dummy;		

		/* ******************************************************************** */
		/* constructors															*/
		/* ******************************************************************** */

		RBnode(const value_type value) : 
			_parent(NULL), 
			_color(RED), 
			_data(value)
			_dummy(false) { 
			_left = NULL; 
			_right = NULL;
		}
		
		RBnode() :
			_parent(NULL), 
			_color(RED), 
			_content(),
			_dummy(false) {
			_left = NULL;
			_right = NULL;
		}

	};


	template <class T>
	struct RBcontent{

		/* ******************************************************************** */
		/* types and definitions												*/
		/* ******************************************************************** */
		
		typedef T									value_type;
		typedef ft::RBcontent<T>					data_type;
		typedef data_type *							data_ptr;
		typedef data_type &							data_ref;
		typedef size_t								size_type;
		typedef const data_type &					const_data_ref;

				/* ******************************************************************** */
		/* variables															*/
		/* ******************************************************************** */

		value_type		_content;
	}
}


#endif