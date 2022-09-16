/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:58:21 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/12 14:43:01 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(SetPerformance_ft);

TYPED_TEST(SetPerformance_ft, Insert){
	SET		s1;

	for (int i = 0; i < 1000000; i++)
		s1.insert(i);	
};

TYPED_TEST(SetPerformance_ft, Erase){
	SET		s1;

	for (int i = 0; i < 1000000; i++)
		s1.insert(i);	

	s1.clear();
};

TYPED_TEST_SUITE_P(SetPerformance_std);

TYPED_TEST(SetPerformance_std, Insert){
	SET		s1;

	for (int i = 0; i < 1000000; i++)
		s1.insert(i);	
};

TYPED_TEST(SetPerformance_std, Erase){
	SET		s1;

	for (int i = 0; i < 1000000; i++)
		s1.insert(i);	

	s1.clear();
};