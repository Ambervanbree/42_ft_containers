/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/29 14:29:29 by avan-bre         ###   ########.fr       */
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


	// ft::RBnode<int, const std::less<int> >	node7(7);
	// ft::RBnode<int, const std::less<int> >	node3(3);
	// ft::RBnode<int, const std::less<int> >	node6(6);


	// tree.insert_node(&node5, NULL, 0);
	// ft::RBnode<int, const std::less<int> > *parent = tree.find_parent(&node7);
	// tree.insert_node(&node7, parent, parent->_content < node7._content);
	// parent = tree.find_parent(&node3);
	// tree.insert_node(&node3, parent, parent->_content < node3._content);
	// parent = tree.find_parent(&node6);
	// tree.insert_node(&node6, parent, parent->_content < node6._content);
	// tree.visualise();
	// tree.delete_node(&node3);
	// tree.visualise();
	// // tree.delete_node(&node6);
}