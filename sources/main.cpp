/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:06:22 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/08 17:39:21 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector_new.hpp"

void print_veccie(std::vector<int> &vec, std::string name){
	std::cout << "Veccie " << name << " (size " 
	<< vec.size() << ", capacity " << vec.capacity() << ") contains: " << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main(void){
	{
		std::vector<int>	v1(5);
		std::vector<int>	v2(5);

		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);

		print_veccie(v1, "v1");
		v1.insert(v1.begin() + 7, 2);
		print_veccie(v1, "v1");
		v1.insert(v1.begin(), 10, 3);
		print_veccie(v1, "v1");
		v2.insert(v2.begin() + 2, v1.begin() + 15, v1.begin() + 17);
		print_veccie(v2, "v2");

		v1.pop_back();
		print_veccie(v1, "v1");
	}
	{
		std::cout << std::endl << std::endl;
		ft::vector_new<int>	v1(5);
		ft::vector_new<int>	v2(5);

		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);

		v1.print_veccie("v1");
		v1.insert(v1.begin() + 7, 2);
		v1.print_veccie("v1");
		v1.insert(v1.begin(), 10, 3);
		v1.print_veccie("v1");
		v2.insert(v2.begin() + 2, v1.begin() + 15, v1.begin() + 17);
		v2.print_veccie("v2");

		v1.pop_back();
		v1.print_veccie("v1");
	}
}
