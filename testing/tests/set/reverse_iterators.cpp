/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:56:42 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/11 19:04:41 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetReverseIterators);

TYPED_TEST(SetReverseIterators, Rbegin){
	SET				s1;

	for (int i = 0; i < 3; i++)
		s1.insert(i + 1);

	SET::reverse_iterator	rit = s1.rbegin();
	
	EXPECT_EQ(*rit, 3);
}

TYPED_TEST(SetReverseIterators, Rend){
	SET				s1;

	for (int i = 0; i < 3; i++)
		s1.insert(i + 1);

	SET::reverse_iterator	rite = s1.rend();
	
	EXPECT_EQ(*(--rite), 1);
}

TYPED_TEST(SetReverseIterators, Increment){
	SET	s1;

	for (int i = 0; i < 6; i++)
		s1.insert(i + 1);

	SET::reverse_iterator	rit = s1.rbegin();
	SET::reverse_iterator	rite = s1.rend();

	EXPECT_EQ(*rit, 6);
	EXPECT_EQ(*(++rit), 5);
	EXPECT_EQ(*(rit++), 5);
	EXPECT_EQ(*rit, 4);
	
	while (rit != rite)
		rit++;
	
	EXPECT_EQ(*(--rit), 1);
}

TYPED_TEST(SetReverseIterators, Decrement){
	SET	s1;

	for (int i = 0; i < 6; i++)
		s1.insert(i + 1);

	SET::reverse_iterator	rit = s1.rbegin();
	SET::reverse_iterator	rite = s1.rend();
	
	EXPECT_EQ(*(--rite), 1);
	EXPECT_EQ(*(rite--), 1);
	EXPECT_EQ(*rite, 2);

	while (rite != rit)
		rite--;
		
	EXPECT_EQ(*rite, 6);
};
