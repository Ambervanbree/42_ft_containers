/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:34:37 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/16 16:49:37 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"
#include <memory>

TYPED_TEST_SUITE_P(VectorCapacity);

TYPED_TEST(VectorCapacity, Size){
	VECTOR	v1;
	VECTOR	v2(5);

	EXPECT_EQ(v1.size(), 0);
	EXPECT_EQ(v2.size(), 5);
}

TYPED_TEST(VectorCapacity, MaxSize){
	VECTOR				v1;
	std::allocator<int>	alloc;
	
	EXPECT_EQ(v1.max_size(), alloc.max_size());
}

TYPED_TEST(VectorCapacity, Empty){
	VECTOR				v1;
	
	EXPECT_TRUE(v1.empty());

	v1.push_back(20);

	EXPECT_FALSE(v1.empty());
}

TYPED_TEST(VectorCapacity, Resize){
	VECTOR	v1;
	VECTOR	v2;

	// adding 100 * 23:
	for (size_t i = 0; i < 100; i++){
		v1.push_back(23);
	}

	// resizing to a smaller size,
	// this doesn't change capacity:

	v1.resize(25);

	EXPECT_EQ(v1.size(), 25);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v1[0], 23);
	EXPECT_EQ(v1[24], 23);

	v1.resize(75);

	// resizing to a bigger size
	// will add default int's: 

	EXPECT_EQ(v1.size(), 75);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v1[0], 23);
	EXPECT_EQ(v1[74], 0);
}

TYPED_TEST(VectorCapacity, Reserve){
	VECTOR	v1;
	VECTOR	v2;

	for (size_t i = 0; i < 100; i++){
		v1.push_back(23);
	}

	v2.reserve(100);

	EXPECT_EQ(v1.size(), 100);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v2.size(), 0);
	EXPECT_EQ(v2.capacity(), 100);
}

TYPED_TEST_SUITE_P(VectorCapacityString);

TYPED_TEST(VectorCapacityString, Empty){
	VECTOR				v1;
	
	EXPECT_TRUE(v1.empty());

	v1.push_back("Hi there");

	EXPECT_FALSE(v1.empty());
}

TYPED_TEST(VectorCapacityString, Resize){
	VECTOR	v1;
	VECTOR	v2;

	for (size_t i = 0; i < 100; i++){
		v1.push_back("Why are you reading this?");
	}

	v1.resize(25);

	EXPECT_EQ(v1.size(), 25);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v1[0], "Why are you reading this?");
	EXPECT_EQ(v1[24], "Why are you reading this?");

	v1.resize(75);

	EXPECT_EQ(v1.size(), 75);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v1[0], "Why are you reading this?");
	EXPECT_EQ(v1[74], "\0");

	v1.resize(130);

	EXPECT_EQ(v1.size(), 130);
	EXPECT_EQ(v1.capacity(), 150);
	EXPECT_EQ(v1[0], "Why are you reading this?");
	EXPECT_EQ(v1[129], "\0");
}

TYPED_TEST(VectorCapacityString, Reserve){
	VECTOR	v1;
	VECTOR	v2;

	for (size_t i = 0; i < 100; i++){
		v1.push_back("Lalalala");
	}

	v2.reserve(100);

	EXPECT_EQ(v1.size(), 100);
	EXPECT_EQ(v1.capacity(), 128);
	EXPECT_EQ(v2.size(), 0);
	EXPECT_EQ(v2.capacity(), 100);
}
