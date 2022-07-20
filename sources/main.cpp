/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/20 18:23:13 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include <iostream>

int		main(void){
	ft::map<int, char>	m1;

	std::cout << "m1.empty(): " << m1.empty() << std::endl;
	std::cout << "m1.size(): " << m1.size() << std::endl;
	std::cout << "m1.max_size(): " << m1.max_size() << std::endl;
	
	ft::RBnode<int, std::string>	N(1, "Amber");
	ft::RBnode<int, std::string>	*ptr = &N;
	ft::RBtree<int, std::string>	*T;
	
	ft::RB_insert_one(T, ptr, NULL, 0);

	std::map<int, char>	m2;

	std::cout << "m2.empty(): " << m2.empty() << std::endl;
	std::cout << "m2.size(): " << m2.size() << std::endl;
	std::cout << "m2.max_size(): " << m2.max_size() << std::endl;
}


// TESTING MAP WITH THIS MAIN
	// std::map<int, std::string>	m1;

	// m1.insert(std::pair<int, std::string>(33, "Joehoe"));
	// m1.insert(std::pair<int, std::string>(2, "Amber"));

	// std::map<int, std::string>::iterator	i = m1.begin();

	// std::cout << "Map size is: " << m1.size() << std::endl;
	// for (; i != m1.end(); i++)
	// 	std::cout << "Map item: " << (*i).first << ", " << (*i).second << std::endl;

	// std::cout << std::endl;
	// std::map<std::string, int>	m2;

	// m2.insert(std::make_pair("Arthur", 2));
	// m2.insert(std::make_pair("Amber", 20));
	// m2.insert(std::make_pair("Morgan", 12));

	// std::map<std::string, int>::iterator	it = m2.begin();

	// std::cout << "Map size is: " << m2.size() << std::endl;
	// for (; it != m2.end(); it++)
	// 	std::cout << "Map item: " << (*it).first << ", " << (*it).second << std::endl;