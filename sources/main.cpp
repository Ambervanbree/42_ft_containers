/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/04 12:07:56 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "RBtree.hpp"
#include <iostream>

using namespace ft;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main (){
	{
  map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  mymap.visualise();

  // show content:
	map<char,int>::reverse_iterator rit = mymap.rbegin();
	std::cout << "rbegin is " << mymap.rbegin()->first << std::endl;
	std::cout << "rend is " << mymap.rend()->first << std::endl;

	std::cout << rit->first << " => " << rit->second << '\n';
	++rit;
	std::cout << rit->first << " => " << rit->second << '\n';
	++rit;
	std::cout << rit->first << " => " << rit->second << '\n';
	++rit;
	std::cout << rit->first << " => " << rit->second << '\n';

//   for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)

	// for (map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); it++)
    // std::cout << it->first << " => " << it->second << '\n';

	// map<char, int>::const_reverse_iterator it = mymap.rbegin();
	// map<char, int>::const_reverse_iterator ti = mymap.rend();

	// it++;
	// ++it;
	// it--;
	// --it;

	// ti--;
	// --ti;
	// ++ti;
	// ti++;

	// ti = it;

	// map<char, int>::reverse_iterator end = mymap.rend();
	// while(it != end)
	// {
    // 	std::cout << it->first << " => " << it->second << '\n';
	// 	it++;
	// }


  return 0;
	}
}
