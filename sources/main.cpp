/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/03 18:25:53 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "RBtree.hpp"
#include <iostream>

using namespace ft;

int main()
{
	pair<int, std::string>			my_pair(8, "salut");
	map<int, std::string>			test;
	map<int, std::string>::iterator	it;

	test.insert(my_pair);
	test.insert(pair<int, std::string>(-4, "bar"));
	// test.insert(pair<int, std::string>(2, "machin"));
	// test.insert(pair<int, std::string>(3, "foo"));
	// test.insert(pair<int, std::string>(746, "Marcel"));
	// test.insert(pair<int, std::string>(1, "truc"));
	test.visualise();
// 	it = test.begin();
// 	std::cout << '\n';

// 	while (it != test.end())
// 	{
// 		// std::cout << "start of while\n";
// 		std::cout << it->first << ", " << it->second << '\n';
// 		it++;
// 		// std::cout << "iterator incremented\n";
// 		// std::cout << "iterator is now " << it->first << std::endl;

// // #ifndef STD
// // 		cout << it.getPointer() << '\n';
// // 		cout << test.end().getPointer() << '\n';
// // #endif

// 	}
// 	std::cout << "End of display loop\n";
}
