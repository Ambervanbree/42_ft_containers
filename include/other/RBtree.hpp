/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:26:58 by amber             #+#    #+#             */
/*   Updated: 2022/07/21 15:57:23 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

# include "pair.hpp"
# include <memory>

# define NIL   NULL // null pointer  or  pointer to sentinel node
# define LEFT  0
# define RIGHT 1
# define left  child[LEFT]
# define right child[RIGHT]

namespace ft{
	enum	color_t {BLACK, RED};

	template <class key, class value>
	class RBnode{
		RBnode					*parent;
		RBnode					*child[2];
		color_t					color;
		ft::pair<key, value>	content;
		
		// RBnode() {
		// 	left = NIL;
		// 	right = NIL;
		// 	color = RED;
		// }

		// RBnode(key Key, value Value) {
		// 	content = ft::make_pair(Key, Value);
		// 	left = NIL;
		// 	right = NIL;
		// 	color = RED;
		// }
	};

	template <class key, class value, class Allocator = std::allocator<ft::pair<const key, value> >
	class RBtree{
		RBnode<key, value>		*root;

		RBtree(const Allocator& alloc){
			
		}
	};
}
	// template<class key, class value>
	// struct RBnode<key, value> *RB_find_parent(RBtree<key, value> *T, struct RBnode<key, value> *N){
	// 	// if ()
	// 	// while (T->)
	// }

// 	template <class key, class value>
// 	void	RB_insert_one(RBtree<key, value> *T, RBnode<key, value> *N, RBnode<key, value> *P, int dir){
// 		// N->color = RED;
// 		// N->left = NIL;
// 		// N->right = NIL;
// 		// N->parent = P;

// 		if (P == NULL) {
// 			T->root = N; return;
// 		}
// 		P->child[dir] = N;
// 		if (P->parent == NULL) {
// 			P->color = BLACK; return; 
// 		}

// 		// if ()
// 	}
// }



// 		struct RBnode	*G;
// 		struct RBnode	*A;
		
// 		N->color = RED;
// 		N->left = NIL;
// 		N->right = NIL;
// 		N->parent = P;

			// 		if (P == NULL)
			// 			T->root = N; return ;
			// 		P->child[dir] = N;
			// 		do{
			// 			if (P->color == BLACK) {return; }
			// 			if ((G = P->parent) == NULL) {goto Case_I4; }
			// 			dir = childDir(P);
			// 			A = G->child[1 - dir];
			// 			if (A == NULL || A->color == BLACK) {goto Case_I56; }
// 			P->color = BLACK;
// 			A->color = BLACK;
// 			G->color = RED;
// 			N = G;
// 		} while ((P = N->parent) != NULL);
// 		return ;
// 		Case_I4:
// 			P->color = BLACK; return ; // parent is root and RED, change parent to BLACK
// 		Case_I56
// 			if (N == P->child[1 - dir]){
// 				RotateDir(P, dir);
// 				N = P;
// 				P = G->child[dir];
// 			}
// 			RotateDirRoot(T, G, 1 - dir);
// 			P->color = BLACK;
// 			G->color = RED;
// 			return ;
// 	}
// }

#endif


/*
	-> Case I1:		P is BLACK, N is RED
					Tree is valid, no action needed
	-> Case I4: 	P is RED, P is root
					Change color P to BLACK
	-> Case I56: 	P is RED, Aunt is black
		Case I5:	If N is inner grand child
						N becomes right child of G, P becomes left child of N
						N becomes BLACK
		Case I6:	If N is outer grand child (can be through Case I5)
						Rotate P to G position, G becomes right child, N left
						P becomes BLACK, G becomes RED
	-> Case I2: 	P is RED, Aunt is RED
	-> Case I3:		N is the root, N is RED
					Tree is valid, return
*/