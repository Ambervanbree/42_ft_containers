/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:53:02 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/31 16:00:13 by avan-bre         ###   ########.fr       */
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
	template<class key, class value, class Compare = std::less<key>, 
		class Allocator = std::allocator<ft::pair<const key, value> > >
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
			typedef ft::RBreverse_iterator<node_type>				reverse_iterator;
			typedef ft::RBreverse_iterator<node_type>				const_reverse_iterator;


			/* ******************************************************************** */
			/* construct, copy, destroy												*/
			/* ******************************************************************** */
			
			explicit map(const value_compare& comp = value_compare(key_compare()), 
				const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _tree(comp), _comp(comp) {}

		// 	template <class InputIterator>
		// 	map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());

		// 	map(const map<Key,T,Compare,Allocator>& x);
		
			~map(){}
		
		// 	map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x);
		
			/* ******************************************************************** */
			/* iterators															*/
			/* ******************************************************************** */
			
			iterator 					begin() {return _tree.begin(); }
			const_iterator				begin() const {return _tree.begin(); }
			iterator 					end() {return _tree.end(); }
			const_iterator 				end() const {return _tree.end(); }
			reverse_iterator			rbegin() {return _tree.rbegin(); }
			const_reverse_iterator		rbegin() const {return _tree.rbegin(); }
			reverse_iterator			rend() {return _tree.rend(); }
			const_reverse_iterator		rend() const {return _tree.rend(); }

			/* ******************************************************************** */
			/* capacity																*/
			/* ******************************************************************** */
			
			bool empty() const {return _tree._size < 1 ? 1 : 0; }
			size_type size() const {return _tree._size; }
			size_type max_size() const {return _tree.get_allocator().max_size(); }
			
			/* ******************************************************************** */
			/* element access														*/
			/* ******************************************************************** */
			
			mapped_type& operator[](const key_type& x){
				return insert(ft::make_pair(x, mapped_type())).first->second;
			}

			void visualise(){
				_tree.visualise();
			}

// TODO -------------->> delete!!

			/* ******************************************************************** */
			/* modifiers															*/
			/* ******************************************************************** */
			
			ft::pair<iterator, bool> insert(const value_type& x){
				if (size()){
					iterator	found = find(x.first);
					if (found != end())
						return ft::make_pair(iterator(found), false);
				}
				return _tree.insert(x);
			}
			
		// 	template <class InputIterator> 
		// 	void insert(InputIterator first, InputIterator last);

			void erase(iterator position){
				_tree.erase(position);
			}

			size_type erase(const key_type& x){
				iterator	found = find(x);

				if (found != end()){
					_tree.erase(found);
					return 1;
				}
				return 0;
			}
			
			void erase(iterator first, iterator last){
				iterator	temp;

				while(first != last){
					temp = first;
					first++;
					_tree.erase(temp);
				}
			}
			
		// 	void swap(map<Key,T,Compare,Allocator>&);
		
			void clear(){_tree.clear_tree(); }
		
			/* ******************************************************************** */
			/* observers															*/
			/* ******************************************************************** */
			
			key_compare key_comp() const {return key_compare(); }
			value_compare value_comp() const {return _comp; }

			/* ******************************************************************** */
			/* map operations														*/
			/* ******************************************************************** */
			
			iterator find(const key_type& x){
				return _tree.find(ft::make_pair(x, mapped_type()), _tree._root);
			}
			
			const_iterator find(const key_type& x) const{
				return _tree.find(ft::make_pair(x, mapped_type()), _tree._root);		
			}
		
			size_type count(const key_type& x) const{
				if (find(x) != end())
					return 1;
				return 0;
			}
		
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
				allocator_type									_alloc;
				RBtree<value_type, value_compare, Allocator>	_tree;
				value_compare									_comp;
		};
		
}

#endif