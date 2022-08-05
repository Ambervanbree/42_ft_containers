/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:57:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/05 17:57:40 by avan-bre         ###   ########.fr       */
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
# define LEFT_NON_NIL (node->_left && !node->_left->_dummy)
# define RIGHT_NON_NIL (node->_right && !node->_right->_dummy)
# define LEFT_NIL (!node->_left || node->_left->_dummy)
# define RIGHT_NIL (!node->_right || node->_right->_dummy)

namespace ft{
	enum	color_t {RED, BLACK, ORANGE};
	
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
			bool			_dummy;

			/* ******************************************************************** */
			/* constructors															*/
			/* ******************************************************************** */

			RBnode(value_type value) : 
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

			void print_contents(){
				std::cout << "Content: " << _content.first << std::endl;
				std::cout << "Dummy? " << _dummy << std::endl;
				std::cout << "Color: " << _color << std::endl;
				if (_parent)
					std::cout << "Parent: " << _parent->_content.first << std::endl;
				if (_left)
					std::cout << "Left child: " << _left->_content.first << std::endl;
				if (_right)
					std::cout << "Right child: " << _right->_content.first << std::endl;
				std::cout << std::endl;
			}

			/* ******************************************************************** */
			/* accessors															*/
			/* ******************************************************************** */
			
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
			typedef ft::RBreverse_iterator<node_type>	reverse_iterator;
			typedef ft::RBreverse_iterator<node_type>	const_reverse_iterator;
			typedef typename Allocator::template 
							rebind<node_type>::other	node_allocator;


			/* ******************************************************************** */
			/* variables															*/
			/* ******************************************************************** */
			
			node_ptr									_root;
			node_ptr									_dummy;
			node_allocator								_alloc;
			key_compare									_comp;
			size_type									_size;
			size_type									_height;
			
			/* ******************************************************************** */
			/* constructors															*/
			/* ******************************************************************** */
			
			RBtree(const key_compare &comp) : 
				_root(NULL),
				_alloc(node_allocator()), 
				_comp(comp),
				_size(0),
				_height(0) {
					_dummy = _alloc.allocate(1);
					_alloc.construct(_dummy, value_type());
					_dummy->_dummy = true;
					_dummy->_color = ORANGE;
				}

