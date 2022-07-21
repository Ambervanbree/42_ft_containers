/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:57:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/21 19:08:16 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_TREE_HPP
#define TEST_TREE_HPP

# include <iostream>
# include <memory>
# include <cassert>

# define LEFT  0
# define RIGHT 1
# define _left  _child[LEFT]
# define _right _child[RIGHT]
# define childDir(N) ( N == (N->_parent)->_right ? RIGHT : LEFT )

namespace ft{
	enum	color_t {RED, BLACK};
	
	struct node{
			// typedef	*node		node_ptr;

			node		*_parent;
			node		*_child[2];
			color_t		_color;
			int			_n;

			node(int n) : _n(n){
				std::cout << "Node initialised with n: " << _n << std::endl;
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

			// node *parent() {return _parent; }
			// node *child_left() {return _left; }
			// node *child_right() {return _right; }
			// color_t aunt_color() {
			// 	if (_parent->_child[LEFT] == NULL || _parent->_child[RIGHT] == NULL)
			// 		return BLACK;
			// 	if (_n == _parent->_child[LEFT]->_n)
			// 		return _parent->_child[RIGHT]->_color;
			// 	else
			// 		return _parent->_child[LEFT]->_color;
			// }

			// std::string color() {return _color ? "RED" : "BLACK"; }
			// int n() {return _n; }
			// void change_color(color_t color) {
			// 	_color = color; 
			// 	std::cout << "Color node with n " << _n << " changed to " << this->color() << std::endl;
			// 	return; 
			// }
			
			// void set_child(node *new_node, int dir) {
			// 	_child[dir] = new_node; 
			// 	std::cout << new_node->color() << " node with n " << new_node->n() << " is now child " 
			// 	<< dir << " of " << color() << " parent with n " << _n << std::endl;
			// 	return; }
				
			// void set_parent(node *parent){
			// 	_parent = parent; 
			// 	std::cout << "Node with n " << n() << " now has parent with n " 
			// 	<< parent->_n << std::endl;
			// 	return; }
	};

	node *create_node(int n){
		node *new_node	= new node(n);
		return new_node;
	}

	class tree{
		private:
			node	*_root;

		public:
			tree() {_root = NULL; }

		node *rotate_dir(node *parent, int dir){
			node	*grandma = parent->_parent;
			node	*daughter = parent->_child[1 - dir];
			node	*temp;

			assert(daughter != NULL);
			std::cout << " test test " << std::endl;
			temp = daughter->_child[dir];
			parent->_child[1 - dir] = temp;
			if (temp != NULL) {temp->_parent = parent;}
			daughter->_child[dir] = parent;
			std::cout << "daughter is not null " << daughter->_n << std::endl;
			parent->_parent = daughter;
			daughter->_parent = grandma;
			if (grandma != NULL)
				grandma->_child[parent == grandma->_right ? RIGHT : LEFT] = daughter;
			else
				_root = daughter;
			return daughter;
		}
			
		void insert_node(node *current, node *parent, int dir){
			current->_parent = parent;
			// case 1
			if (_root == NULL) {
				_root = current;
				std::cout << "Node with n " << current->_n << " is now root " << std::endl;
				return ;
				}
			parent->_child[dir] = current;
			node	*grandma = parent->_parent;
			
			// case 4 (parent is now red)
			if (grandma == NULL){
				parent->_color = BLACK;
				return;
			}
			dir = childDir(parent);
			node	*aunt = grandma->_child[1 - dir];
			
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
		}

		void visualise(node *node, std::string indent, bool last){
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
	};
}



#endif


	// // Print tree
	// void    _recursive_print(node_ptr node, std::string indent, bool last) const
	// {
	// 	if (!is_nil(node))
	// 	{
	// 		std::cout << indent;
	// 		if (last)
	// 		{
	// 			std::cout << "R----";
	// 			indent += "     ";
	// 		}
	// 		else
	// 		{
	// 			std::cout << "L----";
	// 			indent += "|    ";
	// 		}
	// 		std::string sColor = node->color ? "BLACK" : "RED";
	// 		std::cout << node->value << "(" << sColor << ")" 
	// 					<< std::endl;
	// 		this->_recursive_print(node->child[LEFT], indent, false);
	// 		this->_recursive_print(node->child[RIGHT], indent, true);
	// 	}
	// }