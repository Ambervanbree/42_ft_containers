/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBnode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:25:13 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/17 17:51:53 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP

# define LEFT  0
# define RIGHT 1
# define _left  _child[LEFT]
# define _right _child[RIGHT]

namespace ft{
	enum	color_t {RED, BLACK, ORANGE};
	
	template <class T>
	struct RBnode{
	
		/* **************************************************************************** */
		/* types and definitions														*/
		/* **************************************************************************** */
			
		typedef T									value_type;
		typedef ft::RBnode<T>						node_type;
		typedef node_type *							node_ptr;
		typedef const node_type *					const_node_ptr;
		typedef node_type &							node_ref;
		typedef size_t								size_type;
		typedef const node_type &					const_node_ref;

		/* **************************************************************************** */
		/* variables																	*/
		/* **************************************************************************** */

		node_ptr		_parent;
		node_ptr		_child[2];
		color_t			_color;
		value_type		_content;
		bool			_dummy;

		/* **************************************************************************** */
		/* construct, copy, destruct													*/
		/* **************************************************************************** */	

		RBnode(const value_type value) : 
			_parent(NULL), 
			_color(RED), 
			_content(value),
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
		
		/* **************************************************************************** */
		/* visualisation																*/
		/* **************************************************************************** */	
		
		void print_contents(){
			std::cout << "Content: " << _content.first << 
				" => " << _content.second << std::endl;
			std::cout << "Dummy? " << _dummy << std::endl;
			std::cout << "Color: " << _color << std::endl;
			if (_parent){
				std::cout << "Parent: " << _parent->_content.first << std::endl;
				if (_parent->_left)
					std::cout << "Parent's left child: " 
					<< _parent->_left->_content.first << std::endl;
				if (_parent->_right)
					std::cout << "Parent's right child: " 
					<< _parent->_right->_content.first << std::endl;
			}
			if (_left){
				if (_left->_dummy)
					std::cout << "Left child: dummy" << std::endl;
				else{
					std::cout << "Left child: " << _left->_content.first << std::endl;
					std::cout << "Left child's parent: " 
					<< _left->_parent->_content.first << std::endl;
				}
			}
			if (_right){
				if (_right->_dummy)
					std::cout << "Right child: dummy" << std::endl;
				else{
					std::cout << "Right child: " << _right->_content.first << std::endl;
					std::cout << "Right child's parent: " 
					<< _right->_parent->_content.first << std::endl;
				}
			}
			std::cout << std::endl;
		}

		void print_contents_set(){
			std::cout << "Content: " << _content << std::endl;
			std::cout << "Dummy? " << _dummy << std::endl;
			std::cout << "Color: " << _color << std::endl;
			if (_parent){
				std::cout << "Parent: " << _parent->_content << std::endl;
				if (_parent->_left)
					std::cout << "Parent's left child: " 
					<< _parent->_left->_content << std::endl;
				if (_parent->_right)
					std::cout << "Parent's right child: " 
					<< _parent->_right->_content << std::endl;
			}
			if (_left){
				if (_left->_dummy)
					std::cout << "Left child: dummy" << std::endl;
				else{
					std::cout << "Left child: " << _left->_content << std::endl;
					std::cout << "Left child's parent: " 
					<< _left->_parent->_content << std::endl;
				}
			}
			if (_right){
				if (_right->_dummy)
					std::cout << "Right child: dummy" << std::endl;
				else{
					std::cout << "Right child: " << _right->_content << std::endl;
					std::cout << "Right child's parent: " 
					<< _right->_parent->_content << std::endl;
				}
			}
			std::cout << std::endl;
		}
		
		/* **************************************************************************** */
		/* node operations																*/
		/* **************************************************************************** */
		
		node_ptr min_value(){
			node_ptr current = this;

			while (current->_left != NULL && !current->_dummy)
				current = current->_left;
			return current;
		}
		
		node_ptr max_value(){
			node_ptr current = this;

			while (current->_right && !current->_dummy)
				current = current->_right;
			return current;
		}
		
		node_ptr successor(){
			if (_dummy)
				return _right;
			if (_right != NULL)
				return _right->min_value();
			else{
				node_ptr 	parent 	= _parent;
				node_ptr 	current = this;
				
				while(parent != NULL && current == parent->_right){
					current = parent;
					parent = parent->_parent;
				}
				return parent;
			}
		}

		node_ptr predecessor(){
			if (_dummy)
				return _left;
			if (_left != NULL)
				return _left->max_value();
			else{
				node_ptr 	parent 	= _parent;
				node_ptr	current	= this;
				
				while(parent != NULL && current == parent->_left){
					current = parent;
					parent = parent->_parent;
				}
				return parent;
			}
		}
	};

	/* **************************************************************************** */
	/* non member operators															*/
	/* **************************************************************************** */

	template <class T>
	bool	operator<(const RBnode<T>& x, const RBnode<T>& y){
		return (x._content < y._content);
	}
}

#endif