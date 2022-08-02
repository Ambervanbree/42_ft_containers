/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/02 11:58:21 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "RBtree.hpp"
#include <iostream>

int		main(void){
	{
		std::map<int, char> map;
		map.insert(std::make_pair(3, 'f'));
		map.insert(std::make_pair(1, 'a'));
		map.insert(std::make_pair(6, 'e'));
		map.insert(std::make_pair(8, 'p'));
		map.insert(std::make_pair(0, 'q'));
		
		std::map<int, char> map2;
		map2.insert(std::make_pair(3, 'f'));
		map2.insert(std::make_pair(1, 'a'));
		map2.insert(std::make_pair(6, 'e'));
		map2.insert(std::make_pair(8, 'p'));
		map2.insert(std::make_pair(0, 'q'));
		
		std::map<int, char>::iterator	it = map.begin();
		std::cout << "iterator start " << it->first << std::endl;
		it++; it++;
		std::cout << "iterator later " << it->first << std::endl;
		std::map<int, char>::iterator	it2 = map.begin();
		it--; it2++;
		std::cout << "iterator " << it->first << " " << it2->first << std::endl;
	}
	{
		ft::map<int, char> map;
		map.insert(ft::make_pair(3, 'f'));
		map.insert(ft::make_pair(1, 'a'));
		map.insert(ft::make_pair(6, 'e'));
		map.insert(ft::make_pair(8, 'p'));
		map.insert(ft::make_pair(0, 'q'));
		
		ft::map<int, char> map2;
		map2.insert(ft::make_pair(3, 'f'));
		map2.insert(ft::make_pair(1, 'a'));
		map2.insert(ft::make_pair(6, 'e'));
		map2.insert(ft::make_pair(8, 'p'));
		map2.insert(ft::make_pair(0, 'q'));
		
		ft::map<int, char>::iterator	it = map.begin();
		std::cout << "iterator start " << it->first << std::endl;
		it++; it++;
		std::cout << "iterator later " << it->first << std::endl;
		ft::map<int, char>::iterator	it2 = map.begin();
		it--; it2++;
		std::cout << "iterator " << it->first << " " << it2->first << std::endl;
	}
	

	// ft::RBtree<int, const std::less<int> >  tree;
	// ft::RBnode<int, const std::less<int> > 	*parent;
	// ft::RBnode<int, const std::less<int> >	node[25];

	// tree.insert_node(&node[0], NULL, 0);

	// for (int i = 1; i < 25; i++){
	// 	node[i]._content = i;
	// 	parent = tree.find_parent(&node[i]);
	// 	tree.insert_node(&node[i], parent, parent->_content < node[i]._content);
	// }

	// tree.delete_node(&node[7]);
	// tree.delete_node(&node[9]);
	// tree.delete_node(&node[22]);
	// tree.delete_node(&node[13]);
	// tree.delete_node(&node[17]);
	// tree.visualise();
	// std::cout << "tree is valid: " << tree.valid() << std::endl;
}