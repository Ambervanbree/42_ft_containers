/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:57:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/17 18:06:43 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

# include <iostream>
# include <memory>
# include <cassert>
# include "pair.hpp"
# include "enable_if.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include "is_integral.hpp"
# include "RBiterators.hpp"
# include "reverse_iterators.hpp"
# include "RBnode.hpp"

# define LEFT  0
# define RIGHT 1
# define _left  _child[LEFT]
# define _right _child[RIGHT]
# define childDir(N) (N == (N->_parent)->_right ? RIGHT : LEFT)
# define LEFT_NON_NIL (node->_left && !node->_left->_dummy)
# define RIGHT_NON_NIL (node->_right && !node->_right->_dummy)
# define LEFT_NIL (!node->_left || node->_left->_dummy)
# define RIGHT_NIL (!node->_right || node->_right->_dummy)

namespace ft{
	template <class T, class Compare, class Allocator = std::allocator<T> >
	struct RBtree{
	
		/* **************************************************************************** */
		/* types and definitions														*/
		/* **************************************************************************** */
		
		typedef T											value_type;
		typedef RBtree<T, Compare, Allocator>				tree_type;
		typedef ft::RBnode<T>								node_type;
		typedef node_type *									node_ptr;
		typedef node_type &									node_ref;
		typedef tree_type *									tree_ptr;
		typedef tree_type &									tree_ref;
		typedef size_t										size_type;
		typedef Allocator									allocator_type;
		typedef Compare										key_compare;
		typedef ft::RBiterator<value_type>					iterator;
		typedef ft::const_RBiterator<value_type> 			const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef typename Allocator::template 
						rebind<node_type>::other			node_allocator;

		/* **************************************************************************** */
		/* variables																	*/
		/* **************************************************************************** */
		
		node_ptr			_root;
		node_ptr			_dummy;
		node_allocator		_alloc;
		key_compare			_comp;
		size_type			_size;

		/* **************************************************************************** */
		/* construct, copy, destruct													*/
		/* **************************************************************************** */		
		
		RBtree(const key_compare& comp) : 
			_root(NULL),
			_alloc(node_allocator()), 
			_comp(comp),
			_size(0) {
				_dummy = _alloc.allocate(1);
				_alloc.construct(_dummy, node_type());
				_dummy->_dummy = true;
				_dummy->_color = ORANGE;
				_dummy->_left = NULL;
				_dummy->_right = NULL;
				_dummy->_parent = NULL;
		}

		RBtree(const RBtree& x) : 
			_root(NULL),
			_alloc(node_allocator()),
			_comp(x._comp),
			_size(0) {
			_dummy = _alloc.allocate(1);
			_alloc.construct(_dummy, node_type());
			_dummy->_dummy = true;
			_dummy->_color = ORANGE;
			_dummy->_left = NULL;
			_dummy->_right = NULL;
			_dummy->_parent = NULL;
			*this = x;
		}

		~RBtree(void) {
			if (_size)
				clear_tree(_root); 
			_alloc.destroy(_dummy);
			_alloc.deallocate(_dummy, 1);
			_root = NULL;
		}

		RBtree<T, Compare, Allocator>& 
			operator=(const RBtree<T, Compare, Allocator> &x) {
			if (*this != x){
				if (_size)
					clear_tree();
				const_iterator it = x.begin(), ite = x.end();
				for (; it != ite; it++)
					insert(*it);
			}
			return *this;
		}

		node_allocator get_allocator() const {return _alloc; }
		
		/* **************************************************************************** */
		/* tree operations																*/
		/* **************************************************************************** */

		// Find_parent iterates through the tree recursively to find the leaf under
		// which the new key can be inserted. It also doubles as a find-function, to
		// make sure a key is not inserted if it already exists. When an equal key
		// is found, it returns a pair with an iterator to this element + a bool
		// false, to indicate that the new element should not be inserted. Else, it
		// returns a pair with an iterator to the element under which the new key can
		// be inserted (the parent) + a boolean true.
		
