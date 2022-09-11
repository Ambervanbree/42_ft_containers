/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:04:34 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/11 17:59:28 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetComplexConstruct);

TYPED_TEST(SetComplexConstruct, Default){
	SET	s1;

	EXPECT_TRUE(s1.empty());
	EXPECT_EQ(s1.size(), 0);
};

TYPED_TEST_SUITE_P(MapSimpleConstruct);

TYPED_TEST(SetSimpleConstruct, CopyConstruct){
	SET	s1;

	for (int i = 0; i < 7; i++)
		s1.insert(i + 1);
	
	SET s2(s1);

	EXPECT_EQ(s2.size(), 7);
	EXPECT_EQ(*s2.begin(), 1);

	s1.erase(1);

	EXPECT_EQ(s1.size(), 6);
	EXPECT_EQ(s2.size(), 7);
	EXPECT_EQ(*s1.begin(), 2);
	EXPECT_EQ(*s2.begin(), 1);
};

TYPED_TEST(SetSimpleConstruct, RangeConstruct){
	SET	s1;

	for (int i = 0; i < 7; i++)
		s1.insert(i + 1);

	SET s2(s1.begin(), s1.end());

	EXPECT_EQ(s2.size(), 7);
	EXPECT_EQ(s1.size(), 7);
	EXPECT_EQ(*s2.begin(), 1);

	s1.insert(0);
	s2.erase(1);
	
	EXPECT_EQ(s1.size(), 8);
	EXPECT_EQ(s2.size(), 6);
	EXPECT_EQ(*s2.begin(), 2);
	EXPECT_EQ(*s1.begin(), 0);
};

TYPED_TEST(SetSimpleConstruct, AssignmentOperator){
	SET	s1;
	SET s2;

	for (int i = 0; i < 7; i++)
		s1.insert(i + 1);

	s2 = s1;

	EXPECT_EQ(s2.size(), 7);
	EXPECT_EQ(s1.size(), 7);
	EXPECT_EQ(*s2.begin(), 1);
	EXPECT_EQ(*s1.begin(), 1);

	s1.insert(0);
	s2.erase(1);
	
	EXPECT_EQ(s1.size(), 8);
	EXPECT_EQ(s2.size(), 6);
	EXPECT_EQ(*s2.begin(), 2);
	EXPECT_EQ(*s1.begin(), 0);
	
	s1 = s2;

	EXPECT_EQ(s1.size(), 6);
	EXPECT_EQ(*s1.begin(), 2);
};
