/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:28:08 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/21 15:38:58 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

# include <iostream>
# include <vector>
# include "vector.hpp"

// Macro for VECTOR
# define VECTOR typename TestFixture::Types

// Types to use for test
using SimpleType = ::testing::Types
<
	ft::vector<int>,
	std::vector<int>
>;

struct A {};

class B {};

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

using StringType = ::testing::Types
<
	ft::vector<std::string>,
	std::vector<std::string>
>;

// Test suites
template<typename T>
struct VectorComplexConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorComplexConstruct, ComplexTypes);

template<typename T>
struct VectorSimpleConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorSimpleConstruct, SimpleType);

template<typename T>
struct VectorStringConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorStringConstruct, StringType);

template<typename T>
struct VectorCapacity : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorCapacity, SimpleType);

template<typename T>
struct VectorCapacityString : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorCapacityString, StringType);

template<typename T>
struct VectorAccess : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorAccess, SimpleType);

template<typename T>
struct VectorModifiers : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorModifiers, SimpleType);

template<typename T>
struct VectorModifiersString : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorModifiersString, StringType);

template<typename T>
struct VectorOperators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorOperators, SimpleType);

template<typename T>
struct VectorIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorIterators, SimpleType);

template<typename T>
struct VectorReverseIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorReverseIterators, SimpleType);

#endif