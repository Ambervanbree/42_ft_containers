/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:01:42 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/27 12:35:26 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <type_traits>
#include <new>
#include <iostream>
#include <string>

template <class T>
void foo(T){
	std::cout << "T is signed" << std::endl;
}

template <class T, class = typename std::enable_if<std::is_unsigned<T>::value>::type>
void foo(T){
	std::cout << "T is unsigned" << std::endl;
}

int main(void){
	unsigned int x = 5;
	foo(x);
}
