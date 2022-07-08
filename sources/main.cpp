/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:06:22 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/08 15:04:50 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector_new.hpp"

int main(void){
	
	// {
	// 	std::vector<int>	v1;

	// 	v1.push_back(2);
	// 	v1.push_back(2);
	// 	v1.push_back(2);

	// 	std::vector<int>	v2;

	// 	v2.push_back(2);
	// 	v2.push_back(2);
	// 	v2.push_back(2);
	// 	v2.push_back(2);

	// 	v2.reserve(12);
		
	// 	v1 = v2;
	
	// 	std::cout << "v1 capacity: " << v1.capacity() << " size: " << v1.size() << std::endl;
	// 	std::cout << "v2 capacity: " << v2.capacity() << " size: " << v2.size() << std::endl;
	// }
	{
		ft::vector_new<int>	v1(5);
	
		v1.print_veccie("v1");
		v1.insert(v1.begin() + 1, 2);
		v1.print_veccie("v1");
	}
}
