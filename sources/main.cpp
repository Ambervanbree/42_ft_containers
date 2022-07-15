/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:14:09 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/15 09:59:56 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "../42TESTERS-CONTAINERS/test_utils.hpp"

int	main(void){
	std::cout << "\nINSERT\n";
	ft::vector<std::string>	v1;
	for (size_t i = 0; i < 15; i++)
		v1.push_back("        hbaudet\n");
	std::cout << "after push_back, before at\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1.at(i) << ' ';
	std::cout << '\n';

	ft::vector<std::string>::iterator	tmp;
	tmp = v1.begin() + 4;
	v1.insert(tmp, 8, "t");
// 	for (size_t i = 0; i < v1.size(); i++)
// 		std::cout << v1.at(i) << ' ';
// 	std::cout << '\n';
}