		ft::pair<iterator, bool> find_parent(const value_type& x, node_ptr subtree){	
			ft::pair<iterator, bool>	temp;				
			
			if (subtree && !subtree->_dummy){
				if (!(_comp(x, subtree->_content) || _comp(subtree->_content, x)))
					return ft::make_pair(iterator(subtree), false);
				else{
					int		next_dir = _comp(subtree->_content, x);
					if (subtree->_child[next_dir] == NULL 
						|| subtree->_child[next_dir]->_dummy)
						return ft::make_pair(iterator(subtree), true);
					else
						return find_parent(x, subtree->_child[next_dir]);
				}
			}
			return (ft::make_pair(end(), true));
		}

		// In the delete function we need to swap the content of two nodes when deleting
		// a black leaf. However, when the RBtree is used for ft::map, the value_type
		// is ft::pair<const key, value>. Because the key is const, it is not possible
		// to assign the content to another node. Therefore I have written the function
		// below which swaps all the pointers of two nodes. It will then have the same
		// memory space (so pointers and iterators will stay intact), but the place in
		// the tree will be swapped.

		void swap_links_leaf(node_ptr  node, node_ptr replace){
			node_ptr	node_parent = node->_parent;
			node_ptr	node_left = node->_left;
			node_ptr	node_right = node->_right;
			node_ptr	replace_parent = replace->_parent;
			node_ptr	replace_left = replace->_left;
			node_ptr	replace_right = replace->_right;

			std::swap(node->_color, replace->_color);
			
			// Node and replace can be connected in the tree, we have to make sure that
			// if we swap links, the node or replace node will not point to itself,
			// creating an infinite loop in later oprations. Because node will always
			// be higher up in the tree than replace, there's a few swaps we can do
			// without problems.
			int		dir_replace = childDir(replace); // safe, becaue replace != _root

			replace->_parent = node_parent;
			if (replace->_parent == NULL)
				_root = replace;
			else
				replace->_parent->_child[childDir(node)] = replace;
			node->_left = replace_left;
			if (node->_left && node->_left->_dummy)
				_dummy->_right = node;
			node->_right = replace_right;
			if (node->_right && node->_right->_dummy)
				_dummy->_left = node;

			// The following swaps depend on if two nodes are connected.
			if (node_left == replace){
				node->_parent = replace;
				replace->_left = node;
				replace->_right = node_right;
				replace->_right->_parent = replace;
			}
			else if (node_right == replace){
				node->_parent = replace;
				replace->_left = node_left;
				replace->_left->_parent = replace;
				replace->_right = node;
			}
			else{
				node->_parent = replace_parent;
				node->_parent->_child[dir_replace] = node;
				replace->_left = node_left;
				replace->_left->_parent = replace;
				replace->_right = node_right;
				replace->_right->_parent = replace;		
			}	
		}

		iterator find(value_type x, node_ptr subtree){
			iterator 	temp;
			iterator	ite = end();
			
			if (subtree && !subtree->_dummy){		
				if (!(_comp(x, subtree->_content) || _comp(subtree->_content, x)))
					return (iterator(subtree));
				else{
					int			dir = _comp(subtree->_content, x);
					
					if ((temp = find(x, subtree->_child[dir])) != ite)
						return temp;
				}
			}
			return ite;
		}

		const_iterator find(value_type x, node_ptr subtree) const{
			const_iterator 	temp;
			const_iterator	cite = end();
			
			if (subtree && !subtree->_dummy){		
				if (!(_comp(x, subtree->_content) || _comp(subtree->_content, x)))
					return (const_iterator(subtree));
				else{
					if ((temp = find(x, subtree->_left)) != cite)
						return temp;
					if ((temp = find(x, subtree->_right)) != cite)
						return temp;
				}
			}
			return cite;
		}

		void swap(tree_type &x){
			node_ptr	temp_root	= _root;
			node_ptr	temp_dummy	= _dummy;
			size_type	temp_size	= _size;

			_root 	= x._root;
			_dummy	= x._dummy;
			_size	= x._size;

			x._root		= temp_root;
			x._dummy	= temp_dummy;
			x._size		= temp_size;
		}
					
