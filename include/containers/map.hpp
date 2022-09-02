/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:53:02 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/02 16:23:36 by avan-bre         ###   ########.fr       */
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
				_alloc(alloc), _tree(comp), _vcomp(comp), _kcomp(key_compare()) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, 
				const value_compare& comp = value_compare(key_compare()), 
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc), _tree(comp), _vcomp(comp), _kcomp(key_compare()) {
					insert(first, last);
			}

			map(const map<key, value, Compare, Allocator>& x) :
				_tree(x._tree), _vcomp(x._vcomp) {
				*this = x;
			}
		
			~map(){}
		
			map<key, value, Compare, Allocator>& 
				operator=(const map<key, value, Compare, Allocator>& x){
				if (*this != x){
					if (size()){ 
						_tree.clear_tree();
					}
					insert(x.begin(), x.end());
				}
				return *this;
			}
		
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

// TODO -------------->> delete!!

			void visualise() {_tree.visualise(); }

			void print_contents(){
				iterator it = begin();
				iterator ite = end();

				for (; it != ite; it++)
					(*it)->print_contents();
			}

// TODO -------------->> delete!!

			/* ******************************************************************** */
			/* modifiers															*/
			/* ******************************************************************** */
			
			ft::pair<iterator, bool> insert(const value_type& x){
				iterator	found = _tree.find(x, _tree._root);

				if (found != end())
					return ft::make_pair(found, false);
				return _tree.insert(x);
			}

			iterator insert(iterator hint, const value_type& x){
				iterator	found = _tree.find(x, _tree._root);

				if (found != end())
					return found;
				return _tree.insert(hint, x);
			}
			
			template <class InputIterator> 
			void insert(InputIterator first, InputIterator last){
				while (first != last)
					_tree.insert(*first++);
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
				iterator	temp;

				while(first != last){
					temp = first;
					first++;
					_tree.erase(temp.base());
				}
			}
			
		 	void swap(map<key, value, Compare, Allocator> &x){
				_tree.swap(x._tree);
			}
		
			void clear() {_tree.clear_tree(); }
		
			/* ******************************************************************** */
			/* observers															*/
			/* ******************************************************************** */
			
			key_compare 	key_comp() const {return _kcomp; }
			value_compare 	value_comp() const {return _vcomp; }

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
		
			iterator lower_bound(const key_type& x){
				iterator	it = begin();
				iterator	ite = end();
				
				while (it != ite && _kcomp(it->first, x)){
					it++;
				}
				return it;
			}
			
			const_iterator lower_bound(const key_type& x) const{
				const_iterator	it = begin();
				const_iterator	ite = end();
				
				while (it != ite && _kcomp(it->first, x)){
					it++;
				}
				return it;
			}
			
			iterator upper_bound(const key_type& x){
				iterator	it = begin();
				iterator	ite = end();
				
				while (it != ite && !_kcomp(x, it->first)){
					it++;
				}
				return it;			
			}
			
			const_iterator upper_bound(const key_type& x) const{
				const_iterator	it = begin();
				const_iterator	ite = end();
				
				while (it != ite && !_kcomp(x, it->first)){
					it++;
				}
				return it;						
			}

			pair<iterator,iterator> equal_range(const key_type& x){
				return ft::make_pair(lower_bound(x), upper_bound(x));
			}
			
			pair<const_iterator,const_iterator> equal_range(const key_type& x) const{
				return ft::make_pair(lower_bound(x), upper_bound(x));
			}

			/* ******************************************************************** */
			/* non member operators													*/
			/* ******************************************************************** */

			friend bool operator==(const map<key, value, Compare, Allocator>& x,
				const map<key, value, Compare, Allocator>& y) {
				return x._tree == y._tree;
			}

			friend bool operator< (const map<key, value, Compare, Allocator>& x,
				const map<key, value, Compare, Allocator>& y){
				return x._tree < y._tree;
			}

			friend bool operator!=(const map<key, value, Compare, Allocator>& x,
				const map<key, value, Compare, Allocator>& y){
				return !(x._tree == y._tree);	
			}

			friend bool operator>(const map<key, value, Compare, Allocator>& x,
				const map<key, value, Compare, Allocator>& y){
				return !(x._tree < y._tree) && !(x._tree == y._tree);
			}

			friend bool operator>=(const map<key, value, Compare, Allocator>& x,
				const map<key, value, Compare, Allocator>& y){
					return !(x._tree < y._tree);
				}

			friend bool operator<=(const map<key, value, Compare, Allocator>& x,
				const map<key, value, Compare, Allocator>& y){
				return (x._tree < y._tree) || (x._tree == y._tree);
			}

			/* ******************************************************************** */
			/* specialised algorithms												*/
			/* ******************************************************************** */
			
			friend void swap(map<key, value, Compare, Allocator>& x, 
				map<key, value, Compare, Allocator>& y) {x.swap(y); }
			
			/* ******************************************************************** */
			/* variables															*/
			/* ******************************************************************** */
			
			private:
				allocator_type									_alloc;
				RBtree<value_type, value_compare, Allocator>	_tree;
				value_compare									_vcomp;
				key_compare										_kcomp;
		};
		
}

#endif