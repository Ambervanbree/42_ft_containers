/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/21 18:53:09 by avan-bre         ###   ########.fr       */
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
	// ft::node	*node6 = ft::create_node(1);
	// ft::node	*node7 = ft::create_node(1);
	// ft::node	*node8 = ft::create_node(1);

	
	tree.insert_node(node, NULL, 0);	
	tree.insert_node(node2, node, node->_n < node2->_n);
	tree.insert_node(node3, node, node->_n < node3->_n);
	tree.insert_node(node4, node3, node3->_n < node4->_n);
	tree.visualise(node, "", false);
	tree.insert_node(node5, node2, node2->_n < node5->_n);
	tree.visualise(node, "", false);
}
