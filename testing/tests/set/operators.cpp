/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:50:56 by amber             #+#    #+#             */
/*   Updated: 2022/09/11 19:42:46 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetOperators);

TYPED_TEST(SetOperators, NonMember){
	SET		s1;
	SET		s2;

	for(int i = 0; i < 6; i++)
		s1.insert(i + 1);
	for(int i = 0; i < 6; i++)
		s2.insert(i + 1);

	EXPECT_TRUE(s1 == s2);
	EXPECT_FALSE(s1 != s2);
	EXPECT_TRUE(s1 <= s2);
	EXPECT_TRUE(s1 >= s2);
	EXPECT_FALSE(s1 < s2);
	EXPECT_FALSE(s1 > s2);
	
	s1.insert(8);
	
	EXPECT_TRUE(s1 != s2);
	EXPECT_FALSE(s1 == s2);
	EXPECT_FALSE(s1 <= s2);
	EXPECT_TRUE(s1 >= s2);
	EXPECT_FALSE(s1 < s2);
	EXPECT_TRUE(s1 > s2);

	s2.insert(9);

	EXPECT_TRUE(s1 != s2);
	EXPECT_FALSE(s1 == s2);
	EXPECT_TRUE(s1 <= s2);
	EXPECT_FALSE(s1 >= s2);
	EXPECT_TRUE(s1 < s2);
	EXPECT_FALSE(s1 > s2);	
};
