/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:55 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/18 18:11:42 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <list>
#include <iostream>

struct B {
	private:
		int			_n;
		std::string	_str;

	public:
		B() : _n(124), _str("Hiyaa") {}
		B(int n, std::string str) : _n(n), _str(str) {}
		B(B const &x ) {*this = x;}
		virtual ~B(void) {}
		
		B &operator=(B const &x) {_n = x._n; _str = x._str; return *this; }
};


template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::reverse_iterator it = vct.rbegin();
	ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	// std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	// std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	// printSize(vct, true);
	// return (0);
}

// int		main(void)
// {
// 	const int size = 5;
// 	ft::vector<int> vct(size);
// 	ft::vector<int>::reverse_iterator it(vct.rbegin());
// 	ft::vector<int>::const_reverse_iterator ite(vct.rend());

// 	for (int i = 1; it != ite; ++i)
// 		*it++ = (i * 7);
// 	printSize(vct, 1);

// 	it = vct.rbegin();
// 	ite = vct.rbegin();

// 	std::cout << *(++ite) << std::endl;
// 	std::cout << *(ite++) << std::endl;
// 	std::cout << *ite++ << std::endl;
// 	std::cout << *++ite << std::endl;

// 	it->m();
// 	ite->m();

// 	std::cout << *(++it) << std::endl;
// 	std::cout << *(it++) << std::endl;
// 	std::cout << *it++ << std::endl;
// 	std::cout << *++it << std::endl;

// 	std::cout << *(--ite) << std::endl;
// 	std::cout << *(ite--) << std::endl;
// 	std::cout << *--ite << std::endl;
// 	std::cout << *ite-- << std::endl;

// 	(*it).m();
// 	(*ite).m();

// 	std::cout << *(--it) << std::endl;
// 	std::cout << *(it--) << std::endl;
// 	std::cout << *it-- << std::endl;
// 	std::cout << *--it << std::endl;

// 	return (0);
// }

	// ft::vector<B> v1(5);
	// std::vector<B> v2(5);

	// std::cout << "size v1: " << v1.size() << std::endl;
	// std::cout << "size v2: " << v2.size() << std::endl;
	// std::cout << "capacity v1: " << v1.capacity() << std::endl;
	// std::cout << "capacity v2: " << v2.capacity() << std::endl;

	// {
	// 	ft::vector<std::string>	v1;

	// 	v1.push_back("hello");
	// 	v1.push_back("how");
	// 	v1.push_back("are");
	// 	v1.push_back("you");
	// 	v1.push_back("silly");

	// 	ft::vector<std::string>::reverse_iterator	rit	= v1.rbegin();
	// 	ft::vector<std::string>::reverse_iterator 	rit2 = v1.rbegin() + 3;

	// 	std::cout << "rit - rit2 is: " << rit - rit2 << std::endl;
	// 	std::cout << "rit2 - rit is: " << rit2 - rit << std::endl;
	// }
	// {
	// 	std::vector<std::string>	v1;

	// 	v1.push_back("hello");
	// 	v1.push_back("how");
	// 	v1.push_back("are");
	// 	v1.push_back("you");
	// 	v1.push_back("silly");

	// 	std::vector<std::string>::reverse_iterator	rit	= v1.rbegin();
	// 	std::vector<std::string>::reverse_iterator 	rit2 = v1.rbegin() + 3;

	// 	std::cout << "rit - rit2 is: " << rit - rit2 << std::endl;
	// 	std::cout << "rit2 - rit is: " << rit2 - rit << std::endl;
	// }
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
