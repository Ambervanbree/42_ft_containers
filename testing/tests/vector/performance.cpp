/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:45:34 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/12 14:52:15 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(VectorPerformance_ft);

TYPED_TEST(VectorPerformance_ft, PushBack){
	VECTOR		v1(20);

	for (int i = 0; i < 1000000; i++)
		v1.push_back(i);	
};

TYPED_TEST(VectorPerformance_ft, Erase){
	VECTOR		v1(20);

	for (int i = 0; i < 1000000; i++)
		v1.push_back(i);	

	v1.clear();
};

TYPED_TEST_SUITE_P(VectorPerformance_std);

TYPED_TEST(VectorPerformance_std, PushBack){
	VECTOR		v1(20);

	for (int i = 0; i < 1000000; i++)
		v1.push_back(i);	
};

TYPED_TEST(VectorPerformance_std, Erase){
	VECTOR		v1(20);

	for (int i = 0; i < 1000000; i++)
		v1.push_back(i);	

	v1.clear();
};
