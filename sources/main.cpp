/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/08/31 18:51:43 by avan-bre         ###   ########.fr       */
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

int main ()
{
  map<char,int> mymap;
  map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  mymap.visualise();

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  std::cout << "low : " << itlow->first << '\n';
  std::cout << "up : " << itup->first << '\n';

  mymap.visualise();
  
  std::cout << "begin: " << mymap.begin()->first << std::endl;
  std::cout << "end: " << mymap.end()->first << std::endl;

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  std::cout << "begin: " << mymap.begin()->first << std::endl;
  std::cout << "end: " << mymap.end()->first << std::endl;

//   mymap.visualise();

//   // print content:
//   for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

  return 0;
}


// int main ()
// {
//  	map<char,int> mymap;

//   // first insert function version (single parameter):
//   mymap.insert ( pair<char,int>('a',100) );
//   mymap.insert ( pair<char,int>('z',200) );

//   pair<map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( pair<char,int>('z',500) );
//   if (ret.second==false) {
//     std::cout << "element 'z' already exists";
//     std::cout << " with a value of " << ret.first->second << '\n';
//   }

// //   // second insert function version (with hint position):
// //   map<char,int>::iterator it = mymap.begin();
// //   mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
// //   mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

// //   // third insert function version (range insertion):
// //   map<char,int> anothermap;
// //   anothermap.insert(mymap.begin(),mymap.find('c'));

// //   // showing contents:
// //   std::cout << "mymap contains:\n";
// //   for (it = mymap.begin(); it!=mymap.end(); ++it)
// //     std::cout << it->first << " => " << it->second << '\n';

// //   std::cout << "anothermap contains:\n";
// //   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
// //     std::cout << it->first << " => " << it->second << '\n';

// //   return 0;
// }
