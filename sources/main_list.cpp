/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:05:00 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/16 11:50:44 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <list>
#include "../containers_test/srcs/vector/common.hpp"
#include "../containers_test/srcs/base.hpp"

#define TESTED_TYPE int

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::vector<TESTED_TYPE> vct(lst.begin(), lst.end());

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	return (0);
}
