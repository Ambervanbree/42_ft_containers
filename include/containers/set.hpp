/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:08:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/16 10:08:13 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <functional>
# include <memory>
# include <map>
# include <iostream>
# include <algorithm>
# include "pair.hpp"
# include "RBtree.hpp"
# include "RBiterators.hpp"
# include "reverse_iterators.hpp"

namespace ft {
	template <class key, class Compare = std::less<key>,
		class Allocator = std::allocator<key> >
	class set {
		public:

			/* **************************************************************************** */
			/* types and definitions														*/
			/* **************************************************************************** */
			
			typedef key												key_type;
			typedef key												value_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef Allocator										allocator_type;
			typedef typename Allocator::reference					reference;
			typedef typename Allocator::const_reference				const_reference;
			typedef RBtree<value_type, value_compare, Allocator>	tree_type;
			typedef RBnode<value_type>								node_type;
			typedef node_type *										node_ptr;
			typedef ft::const_RBiterator<value_type>				iterator;
			typedef ft::const_RBiterator<value_type> 				const_iterator;
			typedef size_t											size_type;
			typedef size_t											difference_type;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef ft::reverse_iterator<const_iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			/* **************************************************************************** */
			/* construct, copy, destruct													*/
			/* **************************************************************************** */

			explicit set(const key_compare& comp = key_compare(), 
				const allocator_type& alloc= allocator_type()) :
				_alloc(alloc), _tree(comp), _comp(comp) {}

			template <class InputIterator>
			set(InputIterator first, InputIterator last, 
				const key_compare& comp = key_compare(), 
				const allocator_type& alloc= allocator_type()) :
				_alloc(alloc), _tree(comp), _comp(comp) {
					insert(first, last);
			}

			set(const set<key, Compare, Allocator>& x) :
				_tree(x._tree), _comp(x._comp) {
				*this = x;	
			}

			~set(){};

			set<key, Compare, Allocator>& 
				operator=(const set<key, Compare, Allocator>& x){
				if (*this != x){
					if (size()){ 
						_tree.clear_tree();
					}
					insert(x.begin(), x.end());
				}
				return *this;				
			}

			allocator_type get_allocator() const {return _alloc; }

			/* **************************************************************************** */
			/* iterators																	*/
			/* **************************************************************************** */
			
			iterator 					begin() {return _tree.begin(); }
			
			const_iterator				begin() const {return _tree.begin(); }
			
			iterator 					end() {return _tree.end(); }

			const_iterator 				end() const {return _tree.end(); }

			reverse_iterator			rbegin() {return _tree.rbegin(); }

			const_reverse_iterator		rbegin() const {return _tree.rbegin(); }

			reverse_iterator			rend() {return _tree.rend(); }
			
			const_reverse_iterator		rend() const {return _tree.rend(); }

			/* **************************************************************************** */
			/* capacity																		*/
			/* **************************************************************************** */	
			
			bool empty() const {return _tree._size < 1 ? 1 : 0; }

			size_type size() const {return _tree._size; }
			
			size_type max_size() const {return _tree.get_allocator().max_size(); }

			/* **************************************************************************** */
			/* modifiers																	*/
			/* **************************************************************************** */

			pair<iterator, bool> insert(const value_type& x){
				return _tree.insert(x);	
			}
			
			iterator insert(iterator hint, const value_type& x){
				return _tree.insert(hint, x);
			}
			
			template <class InputIterator> 
			void insert(InputIterator first, InputIterator last){
				while (first != last)
					insert(*first++);
			}

			void erase(iterator position){_tree.erase(position.base()); }

			size_type erase(const key_type& x){
				iterator	found = find(x);

				if (found != end()){
					_tree.erase(found.base());
					return 1;
				}
				return 0;
			}

			void erase(iterator first, iterator last){				
				key_type	to_delete 	= *first;
				key_type	last_key	= *last;
				key_type	next_key;

				while (to_delete != last_key){
					next_key = *upper_bound(to_delete);
					erase(to_delete);
					to_delete = next_key;
				}
			}

			void swap(set<key, Compare, Allocator>& x){
				_tree.swap(x._tree);
			}

			void clear() {_tree.clear_tree(); }


			/* **************************************************************************** */
			/* observers																	*/
			/* **************************************************************************** */
			
			key_compare 	key_comp() const {return _comp; }
			
			value_compare 	value_comp() const {return _comp; }


			/* **************************************************************************** */
			/* set operations																*/
			/* **************************************************************************** */
			
			iterator find(const key_type& x) const{
				return _tree.find(x, _tree._root);
			}

			size_type count(const key_type& x) const{
				if (find(x) != end())
					return 1;
				return 0;
			}

			iterator lower_bound(const key_type& x) const{
				iterator	it = begin();
				iterator	ite = end();
				
				while (it != ite && _comp(*it, x)){
					it++;
				}
				return it;
			}

			iterator upper_bound(const key_type& x) const{
				iterator	it = begin();
				iterator	ite = end();
				
				while (it != ite && !_comp(x, *it)){
					it++;
				}
				return it;			
			}

			pair<iterator,iterator> equal_range(const key_type& x) const{
				return ft::make_pair(lower_bound(x), upper_bound(x));
			}

			/* **************************************************************************** */
			/* non member operators															*/
			/* **************************************************************************** */

			friend bool operator==(const set<key, Compare, Allocator>& x,
				const set<key, Compare, Allocator>& y) {
				return x._tree == y._tree;
			}

			friend bool operator< (const set<key, Compare, Allocator>& x,
				const set<key, Compare, Allocator>& y){
				return x._tree < y._tree;
			}

			friend bool operator!=(const set<key, Compare, Allocator>& x,
				const set<key, Compare, Allocator>& y){
				return !(x._tree == y._tree);	
			}

			friend bool operator>(const set<key, Compare, Allocator>& x,
				const set<key, Compare, Allocator>& y){
				return !(x._tree < y._tree) && !(x._tree == y._tree);
			}

			friend bool operator>=(const set<key, Compare, Allocator>& x,
				const set<key, Compare, Allocator>& y){
					return !(x._tree < y._tree);
				}

			friend bool operator<=(const set<key, Compare, Allocator>& x,
				const set<key, Compare, Allocator>& y){
				return (x._tree < y._tree) || (x._tree == y._tree);
			}

			/* **************************************************************************** */
			/* specialised algorithms														*/
			/* **************************************************************************** */
			
			void swap(set<key, Compare, Allocator>& x, 
				set<key, Compare, Allocator>& y) {x.swap(y); }

			/* **************************************************************************** */
			/* variables																	*/
			/* **************************************************************************** */
			
			private:
				allocator_type									_alloc;
				RBtree<value_type, value_compare, Allocator>	_tree;
				key_compare										_comp;
	};

}

#endif