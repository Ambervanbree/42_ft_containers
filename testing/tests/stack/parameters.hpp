/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:28:08 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/08 17:56:03 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

# include <stack>
# include "stack.hpp"

// Macro for VECTOR
# define STACK typename TestFixture::Types

// Types to use for test
using SimpleTypes = ::testing::Types
<
	ft::stack<int>,
	std::stack<int>,
	ft::stack<char>,
	std::stack<char>
>;

class A {};
struct B {};

using ComplexTypes = ::testing::Types
<
	ft::stack<int>,
	std::stack<int>,
	ft::stack<char>,
	std::stack<char>,
	ft::stack<std::string>,
	std::stack<std::string>
	// ft::stack<A>,
	// std::stack<A>
	// ft::stack<B>,
	// std::stack<B>
>;

// Test suites
template<typename T>
struct StackComplexConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackComplexConstruct, ComplexTypes);

template<typename T>
struct StackSimpleConstruct : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackSimpleConstruct, SimpleTypes);

template<typename T>
struct StackMemberFunctions : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackMemberFunctions, SimpleTypes);

template<typename T>
struct StackOperators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(StackOperators, SimpleTypes);

#endif