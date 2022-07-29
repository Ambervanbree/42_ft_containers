/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/29 14:51:13 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "RBtree.hpp"
#include <iostream>

int		main(void){
	// std::map<int, char> map;
	// map.insert(std::make_pair(1, 'a'));
	// map.insert(std::make_pair(3, 'f'));
	// map.insert(std::make_pair(6, 'e'));
	// map.insert(std::make_pair(8, 'p'));
	// map.insert(std::make_pair(0, 'q'));
	

	ft::RBtree<int, const std::less<int> >  tree;
	ft::RBnode<int, const std::less<int> > 	*parent;
	ft::RBnode<int, const std::less<int> >	node[25];

	tree.insert_node(&node[0], NULL, 0);

	for (int i = 1; i < 25; i++){
		node[i]._content = i;
		parent = tree.find_parent(&node[i]);
		tree.insert_node(&node[i], parent, parent->_content < node[i]._content);
	}

	tree.visualise();
	tree.delete_node(&node[22]);
	tree.delete_node(&node[23]);
	tree.delete_node(&node[15]);
	tree.delete_node(&node[21]);
	tree.visualise();
}