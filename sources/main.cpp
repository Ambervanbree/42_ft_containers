/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/11 19:48:15 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "map.hpp"
#include <iostream>
#include <list>
#include "../testing/tests/complex_types.hpp"

int main(void)
{
	ft::map<ft::map<int, char>, A<ft::map<int, std::string> > >	m1;

	std::cout << "size is " << m1.size() << std::endl;
	std::cout << "empty is " << m1.empty() << std::endl;
	
	return (0);
}
