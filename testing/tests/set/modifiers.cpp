/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:15:28 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/11 19:29:38 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetModifiers);

TYPED_TEST(SetModifiers, InsertSimple){
	SET		s1;

	EXPECT_TRUE(s1.insert(1).second);
	EXPECT_FALSE(s1.insert(1).second);
	EXPECT_TRUE(s1.insert(2).second);

	EXPECT_EQ(*s1.insert(3).first, 3);
};

TYPED_TEST(SetModifiers, InsertHint){
	SET				s1;

	for(int i = 0; i < 3; i++)
		s1.insert(i + 1);

	SET::iterator	it = s1.begin();
	SET::iterator	ite = s1.end();

	EXPECT_EQ(s1.insert(it, 1), it);
	it++;
	EXPECT_EQ(s1.insert(++it, 4), --ite);
};

TYPED_TEST(SetModifiers, InsertRange){
	SET		s1;
	SET		s2;

	for(int i = 0; i < 3; i++)
		s1.insert(i + 1);

	for(int i = 0; i < 3; i++)
		s1.insert(i + 4);

	s2.insert(s1.begin(), s1.end());

	SET::iterator	it = s2.begin();
	SET::iterator	ite = s2.end();

	EXPECT_EQ(s2.size(), 6);
	EXPECT_EQ(*it, 1);
	EXPECT_EQ(*(--ite), 6);	
};

TYPED_TEST(SetModifiers, EraseIterator){
	SET		s1;
	
	for(int i = 0; i < 6; i++)
		s1.insert(i + 1);

	SET::iterator	it = s1.begin();
	SET::iterator	ite = s1.end();
	
	it++; it++; it++;
	ite--;
	
	s1.erase(it);
	s1.erase(ite);
	
	EXPECT_EQ(s1.size(), 4);
	it = s1.begin();

	EXPECT_EQ(*it++, 1);
	EXPECT_EQ(*it++, 2);
	EXPECT_EQ(*it++, 3);
	EXPECT_EQ(*it++, 5);
};

TYPED_TEST(SetModifiers, EraseKey){
	SET		s1;

	for(int i = 0; i < 6; i++)
		s1.insert(i + 1);

	s1.erase(1);
	s1.erase(6);

	SET::iterator	it = s1.begin();

	for (int i = 2; i < 6; i++, it++)
		EXPECT_EQ(*it, i);
};

TYPED_TEST(SetModifiers, EraseRange){
	SET		s1;
	
	for(int i = 0; i < 6; i++)
		s1.insert(i + 1);

	SET::iterator	it = s1.begin();
	SET::iterator	ite = s1.end();

	ite--; ite--; ite--;
	s1.erase(it, ite);
	it = s1.begin();

	EXPECT_EQ(s1.size(), 3);
	
	for (int i = 4; i < 7; i++, it++)
		EXPECT_EQ(*it, i);

	it = s1.begin();
	ite = s1.end();
	s1.erase(it, ite);

	EXPECT_EQ(s1.size(), 0);
};

TYPED_TEST(SetModifiers, Swap){
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

	s1.swap(s2);
	
	EXPECT_EQ(s1.size(), 4);
	EXPECT_EQ(*s1.begin(), 4);
	EXPECT_EQ(*s1.rbegin(), 7);
	EXPECT_EQ(s2.size(), 3);
	EXPECT_EQ(*s2.begin(), 1);
	EXPECT_EQ(*s2.rbegin(), 3);
};

TYPED_TEST(SetModifiers, Clear){
	SET		s1;
	
	for(int i = 0; i < 6; i++)
		s1.insert(i + 1);

	EXPECT_EQ(s1.size(), 6);
	s1.clear();
	EXPECT_EQ(s1.size(), 0);
	EXPECT_TRUE(s1.empty());
};
