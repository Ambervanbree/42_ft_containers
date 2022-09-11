/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:37:41 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/11 18:58:12 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetIterators);

TYPED_TEST(SetIterators, Begin){
	SET				s1;

	for (int i = 0; i < 3; i++)
		s1.insert(i + 1);

	SET::iterator	it = s1.begin();
	
	EXPECT_EQ(*it, 1);
}

TYPED_TEST(SetIterators, End){
	SET				s1;
	
	for (int i = 0; i < 3; i++)
		s1.insert(i + 1);

	SET::iterator	ite = s1.end();
	
	EXPECT_EQ(*(--ite), 3);
}

TYPED_TEST(SetIterators, Increment){
	SET	s1;

	for (int i = 0; i < 6; i++)
		s1.insert(i + 1);

	SET::iterator	it = s1.begin();
	SET::iterator	ite = s1.end();

	EXPECT_EQ(*it, 1);
	EXPECT_EQ(*(++it), 2);
	EXPECT_EQ(*(it++), 2);
	EXPECT_EQ(*it, 3);
	
	while (it != ite)
		it++;
	
	EXPECT_EQ(*(--it), 6);
}

TYPED_TEST(SetIterators, Decrement){
	SET	s1;

	for (int i = 0; i < 6; i++)
		s1.insert(i + 1);

	SET::iterator	it = s1.begin();
	SET::iterator	ite = s1.end();
	
	EXPECT_EQ(*(--ite), 6);
	EXPECT_EQ(*(--ite), 5);
	EXPECT_EQ(*(ite--), 5);
	EXPECT_EQ(*ite, 4);

	while (ite != it)
		ite--;
		
	EXPECT_EQ(*ite, 1);
};
