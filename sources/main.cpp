/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:06:22 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/28 12:20:00 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <type_traits>
#include <new>
#include <iostream>
#include <string>

template<class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
void foo(T){
	std::cout << "T is integral" << std::endl;
}

void foo(float){
	std::cout << "T is float" << std::endl;
}

void foo(bool){
	std::cout << "T is bool" << std::endl;
}

int main(void){
	int x = 5;
	float y = 5.5;
	bool z = true;
	
	foo(x);
	foo(y);
	foo(z);
}
