/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:53:02 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/26 17:32:21 by avan-bre         ###   ########.fr       */
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
# include "test_tree.hpp"

namespace ft{
	template<class key, class value, class Compare = std::less<key>, class Allocator = std::allocator<ft::pair<const key, value> > >
	class map{
		public:
			//types:
			typedef key												key_type;
			typedef value											mapped_type;
			typedef pair<const key, value>							value_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef typename Allocator::rebind::other		node_allocator_type;
			typedef typename Allocator::reference					reference;
			typedef typename Allocator::const_reference				const_reference;
			typedef typename std::map<key, value>::iterator			iterator;
			typedef typename std::map<key, value>::const_iterator	const_iterator;
			typedef size_t											size_type;
			typedef size_t											difference_type;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef std::reverse_iterator<iterator>					reverse_iterator;
			typedef std::reverse_iterator<const_iterator>			const_reverse_iterator;

			class value_compare : public std::binary_function<value_type,value_type, bool> {
				friend class map;
					protected:
						Compare 	comp;
						value_compare(Compare c) : comp(c) {}
					
					public:
						bool operator()(const value_type& x, const value_type& y) const {
							return comp(x.first, y.first);
						}
			};

			// 23.3.1.1 construct/copy/destroy:
			explicit map(const Compare& comp = Compare(), const node_allocator_type& alloc = node_allocator_type()) :
			_size(0), _alloc(alloc), _tree(tree<key, value>(_alloc)), _comp(comp) {}

		// 	template <class InputIterator>
		// 	map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());

		// 	map(const map<Key,T,Compare,Allocator>& x);
		// 	~map();
		// 	map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x);

		// 	// iterators:
		// 	iterator					begin(); // {return iterator(_tree); }
		// 	const_iterator				begin() const; // {return const_iterator(_tree); }
		// 	iterator					end();
		// 	const_iterator				end() const;
		// 	reverse_iterator			rbegin();
		// 	const_reverse_iterator		rbegin() const;
		// 	reverse_iterator			rend();
		// 	const_reverse_iterator		rend() const;

		// 	// capacity:
			bool empty() const {return _size < 1 ? 1 : 0; }
			size_type size() const {return _size; }
			size_type max_size() const {return _alloc.max_size(); }		

		// 	// 23.3.1.2 element access:
		// 	T& operator[](const key_type& x);

		// 	// modifiers:
		// 	pair<iterator, bool> insert(const value_type& x);
		// 	iterator insert(iterator position, const value_type& x);
			
		// 	template <class InputIterator>
		// 	void insert(InputIterator first, InputIterator last);

		// 	void erase(iterator position);
		// 	size_type erase(const key_type& x);
		// 	void erase(iterator first, iterator last);
		// 	void swap(map<Key,T,Compare,Allocator>&);
		// 	void clear();

		// 	// observers:
		// 	key_compare key_comp() const;
		// 	value_compare value_comp() const;

		// 	// 23.3.1.3 map operations:
		// 	iterator find(const key_type& x);
		// 	const_iterator find(const key_type& x) const;
		// 	size_type count(const key_type& x) const;
		// 	iterator lower_bound(const key_type& x);
		// 	const_iterator lower_bound(const key_type& x) const;
		// 	iterator upper_bound(const key_type& x);
		// 	const_iterator upper_bound(const key_type& x) const;

		// 	pair<iterator,iterator> equal_range(const key_type& x);
		// 	pair<const_iterator,const_iterator> equal_range(const key_type& x) const;

			private:
				tree<key, value>	_tree;
				size_type			_size;
				allocator_type		_alloc;
				key_compare			_comp;
		};
		
		// template <class Key, class T, class Compare, class Allocator>
		// bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

		// template <class Key, class T, class Compare, class Allocator>
		// bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

		// template <class Key, class T, class Compare, class Allocator>
		// bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

		// template <class Key, class T, class Compare, class Allocator>
		// bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

		// template <class Key, class T, class Compare, class Allocator>
		// bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

		// template <class Key, class T, class Compare, class Allocator>
		// bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

		// // specialized algorithms:
		// template <class Key, class T, class Compare, class Allocator>
		// void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y);
}

#endif