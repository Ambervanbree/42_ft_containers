/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:56:42 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/09 17:10:03 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(MapReverseIterators);

TYPED_TEST(MapReverseIterators, Rbegin){
	MAP				m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	MAP::reverse_iterator	rit = m1.rbegin();
	
	EXPECT_EQ(rit->first, 3);
}

TYPED_TEST(MapReverseIterators, Rend){
	MAP				m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	MAP::reverse_iterator	rite = m1.rend();
	
	EXPECT_EQ((--rite)->first, 1);
}

TYPED_TEST(MapReverseIterators, Dereference){
	MAP		m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	MAP::reverse_iterator	rit = m1.rbegin();
	
	EXPECT_EQ(rit->first, 3);
	EXPECT_EQ(rit->second, 'c');
	EXPECT_EQ((*rit).first, 3);
}

TYPED_TEST(MapReverseIterators, Increment){
	MAP	m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP::reverse_iterator	rit = m1.rbegin();
	MAP::reverse_iterator	rite = m1.rend();

	EXPECT_EQ(rit->second, 'f');
	EXPECT_EQ((++rit)->second, 'e');
	EXPECT_EQ(rit++->second, 'e');
	EXPECT_EQ(rit->second, 'd');
	
	while (rit != rite)
		rit++;
	
	EXPECT_EQ(rit->second, '\0');
}

TYPED_TEST(MapReverseIterators, Decrement){
	MAP	m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';
	m1[4] = 'd';
	m1[5] = 'e';
	m1[6] = 'f';

	MAP::reverse_iterator	rit = m1.rbegin();
	MAP::reverse_iterator	rite = m1.rend();
	
	EXPECT_EQ(rite->second, '\0');
	EXPECT_EQ((--rite)->second, 'a');
	EXPECT_EQ(rite--->second, 'a');
	EXPECT_EQ(rite->second, 'b');

	while (rite != rit)
		rite--;
		
	EXPECT_EQ(rite->second, 'f');
};
