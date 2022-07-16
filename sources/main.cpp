/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/16 17:16:05 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
	{
		ft::vector<std::string>	v1;

		v1.push_back("hello");
		v1.push_back("how");
		v1.push_back("are");
		v1.push_back("you");
		v1.push_back("silly");

		ft::vector<std::string>::reverse_iterator	rit	= v1.rbegin();
		ft::vector<std::string>::reverse_iterator 	rit2 = v1.rbegin() + 3;

		std::cout << "rit - rit2 is: " << rit - rit2 << std::endl;
		std::cout << "rit2 - rit is: " << rit2 - rit << std::endl;
	}
	{
		std::vector<std::string>	v1;

		v1.push_back("hello");
		v1.push_back("how");
		v1.push_back("are");
		v1.push_back("you");
		v1.push_back("silly");

		std::vector<std::string>::reverse_iterator	rit	= v1.rbegin();
		std::vector<std::string>::reverse_iterator 	rit2 = v1.rbegin() + 3;

		std::cout << "rit - rit2 is: " << rit - rit2 << std::endl;
		std::cout << "rit2 - rit is: " << rit2 - rit << std::endl;
	}
}





// template <class T>
// void	print(ft::vector<ft::vector<T> >& lst)
// {
// 	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			std::cout << *it2 << ' ';
// 		std::cout << '\n';
// 	}
// }

// template <class T>
// void	print(ft::vector<T>& lst)
// {
// 	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';
// }

// template <class T>
// void	print(ft::vector<ft::vector<T> >& lst)
// {
// 	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			std::cout << *it2 << ' ';
// 		std::cout << '\n';
// 	}
// }

// template <class T>
// void	print(ft::vector<T>& lst)
// {
// 	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';
// }


// int main ()
// {
	// ft::vector<int> myvector (5);  // 5 default-constructed ints

	// int i=0;

	// ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	// for (; rit!= myvector.rend(); ++rit)
	// 	*rit = ++i;

	// std::cout << "myvector contains:";
	// for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// return 0;

	// ft::vector<int>	v1(5);

	// int i=0;

	// // ft::vector<int>::iterator	it;
	// std::cout << "myvector contains:";
	// for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
	
	// ft::vector<int>::reverse_iterator rit = v1.rbegin();
	// for (; rit != v1.rend(); ++rit){
	// 	std::cout << "Base is: " << *rit.base() << std::endl;
	// 	*rit = ++i;
	// 	std::cout << "Rit is: " << *rit << std::endl;
	// }

	// std::cout << "myvector contains:";
	// for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// return 0;	
	
// }
