/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:07:59 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/28 11:24:40 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <gtest/gtest.h>

TEST(ft_stack, operations){
	ft::stack<int>	s1;

	EXPECT_EQ(s1.empty(), true);
	
	s1.push(5);
	s1.push(7);
	s1.push(9);
	s1.push(11);

	EXPECT_EQ(s1.empty(), false);
	EXPECT_EQ(s1.top(), 11);
	EXPECT_EQ(s1.size(), 4);
	
	s1.pop();
	s1.pop();

	EXPECT_EQ(s1.empty(), false);
	EXPECT_EQ(s1.top(), 7);
	EXPECT_EQ(s1.size(), 2);

	s1.pop();
	s1.pop();

	EXPECT_EQ(s1.empty(), true);
	EXPECT_EQ(s1.top(), 0); // *** should segfault but doesn't
	EXPECT_EQ(s1.size(), 0);
}

TEST(ft_stack, operators){
	ft::stack<int>	s1;
	ft::stack<int>	s2;

	s1.push (5);
	s1.push (-1);
	s1.push (0);
	s2.push (5);
	s2.push (-1);
	s2.push (0);

	EXPECT_EQ(s1 == s2, true);
	
	s2.pop();

	EXPECT_EQ(s1 <= s2, false);
	EXPECT_EQ(s1 >= s2, true);
	EXPECT_EQ(s1 < s2, false);
	EXPECT_EQ(s1 > s2, true);
	EXPECT_EQ(s1 != s2, true);
	EXPECT_EQ(s1 == s2, false);
}