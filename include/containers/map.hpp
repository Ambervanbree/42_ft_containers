/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:53:02 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/02 18:19:04 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include <map>
# include <iostream>
# include <algorithm>
# include "pair.hpp"
# include "RBtree.hpp"
# include "RBiterators.hpp"

namespace ft{
	template<class key, class value, class Compare = std::less<key>, class Allocator = std::allocator<ft::pair<const key, value> > >
	class map {
		public:
		
			/* ******************************************************************** */
			/* types and definitions												*/
			/* ******************************************************************** */
			
			typedef key												key_type;
			typedef value											mapped_type;
			typedef ft::pair<const key, value>						value_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef typename Allocator::reference					reference;
			typedef typename Allocator::const_reference				const_reference;
			typedef size_t											size_type;
			typedef size_t											difference_type;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;

			class value_compare : public std::binary_function<value_type, value_type, bool> {
				friend class map;
					protected:
						key_compare 	_comp;
						
						value_compare(key_compare c) : _comp(c) {}
					
					public:
						bool operator()(const value_type& x, const value_type& y) const {
							return _comp(x.first, y.first);
						}
			};

			typedef RBtree<value_type, value_compare, Allocator>	tree_type;
			typedef RBnode<value_type>								node_type;
			typedef node_type *										node_ptr;
			typedef ft::RBiterator<node_type>						iterator;
			typedef ft::RBiterator<node_type>						const_iterator;
			// typedef std::reverse_iterator<node_type>					reverse_iterator;
			// typedef std::reverse_iterator<node_type>			const_reverse_iterator;

			/* ******************************************************************** */
			/* construct, copy, destroy												*/
			/* ******************************************************************** */
			
			explicit map(const value_compare& comp = value_compare(key_compare()), const allocator_type& alloc = allocator_type()) :
			_size(0), _alloc(alloc), _tree(comp), _comp(comp) {}

		// 	template <class InputIterator>
		// 	map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());

		// 	map(const map<Key,T,Compare,Allocator>& x);
		
			~map(){ 
				erase(begin(), end());
			}
		
		// 	map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x);
		
			/* ******************************************************************** */
			/* iterators															*/
			/* ******************************************************************** */
			
			// iterator					begin() {return iterator(_tree._root->min_value()); }
			// const_iterator				begin() const {return iterator(_tree._root->min_value()); }
			// iterator					end() {return iterator(_tree._dummy); } // TODO should be the item after max value
			// const_iterator				end() const {return iterator(_tree._dummy); } // TODO should be the item after max value
			iterator 		begin() {return _tree.begin(); }
			const_iterator	begin() const {return _tree.begin(); }
			iterator 		end() {return _tree.end(); }
			const_iterator 	end() const {return _tree.end(); }
		
		
		// 	reverse_iterator			rbegin();
		// 	const_reverse_iterator		rbegin() const;
		// 	reverse_iterator			rend();
		// 	const_reverse_iterator		rend() const;

			/* ******************************************************************** */
			/* capacity																*/
			/* ******************************************************************** */
			
			bool empty() const {return _size < 1 ? 1 : 0; }
			size_type size() const {return _size; }
			size_type max_size() const {return _tree.get_allocator().max_size(); }
			
			/* ******************************************************************** */
			/* element access														*/
			/* ******************************************************************** */
			
			value& operator[](const key_type& x){
				return find(x)->second;
			}

			/* ******************************************************************** */
			/* modifiers															*/
			/* ******************************************************************** */
			
			ft::pair<iterator, bool> insert(const value_type& x){
				node_ptr		new_node;
				node_ptr		parent;
				int				dir 		= 0;
				iterator		it;

				new_node = _tree.get_allocator().allocate(1);
				_tree.get_allocator().construct(new_node, x);
				parent = _tree.find_parent(new_node);
				if (parent){
					dir = _comp(parent->_content, new_node->_content);
					if ((parent->_content.first == x.first )||
						(parent->_child[dir] && parent->_child[dir]->_content.first == x.first)){
						return (ft::make_pair(find(x.first), false));
// TODO ----------------->> dit is niet heel optimaal, want ik iterate twee keer door de boom
					}
				}
				_tree.insert_node(new_node, parent, dir);
				_size++;
				return ft::make_pair(iterator(new_node), true);
			}
			
			// iterator insert(iterator position, const value_type& x){
			// 	_tree.insert_node(*position, *(position->_parent), 0);
			// }
			
		// 	template <class InputIterator> 
		// 	void insert(InputIterator first, InputIterator last);

			void erase(iterator position){
				// iterator deleted = 
				_tree.delete_node(*position);
				// _tree.get_allocator().destroy(*deleted);
				// _tree.get_allocator().deallocate(*deleted, 1);
				_size--;
// TODO ---->> dit werkt, behalve dat dus die nodes niet goed geswapt worden.
			}

		// 	size_type erase(const key_type& x);
			void erase(iterator first, iterator last){
				for(; first != last; first++)
					erase(first);
			}
			
		// 	void swap(map<Key,T,Compare,Allocator>&);
		// 	void clear();
		
			/* ******************************************************************** */
			/* observers															*/
			/* ******************************************************************** */
			
		// 	key_compare key_comp() const;
		// 	value_compare value_comp() const;

			/* ******************************************************************** */
			/* map operations														*/
			/* ******************************************************************** */
			
			iterator find(const key_type& x){
				iterator	it 		= begin();
				iterator	ite 	= end();
				key_compare	comp	= key_compare();

				for(; it != ite; it++){
					if (!comp(it->first, x) && !comp(x, it->first))
						return it;
				}
				return ite;
			}
			
		// 	const_iterator find(const key_type& x) const;
		// 	size_type count(const key_type& x) const;
		// 	iterator lower_bound(const key_type& x);
		// 	const_iterator lower_bound(const key_type& x) const;
		// 	iterator upper_bound(const key_type& x);
		// 	const_iterator upper_bound(const key_type& x) const;

		// 	pair<iterator,iterator> equal_range(const key_type& x);
		// 	pair<const_iterator,const_iterator> equal_range(const key_type& x) const;

			/* ******************************************************************** */
			/* non member operators													*/
			/* ******************************************************************** */

			// template <class Key, class T, class Compare, class Allocator>
			// friend bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

			// template <class Key, class T, class Compare, class Allocator>
			// friend bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

			// template <class Key, class T, class Compare, class Allocator>
			// friend bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

			// template <class Key, class T, class Compare, class Allocator>
			// friend bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

			// template <class Key, class T, class Compare, class Allocator>
			// friend bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

			// template <class Key, class T, class Compare, class Allocator>
			// friend bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

			/* ******************************************************************** */
			/* specialised algorithms												*/
			/* ******************************************************************** */
			
			// template <class Key, class T, class Compare, class Allocator>
			// friend void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y);
			
			/* ******************************************************************** */
			/* variables															*/
			/* ******************************************************************** */
			
			private:
				size_type										_size;
				allocator_type									_alloc;
				RBtree<value_type, value_compare, Allocator>	_tree;
				value_compare									_comp;
		};
		
}

#endif