/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/09 13:16:45 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "map.hpp"
#include <iostream>
#include <list>
// #include "../containers_test/srcs/base.hpp"
#include "../containers_test/srcs/set/common.hpp"
#include "../testing/tests/complex_types.hpp"

int main(void)
{
	ft::map<ft::map<int, char>, A<ft::map<int, std::string> > >	m1;

	std::cout << "size is " << m1.size() << std::endl;
	std::cout << "empty is " << m1.empty() << std::endl;
	
	return (0);
}
