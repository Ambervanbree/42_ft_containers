/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:28:08 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/06 12:42:31 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

# include <vector>
# include "vector.hpp"

// Macro for VECTOR
# define VECTOR typename TestFixture::Types

// Types to use for test
using SimpleTypes = ::testing::Types
<
	ft::vector<int>,
	std::vector<int>,
	ft::vector<char>,
	std::vector<char>
>;

class A {};
struct B {};

using ComplexTypes = ::testing::Types
<
	ft::vector<int>,
	std::vector<int>,
	ft::vector<char>,
	std::vector<char>,	
	ft::vector<A>,
	std::vector<A>,
	ft::vector<B>,
	std::vector<B>
>;

// Test suites
template<typename T>
struct VectorComplexConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorComplexConstruct, ComplexTypes);

template<typename T>
struct VectorSimpleConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorSimpleConstruct, SimpleTypes);

#endif