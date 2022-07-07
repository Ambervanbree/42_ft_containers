/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:58:31 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/06 12:41:08 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorComplexConstruct);

TYPED_TEST(VectorComplexConstruct, Default){
	VECTOR	v1;
	
	EXPECT_EQ(v1.size(), 0);
	EXPECT_EQ(v1.capacity(), 0);
}

TYPED_TEST(VectorComplexConstruct, Param){
	VECTOR	v1(5);

	EXPECT_EQ(v1.size(), 5);
	EXPECT_EQ(v1.capacity(), 5);
}

TYPED_TEST_SUITE_P(VectorSimpleConstruct);

TYPED_TEST(VectorSimpleConstruct, CopyConstruct){
	VECTOR	v1(5);

	v1.push_back(2);
	v1.push_back(34);

	VECTOR	v2(v1);

	EXPECT_EQ(v2.size(), 7);
	EXPECT_EQ(v2.capacity(), 7);
	EXPECT_EQ(v2[0], 0);
	EXPECT_EQ(v2[6], 34);

	v1[2] = 3;
	v2[3] = 2;

	EXPECT_EQ(v1[2], 3);
	EXPECT_EQ(v1[3], 0);
	EXPECT_EQ(v2[2], 0);
	EXPECT_EQ(v2[3], 2);
}

	
// 	v1.push_back(2);
// 	v1.push_back(-4);
// 	v1.push_back(0);

// 	EXPECT_EQ(v1[0], 2);
// 	EXPECT_EQ(v1[2], 0);
// 	EXPECT_EQ(v2[0], 0);
// 	EXPECT_EQ(v2[2], 0);
// 	EXPECT_EQ(v2[4], 0);

// 	EXPECT_EQ(v1.size(), 3);
// 	EXPECT_EQ(v1.capacity(), 4);
	
// 	v2.push_back(2);
// 	v2.push_back(-4);
// 	v2.push_back(0);

// 	EXPECT_EQ(v2.size(), 8);
// 	EXPECT_EQ(v2.capacity(), 10);
// }

// TYPED_TEST(Vector_test, capacity){
// 		VECTOR	v1(5);

// 		v1.push_back(4);
// 		v1.push_back(5);
// 		v1.push_back(6);
		
// 		VECTOR	v2(v1);

// 		EXPECT_FALSE(v1.empty());
// 		EXPECT_EQ(v1.size(), 8);
// 		EXPECT_EQ(v1.capacity(), 10);
// 		EXPECT_EQ(v1[0], 0);
// 		EXPECT_EQ(v1[7], 6);
// 		EXPECT_EQ(v2.size(), 8);
// 		EXPECT_EQ(v2.capacity(), 8);
// 		EXPECT_EQ(v2[0], 0);
// 		EXPECT_EQ(v2[7], 6);

// 		v1[3] = 8;
// 		v2[2] = 7;

// 		EXPECT_EQ(v1.size(), 8);
// 		EXPECT_EQ(v1.capacity(), 10);
// 		EXPECT_EQ(v1[2], 0);
// 		EXPECT_EQ(v1[3], 8);
// 		EXPECT_EQ(v2.size(), 8);
// 		EXPECT_EQ(v2.capacity(), 8);
// 		EXPECT_EQ(v2[2], 7);
// 		EXPECT_EQ(v2[3], 0);

// 		VECTOR v3;
// 		VECTOR v4;

// 		EXPECT_TRUE(v3.empty());
// 		EXPECT_TRUE(v4.empty());
		
// 		v3.reserve(4);
// 		v4.reserve(100);
// 		v3[1] = 8;
// 		v3[3] = 10;
// 		v3 = v1;
// 		v4 = v1;
		
// 		EXPECT_FALSE(v3.empty());
// 		EXPECT_FALSE(v4.empty());
// 		EXPECT_EQ(v3.size(), 8);
// 		EXPECT_EQ(v3.capacity(), 8);
// 		EXPECT_EQ(v3[2], 0);
// 		EXPECT_EQ(v3[3], 8);
// 		EXPECT_EQ(v4.size(), 8);
// 		EXPECT_EQ(v4.capacity(), 100);
// 		EXPECT_EQ(v4[2], 0);
// 		EXPECT_EQ(v4[3], 8);

// 		v1[4] = 8;
// 		v4[5] = 7;
		
// 		EXPECT_EQ(v1[4], 8);
// 		EXPECT_EQ(v1[5], 4);
// 		EXPECT_EQ(v4[4], 0);
// 		EXPECT_EQ(v4[5], 7);
// }