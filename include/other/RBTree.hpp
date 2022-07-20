/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:26:58 by amber             #+#    #+#             */
/*   Updated: 2022/07/20 08:35:56 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

# include "pair.hpp"

# define NIL   NULL // null pointer  or  pointer to sentinel node
# define LEFT  0
# define RIGHT 1
# define left  child[LEFT]
# define right child[RIGHT]

namespace ft{
	enum	color_t {BLACK, RED};

	template <class T, class U>
	struct RBnode{
		RBnode			*parent;
		RBnode			*child[2];
		color_t			color;
		ft::pair<T, U>	key;
	};

	template <class T, class U>
	struct RBtree{
		RBnode<T, U>	*root;
	};
}

#endif