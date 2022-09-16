/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:00:48 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/16 09:46:53 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetCapacity);

TYPED_TEST(SetCapacity, Empty){
	SET				s1;

	EXPECT_TRUE(s1.empty());

	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);

	EXPECT_FALSE(s1.empty());

	s1.clear();

	EXPECT_TRUE(s1.empty());
};


TYPED_TEST(SetCapacity, Size){
	SET				s1;

	EXPECT_EQ(s1.size(), 0);

	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	
	EXPECT_EQ(s1.size(), 4);

	s1.clear();

	EXPECT_EQ(s1.size(), 0);
};

TYPED_TEST(SetCapacity, MaxSize){
	SET									s1;
	std::allocator<ft::RBnode<int> >	alloc;
	
	EXPECT_EQ(s1.max_size(), alloc.max_size());
};
