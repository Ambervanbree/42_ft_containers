/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/27 18:23:20 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "RBtree.hpp"
#include <iostream>

int		main(void){
	// {
	// 	ft::map<int, std::string>	map;
	// 	std::cout << "Map is empty: " << map.empty() << std::endl;
	// 	std::cout << "Size map: " << map.size() << std::endl;

	// }
	// {
	// 	std::map<int, char *>	map;
	// 	std::cout << "Map is empty: " << map.empty() << std::endl;
	// 	std::cout << "Size map: " << map.size() << std::endl;
	// }

	ft::RBtree<int, const std::less<int> >  tree;
	ft::RBnode<int, const std::less<int> >	node(5);
	ft::RBnode<int, const std::less<int> >	node1(6);
	ft::RBnode<int, const std::less<int> >	node2(4);
	ft::RBnode<int, const std::less<int> >	node3(11);
	ft::RBnode<int, const std::less<int> >	node4(3);
	ft::RBnode<int, const std::less<int> >	node5(1);


	tree.insert_node(&node, NULL, 0);
	ft::RBnode<int, const std::less<int> > *parent = tree.find_parent(&node1);
	tree.insert_node(&node1, parent, parent->_content < node1._content);
	parent = tree.find_parent(&node2);
	tree.insert_node(&node2, parent, parent->_content < node2._content);
	parent = tree.find_parent(&node3);
	tree.insert_node(&node3, parent, parent->_content < node3._content);
	parent = tree.find_parent(&node4);
	tree.insert_node(&node4, parent, parent->_content < node4._content);
	parent = tree.find_parent(&node5);
	tree.insert_node(&node5, parent, parent->_content < node5._content);
	tree.visualise();
	tree.delete_node(&node1);
	tree.visualise();
	tree.delete_node(&node2);
	tree.delete_node(&node2);
	tree.visualise();
	
	// ft::node<int, std::string>	node2(6, "doei");
	// ft::node	*node2 = ft::create_node(6);
	// ft::node	*node3 = ft::create_node(4);
	// ft::node	*node4 = ft::create_node(1);
	// ft::node	*node5 = ft::create_node(8);
	// ft::node	*node6 = ft::create_node(3);
	// ft::node	*node7 = ft::create_node(10);
	// ft::node	*node8 = ft::create_node(15);
	// ft::node	*node9 = ft::create_node(16);
	// ft::node	*node10 = ft::create_node(17);
	// ft::node	*node11 = ft::create_node(-5);
	// ft::node	*node12 = ft::create_node(11);
	// ft::node	*node13 = ft::create_node(12);
	// ft::node	*node14 = ft::create_node(13);

	
	// tree.insert_node(&node, NULL, 0);
	// tree.insert_node(&node2, &node, 0);
	// tree.insert_node(node2, node, node->_n < node2->_n);
	// tree.insert_node(node3, node, node->_n < node3->_n);
	// tree.insert_node(node4, node3, node3->_n < node4->_n);
	// tree.insert_node(node5, node2, node2->_n < node5->_n);
	// tree.insert_node(node6, node4, node4->_n < node6->_n);
	// tree.insert_node(node7, node5, node5->_n < node7->_n);
	// tree.insert_node(node8, node7, node7->_n < node8->_n);
	// tree.insert_node(node9, node8, node8->_n < node9->_n);
	// tree.insert_node(node10, node9, node9->_n < node10->_n);
	// ft::node *parent = tree.find_parent(node11);
	// std::cout << "Parent is: " << parent->_n << std::endl;
	// tree.insert_node(node11, parent, parent->_n < node11->_n);
	// parent = tree.find_parent(node12);
	// std::cout << "Parent is: " << parent->_n << std::endl;
	// tree.insert_node(node12, parent, parent->_n < node12->_n);
	// parent = tree.find_parent(node13);
	// std::cout << "Parent is: " << parent->_n << std::endl;
	// tree.insert_node(node13, parent, parent->_n < node13->_n);
	// parent = tree.find_parent(node14);
	// std::cout << "Parent is: " << parent->_n << std::endl;
	// tree.insert_node(node14, parent, parent->_n < node14->_n);

	// tree.visualise(tree._root, "", false);
}