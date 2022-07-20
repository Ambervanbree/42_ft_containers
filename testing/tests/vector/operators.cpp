/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:35:27 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/19 12:38:52 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorOperators);

TYPED_TEST(VectorOperators, NonMember){
	VECTOR	v1(4);
	VECTOR	v2(4);
	
	EXPECT_TRUE(v1 == v2);
	EXPECT_TRUE(v1 == v1);

	v1.resize(23);

	EXPECT_FALSE(v1 == v2);
	EXPECT_TRUE(v1 != v2);
	
	v2.insert(v2.begin() + 2, 3, 12);
	
	EXPECT_TRUE(v1 <= v2);
	EXPECT_FALSE(v1 >= v2);
	EXPECT_TRUE(v1 < v2);
	EXPECT_FALSE(v1 > v2);
}

TYPED_TEST(VectorOperators, NonMemberSwap){
	VECTOR				v1(4);
	VECTOR				v2(4);

	v1.resize(23);
	v2.insert(v2.begin(), 3, 12);

	VECTOR::iterator	it1 = v1.begin();
	VECTOR::iterator	it2 = v2.begin();

	EXPECT_EQ(*it1, 0);
	EXPECT_EQ(*it2, 12);
	EXPECT_EQ(*(v1.begin()), 0);
	EXPECT_EQ(*(v2.begin()), 12);	

	swap(v1, v2);
	
	EXPECT_EQ(*it1, 0);
	EXPECT_EQ(*it2, 12);
	EXPECT_EQ(*(v1.begin()), 12);
	EXPECT_EQ(*(v2.begin()), 0);	
}
