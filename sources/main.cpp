/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:06:22 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/11 17:09:32 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

void print_veccie(std::vector<int> &vec, std::string name){
	std::cout << "Veccie " << name << " (size " 
	<< vec.size() << ", capacity " << vec.capacity() << ") contains: " << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

class Amber{
	public:
		Amber() {std::cout << "constructor called" << std::endl; }
		~Amber() {std::cout << "destructor called" << std::endl; };

};

int main(void){
	{
		std::vector<int>	v1(5);
		std::vector<int>	v2(5);

		v2.push_back(5);
		v2.pop_back();

		std::cout << "!=: " << (v1 != v2) << std::endl;

		// v2.push_back(10);

		std::cout << "<=: " << (v1 <= v2) << std::endl;
		std::cout << ">=: " << (v1 >= v2) << std::endl;
		std::cout << "<: " << (v1 < v2) << std::endl;
		std::cout << ">: " << (v1 > v2) << std::endl;
	}
	{
		ft::vector<int>	v1(5);
		ft::vector<int>	v2(5);

		v2.push_back(5);
		v2.pop_back();

		std::cout << "!=: " << (v1 != v2) << std::endl;

		// v2.push_back(10);

		std::cout << "<=: " << (v1 <= v2) << std::endl;
		std::cout << ">=: " << (v1 >= v2) << std::endl;
		std::cout << "<: " << (v1 < v2) << std::endl;
		std::cout << ">: " << (v1 > v2) << std::endl;
	}
}


	// {
	// 	// std::vector<Amber>	v1(2);
		
	// 	// v1.pop_back();

	// 	// std::vector<Amber>	v2(2);

	// 	std::vector<int>	v1(5);
	// 	std::vector<int>	v2(5);

	// 	v1.push_back(4);
	// 	v1.push_back(5);
	// 	v1.push_back(6);

	// 	print_veccie(v1, "v1");
	// 	v1.insert(v1.begin() + 7, 2);
	// 	print_veccie(v1, "v1");
	// 	v1.insert(v1.begin(), 10, 3);
	// 	print_veccie(v1, "v1");
	// 	v2.insert(v2.begin() + 2, v1.begin() + 15, v1.begin() + 17);
	// 	print_veccie(v2, "v2");

	// 	v1.pop_back();
	// 	std::cout << *(v1.erase(v1.end() - 3)) << std::endl;
	// 	print_veccie(v1, "v1");
	// 	v1.erase(v1.begin() + 2, v1.begin() + 16);
	// 	print_veccie(v1, "v1");
	// 	v1.assign(10, 2);
	// 	print_veccie(v1, "v1");
	// 	print_veccie(v2, "v2");
	// 	v1.assign(v2.begin() + 1, v2.end());
	// 	print_veccie(v1, "v1");
	// 	v2.assign(3, 3);
	// 	print_veccie(v2, "v2");
	// 	v2.assign(11, 11);
	// 	print_veccie(v1, "v1");
	// 	print_veccie(v2, "v2");
	// 	v1.swap(v2);
	// 	print_veccie(v1, "v1");
	// 	print_veccie(v2, "v2");

	// 	std::cout << "max size: " << v1.max_size() << std::endl;
	// 	std::cout << "max size: " << v2.max_size() << std::endl;

	// 	v2.resize(10);
	// 	v1.resize(5);
	// 	print_veccie(v1, "v1");
	// 	print_veccie(v2, "v2");

	// 	std::cout << "at 4: " << v2.at(4) << std::endl;
	// 	std::cout << "at 1: " << v2.at(1) << std::endl;
	// 	std::cout << "front: " << v2.front() << std::endl;
	// 	std::cout << "back: " << v2.back() << std::endl;
	// }
	// {
	// 	// std::cout << std::endl;
		
	// 	// ft::vector<Amber>	v1(2);

	// 	// v1.pop_back();

	// 	// ft::vector<Amber>	v2(2);

	// 	std::cout << std::endl << std::endl;
	// 	ft::vector<int>	v1(5);
	// 	ft::vector<int>	v2(5);

	// 	v1.push_back(4);
	// 	v1.push_back(5);
	// 	v1.push_back(6);

	// 	v1.print_veccie("v1");
	// 	v1.insert(v1.begin() + 7, 2);
	// 	v1.print_veccie("v1");
	// 	v1.insert(v1.begin(), 10, 3);
	// 	v1.print_veccie("v1");
	// 	v2.insert(v2.begin() + 2, v1.begin() + 15, v1.begin() + 17);
	// 	v2.print_veccie("v2");

	// 	v1.pop_back();
	// 	std::cout << *(v1.erase(v1.end() - 3)) << std::endl;
	// 	v1.print_veccie("v1");
	// 	v1.erase(v1.begin() + 2, v1.begin() + 16);
	// 	v1.print_veccie("v1");
	// 	v1.assign(10, 2);
	// 	v1.print_veccie("v1");
	// 	v2.print_veccie("v2");
	// 	v1.assign(v2.begin() + 1, v2.end());
	// 	v1.print_veccie("v1");
	// 	v2.assign(3, 3);
	// 	v2.print_veccie("v2");
	// 	v2.assign(11, 11);
	// 	v1.print_veccie("v1");
	// 	v2.print_veccie("v2");
	// 	v1.swap(v2);
	// 	v1.print_veccie("v1");
	// 	v2.print_veccie("v2");

	// 	std::cout << "max size: " << v1.max_size() << std::endl;
	// 	std::cout << "max size: " << v2.max_size() << std::endl;

	// 	v2.resize(10);
	// 	v1.resize(5);
	// 	v1.print_veccie("v1");
	// 	v2.print_veccie("v2");

	// 	std::cout << "at 4: " << v2.at(4) << std::endl;
	// 	std::cout << "at 1: " << v2.at(1) << std::endl;
	// 	std::cout << "front: " << v2.front() << std::endl;
	// 	std::cout << "back: " << v2.back() << std::endl;
	// }