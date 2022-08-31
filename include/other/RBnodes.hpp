#ifndef RBNODES_HPP
# define RBNODES_HPP

# include <iostream>
# include "pair.hpp"

namespace ft{
	enum	color_t {RED, BLACK, ORANGE};
	
	template <class T>
	struct RBnode{

			/* ******************************************************************** */
			/* types and definitions												*/
			/* ******************************************************************** */
			
			// typedef T									value_type;
			typedef ft::RBnode<T>						node_type;
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
			value_type		_content;
			bool			_dummy;					
	}
}

#endif