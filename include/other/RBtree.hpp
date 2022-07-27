/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:57:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/27 16:34:43 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

# include <iostream>
# include <memory>
# include <cassert>
# include "pair.hpp"

# define LEFT  0
# define RIGHT 1
# define _left  _child[LEFT]
# define _right _child[RIGHT]
# define childDir(N) ( N == (N->_parent)->_right ? RIGHT : LEFT )

namespace ft{
	enum	color_t {RED, BLACK};
	
	template <class T, class Compare>
	struct RBnode{

			/* ******************************************************************** */
			/* types and definitions												*/
			/* ******************************************************************** */
			
			typedef T									value_type;
			typedef ft::RBnode<T, Compare>				node_type;
			typedef node_type *							node_ptr;
			typedef node_type &							node_ref;
			typedef const node_type &					const_node_ref;
			typedef Compare								value_compare;

			/* ******************************************************************** */
			/* variables															*/
			/* ******************************************************************** */

			node_ptr		_parent;
			node_ptr		_child[2];
			color_t			_color;
			value_type		_content;
			value_compare	_comp;

			/* ******************************************************************** */
			/* constructors															*/
			/* ******************************************************************** */

			RBnode(value_type value, value_compare &comp = Compare()) :
				_parent(NULL), _color(RED), _content(value), _comp(comp){
				_left = NULL;
				_right = NULL;
			}
			
			node_ref operator=(const_node_ref x){
				_comp = x._comp;
				_content = x._content;
				_color = x._color;
				_parent = x._parent;
				_left = x._left;
				_right = x._right;
				return *this;
			}
	};

	// // template <class key, class value>
	// node * create_node(int n){
	// 	node *new_node	= new node(n);
	// 	return new_node;
	// }

	template <class T, class Compare, class Allocator = std::allocator<T> >
	struct RBtree{
		
			/* ******************************************************************** */
			/* types and definitions												*/
			/* ******************************************************************** */
			
			typedef T									value_type;
			typedef RBtree<T, Compare, Allocator>		tree_type;
			typedef ft::RBnode<T, Compare>				node_type;
			typedef node_type *							node_ptr;
			typedef node_type &							node_ref;
			typedef tree_type *							tree_ptr;
			typedef tree_type &							tree_ref;
			typedef Allocator							allocator_type;
			typedef Compare								value_compare;
			typedef typename Allocator::template rebind<node_type>::other	node_allocator;


			/* ******************************************************************** */
			/* variables															*/
			/* ******************************************************************** */
			
			node_ptr									_root;
			node_allocator								_alloc;
			value_compare								_comp;
			
			/* ******************************************************************** */
			/* constructors															*/
			/* ******************************************************************** */
			
			RBtree() : _root(NULL), _alloc(node_allocator()), _comp(value_compare()){}
			
			/* ******************************************************************** */
			/* member functions														*/
			/* ******************************************************************** */
			
			node_ptr find_parent(node_ptr new_node){
				node_ptr	current = _root;
				
				while (1){
					node_ptr next = current->_child[_comp(current->_content, new_node->_content)];
					if (next == NULL)
						return current;
					else
						current = next;
				}
			}

			node_ptr rotate_dir(node_ptr current, int dir){
				node_ptr	grandma = current->_parent;
				node_ptr	daughter = current->_child[1 - dir];
				node_ptr	temp;

				assert(daughter != NULL);
				temp = daughter->_child[dir];
				current->_child[1 - dir] = temp;
				if (temp != NULL) {temp->_parent = current;}
				daughter->_child[dir] = current;
				current->_parent = daughter;
				daughter->_parent = grandma;
				if (grandma != NULL)
					grandma->_child[current == grandma->_right ? RIGHT : LEFT] = daughter;
				else
					_root = daughter;
				return daughter;
			}
			
			void insert_node(node_ptr current, node_ptr parent, int dir){
				node_ptr	grandma;
				node_ptr	aunt;
				
				current->_parent = parent;
				
				// Case 0: tree is empty, current becomes root.
				if (_root == NULL) {_root = current; return; }
				parent->_child[dir] = current;
				do{	
					// case 1: tree is valid, no action needed
					if (parent->_color == BLACK) {return; }	
				
					// case 4: parent is red and root, tree is not valid.
					// To balance the tree parent is repainted.
					if ((grandma = parent->_parent) == NULL){
						parent->_color = BLACK;
						return;
					}
					dir = childDir(parent);
					aunt = grandma->_child[1 - dir];
					
					// case 5 + 6: grandma exists and aunt is black or NULL,
					// we have to do a color flip (case 6). If the node is the inner grand 
					// child we put it between parent and grandparent first (case 5 + 6).
					if (aunt == NULL || aunt->_color == BLACK){
						if (current == parent->_child[1 - dir]){
							rotate_dir(parent, dir);
							current = parent;
							parent = grandma->_child[dir];
						}
						rotate_dir(grandma, 1 - dir);
						parent->_color = BLACK;
						grandma->_color = RED;
						return;
					}
					
					// case 2: we repaint grandma, aunt and parent. With these color changes
					// it's possible the tree becomes invalid higher up (connected red nodes).
					// Thus this process is repeated until the tree is balanced.
					parent->_color = BLACK;
					aunt->_color = BLACK;
					grandma->_color = RED;
					current = grandma;
				}while ((parent = current->_parent) != NULL);
			}

			// void delete_node(node_ptr current){
				
			// }

			void visualise(){
				visualise(_root, "", false);
			}

			void visualise(node_ptr node, std::string indent, bool right){
				if (node != NULL){
					std::cout << indent;
					if (right){
						std::cout << "R----";
						indent += "     ";
					}
					else{ 
						if (node != _root){
							std::cout << "L----";
							indent += "|    ";
						}
					}
					std::cout << node->_content << "(" << (node->_color ? "BLACK" : "RED") << ")" << std::endl;
					visualise(node->_left, indent, false);
					visualise(node->_right, indent, true);
				}
				
			}

	};
}

#endif
