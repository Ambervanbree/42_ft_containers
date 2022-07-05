/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_stack.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:14:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/05 12:42:50 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <gtest/gtest.h>
#include <iostream>

TEST(std_stack, operations){
	std::stack<int>	s1;

	EXPECT_TRUE(s1.empty());
	
	s1.push(5);
	s1.push(7);
	s1.push(9);
	s1.push(11);

	EXPECT_FALSE(s1.empty());
	EXPECT_EQ(s1.top(), 11);
	EXPECT_EQ(s1.size(), 4);
	
	s1.pop();
	s1.pop();

	EXPECT_FALSE(s1.empty());
	EXPECT_EQ(s1.top(), 7);
	EXPECT_EQ(s1.size(), 2);

	s1.pop();
	s1.pop();

	EXPECT_TRUE(s1.empty());
	EXPECT_EQ(s1.size(), 0);
}

TEST(std_stack, operators){
	std::stack<int>	s1;
	std::stack<int>	s2;

	s1.push (5);
	s1.push (-1);
	s1.push (0);
	s2.push (5);
	s2.push (-1);
	s2.push (0);

	EXPECT_TRUE(s1 == s2);
	
	s2.pop();

	EXPECT_FALSE(s1 <= s2);
	EXPECT_TRUE(s1 >= s2);
	EXPECT_FALSE(s1 < s2);
	EXPECT_TRUE(s1 > s2);
	EXPECT_TRUE(s1 != s2);
	EXPECT_FALSE(s1 == s2);
}