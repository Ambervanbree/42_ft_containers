/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:34:37 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/18 11:55:46 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"
#include <memory>

TYPED_TEST_SUITE_P(VectorCapacity);

TYPED_TEST(VectorCapacity, MaxSize){
	VECTOR				v1;
	std::allocator<int>	alloc;
	
	EXPECT_EQ(v1.max_size(), alloc.max_size());
}

