/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:01:42 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/21 15:53:39 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <type_traits>
 
class A {};
 
template <typename T>
void isintegral(T a){
	(void)a;
	std::cout << std::boolalpha;
	std::cout << std::is_integral<T>::value << std::endl;
}
 
int main()
{
	bool		t1 = 12;
	char		t2 = 14;
	char16_t	t3 = 3857;
	char32_t	t4 = -5;
	wchar_t		t5 = 73;
	short		t6 = -389;
	int			t7 = 3423235;
	long		t8 = 23749237492374;
	long long	t9 = 1468764983276498763;
	float		t10 = 1.25;
	double		t11 = 5.25;
	long double	t12 = 856487356387465893.2;
	A			t13;
	std::string	t14 = "Hello";
	int			t15[3];
	

	isintegral(t1);
	isintegral(t2);
	isintegral(t3);
	isintegral(t4);
	isintegral(t5);
	isintegral(t6);
	isintegral(t7);
	isintegral(t8);
	isintegral(t9);
	isintegral(t10);
	isintegral(t11);
	isintegral(t12);
	isintegral(t13);
	isintegral(t14);
	isintegral(t15);
}
