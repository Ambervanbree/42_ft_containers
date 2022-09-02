/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/02 17:50:26 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include <iostream>
#include <list>
// #include "../containers_test/srcs/base.hpp"
#include "../containers_test/srcs/map/common.hpp"

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "param: " << param->first << " => " << param->second << std::endl;
	mp.visualise();
	// for (ft::map<T1, T2>::iterator it = mp.begin(); it != mp.end(); it++)
	// 	it.base()->print_contents();
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_erase(mp, ++mp.begin());

	// ft_erase(mp, mp.begin());
	// ft_erase(mp, --mp.end());

	// ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	// ft_erase(mp, --(--(--mp.end())), --mp.end());

	// mp[10] = "Hello";
	// mp[11] = "Hi there";
	// printSize(mp);
	// ft_erase(mp, --(--(--mp.end())), mp.end());

	// mp[12] = "ONE";
	// mp[13] = "TWO";
	// mp[14] = "THREE";
	// mp[15] = "FOUR";
	// printSize(mp);
	// ft_erase(mp, mp.begin(), mp.end());

	// return (0);
}
