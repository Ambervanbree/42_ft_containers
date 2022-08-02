/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:57:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/02 18:23:24 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

# include <iostream>
# include <memory>
# include <cassert>
# include "pair.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "RBiterators.hpp"

# define LEFT  0
# define RIGHT 1
# define _left  _child[LEFT]
# define _right _child[RIGHT]
# define childDir(N) ( N == (N->_parent)->_right ? RIGHT : LEFT )

namespace ft{
	enum	color_t {RED, BLACK};
	
	template <class T>
	struct RBnode{

			/* ******************************************************************** */
			/* types and definitions												*/
			/* ******************************************************************** */
			
			typedef T									value_type;
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
			size_type		_depth;

			/* ******************************************************************** */
			/* constructors															*/
			/* ******************************************************************** */

			RBnode(value_type value) : 
				_parent(NULL), 
				_color(RED), 
				_content(value) { 
				_left = NULL; 
				_right = NULL;
			}
			
			RBnode() :
				_parent(NULL), 
				_color(RED), 
				_content() {
				_left = NULL;
				_right = NULL;
			}

			void print_contents(){
				std::cout << "Content: " << _content << std::endl;
				std::cout << "Color: " << _color << std::endl;
				if (_parent)
					std::cout << "Parent: " << _parent->_content << std::endl;
				if (_left)
					std::cout << "Left child: " << _left->_content << std::endl;
				if (_right)
					std::cout << "Right child: " << _right->_content << std::endl;
				std::cout << std::endl;
			}

			/* ******************************************************************** */
			/* accessors															*/
			/* ******************************************************************** */
			
			node_ptr min_value(){
				node_ptr current = this;

				while (current->_left != NULL)
					current = current->_left;
				return current;
			}
			
			node_ptr max_value(){
				node_ptr current = this;

				while (current->_right != NULL)
					current = current->_right;
				return current;
			}
			
			node_ptr successor(){
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

			friend bool operator==(const RBnode& x, const RBnode& y){
			if ((x._color != y._color) ||
				(x._content != y._content) ||
				(x._parent != y._parent) ||
				(x._child[0] != y._child[0]) ||
				(x._child[1] != y._child[1])) {return false; }
			return true;
			}

			friend bool operator!=(const RBnode& x, const RBnode& y){
			return !(x == y);
			}
	};

	template <class T, class Compare, class Allocator = std::allocator<T> >
	struct RBtree{
		
			/* ******************************************************************** */
			/* types and definitions												*/
			/* ******************************************************************** */
			
			typedef T									value_type;
			typedef RBtree<T, Compare, Allocator>		tree_type;
			typedef ft::RBnode<T>						node_type;
			typedef node_type *							node_ptr;
			typedef node_type &							node_ref;
			typedef tree_type *							tree_ptr;
			typedef tree_type &							tree_ref;
			typedef size_t								size_type;
			typedef Allocator							allocator_type;
			typedef Compare								key_compare;
			typedef ft::RBiterator<node_type>			iterator;
			typedef ft::RBiterator<node_type>			const_iterator;
			typedef typename Allocator::template 
							rebind<node_type>::other	node_allocator;


			/* ******************************************************************** */
			/* variables															*/
			/* ******************************************************************** */
			
			node_ptr									_root;
			node_ptr									_dummy;
			node_allocator								_alloc;
			key_compare									_comp;
			size_type									_height;
			
			/* ******************************************************************** */
			/* constructors															*/
			/* ******************************************************************** */
			
			RBtree(const key_compare &comp) : 
				_root(NULL),
				_alloc(node_allocator()), 
				_comp(comp), 
				_height(0) {
					_dummy = _alloc.allocate(1);
					_alloc.construct(_dummy, value_type());
				}

			~RBtree(void) {
					_alloc.destroy(_dummy);
					_alloc.deallocate(_dummy, 1);
				}
			
			/* ******************************************************************** */
			/* accessors															*/
			/* ******************************************************************** */
			
		 	node_ptr find_parent(node_ptr new_node){
				if (_root == NULL)
					return NULL;
				
				node_ptr	current = _root;
				node_ptr	next;
				
				while (1){
					next = current->_child[_comp(current->_content, new_node->_content)];
					
					if (next == NULL || next == _dummy)
						return current;
					else
						current = next;
				}
			}
			
			node_allocator get_allocator() const {return _alloc; }
			
			/* ******************************************************************** */
			/* iterators															*/
			/* ******************************************************************** */

			iterator		begin() {return iterator(_root->min_value()); }
			const_iterator	begin() const {return iterator(_root->min_value()); }
			iterator		end() {return iterator(_dummy); }
			const_iterator	end() const {return iterator(_dummy); }

			/* ******************************************************************** */
			/* insert and delete													*/
			/* ******************************************************************** */

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
				if (parent && parent->_right && parent->_right == _dummy){
					current->_right = _dummy;
					_dummy->_parent = current;
				}
				
				// Case 1: tree is empty, current becomes root.
				if (_root == NULL) {
					_root = current; 
					_root->_right = _dummy;
					_dummy->_parent = _root;
					return; }
				parent->_child[dir] = current;
				do{	
					// case 2: tree is valid, no action needed
					if (parent->_color == BLACK) {return; }	
				
					// case 3: parent is red and root, tree is not valid.
					// To balance the tree parent is repainted.
					if ((grandma = parent->_parent) == NULL){
						parent->_color = BLACK;
						return;
					}
					dir = childDir(parent);
					aunt = grandma->_child[1 - dir];
					
					// case 4 + 5: grandma exists and aunt is black or NULL,
					// we have to do a color flip (case 4). If the node is the inner grand 
					// child we put it between parent and grandparent first (case 4 + 5).
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
					
					// case 6: we repaint grandma, aunt and parent. With these color changes
					// it's possible the tree becomes invalid higher up (connected red nodes).
					// We repeat the process with a higher node until the tree is balanced.
					parent->_color = BLACK;
					aunt->_color = BLACK;
					grandma->_color = RED;
					current = grandma;
				}while ((parent = current->_parent) != NULL);
				// return iterator(current);
			}

