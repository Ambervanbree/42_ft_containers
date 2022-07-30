/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/30 17:35:19 by avan-bre         ###   ########.fr       */
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
		// map.insert(std::make_pair(3, 'f'));
		// map.insert(std::make_pair(6, 'e'));
		// map.insert(std::make_pair(8, 'p'));
		// map.insert(std::make_pair(0, 'q'));
	}
	{
		ft::map<int, char> map;
		map.insert(std::make_pair(3, 'f'));
		// map.insert(std::make_pair(3, 'f'));
		// map.insert(std::make_pair(6, 'e'));
		// map.insert(std::make_pair(8, 'p'));
		// map.insert(std::make_pair(0, 'q'));
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