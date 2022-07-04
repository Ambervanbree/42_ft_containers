/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:06:22 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/28 12:20:00 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
// #include "vector.hpp"
#include "vector_test.hpp"

int main(void){
	{
		ft::vector_test<int>	fv1;
		
		std::cout << "VECTOR UNITIALISED: " << std::endl;
		std::cout << "Size fv1 = 	" << fv1.size() << std::endl;
		std::cout << "Capacity fv1 =	" << fv1.capacity() << std::endl << std::endl;

		ft::vector_test<int>	fv2(5);

		std::cout << "Elements: " << fv2[0] << fv2[1] << fv2[2] << fv2[3] << fv2[4] << std::endl << std::endl;
		fv2.push_back(5);

		std::cout << std::endl << "VECTOR INITIALISED WITH A SIZE OF 5: " << std::endl;
		std::cout << "Size fv1 = 	" << fv2.size() << std::endl;
		std::cout << "Capacity fv1 =	" << fv2.capacity() << std::endl << std::endl;

		std::cout << "Added element: " << fv2[5] << std::endl << std::endl;
	}
}


	// {
	// std::vector<int>	v1;

	// std::cout << "VECTOR UNITIALISED: " << std::endl;
	// std::cout << "Size v1 = 	" << v1.size() << std::endl;
	// std::cout << "Capacity v1 =	" << v1.capacity() << std::endl << std::endl;

	// for (int i = 0; i < 18; i++){
	// 	v1.push_back(42);
	// 	std::cout << "Size v1 =	" << v1.size() << std::endl;
	// 	std::cout << "Capacity V1 =	" << v1.capacity() << std::endl << std::endl;		
	// }

	// std::vector<int>	v2(5);

	// std::cout << "Elements: " << v2[0] << v2[1] << v2[2] << v2[3] << v2[4] << std::endl << std::endl;

	// std::cout << "VECTOR INITIALISED WITH A SIZE OF 5: " << std::endl;
	// std::cout << "Size v2 = 	" << v2.size() << std::endl;
	// std::cout << "Capacity v2 =	" << v2.capacity() << std::endl << std::endl;

	// for (int i = 0; i < 18; i++){
	// 	v2.push_back(42);
	// 	std::cout << "Size v2 =	" << v2.size() << std::endl;
	// 	std::cout << "Capacity v2 =	" << v2.capacity() << std::endl << std::endl;		
	// }
	// }
