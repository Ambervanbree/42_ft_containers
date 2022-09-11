/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialised_algorithms.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:56:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/11 19:45:05 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetSpecialisedAlgorithms);

TYPED_TEST(SetSpecialisedAlgorithms, NonMemberSwap){
	SET		s1;
	SET		s2;

	for(int i = 0; i < 3; i++)
		s1.insert(i + 1);
	for(int i = 0; i < 4; i++)
		s2.insert(i + 4);

	EXPECT_EQ(s1.size(), 3);
	EXPECT_EQ(*s1.begin(), 1);
	EXPECT_EQ(*s1.rbegin(), 3);
	EXPECT_EQ(s2.size(), 4);
	EXPECT_EQ(*s2.begin(), 4);
	EXPECT_EQ(*s2.rbegin(), 7);

	swap(s1, s2);
	
	EXPECT_EQ(s1.size(), 4);
	EXPECT_EQ(*s1.begin(), 4);
	EXPECT_EQ(*s1.rbegin(), 7);
	EXPECT_EQ(s2.size(), 3);
	EXPECT_EQ(*s2.begin(), 1);
	EXPECT_EQ(*s2.rbegin(), 3);		
};
