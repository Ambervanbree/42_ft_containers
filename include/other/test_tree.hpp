/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:57:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/22 12:48:12 by amber            ###   ########.fr       */
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
	
	template <class key, class value, class Allocator = std::allocator<ft::pair<key, value> > >
	struct node{
			typedef	node *		node_ptr;

			node_ptr				_parent;
			node_ptr				_child[2];
			color_t					_color;
			int						 _n;
			ft::pair<key, value>	_content;

			node(int n) : _n(n){
				_parent = NULL;
				_left = NULL;
				_right = NULL;
				_color = RED;
			}
			
			node & operator=(const node& x){
				_n = x._n;
				_parent = x._parent;
				_left = x._left;
				_right = x._right;
				return *this;
			}
	};

	template <class key, class value>
	node<key, value> * create_node(int n){
		node *new_node	= new node(n);
		return new_node;
	}

	class tree{
		public:
			typedef ft::node *		node_ptr;
			
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

			node_ptr rotate_dir(node_ptr parent, int dir){
				node_ptr	grandma = parent->_parent;
				node_ptr	daughter = parent->_child[1 - dir];
				node_ptr	temp;

				assert(daughter != NULL);
				temp = daughter->_child[dir];
				parent->_child[1 - dir] = temp;
				if (temp != NULL) {temp->_parent = parent;}
				daughter->_child[dir] = parent;
				parent->_parent = daughter;
				daughter->_parent = grandma;
				if (grandma != NULL)
					grandma->_child[parent == grandma->_right ? RIGHT : LEFT] = daughter;
				else
					_root = daughter;
				return daughter;
			}
			
		void insert_node(node_ptr current, node_ptr parent, int dir){
			current->_parent = parent;
			if (_root == NULL) {
				_root = current;
				std::cout << "Node with n " << current->_n << " is now root " << std::endl;
				return ;
				}
			parent->_child[dir] = current;
			do{	
				// case 1
				if (parent->_color == BLACK) {return; }	
				node_ptr	grandma = parent->_parent;
				// case 4 (parent is now red)
				if (grandma == NULL){
					parent->_color = BLACK;
					return;
				}
				dir = childDir(parent);
				node_ptr	aunt = grandma->_child[1 - dir];
				
				// case 5 + 6 (grandma exists)
				if (aunt == NULL || aunt->_color == BLACK){
					std::cout << "in aunt black " << current->_n << " dir " << dir << std::endl;
					// if the node is the inner grand child we put it between parent and grandparent
					// before we do the color flip
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
				// case 2, aunt, parent and grandma can be repainted
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
				std::cout << node->_n << "(" << (node->_color ? "BLACK" : "RED") << ")" << std::endl;
				visualise(node->_left, indent, false);
				visualise(node->_right, indent, true);
			}
			
		}

		private:
			node_ptr	_root;
	};
}

#endif