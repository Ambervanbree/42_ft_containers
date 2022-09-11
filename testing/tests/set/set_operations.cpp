/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operations.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:40:01 by amber             #+#    #+#             */
/*   Updated: 2022/09/11 19:35:50 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetOperations);

TYPED_TEST(SetOperations, Find){
	SET	s1;
	
	for (int i = 0; i < 3; i++)
		s1.insert(i + 1);
	
	EXPECT_EQ(*s1.find(2), 2);
	EXPECT_EQ(s1.find(1), s1.begin());
	EXPECT_EQ(s1.find(5), s1.end());
};

TYPED_TEST(SetOperations, Count){
	SET	s1;
	
	for (int i = 0; i < 3; i++)
		s1.insert(i + 1);
	
	EXPECT_EQ(s1.count(2), 1);
	EXPECT_EQ(s1.count(3), 1);
	EXPECT_EQ(s1.count(5), 0);
};

TYPED_TEST(SetOperations, LowerBound){
	SET	s1;
	
	for (int i = 0; i < 4; i++)
		s1.insert(i + 1);
	
	EXPECT_EQ(*s1.lower_bound(2), 2);
	EXPECT_EQ(*s1.lower_bound(4), 4);
	EXPECT_EQ(s1.lower_bound(5), s1.end());
};

TYPED_TEST(SetOperations, UpperBound){
	SET	s1;
	
	for (int i = 0; i < 4; i++)
		s1.insert(i + 1);
	
	EXPECT_EQ(*s1.upper_bound(2), 3);
	EXPECT_EQ(s1.upper_bound(4), s1.end());
	EXPECT_EQ(s1.upper_bound(5), s1.end());
};

TYPED_TEST(SetOperations, EqualRange){
	SET	s1;
	
	for (int i = 0; i < 4; i++)
		s1.insert(i + 1);
	
	EXPECT_EQ(*s1.equal_range(2).first, 2);
	EXPECT_EQ(*s1.equal_range(2).second, 3);
	EXPECT_EQ(*s1.equal_range(3).first, 3);
	EXPECT_EQ(*s1.equal_range(3).second, 4);
	EXPECT_EQ(s1.equal_range(5).first, s1.end());
	EXPECT_EQ(s1.equal_range(5).second, s1.end());
};
