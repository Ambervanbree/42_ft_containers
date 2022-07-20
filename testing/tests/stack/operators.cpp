/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:01:05 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/06 18:01:54 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(StackOperators);

TYPED_TEST(StackOperators, general){
	STACK	s1;
	STACK	s2;

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