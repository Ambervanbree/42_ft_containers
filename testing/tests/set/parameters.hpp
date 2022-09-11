/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:28:08 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/11 19:43:40 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

# include <iostream>
# include <set>
# include "set.hpp"
# include "../complex_types.hpp"

// Macro for MAP
# define SET typename TestFixture::Types

// Types to use for test
using SimpleType = ::testing::Types
<
	ft::set<int>,
	std::set<int>
>;

using ComplexTypes = ::testing::Types
<
	ft::set<char>,
	std::set<char>,
	ft::set<std::string>,
	std::set<std::string>,
	ft::set<B>,
	std::set<B>,
	ft::set< A<int> >,
	std::set< A<int> >,
	ft::set< A<ft::set<int> > >,
	std::set< A<std::set<int> > >
>;

// Test suites
template<typename T>
struct SetComplexConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetComplexConstruct, ComplexTypes);

template<typename T>
struct SetSimpleConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetSimpleConstruct, SimpleType);

template<typename T>
struct SetIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetIterators, SimpleType);

template<typename T>
struct SetReverseIterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetReverseIterators, SimpleType);

template<typename T>
struct SetCapacity : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetCapacity, SimpleType);

template<typename T>
struct SetModifiers : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetModifiers, SimpleType);

template<typename T>
struct SetOperations : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetOperations, SimpleType);

template<typename T>
struct SetOperators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetOperators, SimpleType);

template<typename T>
struct SetSpecialisedAlgorithms : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(SetSpecialisedAlgorithms, SimpleType);

#endif