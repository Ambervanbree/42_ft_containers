/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:57:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/26 17:45:08 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_TREE_HPP
#define TEST_TREE_HPP

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
	
	template <class key, class value>
	struct node{
			typedef	node *		node_ptr;

			node_ptr				_parent;
			node_ptr				_child[2];
			color_t					_color;
			ft::pair<key, value>	_content;

			node<key, value> (key Key, value Value){
				_content = ft::make_pair(Key, Value);
				_parent = NULL;
				_left = NULL;
				_right = NULL;
				_color = RED;
			}
			
			node & operator=(const node& x){
				// _n = x._n;
				_content = x._content;
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

	template <class key, class value>
	struct tree{
			node_ptr							_root;
		
			typedef ft::node<key, value> *			node_ptr;	
			
			tree() {_root = NULL; }
			node_ptr get_root() {return _root; }

			node_ptr find_parent(node_ptr new_node){
				node_ptr	current = _root;
				
				while (1){
					node_ptr next = current->_child[current->_n < new_node->_n];
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
			// If tree is empty, current becomes root.
			if (_root == NULL) {_root = current; return; }
			parent->_child[dir] = current;
			do{	
				// case 1: tree is valid, no action needed
				if (parent->_color == BLACK) {return; }	
			
				// case 4: parent is red and root, parent changes color
				// and tree is balanced
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
				// it's possible multiple red nodes follow each other. To check that
				// we iterate through the tree until the top or until it's balanced.
				parent->_color = BLACK;
				aunt->_color = BLACK;
				grandma->_color = RED;
				current = grandma;
			}while ((parent = current->_parent) != NULL);
		}

		void visualise(node_ptr node, std::string indent, bool last){
			if (node != NULL){
				std::cout << indent;
				if (last){
					std::cout << "R----";
					indent += "     ";
				}
				else{
					std::cout << "L----";
					indent += "|    ";
				}
				std::cout << node->_content.first << "(" << (node->_color ? "BLACK" : "RED") << ")" << std::endl;
				visualise(node->_left, indent, false);
				visualise(node->_right, indent, true);
			}
			
		}

	};
}

#endif
