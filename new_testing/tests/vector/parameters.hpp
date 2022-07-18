/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:28:08 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/18 12:46:57 by avan-bre         ###   ########.fr       */
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

class A {};

struct B {
	private:
		int			_n;
		// std::string	_str;

	public:
		B() : _n(124) {}
		// _str("Hiyaa") {}
		B(int n, std::string str) : _n(n) {}
		//, _str(str) {}
		B(B const &x ) {*this = x;}
		virtual ~B(void) {}
		
		B &operator=(B const &x) {_n = x._n; return *this; }
		// _str = x._str; return *this; }
};

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

using StringTypes = ::testing::Types
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
TYPED_TEST_SUITE(VectorStringConstruct, StringTypes);

template<typename T>
struct VectorCapacity : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(VectorCapacity, SimpleType);

#endif