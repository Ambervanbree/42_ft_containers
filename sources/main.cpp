/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/22 11:24:01 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
// #include "map.hpp"
#include "test_tree.hpp"
#include <iostream>

int		main(void){
	ft::tree	tree;

	ft::node	*node = ft::create_node(5);
	ft::node	*node2 = ft::create_node(6);
	ft::node	*node3 = ft::create_node(4);
	ft::node	*node4 = ft::create_node(1);
	ft::node	*node5 = ft::create_node(8);
	ft::node	*node6 = ft::create_node(3);
	ft::node	*node7 = ft::create_node(10);
	ft::node	*node8 = ft::create_node(15);
	ft::node	*node9 = ft::create_node(16);
	ft::node	*node10 = ft::create_node(17);

	
	tree.insert_node(node, NULL, 0);	
	tree.insert_node(node2, node, node->_n < node2->_n);
	tree.insert_node(node3, node, node->_n < node3->_n);
	tree.insert_node(node4, node3, node3->_n < node4->_n);
	tree.insert_node(node5, node2, node2->_n < node5->_n);
	tree.insert_node(node6, node4, node4->_n < node6->_n);
	tree.insert_node(node7, node5, node5->_n < node7->_n);
	tree.insert_node(node8, node7, node7->_n < node8->_n);
	tree.insert_node(node9, node8, node8->_n < node9->_n);
	std::cout << "Parent is " << tree.find_parent(node10)->_n << std::endl;
	// here it goes wrong

	// tree.insert_node(node10, node9, node9->_n < node10->_n);

	tree.visualise(node, "", false);
}