			~RBtree(void) {
				clear_tree(_root); 
				_alloc.destroy(_dummy);
				_alloc.deallocate(_dummy, 1);
				_root = NULL;
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
					
					if (next == NULL || next->_dummy)
						return current;
					else
						current = next;
				}
			}
			
			node_allocator get_allocator() const {return _alloc; }
			
			/* ******************************************************************** */
			/* iterators															*/
			/* ******************************************************************** */

			iterator				begin() {
										if (_root == NULL)
											return iterator(_dummy);
										return iterator(_dummy->successor()); 
									}
			
			const_iterator			begin() const {									
										if (_root == NULL)
											return iterator(_dummy);
										return iterator(_dummy->successor()); 
									}
									
			iterator				end() {return iterator(_dummy); }
			const_iterator			end() const {return iterator(_dummy); }

			reverse_iterator		rbegin() {
										if (_root == NULL)
											return reverse_iterator(_dummy);
										return reverse_iterator(_dummy->predecessor()); 
									}
									
			const_reverse_iterator	rbegin() const {
										if (_root == NULL)
											return reverse_iterator(_dummy);
										return reverse_iterator(_dummy->predecessor());
									}
									
			reverse_iterator		rend() {return reverse_iterator(_dummy); }
			const_reverse_iterator	rend() const {return reverse_iterator(_dummy); }

			/* ******************************************************************** */
			/* insert																*/
			/* ******************************************************************** */

			ft::pair<iterator, bool> insert(const value_type& x){
				node_ptr	new_node;
				node_ptr	parent;
				int			dir  		= 0;
				iterator	it;

				new_node = _alloc.allocate(1);
				_alloc.construct(new_node, x);
				parent = find_parent(new_node);
				if (parent)
					dir = _comp(parent->_content, new_node->_content);
				insert_node(new_node, parent, dir);
				_size++;
				return ft::make_pair(iterator(new_node), true);
			}
			
			void insert_node(node_ptr current, node_ptr parent, int dir){
				node_ptr	grandma;
				node_ptr	aunt;

				current->_parent = parent;
				update_dummy(current, parent, dir);

				// Case 1: tree is empty, current becomes root.
				if (_root == NULL) {_root = current; return; }
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
					if (aunt && aunt->_dummy)
						aunt = NULL;
					
					// case 4 + 5: grandma exists and aunt is black or NULL,
					// we have to do a color flip (case 4). If the node is the inner grand 
					// child we put it between parent and grandparent first (case 4 + 5).
					if (aunt == NULL || aunt->_color == BLACK){
						if (current == parent->_child[1 - dir]){
							rotate_dir(parent, dir);
							current = parent;
							parent = grandma->_child[dir];
							if (parent->_dummy)
								parent = NULL;
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
			}

			void update_dummy(node_ptr current, node_ptr parent, int dir){
			// The dummy is an empty node, _left of the first node points to it
			// and _right of the last node too. With this node I create a memory
			// space that we can use with iterators end() and rend().
			
				if (_root == NULL){
					current->_right = _dummy;
					current->_left = _dummy;
					_dummy->_right = current;
					_dummy->_left = current;
				}
				if (parent){
					if (dir && parent->_right && parent->_right == _dummy){
						current->_right = _dummy;
						_dummy->_left = current;
					}
					if (!dir && parent->_left && parent->_left == _dummy){
						current->_left = _dummy;
						_dummy->_right = current;
					}
				}
			}	

			/* ******************************************************************** */
			/* delete																*/
			/* ******************************************************************** */
			
			node_ptr not_dummy_assignment(node_ptr node){
				if (node && !node->_dummy)
					return node;
				return NULL;
			}

			void delete_black_leaf(node_ptr current){
				node_ptr	parent 		= current->_parent;
				int			dir			= childDir(current); // safe, because current != _root
				node_ptr	sister;
				node_ptr	niece;
				node_ptr	far_niece;

				parent->_child[dir] = current->_child[dir]; 
				do{
					sister = not_dummy_assignment(parent->_child[1 - dir]);
					niece = not_dummy_assignment(sister->_child[dir]);
					far_niece = not_dummy_assignment(sister->_child[1 - dir]);

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
						sister = not_dummy_assignment(niece);
						far_niece = not_dummy_assignment(sister->_child[1 - dir]);
						niece = not_dummy_assignment(sister->_child[dir]);
					}
					
					// case 2: the inner child (niece) is red. We rotate so that niece comes
					// between parent and sister and flip colors. Sister becomes the new far
					// niece and is red, so we can continue our loop.
					if (niece && niece->_color == RED){
						rotate_dir(sister, 1 - dir);
						sister->_color = RED;
						niece->_color = BLACK;
						far_niece = not_dummy_assignment(sister);
						sister = not_dummy_assignment(niece);
					}
					
					// case 3: outer child (far niece) or both children are red. We rotate 
					// sister up and have parent and sister switch colors. Black height has 
					// been restored, we can return.
					if (far_niece && far_niece->_color == RED){
						rotate_dir(parent, dir);
						sister->_color = parent->_color;
						parent->_color = BLACK;
						far_niece->_color = BLACK;
						return ;
					}

					// case 4: both sister's children are black and parent is red. 
					// We balance the tree by flipping colors of parent and sister.
					if (parent->_color == RED){
						sister->_color = RED;
						parent->_color = BLACK;
						return ;
					}
					// case 5: repainting sister balances the subtree of parent, but
					// it will have one less black node than the rest of the tree.
					// We go a level up and iterate through until full tree is balanced.
					sister->_color = RED;
					current = parent;
					dir = childDir(current);
				} while ((parent = current->_parent) != NULL);
				
			}

			void two_child_delete(node_ptr node){
				// Node has 2 non nil children, so predecessor or successor
				// can't be the dummy node. We will now switch the node
				// with a successor (if dir is left) or a predecessor,
				// which will always be a leaf node. We then pass it through
				// delete_node again.
				
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
				swap_links(node, replace);
				delete_node(node);
			}
			
			void delete_node(node_ptr node){
				// For a node with 2 children, see function above. Else, if
				// a node has no children and is red or has one child
				// we can delete as if it was a normal BST. For the difficult
				// case: deleting a black leaf node, we use a special function.
				
				if (LEFT_NON_NIL && RIGHT_NON_NIL){
					two_child_delete(node);
				}
				else if (LEFT_NIL && RIGHT_NIL){
					if (node == _root) {_root = NULL; }
					else if (node->_color == RED) {
						int dir = childDir(node);
						update_dummy(node->_parent, node, dir);
					}
					else
						delete_black_leaf(node);
				}
				else if (LEFT_NON_NIL){
					node->_left->_color = BLACK;
					node->_left->_parent = node->_parent;
					if (node == _root){
						node->_left->_right = node->_right;
						_root = node->_left;
						if (node->_right && node->_right->_dummy)
							node->_right->_left = _root;
					}
					else
						update_dummy(node->_parent, node, LEFT);
				}
				else if (RIGHT_NON_NIL){
					node->_right->_color = BLACK;
					node->_right->_parent = node->_parent;
					if (node == _root){
						node->_right->_left = node->_left;
						_root = node->_right;
						if (node->_left && node->_left->_dummy)
							node->_left->_right = _root;
					}	
					else
						update_dummy(node->_parent, node, RIGHT);
				}
			}

			void erase(iterator position){				
				delete_node(*position);
				_alloc.destroy(*position);
				_alloc.deallocate(*position, 1);
				_size--;
			}

			/* ******************************************************************** */
			/* node utils															*/
			/* ******************************************************************** */

			bool equal_nodes(node_ptr node1, node_ptr node2){
				if (_comp(node1->_content, node2->_content))
					return false;
				if (_comp(node2->_content, node1->_content))
					return false;
				return true;
			}

			void swap_links(node_ptr node1, node_ptr node2){
				node_ptr	temp = _alloc.allocate(1);
				_alloc.construct(temp, value_type());

				if (_root == node1)
					_root = node2;
				else if (_root == node2)
					_root = node1;

				std::swap(node1->_color, node2->_color);
			
				temp->_parent	= node1->_parent;
				temp->_left 	= node1->_left;
				temp->_right	= node1->_right;
				
				node2->_parent == node1 ? node1->_parent = node2
					: node1->_parent = node2->_parent;
				node2->_left == node1 ? node1->_left = node2
					: node1->_left = node2->_left;
				node2->_right == node1 ? node1->_right = node2
					: node1->_right = node2->_right;

				temp->_parent == node2 ? node2->_parent = node1
					: node2->_parent = temp->_parent;		
				temp->_left == node2 ? node2->_left = node1
					: node2->_left = temp->_left;
				temp->_right == node2 ? node2->_right = node1
					: node2->_right = temp->_right;

				_alloc.destroy(temp);
				_alloc.deallocate(temp, 1);
			}

			/* ******************************************************************** */
			/* tree utils															*/
			/* ******************************************************************** */
			
			void clear_tree(){
				clear_tree(_root);
				_dummy->_right = NULL;
				_dummy->_left = NULL;
				_root = NULL;
			}
			
			void clear_tree(node_ptr subtree){		
				if (subtree && !subtree->_dummy){
					node_ptr next_left = subtree->_left;
					node_ptr next_right = subtree->_right;
					_alloc.destroy(subtree);
					_alloc.deallocate(subtree, 1);
					clear_tree(next_left);
					clear_tree(next_right);
				}
			}
			
			node_ptr rotate_dir(node_ptr current, int dir){
				node_ptr	grandma = current->_parent;
				node_ptr	daughter = current->_child[1 - dir];
				node_ptr	temp;

				assert(daughter != NULL && !daughter->_dummy);
				temp = daughter->_child[dir];
				if (temp && temp->_dummy)
					temp = NULL;
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
					std::cout << node->_content.first << "(";
						if (node->_color == 0)
							std::cout << "RED";			
						if (node->_color == 1)
							std::cout << "BLACK";					
						if (node->_color == 2)
							std::cout << "ORANGE";
						std::cout << ")" << std::endl;
					if (!node->_dummy)
						visualise(node->_left, indent, false);
					if (!node->_dummy)
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
