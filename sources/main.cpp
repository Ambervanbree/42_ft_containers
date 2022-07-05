/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:06:22 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/05 15:57:26 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

int main(void){
	{
		std::vector<int>	v1(5);

		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		
		std::vector<int>	v2(v1);

		std::cout << "STD VECTOR" << std::endl;
		
		std::cout << "v1: size " << v1.size() << ", capacity " << v1.capacity()
		<< ", first el " << v1[0] << ", last el " << v1[7] << std::endl;

		std::cout << "v2: size " << v2.size() << ", capacity " << v2.capacity()
		<< ", first el " << v2[0] << ", last el " << v2[7] << std::endl;

		v1[3] = 8;
		v2[2] = 7;

		std::cout << "v1: size " << v1.size() << ", capacity " << v1.capacity()
		<< ", 2nd el " << v1[2] << ", 3rd el " << v1[3] << std::endl;

		std::cout << "v2: size " << v2.size() << ", capacity " << v2.capacity()
		<< ", 2nd el " << v2[2] << ", 3rd el " << v2[3] << std::endl;

		std::vector<int> v3(4);
		v3[1] = 8;
		v3[3] = 10;
		std::cout << "BEGINNNN before v3" << &(*(v3.begin())) << std::endl;

		v3 = v1;

		std::cout << "BEGINNNN after v3" << &(*(v3.begin())) << std::endl;

		
		std::cout << "v3: size " << v3.size() << ", capacity " << v3.capacity()
		<< ", 2nd el " << v3[2] << ", 3rd el " << v3[3] << std::endl;
	}
	{
		ft::vector<int>	v1(5);

		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		
		ft::vector<int>	v2(v1);

		std::cout << "FT VECTOR" << std::endl;
		
		std::cout << "v1: size " << v1.size() << ", capacity " << v1.capacity()
		<< ", first el " << v1[0] << ", last el " << v1[7] << std::endl;

		std::cout << "v2: size " << v2.size() << ", capacity " << v2.capacity()
		<< ", first el " << v2[0] << ", last el " << v2[7] << std::endl;

		v1[3] = 8;
		v2[2] = 7;

		std::cout << "v1: size " << v1.size() << ", capacity " << v1.capacity()
		<< ", 2nd el " << v1[2] << ", 3rd el " << v1[3] << std::endl;

		std::cout << "v2: size " << v2.size() << ", capacity " << v2.capacity()
		<< ", 2nd el " << v2[2] << ", 3rd el " << v2[3] << std::endl;

		ft::vector<int> v3(4);
		v3[1] = 8;
		v3[3] = 10;

		v3 = v1;
		std::cout << "v3: size " << v3.size() << ", capacity " << v3.capacity()
		<< ", 2nd el " << v3[2] << ", 3rd el " << v3[3] << std::endl;
	}
}
