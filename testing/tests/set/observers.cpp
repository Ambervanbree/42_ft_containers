/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:25:48 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/12 09:30:40 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetObservers);

TYPED_TEST(SetObservers, KeyComp){
	SET		m1;

	for(int i = 0; i < 3; i++)
		m1.insert(i + 1);

	SET::key_compare	comp = m1.key_comp();
	SET::iterator		it = m1.begin();

	EXPECT_TRUE(comp(*it, 2));
	EXPECT_FALSE(comp(*(++it), 2));
};

TYPED_TEST(SetObservers, ValueComp){
	SET		m1;

	for(int i = 0; i < 3; i++)
		m1.insert(i + 1);

	SET::key_compare	comp = m1.key_comp();
	SET::iterator		it = m1.begin();

	EXPECT_TRUE(comp(*it, 2));
	EXPECT_FALSE(comp(*(++it), 2));
};
