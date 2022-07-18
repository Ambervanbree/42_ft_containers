/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:58:31 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/18 12:33:58 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorComplexConstruct);

TYPED_TEST(VectorComplexConstruct, DefaultConstruct){
	VECTOR	v1;
	
	EXPECT_TRUE(v1.empty());
}

TYPED_TEST(VectorComplexConstruct, SizedConstruct){
	VECTOR	v1(5);

	std::cout << "size v1: " << v1.size() << std::endl;
	std::cout << "capacity v1: " << v1.capacity() << std::endl;
	// EXPECT_EQ(v1.size(), 5);
	// EXPECT_EQ(v1.capacity(), 5);
}

// TYPED_TEST_SUITE_P(VectorSimpleConstruct);

// TYPED_TEST(VectorSimpleConstruct, CopyConstruct){
// 	VECTOR	v1(5);

// 	v1.push_back(2);
// 	v1.push_back(34);

// 	VECTOR	v2(v1);

// 	EXPECT_EQ(v2.size(), 7);
// 	EXPECT_EQ(v2.capacity(), 7);
// 	EXPECT_EQ(v2[0], 0);
// 	EXPECT_EQ(v2[6], 34);

// 	v1[2] = 3;
// 	v2[3] = 2;

// 	EXPECT_EQ(v1[2], 3);
// 	EXPECT_EQ(v1[3], 0);
// 	EXPECT_EQ(v2[2], 0);
// 	EXPECT_EQ(v2[3], 2);
// }

// TYPED_TEST(VectorSimpleConstruct, RangeConstruct){
// 	VECTOR	v1(5);

// 	v1.push_back(2);
// 	v1.push_back(34);
// 	v1.push_back(28);
// 	v1.push_back(75);
	
// 	VECTOR	v2(v1.begin() + 4, v1.end());
// 	VECTOR	v3(v2.begin(), v2.begin() + 3);

// 	EXPECT_EQ(v2.size(), 5);
// 	EXPECT_EQ(v2.capacity(), 5);
// 	EXPECT_EQ(v2[0], 0);
// 	EXPECT_EQ(v2[4], 75);

// 	EXPECT_EQ(v3.size(), 3);
// 	EXPECT_EQ(v3.capacity(), 3);
// 	EXPECT_EQ(v3[0], 0);
// 	EXPECT_EQ(v3[2], 34);
// }

// TYPED_TEST_SUITE_P(VectorStringConstruct);

// TYPED_TEST(VectorStringConstruct, StringConstruct){
// 	VECTOR	v1;
	
// 	EXPECT_TRUE(v1.empty());
	
// 	v1.push_back("Hello");
// 	v1.push_back("Wazzaaa");
// 	v1.push_back("All good?");

// 	VECTOR	v2(5);

// 	EXPECT_FALSE(v2.empty());
// 	EXPECT_EQ(v2.size(), 5);
// 	EXPECT_EQ(v2.capacity(), 5);
// 	EXPECT_EQ(v2[0], "\0");
// 	EXPECT_EQ(v2[2], "\0");	

// 	VECTOR	v3(v1);
	
// 	v1[0] = "Later bro.";
// 	v3[0] = "We are independant now.";

// 	EXPECT_EQ(v1.size(), 3);
// 	EXPECT_EQ(v1.capacity(), 4);
// 	EXPECT_EQ(v1[0], "Later bro.");
// 	EXPECT_EQ(v1[2], "All good?");
// 	EXPECT_EQ(v3.size(), 3);
// 	EXPECT_EQ(v3.capacity(), 3);
// 	EXPECT_EQ(v3[0], "We are independant now.");
// 	EXPECT_EQ(v3[2], "All good?");	
// }
