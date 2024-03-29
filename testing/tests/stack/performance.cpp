/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:45:34 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/12 14:56:21 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(StackPerformance_ft);

TYPED_TEST(StackPerformance_ft, Insert){
	STACK		s1;

	for (int i = 0; i < 1000000; i++)
		s1.push(i);	
};

TYPED_TEST(StackPerformance_ft, Pop){
	STACK		s1;

	for (int i = 0; i < 1000000; i++)
		s1.push(i);	

	for (int i = 0; i < 1000000; i++)
		s1.pop();	
};

TYPED_TEST_SUITE_P(StackPerformance_std);

TYPED_TEST(StackPerformance_std, Insert){
	STACK		s1;

	for (int i = 0; i < 1000000; i++)
		s1.push(i);	
};

TYPED_TEST(StackPerformance_std, Pop){
	STACK		s1;

	for (int i = 0; i < 1000000; i++)
		s1.push(i);

	for (int i = 0; i < 1000000; i++)
		s1.pop();	
};
