/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:06:22 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/07 17:26:08 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

int main(void){
	{
		std::vector<int>	v1;

		v1.push_back(3);
		v1.push_back(5);
		v1.push_back(6);
		v1.push_back(20);
		
		v1.insert(v1.begin() + 2, 10);

		std::vector<int>	v2(v1);

		std::cout << "Capacity: " << v1.capacity() << " size: " << v1.size() << std::endl;
		std::cout << "Vector: " << v1[0] << " " << v1[1] << " " << v1[2] << std::endl;
	}
	{
		ft::vector<int>	v1;

		v1.push_back(3);
		v1.push_back(5);
		v1.push_back(6);
		v1.push_back(20);

		ft::vector<int>	v2(v1);
		
		v1.insert(v1.begin() + 2, 10);

		std::cout << "Capacity: " << v1.capacity() << " size: " << v1.size() << std::endl;
		std::cout << "Vector: " << v1[0] << " " << v1[1] << " " << v1[2] << std::endl;
	}
}
