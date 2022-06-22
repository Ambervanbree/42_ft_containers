/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:01:42 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/22 18:57:47 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "equal.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

bool is_equal_adjacent(std::vector<int> &array1, std::vector<int> &array2){
	return std::equal(array1.begin(), array1.end(), array2.begin() + 1);
}

bool ft_is_equal_adjacent(std::vector<int> &array1, std::vector<int> &array2){
	return ft::equal(array1.begin(), array1.end(), array2.begin() + 1);
}


int main(void){
	std::vector<int>	array1;
	std::vector<int>	array2;
	int 				i = 0;
	
	for (; i < 10; i++){
		array1.push_back(i + 1);
		array2.push_back(i);
	}
	array2.push_back(i);
	
	std::cout << is_equal_adjacent(array1, array2) << std::endl;
	std::cout << ft_is_equal_adjacent(array1, array2) << std::endl;

	// EXPECT_EQ(is_equal_adjacent(array1, array2), true);
}
