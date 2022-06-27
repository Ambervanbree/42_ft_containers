/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:06:22 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/27 17:09:11 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include "stack.hpp"

int	main(void){
	ft::stack<int>	s1;
	std::stack<int>	s2;

	std::cout << "empty " << s1.empty() << std::endl;
	std::cout << "empty " << s2.empty() << std::endl;
	s1.push(5);
	s2.push(5);
	std::cout << "top " << s1.top() << std::endl;
	std::cout << "top " << s2.top() << std::endl;
	std::cout << "empty " << s1.empty() << std::endl;
	std::cout << "empty " << s2.empty() << std::endl;
	std::cout << "size " << s1.size() << std::endl;
	std::cout << "size " << s2.size() << std::endl;
	s1.pop();
	s2.pop();
	std::cout << "empty " << s1.empty() << std::endl;
	std::cout << "empty " << s2.empty() << std::endl;
}