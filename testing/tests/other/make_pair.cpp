/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:47:36 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/06 16:34:25 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <utility>

TEST(ft_make_pair, general){
	ft::pair<int, char>		p1 = ft::make_pair(25, 'A');
	ft::pair<int, double>	p2 = ft::make_pair(310, 2.45);

	std::string	str1 = "Hello";
	
	ft::pair<float, std::string>	p3 = ft::make_pair(1.2, str1);

	EXPECT_EQ(p1.first, 25);
	EXPECT_EQ(p1.second, 'A');
	EXPECT_EQ(p2.first, 310);
	EXPECT_EQ(p2.second, 2.45);
	EXPECT_EQ(p3.first, 1.2f);
	EXPECT_EQ(p3.second, "Hello");
}

TEST(std_make_pair, general){
	std::pair<int, char>		p1 = std::make_pair(25, 'A');
	std::pair<int, double>	p2 = std::make_pair(310, 2.45);

	std::string	str1 = "Hello";
	
	std::pair<float, std::string>	p3 = std::make_pair(1.2, str1);

	EXPECT_EQ(p1.first, 25);
	EXPECT_EQ(p1.second, 'A');
	EXPECT_EQ(p2.first, 310);
	EXPECT_EQ(p2.second, 2.45);
	EXPECT_EQ(p3.first, 1.2f);
	EXPECT_EQ(p3.second, "Hello");
}