		node_ptr rotate_dir(node_ptr current, int dir){
			// This is the rotation funtion that is used in insert and delete.
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

		/* **************************************************************************** */
		/* iterators																	*/
		/* **************************************************************************** */

		iterator				begin() {
									if (_root == NULL)
										return iterator(_dummy);
									return iterator(_dummy->successor()); 
								}
		
		const_iterator			begin() const {									
									if (_root == NULL)
										return const_iterator(_dummy);
									return const_iterator(_dummy->successor()); 
								}
								
		iterator				end() {return iterator(_dummy); }
		const_iterator			end() const {return const_iterator(_dummy); }

		reverse_iterator		rbegin() {
									if (_root == NULL)
										return reverse_iterator(end());
									return reverse_iterator(end()--);
								}
								
		const_reverse_iterator	rbegin() const {
									if (_root == NULL)
										return const_reverse_iterator(end());
									return const_reverse_iterator(end()--);
								}
								
		reverse_iterator		rend() {return reverse_iterator(begin()); }
		const_reverse_iterator	rend() const {return const_reverse_iterator(begin()); }

		/* **************************************************************************** */
		/* modifiers: insert															*/
		/* **************************************************************************** */

		ft::pair<iterator, bool> insert(const value_type& x){
			ft::pair<iterator, bool>	found;

			found = find_parent(x, _root);
			if (!found.second)
				return found;
			
			node_ptr	new_node = _alloc.allocate(1);
			node_ptr	parent = NULL;
			int			dir = 0;

			_alloc.construct(new_node, node_type(x));
			if (found.first != end()){
				parent = found.first.base();
				dir = _comp(parent->_content, new_node->_content); 
			}
			insert_node(new_node, parent, dir);
			_size++;
			return ft::make_pair(iterator(new_node), true);
		}

		iterator insert(iterator hint, const value_type& x){
			hint = begin();

			return insert(x).first;
		}

		iterator insert(const_iterator hint, const value_type& x){
			hint = begin();

			return insert(x).first;
		}

		// A new node to be inserted will always be red. We then insert it
		// in the tree under its parent. If this node is red too, the tree
		// needs to be rebalanced.
		
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

		/* **************************************************************************** */
		/* modifiers: delete															*/
		/* **************************************************************************** */

		void erase(node_ptr node){
			delete_node(node);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			_size--;
		}

		// Deletion of a node generally works the same as for a regular tree. If the
		// node to be deleted has one child, we will connect it to node's parent (and vv)
		// and we can delete node. If it has no children, we can just delete it. And if
		// it has two children we will swap it with its successor or predecessor,
		// based on its location in the tree. The node then will only have one or zero
		// children and we delete it.
		// The only exception with a Red Black Tree is when a black node is deleted.
		// In that case, the current branch will have one black node less and the
		// tree needs to be rebalanced. See delete_black_leaf for this.

		void delete_node(node_ptr node){					
			if (LEFT_NON_NIL && RIGHT_NON_NIL){
				two_child_delete(node);
			}
			else if (LEFT_NIL && RIGHT_NIL){
				if (node == _root) {
					_root = NULL; 
					_dummy->_left = NULL;
					_dummy->_right = NULL;
				}
				else if (node->_color == RED)
					no_dummy_delete(node);
				else
					delete_black_leaf(node);
			}
			else if (LEFT_NON_NIL)
				one_child_delete(node, LEFT);
			else if (RIGHT_NON_NIL)
				one_child_delete(node, RIGHT);
		}

		/* **************************************************************************** */
		/* modifiers: delete utils														*/
		/* **************************************************************************** */

		void one_child_delete(node_ptr node, int dir){
			// Node has one child, since no two red nodes can follow each other, they
			// both have another color. We make sure that the node's child is black and
			// connect it to the parent of node to be deleted. Also, the node could be
			// connected to the _dummy, so we have to make sure it gets updated.
			node_ptr	child = node->_child[dir];
			
			child->_color = BLACK;
			child->_parent = node->_parent;
			if (node == _root)
				_root = child;
			else
				node->_parent->_child[childDir(node)] = child;
			if (node->_child[1 - dir]){
				child->_child[1 - dir] = _dummy;
				_dummy->_child[dir] = child;
			}
		}
		
		void two_child_delete(node_ptr node){
			// Node has two children, which means we will swap it with its successor
			// or predecessor as described earlier. Because it is possible that the node
			// is now a black leaf node, we pass it through the function delete_node
			// once more.
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
			swap_links_leaf(node, replace);
			delete_node(node);
		}

		void delete_black_leaf(node_ptr current){
			node_ptr	parent 		= current->_parent;
			int			dir			= childDir(current); // safe, because current != _root
			node_ptr	sister;
			node_ptr	niece;
			node_ptr	far_niece;
			
			no_dummy_delete(current);
			do{
				sister = no_dummy_assign(parent->_child[1 - dir]);
				niece = no_dummy_assign(sister->_child[dir]);
				far_niece = no_dummy_assign(sister->_child[1 - dir]);;

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
					sister = no_dummy_assign(niece);
					far_niece = no_dummy_assign(sister->_child[1 - dir]);
					niece = no_dummy_assign(sister->_child[dir]);
				}
				
				// case 2: the inner child (niece) is red. We rotate so that niece comes
				// between parent and sister and flip colors. Sister becomes the new far
				// niece and is red, so we can continue our loop.
				if (niece && niece->_color == RED){
					rotate_dir(sister, 1 - dir);
					sister->_color = RED;
					niece->_color = BLACK;
					far_niece = no_dummy_assign(sister);
					sister = no_dummy_assign(niece);
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
				if (current->_parent)
					dir = childDir(current);
			} while ((parent = current->_parent) != NULL);
		}

		/* **************************************************************************** */
		/* dummy operations																*/
		/* **************************************************************************** */
		
		// The _dummy is an empty node that is used as memory space for the commands
		// end() and rend(). The left child of the first element points to it, and the
		// right child of the last element. In return, the left child of the dummy
		// points to the last element and the right child to the first. This way, we can
		// iterate both ways without pointing to memory that isn't allocated.
		// Below functions are utils to update the dummy accordingly when executing
		// tree operations as insert and delete.

		void update_dummy(node_ptr current, node_ptr parent, int dir){
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

		node_ptr no_dummy_assign(node_ptr node){
			if (node && !node->_dummy)
				return node;
			return NULL;
		}

		void no_dummy_delete(node_ptr node){
			int	dir = childDir(node); //safe, because node can't be root

			node->_parent->_child[dir] = node->_child[dir];
			if (node->_child[dir] && node->_child[dir]->_dummy){
				_dummy->_child[1 - dir] = node->_parent;
			}
		}

		/* **************************************************************************** */
		/* modifiers: other																*/
		/* **************************************************************************** */
		
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
				_size--;
				clear_tree(next_left);
				clear_tree(next_right);
			}
		}