			iterator delete_black_leaf(node_ptr current){
				node_ptr	parent 	= current->_parent;
				int			dir		= childDir(current); // safe, because current != _root
				node_ptr	sister;
				node_ptr	niece;
				node_ptr	far_niece;

				parent->_child[dir] = NULL;
				do{
					sister 		= parent->_child[1 - dir];
					niece 		= sister->_child[dir];
					far_niece	= sister->_child[1 - dir];

					// case 1: sister is red, we rotate so she will become the grandparent
					// and we can repaint the parent. This way we end up with a black
					// leaf root and we can continue the cycle until tree is balanced.
					if (sister->_color == RED){
						rotate_dir(parent, dir);
						parent->_color = RED;
						sister->_color = BLACK;
						// rotation moved sister up, niece becomes parent's other child.
						// We update the situation and make her children niece and far niece. 
						// We know sister is black, so we can fall through.
						sister = niece;
						far_niece = sister->_child[1 - dir];
						niece = sister->_child[dir];
					}
					
					// case 2: the inner child (niece) is red. We rotate so that niece comes
					// between parent and sister and flip colors. Sister becomes the new far
					// niece and is red, so we can continue our loop.
					if (niece && niece->_color == RED){
						rotate_dir(sister, 1 - dir);
						sister->_color = RED;
						niece->_color = BLACK;
						far_niece = sister;
						sister = niece;
					}
					
					// case 3: outer child (far niece) or both children are red. We rotate 
					// sister up and have parent and sister switch colors. Black height has 
					// been restored, we can return.
					if (far_niece && far_niece->_color == RED){
						rotate_dir(parent, dir);
						sister->_color = parent->_color;
						parent->_color = BLACK;
						far_niece->_color = BLACK;
						return iterator(current);
					}

					// case 4: both sister's children are black and parent is red. 
					// We balance the tree by flipping colors of parent and sister.
					if (parent->_color == RED){
						sister->_color = RED;
						parent->_color = BLACK;
						return iterator(current);
					}
					// case 5: repainting sister balances the subtree of parent, but
					// it will have one less black node than the rest of the tree.
					// We go a level up and iterate through until full tree is balanced.
					sister->_color = RED;
					current = parent;
					dir = childDir(current);
				} while ((parent = current->_parent) != NULL);
				return iterator(current);
			}

			iterator two_child_delete(node_ptr node){
				// if a node has 2 children, we are going to swap it with
				// its predecessor (if subtree direction is left) or else
				// with its successor. The swap makes that the node to be
				// deleted is now a leaf node, so we call delete on that.
				
				node_ptr	replace;
				
				if (node == _root){
					replace = _root->successor();
					if (replace->_color == BLACK) {replace = _root->predecessor(); }
				}
				else{
					int 	dir 	= childDir(node);
					
					if (dir == 1) {replace = node->predecessor(); }
					else {replace = node->successor(); }
				}
				std::swap(node->_content, replace->_content);
				return delete_node(replace);
			}
			
			iterator delete_node(node_ptr node){
				// For a node with 2 children, see function above. Else, if
				// a node has no children and is red or has one child
				// we can delete as if it was a normal BST. For the difficult
				// case: deleting a black leaf node, we use a special function.
				
				if (node->_left && node->_right) {return two_child_delete(node); }
				else if (!node->_left && !node->_right){
					std::cout << "position is " << node->_content.first << " color is " << node->_color << std::endl;
					if (node == _root) {_root = NULL; }
					else if (node->_color == RED) {
						int dir = childDir(node);
						node->_parent->_child[dir] = NULL;
					}
					else
						return delete_black_leaf(node);
				}
				else if (node->_left){
					node->_left->_color = BLACK;
					node->_left->_parent = node->_parent;
					node->_parent->_left = node->_left;
				}
				else if (node->_right){
					node->_right->_color = BLACK;
					node->_right->_parent = node->_parent;			
					node->_parent->_right = node->_right;
				}
				else
					std::cout << "Something is not right, black single child found" << std::endl;
				return iterator(node) ;
				// TODO delete node for real
			}

			/* ******************************************************************** */
			/* utils																*/
			/* ******************************************************************** */

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

			bool valid(){
				int 		black_height = 0;
				node_ptr 	current = _root;
				
				if (_root == NULL) {return true; }
				while (current != NULL){
					if (current->_color == BLACK) {black_height++;}
					current = current->_left;
				}
				if (valid(_root, 0, black_height) == false) {return false; }
				return true ;
			}

			bool valid(node_ptr node, int black_nodes, int black_height){
				if (node != NULL){
					if (node->_color == BLACK) {black_nodes++; }
					else{
						if (node->_parent && node->_parent->_color == RED) {
							return false ; 
						}
					}
					if (valid(node->_left, black_nodes, black_height) == false)
						return false;
					if (valid(node->_right, black_nodes, black_height) == false)
						return false;
				}
				if (black_nodes > black_height)
					return false ;
				return true ;
			}

	};
}

#endif
