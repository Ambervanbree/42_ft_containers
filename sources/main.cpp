/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/20 09:49:35 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>

int		main(void){
	std::map<int, std::string>	m1;

	m1.insert(std::pair<int, std::string>(33, "Joehoe"));
	m1.insert(std::pair<int, std::string>(2, "Amber"));

	std::map<int, std::string>::iterator	i = m1.begin();

	std::cout << "Map size is: " << m1.size() << std::endl;
	for (; i != m1.end(); i++)
		std::cout << "Map item: " << (*i).first << ", " << (*i).second << std::endl;

	std::cout << std::endl;
	std::map<std::string, int>	m2;

	m2.insert(std::make_pair("Arthur", 2));
	m2.insert(std::make_pair("Amber", 20));
	m2.insert(std::make_pair("Morgan", 12));

	std::map<std::string, int>::iterator	it = m2.begin();

	std::cout << "Map size is: " << m2.size() << std::endl;
	for (; it != m2.end(); it++)
		std::cout << "Map item: " << (*it).first << ", " << (*it).second << std::endl;
}