		/* **************************************************************************** */
		/* visualisation																*/
		/* **************************************************************************** */
		
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

		void visualise_set(){
			visualise_set(_root, "", false);
		}

		void visualise_set(node_ptr node, std::string indent, bool right){
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
				std::cout << node->_content << "(";
					if (node->_color == 0)
						std::cout << "RED";			
					if (node->_color == 1)
						std::cout << "BLACK";					
					if (node->_color == 2)
						std::cout << "ORANGE";
					std::cout << ")" << std::endl;
				if (!node->_dummy)
					visualise_set(node->_left, indent, false);
				if (!node->_dummy)
					visualise_set(node->_right, indent, true);
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
	
	/* **************************************************************************** */
	/* non member operators															*/
	/* **************************************************************************** */
	
	template <class T, class Compare, class Allocator>
	bool operator==(const RBtree<T, Compare, Allocator>& x,
		const RBtree<T, Compare, Allocator>& y) {
		if (x._size != y._size) return false; 
		return (ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <class T, class Compare, class Allocator>
	bool operator !=(const RBtree<T, Compare, Allocator>& x,
		const RBtree<T, Compare, Allocator>& y) {
		return !(x == y);
	}

	template <class T, class Compare, class Allocator>
	bool operator<(const RBtree<T, Compare, Allocator>& x,
		const RBtree<T, Compare, Allocator>& y) {
		return ft::lexicographical_compare(x.begin(), x.end(), 
			y.begin(), y.end());
	}
}

#endif